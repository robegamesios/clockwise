#include <Arduino.h>

// Clockface
#include <ClockfaceSetup.h>
// Commons
#include <CWWebServer.h>
#include <StatusController.h>

#include <AudioVisualizer.h>

#define ESP32_LED_BUILTIN 2
uint8_t selectedTheme = 7;

void setup()
{
  Serial.begin(115200);
  pinMode(ESP32_LED_BUILTIN, OUTPUT);

  // StatusController::getInstance()->blink_led(5, 100);
  if (selectedTheme == 7)
  {
    setupAudiVisualizer();
    // return;
  }
  else
  {
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

  if (selectedTheme != 7)
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

  if (selectedTheme == 7)
  {
    loopAudioVisualizer();
  }
  else
  {
    clockface->update();
    automaticBrightControl();
  }
}
