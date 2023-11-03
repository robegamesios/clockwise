#pragma once

#include <WiFi.h>
#include <CWPreferences.h>
#include "StatusController.h"
#include "SettingsWebPage.h"
#include <WiFiConnect.h>

#ifndef CLOCKFACE_NAME
#define CLOCKFACE_NAME "UNKNOWN"
#endif

#include <WebServer.h>
#include <ESPmDNS.h>
#include <Update.h>

const char *host = "esp32";
WebServer server(80);
WiFiConnect wifi;

// Function to reset WiFi Manager settings
void resetWiFiManagerSettings()
{
  delay(1000);
  wifi.resetWifi();
  StatusController::getInstance()->forceRestart();
}

void getCurrentSettings()
{
  ClockwiseParams::getInstance()->load();
}

struct ClockwiseWebServer
{
  // String httpBuffer;
  // bool force_restart;
  // bool reset_wifi;
  // const char *HEADER_TEMPLATE_D = "X-%s: %d\r\n";
  // const char *HEADER_TEMPLATE_S = "X-%s: %s\r\n";

  static ClockwiseWebServer *getInstance()
  {
    static ClockwiseWebServer base;
    return &base;
  }

  void startWebServer()
  {
    /*use mdns for host name resolution*/
    if (!MDNS.begin(host))
    { // http://esp32.local
      Serial.println("Error setting up MDNS responder!");
      while (1)
      {
        delay(1000);
      }
    }
    Serial.println("mDNS responder started");
    /*return index page which is stored in serverIndex */
    server.on("/", HTTP_GET, []()
              {
    server.sendHeader("Connection", "close");
    server.send(200, "text/html", serverIndex); });

    // New route handler for resetting WiFi Manager
    server.on("/reset_wifi", HTTP_GET, []()
              {
                server.sendHeader("Connection", "close");
                server.send(200, "text/html", "WiFi Manager has been reset. Your device will restart.");
                resetWiFiManagerSettings(); // Call the reset function
              });

    /*handling uploading firmware file */
    server.on(
        "/update_firmware", HTTP_POST, []()
        {
    server.sendHeader("Connection", "close");
    server.send(200, "text/plain", (Update.hasError()) ? "FAIL" : "OK");
    ESP.restart(); },
        []()
        {
          HTTPUpload &upload = server.upload();
          if (upload.status == UPLOAD_FILE_START)
          {
            Serial.printf("Update: %s\n", upload.filename.c_str());
            if (!Update.begin(UPDATE_SIZE_UNKNOWN))
            { // start with max available size
              Update.printError(Serial);
            }
          }
          else if (upload.status == UPLOAD_FILE_WRITE)
          {
            /* flashing firmware to ESP*/
            if (Update.write(upload.buf, upload.currentSize) != upload.currentSize)
            {
              Update.printError(Serial);
            }
          }
          else if (upload.status == UPLOAD_FILE_END)
          {
            if (Update.end(true))
            { // true to set the size to the current progress
              Serial.printf("Update Success: %u\nRebooting...\n", upload.totalSize);
            }
            else
            {
              Update.printError(Serial);
            }
          }
        });

    server.begin();
  }

  void stopWebServer()
  {
    server.stop();
  }

  void handleHttpRequest()
  {
    server.handleClient();
    delay(1);

    // if (force_restart)
    // {
    //   StatusController::getInstance()->forceRestart();
    // }

    // if (reset_wifi) {
    // delay(1000);
    // wifi.resetWifi();
    // StatusController::getInstance()->forceRestart();
    // }

    // WiFiClient client = server.available();
    // if (client)
    // {
    //   StatusController::getInstance()->blink_led(100, 1);

    //   while (client.connected())
    //   {
    //     if (client.available())
    //     {
    //       char c = client.read();
    //       httpBuffer.concat(c);

    //       if (c == '\n')
    //       {
    //         uint8_t method_pos = httpBuffer.indexOf(' ');
    //         uint8_t path_pos = httpBuffer.indexOf(' ', method_pos + 1);

    //         String method = httpBuffer.substring(0, method_pos);
    //         String path = httpBuffer.substring(method_pos + 1, path_pos);
    //         String key = "";
    //         String value = "";

    //         if (path.indexOf('?') > 0)
    //         {
    //           key = path.substring(path.indexOf('?') + 1, path.indexOf('='));
    //           value = path.substring(path.indexOf('=') + 1);
    //           path = path.substring(0, path.indexOf('?'));
    //         }

    //         processRequest(client, method, path, key, value);
    //         httpBuffer = "";
    //         break;
    //       }
    //     }
    //   }
    //   delay(1);
    //   client.stop();
    // }
  }

