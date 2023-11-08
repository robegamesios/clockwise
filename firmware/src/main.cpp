#include <Arduino.h>

// Clockface
#include <ClockfaceSetup.h>
// Commons
#include <CWWebServer.h>
#include <StatusController.h>

#include <AudioVisualizer.h>

#define ESP32_LED_BUILTIN 2
#define AUDIO_VISUALIZER_THEME 100
uint8_t selectedTheme = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(ESP32_LED_BUILTIN, OUTPUT);

  ClockwiseParams::getInstance()->load();

  selectedTheme = ClockwiseParams::getInstance()->selectedTheme;

  // StatusController::getInstance()->blink_led(5, 100);
  
  if (selectedTheme == AUDIO_VISUALIZER_THEME)
  {
    Serial.println("selected audio visualizer");
    setupAudiVisualizer();
  }
  else
  {
    Serial.println("selected clockface");
    setupClockface();
  }

  // StatusController::getInstance()->clockwiseLogo();
  delay(1000);

  // StatusController::getInstance()->wifiConnecting();
  wifi.connect();

  while (!wifi.isConnected())
  {
    Serial.println("Wifi not connected, resetting in 1 sec");
    ClockwiseWebServer::getInstance()->stopWebServer();
    delay(1000);
  }

  if (selectedTheme != AUDIO_VISUALIZER_THEME)
  {
    createClockface();
  }

  delay(1000);
  ClockwiseWebServer::getInstance()->startWebServer();
}

void loop()
{

  if (wifi.isConnected())
  {
    ClockwiseWebServer::getInstance()->handleHttpRequest();
  }

  if (selectedTheme == AUDIO_VISUALIZER_THEME)
  {
    loopAudioVisualizer();
  }
  else
  {
    clockface->update();
    automaticBrightControl();
  }
}
