#include <Arduino.h>
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

// Clockface
#include <Clockface.h>
#include <Clockface_mario.h>
#include <Clockface_pacman.h>
// Commons
#include <CWDateTime.h>
#include <CWPreferences.h>
#include <CWWebServer.h>
#include <StatusController.h>

#define MIN_BRIGHT_DISPLAY_ON 4
#define MIN_BRIGHT_DISPLAY_OFF 0

#define ESP32_LED_BUILTIN 2

MatrixPanel_I2S_DMA *dma_display = nullptr;

IClockface *clockface;

CWDateTime cwDateTime;

bool autoBrightEnabled;
long autoBrightMillis = 0;

void displaySetup(bool swapBlueGreen, uint8_t displayBright)
{
  HUB75_I2S_CFG mxconfig(64, 64, 1);

  if (swapBlueGreen)
  {
    // Swap Blue and Green pins because the panel is RBG instead of RGB.
    mxconfig.gpio.b1 = 26;
    mxconfig.gpio.b2 = 12;
    mxconfig.gpio.g1 = 27;
    mxconfig.gpio.g2 = 13;
  }

  mxconfig.gpio.e = 18;
  mxconfig.clkphase = false;

  // Display Setup
  dma_display = new MatrixPanel_I2S_DMA(mxconfig);
  dma_display->begin();
  dma_display->setBrightness8(displayBright);
  dma_display->clearScreen();
}

void automaticBrightControl()
{
  if (autoBrightEnabled)
  {
    if (millis() - autoBrightMillis > 3000)
    {
      int16_t currentValue = analogRead(ClockwiseParams::getInstance()->ldrPin);

      uint16_t ldrMin = ClockwiseParams::getInstance()->autoBrightMin;
      uint16_t ldrMax = ClockwiseParams::getInstance()->autoBrightMax;

      const uint8_t minBright = (currentValue < ldrMin ? MIN_BRIGHT_DISPLAY_OFF : MIN_BRIGHT_DISPLAY_ON);
      uint8_t maxBright = ClockwiseParams::getInstance()->displayBright;

      uint8_t mapLDR = map(currentValue, ldrMin, ldrMax, 1, 5); // 5 slots
      uint8_t mapBright = map(mapLDR, 1, 5, minBright, maxBright);

      // Serial.printf("LDR: %d, Bright: %d\n", currentValue, mapBright);

      dma_display->setBrightness8(mapBright);

      autoBrightMillis = millis();
    }
  }
}

void setup()
{
  Serial.begin(115200);
  pinMode(ESP32_LED_BUILTIN, OUTPUT);

  StatusController::getInstance()->blink_led(5, 100);

  ClockwiseParams::getInstance()->load();

  pinMode(ClockwiseParams::getInstance()->ldrPin, INPUT);

  displaySetup(ClockwiseParams::getInstance()->swapBlueGreen, ClockwiseParams::getInstance()->displayBright);

  uint8_t selectedTheme = ClockwiseParams::getInstance()->selectedTheme;
  Serial.printf("selectedtheme = %d\n", selectedTheme);
  switch (selectedTheme)
  {
  case 0:
    clockface = new Clockface(dma_display);
    break;

  case 1:
    //mario
    clockface = new Clockface_mario(dma_display);
    break;

  case 2:
    //pacman
    clockface = new Clockface_pacman(dma_display);
    break;

  default:
    //same as 0
    clockface = new Clockface(dma_display);
    break;
  }

  autoBrightEnabled = (ClockwiseParams::getInstance()->autoBrightMax > 0);

  StatusController::getInstance()->clockwiseLogo();
  delay(1000);

  StatusController::getInstance()->wifiConnecting();
  wifi.connect();

  while (!wifi.isConnected())
  {
    Serial.println("Wifi not connected, resetting in 1 sec");
    ClockwiseWebServer::getInstance()->stopWebServer();
    delay(1000);
  }
  cwDateTime.begin(ClockwiseParams::getInstance()->timeZone.c_str(),
                   ClockwiseParams::getInstance()->use24hFormat,
                   ClockwiseParams::getInstance()->ntpServer.c_str(),
                   ClockwiseParams::getInstance()->manualPosix.c_str());
  clockface->setup(&cwDateTime);

  delay(1000);
  ClockwiseWebServer::getInstance()->startWebServer();
}

void loop()
{

  if (wifi.isConnected())
  {
    ClockwiseWebServer::getInstance()->handleHttpRequest();
  }

  clockface->update();

  automaticBrightControl();
}
