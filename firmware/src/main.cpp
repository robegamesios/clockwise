#include <Arduino.h>

// Clockface
#include <ClockfaceSetup.h>
// Commons
#include <CWWebServer.h>
#include <StatusController.h>
#include <HTTPUpdate.h>

#define ESP32_LED_BUILTIN 2
#define AUDIO_VISUALIZER_THEME 100

void setup()
{
  Serial.begin(115200);
  pinMode(ESP32_LED_BUILTIN, OUTPUT);

  ClockwiseParams::getInstance()->load();

  uint8_t selectedTheme = ClockwiseParams::getInstance()->selectedTheme;

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

  if (selectedTheme == AUDIO_VISUALIZER_THEME)
  {
    Serial.printf("selectedtheme = %d\n", selectedTheme);
    // update firmware to canvas
        WiFiClientSecure client;
    client.setInsecure();

    // Reading data over SSL may be slow, use an adequate timeout
    client.setTimeout(12000 / 1000); // timeout argument is defined in seconds for setTimeout

    t_httpUpdate_return ret = httpUpdate.update(client, "https://raw.githubusercontent.com/robegamesios/clock-club/main/binFiles/audioVisualizerPlusFirmware.bin");
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

  setupClockface();

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
