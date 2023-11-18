#include <Arduino.h>

// Clockface
#include <ClockfaceSetup.h>
// Commons
#include <CWWebServer.h>
#include <StatusController.h>
#include "AudioVisualizer.h"
#include <HTTPUpdate.h>

#define ESP32_LED_BUILTIN 2
#define AUDIO_VISUALIZER_THEME 100
#define CANVAS_THEME 0

void update_progress(int cur, int total)
{
  // Clear screen
  Locator::getDisplay()->fillRect(0, 35, 64, 64, 0x0000);

  // Display progress
  float progress = cur * 100.0 / total;
  char buffer[30];
  sprintf(buffer, "%.0f%%", progress);
  StatusController::getInstance()->printCenter(buffer, 40);
}

void setup()
{
  Serial.begin(115200);
  pinMode(ESP32_LED_BUILTIN, OUTPUT);

  setupClockface();

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

  if (selectedTheme == CANVAS_THEME)
  {
    Serial.print("will update firmware to canvasPlusFirmware");
    // update firmware to canvas
    WiFiClientSecure client;
    client.setInsecure();

    // Reading data over SSL may be slow, use an adequate timeout
    client.setTimeout(12000 / 1000); // timeout argument is defined in seconds for setTimeout

    // Display IP address
    char ipAddressLabel[16];
    sprintf(ipAddressLabel, "IP Address:");
    StatusController::getInstance()->printCenter(ipAddressLabel, 5);

    IPAddress ipAddress = WiFi.localIP();
    char ipAddressString[16];
    sprintf(ipAddressString, "%s", ipAddress.toString().c_str());
    StatusController::getInstance()->printCenter(ipAddressString, 15);

    // Display Loading text
    const char *loadingText = "Loading..";
    StatusController::getInstance()->printCenter(loadingText, 30);

    httpUpdate.onProgress(update_progress);

    t_httpUpdate_return ret = httpUpdate.update(client, "https://raw.githubusercontent.com/robegamesios/clock-club/main/binFiles/canvasPlusFirmware.bin");

    switch (ret)
    {
    case HTTP_UPDATE_FAILED:
      Serial.printf("HTTP_UPDATE_FAILED Error (%d): %s\n", httpUpdate.getLastError(), httpUpdate.getLastErrorString().c_str());
      break;

    case HTTP_UPDATE_NO_UPDATES:
      Serial.println("HTTP_UPDATE_NO_UPDATES");
      break;

    case HTTP_UPDATE_OK:
      Serial.println("HTTP_UPDATE_OK");
      break;
    }
    return;
  }

  if (selectedTheme == AUDIO_VISUALIZER_THEME)
  {
    setupAudioVisualizer();
  }
  else
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