  // void processRequest(WiFiClient client, String method, String path, String key, String value)
  // {
  //   if (method == "GET" && path == "/")
  //   {
  //     client.println("HTTP/1.0 200 OK");
  //     client.println("Content-Type: text/html");
  //     client.println();
  //     client.println(SETTINGS_PAGE);
  //   }
  //   else if (method == "GET" && path == "/get")
  //   {
  //     getCurrentSettings(client);
  //   }
  //   else if (method == "GET" && path == "/read")
  //   {
  //     if (key == "pin")
  //     {
  //       readPin(client, key, value.toInt());
  //     }
  //   }
  //   else if (method == "POST" && path == "/restart")
  //   {
  //     client.println("HTTP/1.0 204 No Content");
  //     force_restart = true;
  //   }
  //   else if (method == "POST" && path == "/set")
  //   {
  //     ClockwiseParams::getInstance()->load();
  //     // a baby seal has died due this ifs
  //     if (key == ClockwiseParams::getInstance()->PREF_DISPLAY_BRIGHT)
  //     {
  //       ClockwiseParams::getInstance()->displayBright = value.toInt();
  //     }
  //     else if (key == ClockwiseParams::getInstance()->PREF_WIFI_SSID)
  //     {
  //       ClockwiseParams::getInstance()->wifiSsid = value;
  //     }
  //     else if (key == ClockwiseParams::getInstance()->PREF_WIFI_PASSWORD)
  //     {
  //       ClockwiseParams::getInstance()->wifiPwd = value;
  //     }
  //     else if (key == "autoBright")
  //     { // autoBright=0010,0800
  //       ClockwiseParams::getInstance()->autoBrightMin = value.substring(0, 4).toInt();
  //       ClockwiseParams::getInstance()->autoBrightMax = value.substring(5, 9).toInt();
  //     }
  //     else if (key == ClockwiseParams::getInstance()->PREF_SWAP_BLUE_GREEN)
  //     {
  //       ClockwiseParams::getInstance()->swapBlueGreen = (value == "1");
  //     }
  //     else if (key == ClockwiseParams::getInstance()->PREF_USE_24H_FORMAT)
  //     {
  //       ClockwiseParams::getInstance()->use24hFormat = (value == "1");
  //     }
  //     else if (key == ClockwiseParams::getInstance()->PREF_LDR_PIN)
  //     {
  //       ClockwiseParams::getInstance()->ldrPin = value.toInt();
  //     }
  //     else if (key == ClockwiseParams::getInstance()->PREF_TIME_ZONE)
  //     {
  //       ClockwiseParams::getInstance()->timeZone = value;
  //     }
  //     else if (key == ClockwiseParams::getInstance()->PREF_NTP_SERVER)
  //     {
  //       ClockwiseParams::getInstance()->ntpServer = value;
  //     }
  //     else if (key == ClockwiseParams::getInstance()->PREF_CANVAS_FILE)
  //     {
  //       ClockwiseParams::getInstance()->canvasFile = value;
  //     }
  //     else if (key == ClockwiseParams::getInstance()->PREF_CANVAS_SERVER)
  //     {
  //       ClockwiseParams::getInstance()->canvasServer = value;
  //     }
  //     else if (key == ClockwiseParams::getInstance()->PREF_MANUAL_POSIX)
  //     {
  //       ClockwiseParams::getInstance()->manualPosix = value;
  //     }
  //     ClockwiseParams::getInstance()->save();
  //     client.println("HTTP/1.0 204 No Content");
  //   }
  //   else if (method == "POST" && path == "/reset_wifi")
  //   {
  //     client.println("HTTP/1.0 204 No Content");
  //     reset_wifi = true;
  //   }
  // }

  // void readPin(WiFiClient client, String key, uint16_t pin)
  // {
  //   ClockwiseParams::getInstance()->load();

  //   client.println("HTTP/1.0 204 No Content");
  //   client.printf(HEADER_TEMPLATE_D, key, analogRead(pin));

  //   client.println();
  // }

  // void getCurrentSettings(WiFiClient client)
  // {
  //   ClockwiseParams::getInstance()->load();

  //   client.println("HTTP/1.0 204 No Content");

  //   client.printf(HEADER_TEMPLATE_D, ClockwiseParams::getInstance()->PREF_DISPLAY_BRIGHT, ClockwiseParams::getInstance()->displayBright);
  //   client.printf(HEADER_TEMPLATE_D, ClockwiseParams::getInstance()->PREF_DISPLAY_ABC_MIN, ClockwiseParams::getInstance()->autoBrightMin);
  //   client.printf(HEADER_TEMPLATE_D, ClockwiseParams::getInstance()->PREF_DISPLAY_ABC_MAX, ClockwiseParams::getInstance()->autoBrightMax);
  //   client.printf(HEADER_TEMPLATE_D, ClockwiseParams::getInstance()->PREF_SWAP_BLUE_GREEN, ClockwiseParams::getInstance()->swapBlueGreen);
  //   client.printf(HEADER_TEMPLATE_D, ClockwiseParams::getInstance()->PREF_USE_24H_FORMAT, ClockwiseParams::getInstance()->use24hFormat);
  //   client.printf(HEADER_TEMPLATE_D, ClockwiseParams::getInstance()->PREF_LDR_PIN, ClockwiseParams::getInstance()->ldrPin);
  //   client.printf(HEADER_TEMPLATE_S, ClockwiseParams::getInstance()->PREF_TIME_ZONE, ClockwiseParams::getInstance()->timeZone.c_str());
  //   client.printf(HEADER_TEMPLATE_S, ClockwiseParams::getInstance()->PREF_WIFI_SSID, ClockwiseParams::getInstance()->wifiSsid.c_str());
  //   client.printf(HEADER_TEMPLATE_S, ClockwiseParams::getInstance()->PREF_NTP_SERVER, ClockwiseParams::getInstance()->ntpServer.c_str());
  //   client.printf(HEADER_TEMPLATE_S, ClockwiseParams::getInstance()->PREF_CANVAS_FILE, ClockwiseParams::getInstance()->canvasFile.c_str());
  //   client.printf(HEADER_TEMPLATE_S, ClockwiseParams::getInstance()->PREF_CANVAS_SERVER, ClockwiseParams::getInstance()->canvasServer.c_str());
  //   client.printf(HEADER_TEMPLATE_S, ClockwiseParams::getInstance()->PREF_MANUAL_POSIX, ClockwiseParams::getInstance()->manualPosix.c_str());

  //   client.printf(HEADER_TEMPLATE_S, "CW_FW_VERSION", CW_FW_VERSION);
  //   client.printf(HEADER_TEMPLATE_S, "CW_FW_NAME", CW_FW_NAME);
  //   client.printf(HEADER_TEMPLATE_S, "CLOCKFACE_NAME", CLOCKFACE_NAME);
  //   client.println();
  // }
};
