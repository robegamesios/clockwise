#include <Arduino.h>

/********************************************************************************************************************************************************
 * EPS32 Audio Visualizer
 * Github: https://github.com/robegamesios/FFT_ESP32_Analyzer
 * Features:
 *  Web interface by accessing the ESP32 wifi address
 *  Update the firmware via OTA
 *
 * Forked from https://github.com/donnersm/FFT_ESP32_Analyzer

********************************************************************************************************************************************************/

#include <FastLED_NeoMatrix.h>
#include <arduinoFFT.h>
#include "I2SPLUGIN.h"
#include <math.h>
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include "FFT.h"
#include "LEDDRIVER.H"
#include "Settings.h"
#include "PatternsHUB75.h"
#include "fire.h"
#define up 1
#define down 0
int PeakDirection = 0;

long LastDoNothingTime = 0; // only needed for screensaver
int DemoModeMem = 0;        // to remember what mode we are in when going to demo, in order to restore it after wake up
bool AutoModeMem = false;   // same story
bool DemoFlag = false;      // we need to know if demo mode was manually selected or auto engadged.

char LCDPrintBuf[30];

// BucketFrequency
//
// Return the frequency corresponding to the Nth sample bucket.  Skips the first two
// buckets which are overall amplitude and something else.

int BucketFrequency(int iBucket)
{
  if (iBucket <= 1)
    return 0;
  int iOffset = iBucket - 2;
  return iOffset * (samplingFrequency / 2) / (SAMPLEBLOCK / 2);
}

void DrawVUPixels(int i, int yVU, int fadeBy = 0)
{
  CRGB VUC;
  if (i > (PANE_WIDTH / 3))
  {
    VUC.r = 255;
    VUC.g = 0;
    VUC.b = 0;
  }
  else if (i > (PANE_WIDTH / 5))
  {
    VUC.r = 255;
    VUC.g = 255;
    VUC.b = 0;
  }
  else
  { // green
    VUC.r = 0;
    VUC.g = 255;
    VUC.b = 0;
  }

  int xHalf = PANE_WIDTH / 2;
  dma2_display->drawPixelRGB888(xHalf - i - 2, yVU, VUC.r, VUC.g, VUC.b);     // left side of screen line 0
  dma2_display->drawPixelRGB888(xHalf - i - 2, yVU + 1, VUC.r, VUC.g, VUC.b); // left side of screen line 1
  dma2_display->drawPixelRGB888(xHalf + i + 1, yVU, VUC.r, VUC.g, VUC.b);     // right side of screen line 0
  dma2_display->drawPixelRGB888(xHalf + i + 1, yVU + 1, VUC.r, VUC.g, VUC.b); // right side of screen line 1
}

void DrawVUMeter(int yVU)
{
  static int iPeakVUy = 0;           // size (in LED pixels) of the VU peak
  static unsigned long msPeakVU = 0; // timestamp in ms when that peak happened so we know how old it is
  const int MAX_FADE = 256;
  for (int x = 0; x < PANE_WIDTH; x++)
  {
    dma2_display->drawPixelRGB888(x, yVU, 0, 0, 0);
    dma2_display->drawPixelRGB888(x, yVU + 1, 0, 0, 0);
  }
  if (iPeakVUy > 1)
  {
    int fade = MAX_FADE * (millis() - msPeakVU) / (float)1000;
    DrawVUPixels(iPeakVUy, yVU, fade);
  }
  int xHalf = (PANE_WIDTH / 2) - 1;
  int bars = map(gVU, 0, MAX_VU, 1, xHalf);
  bars = min(bars, xHalf);
  if (bars > iPeakVUy)
  {
    msPeakVU = millis();
    iPeakVUy = bars;
  }
  else if (millis() - msPeakVU > 1000)
    iPeakVUy = 0;
  for (int i = 0; i < bars; i++)
    DrawVUPixels(i, yVU);
}

