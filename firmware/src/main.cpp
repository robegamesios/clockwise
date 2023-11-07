#include <Arduino.h>

// Clockface
#include <ClockfaceSetup.h>
// Commons
#include <CWWebServer.h>
#include <StatusController.h>

#define ESP32_LED_BUILTIN 2

void setup()
{
  Serial.begin(115200);
  pinMode(ESP32_LED_BUILTIN, OUTPUT);

  StatusController::getInstance()->blink_led(5, 100);

  setupClockface();

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

  createClockface();

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
