#pragma once

#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Tile.h>
#include <Locator.h>
#include <Game.h>
#include <Object.h>
#include <ImageUtils.h>
#include <ColorUtil.h>
#include "IClockface.h"
#include "assets_castlevania.h"


class Clockface_castlevania: public IClockface {
  private:
    Adafruit_GFX* _display;
    CWDateTime* _dateTime;
  private:
    void updateClock();
    void drawClockPointer(float angle, byte pointerSize, uint16_t color);
    float degreesToRadians(float degrees);

    
  public:
    Clockface_castlevania(Adafruit_GFX* display);
    void setup(CWDateTime *dateTime);
    void update();
};