void Calibration(void)
{
  Serial.printf("BandCalibration_XXXX[%1d]=\n{", numBands);
  long Totalbnd = 0;

  for (int g = 0; g < numBands; g++)
  {
    if (bndcounter[g] > Totalbnd)
      Totalbnd = bndcounter[g];
  }

  for (int g = 0; g < numBands; g++)
  {
    bndcounter[g] = Totalbnd / bndcounter[g];
    Serial.printf(" %2.2f", bndcounter[g]);
    if (g < numBands - 1)
      Serial.printf(",");
    else
      Serial.print(" };\n");
  }
}

void make_fire()
{
  uint16_t i, j;

  if (t > millis())
    return;
  t = millis() + (1000 / FPS);

  // First, move all existing heat points up the display and fade

  for (i = rows - 1; i > 0; --i)
  {
    for (j = 0; j < cols; ++j)
    {
      uint8_t n = 0;
      if (pix[i - 1][j] > 0)
        n = pix[i - 1][j] - 1;
      pix[i][j] = n;
    }
  }

  // Heat the bottom row
  for (j = 0; j < cols; ++j)
  {
    i = pix[0][j];
    if (i > 0)
    {
      pix[0][j] = random(NCOLORS - 6, NCOLORS - 2);
    }
  }

  // flare
  for (i = 0; i < nflare; ++i)
  {
    int x = flare[i] & 0xff;
    int y = (flare[i] >> 8) & 0xff;
    int z = (flare[i] >> 16) & 0xff;
    glow(x, y, z);
    if (z > 1)
    {
      flare[i] = (flare[i] & 0xffff) | ((z - 1) << 16);
    }
    else
    {
      // This flare is out
      for (int j = i + 1; j < nflare; ++j)
      {
        flare[j - 1] = flare[j];
      }
      --nflare;
    }
  }
  newflare();

  // Set and draw
  for (i = 0; i < rows; ++i)
  {
    for (j = 0; j < cols; ++j)
    {
      // matrix -> drawPixel(j, rows - i, colors[pix[i][j]]);
      CRGB COlsplit = colors[pix[i][j]];
      dma2_display->drawPixelRGB888(j, rows - i, COlsplit.r, COlsplit.g, COlsplit.b);
    }
  }
}

void DisplayPrint(char *text)
{
  dma2_display->fillRect(8, 8, kMatrixWidth - 16, 11, dma2_display->color444(0, 0, 0));
  dma2_display->setTextSize(1);
  dma2_display->setTextWrap(false);
  dma2_display->setCursor(10, 10);
  dma2_display->print(text);
  delay(1000);
  dma2_display->fillRect(8, 8, kMatrixWidth - 16, 11, dma2_display->color444(0, 0, 0));
}

void setupAudioVisualizer()
{
  Serial.begin(115200);
  Serial.println("Setting up Audio Input I2S");
  setupI2S();
  Serial.println("Audio input setup completed");
  delay(1000);

  SetupHUB75();
  if (kMatrixHeight > 60)
  {
    dma2_display->setBrightness8(32);
  }
}

