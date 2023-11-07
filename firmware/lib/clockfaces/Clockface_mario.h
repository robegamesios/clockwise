#pragma once

#include <Arduino.h>

#include "gfx_mario/Super_Mario_Bros__24pt7b.h"

#include <Adafruit_GFX.h>
#include <Tile.h>
#include <Locator.h>
#include <Game.h>
#include <Object.h>
#include <ImageUtils.h>
// Commons
#include <IClockface.h>
#include <CWDateTime.h>

#include "gfx_mario/assets.h"
#include "gfx_mario/mario.h"
#include "gfx_mario/block.h"

class Clockface_mario: public IClockface {
  private:
    Adafruit_GFX* _display;
    CWDateTime* _dateTime;
    void updateTime();

  public:
    Clockface_mario(Adafruit_GFX* display);
    void setup(CWDateTime *dateTime);
    void update();
    void externalEvent(int type);

};
