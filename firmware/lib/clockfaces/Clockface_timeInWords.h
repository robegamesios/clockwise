#pragma once

#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Tile.h>
#include <Locator.h>
#include <Game.h>
#include <Object.h>
#include <ImageUtils.h>
#include <WiFi.h>

#include "hour8pt7b_timeInWords.h"
#include "minute7pt7b_timeInWords.h"
#include "small4pt7b_timeInWords.h"
#include "DateI18nEN_timeInWords.h"

// Commons
#include "IClockface.h"
#include "Icons.h"


class Clockface_timeInWords: public IClockface {
  private:
    Adafruit_GFX* _display;
    CWDateTime* _dateTime;
    void timeInWords(int h, int m, char* hWords, char* mWords);
    void updateTime();
    void updateDate();
    void updateTemperature();

  public:
    Clockface_timeInWords(Adafruit_GFX* display);
    void setup(CWDateTime *dateTime);
    void update();
};