void loopAudioVisualizer()
{
  size_t bytesRead = 0;

  // ############ Step 1: read samples from the I2S Buffer ##################
  i2s_read(I2S_PORT,
           (void *)samples,
           sizeof(samples),
           &bytesRead,     // workaround This is the actual buffer size last half will be empty but why?
           portMAX_DELAY); // no timeout

  if (bytesRead != sizeof(samples))
  {
    Serial.printf("Could only read %u bytes of %u in FillBufferI2S()\n", bytesRead, sizeof(samples));
    // return;
  }

  // ############ Step 2: compensate for Channel number and offset, safe all to vReal Array   ############
  for (uint16_t i = 0; i < ARRAYSIZE(samples); i++)
  {

    vReal[i] = offset - samples[i];
    vImag[i] = 0.0; // Imaginary part must be zeroed in case of looping to avoid wrong calculations and overflows
  }

  // ############ Step 3: Do FFT on the VReal array  ############
  //  compute FFT
  FFT.DCRemoval();
  FFT.Windowing(vReal, SAMPLEBLOCK, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.Compute(vReal, vImag, SAMPLEBLOCK, FFT_FORWARD);
  FFT.ComplexToMagnitude(vReal, vImag, SAMPLEBLOCK);
  FFT.MajorPeak(vReal, SAMPLEBLOCK, samplingFrequency);
  for (int i = 0; i < numBands; i++)
  {
    FreqBins[i] = 0;
  }
  // ############ Step 4: Fill the frequency bins with the FFT Samples ############
  float averageSum = 0.0f;
  for (int i = 2; i < SAMPLEBLOCK / 2; i++)
  {
    averageSum += vReal[i];
    if (vReal[i] > NoiseTresshold)
    {
      int freq = BucketFrequency(i);
      int iBand = 0;
      while (iBand < numBands)
      {
        if (freq < BandCutoffTable[iBand])
          break;
        iBand++;
      }
      if (iBand > numBands)
        iBand = numBands;
      FreqBins[iBand] += vReal[i];
      //  float scaledValue = vReal[i];
      //  if (scaledValue > peak[iBand])
      //    peak[iBand] = scaledValue;
    }
  }

  // bufmd[0]=FreqBins[12];

  // ############ Step 5: Determine the VU value  and mingle in the readout...( cheating the bands ) ############ Step
  float t = averageSum / (SAMPLEBLOCK / 2);
  gVU = max(t, (oldVU * 3 + t) / 4);
  oldVU = gVU;
  if (gVU > DemoTreshold)
    LastDoNothingTime = millis(); // if there is signal in any off the bands[>2] then no demo mode

  // Serial.printf("gVu: %d\n",(int) gVU);

  for (int j = 0; j < numBands; j++)
  {
    if (CalibrationType == 1)
      FreqBins[j] *= BandCalibration_Pink[j];
    else if (CalibrationType == 2)
      FreqBins[j] *= BandCalibration_White[j];
    else if (CalibrationType == 3)
      FreqBins[j] *= BandCalibration_Brown[j];
  }

  //*
  // ############ Step 6: Averaging and making it all fit on screen
  // for (int i = 0; i < numBands; i++) {
  // Serial.printf ("Chan[%d]:%d",i,(int)FreqBins[i]);
  // FreqBins[i] = powf(FreqBins[i], gLogScale); // in case we want log scale..i leave it in here as reminder
  //  Serial.printf( " - log: %d \n",(int)FreqBins[i]);
  // }
  static float lastAllBandsPeak = 0.0f;
  float allBandsPeak = 0;
  // bufmd[1]=FreqBins[13];
  // bufmd[2]=FreqBins[1];
  for (int i = 0; i < numBands; i++)
  {
    // allBandsPeak = max (allBandsPeak, FreqBins[i]);
    if (FreqBins[i] > allBandsPeak)
    {
      allBandsPeak = FreqBins[i];
    }
  }
  if (allBandsPeak < 1)
    allBandsPeak = 1;
  //  The followinf picks allBandsPeak if it's gone up.  If it's gone down, it "averages" it by faking a running average of GAIN_DAMPEN past peaks
  allBandsPeak = max(allBandsPeak, ((lastAllBandsPeak * (GAIN_DAMPEN - 1)) + allBandsPeak) / GAIN_DAMPEN); // Dampen rate of change a little bit on way down
  lastAllBandsPeak = allBandsPeak;

  if (allBandsPeak < 80000)
    allBandsPeak = 80000;
  for (int i = 0; i < numBands; i++)
  {
    FreqBins[i] /= (allBandsPeak * 1.0f);
  }

  // Process the FFT data into bar heights
  for (int band = 0; band < numBands; band++)
  {
    int barHeight = FreqBins[band] * kMatrixHeight - 1; //(AMPLITUDE);
    if (barHeight > TOP - 2)
      barHeight = TOP - 2;

    // Small amount of averaging between frames
    barHeight = ((oldBarHeights[band] * 1) + barHeight) / 2;

    // Move peak up
    if (barHeight > peak[band])
    {
      peak[band] = min(TOP, barHeight);
      PeakFlag[band] = 1;
    }
    bndcounter[band] += barHeight; // ten behoeve calibratie

    // if there hasn't been much of a input signal for a longer time ( see settings ) go to demo mode
    if ((millis() - LastDoNothingTime) > DemoAfterSec && DemoFlag == false)
    {
      DemoFlag = true;
      // first store current mode so we can go back to it after wake up
      DemoModeMem = buttonPushCounter;
      AutoModeMem = autoChangePatterns;
      autoChangePatterns = false;
      buttonPushCounter = 12;
      dma2_display->clearScreen();
    }
    // Wait,signal is back? then wakeup!
    else if (DemoFlag == true && (millis() - LastDoNothingTime) < DemoAfterSec)
    { //("In loop 2:  %d", millis() - LastDoNothingTime);
      // while in demo the democounter was reset due to signal on one of the bars.
      // So we need to exit demo mode.
      dma2_display->clearScreen();
      buttonPushCounter = DemoModeMem;  // restore settings
      autoChangePatterns = AutoModeMem; // restore settings
      DemoFlag = false;
    }
    // Now visualize those bar heights
    switch (buttonPushCounter)
    {
    case 0:
      PeakDirection = down;
      BoxedBars(band, barHeight);
      BluePeak(band);
      break;

    case 1:
      PeakDirection = down;
      BoxedBars2(band, barHeight);
      BluePeak(band);
      break;
    case 2:
      PeakDirection = down;
      BoxedBars3(band, barHeight);
      RedPeak(band);
      break;
    case 3:
      PeakDirection = down;
      RedBars(band, barHeight);
      BluePeak(band);
      break;
    case 4:
      PeakDirection = down;
      ColorBars(band, barHeight);
      break;
    case 5:
      PeakDirection = down;
      Twins(band, barHeight);
      WhitePeak(band);
      break;
    case 6:
      PeakDirection = down;
      Twins2(band, barHeight);
      WhitePeak(band);
      break;
    case 7:
      PeakDirection = down;
      TriBars(band, barHeight);
      TriPeak(band);
      break;
    case 8:
      PeakDirection = up;
      TriBars(band, barHeight);
      TriPeak(band);
      break;
    case 9:
      PeakDirection = down;
      centerBars(band, barHeight);
      break;
    case 10:
      PeakDirection = down;
      centerBars2(band, barHeight);
      break;
    case 11:
      PeakDirection = down;
      BlackBars(band, barHeight);
      DoublePeak(band);
      break;
    case 12:
      make_fire(); // go to demo mode
      break;
    }

    // Save oldBarHeights for averaging later
    oldBarHeights[band] = barHeight;
  }
  // for calibration
  // bndcounter[h]+=barHeight;
  if (loopcounter == 256)
  {
    loopcounter = 0;
  }
  loopcounter++;

  if (buttonPushCounter != 12)
    DrawVUMeter(0); // Draw it when not in screensaver mode

  // Decay peak
  EVERY_N_MILLISECONDS(Fallingspeed)
  {
    for (byte band = 0; band < numBands; band++)
    {
      if (PeakFlag[band] == 1)
      {
        PeakTimer[band]++;
        if (PeakTimer[band] > Peakdelay)
        {
          PeakTimer[band] = 0;
          PeakFlag[band] = 0;
        }
      }
      else if ((peak[band] > 0) && (PeakDirection == up))
      {
        peak[band] += 1;
        if (peak[band] > (kMatrixHeight + 10))
          peak[band] = 0;
      } // when to far off screen then reset peak height
      else if ((peak[band] > 0) && (PeakDirection == down))
      {
        peak[band] -= 1;
      }
    }
    colorTimer++;
  }

  EVERY_N_MILLISECONDS(10)
  colorTimer++; // Used in some of the patterns

  EVERY_N_SECONDS(secToChangePattern)
  {
    // if (FastLED.getBrightness() == 0) FastLED.setBrightness(BRIGHTNESSMARK);  //Re-enable if lights are "off"
    if (autoChangePatterns)
    {
      buttonPushCounter = (buttonPushCounter + 1) % 12;
      dma2_display->clearScreen();
    }
  }
} // loop end
