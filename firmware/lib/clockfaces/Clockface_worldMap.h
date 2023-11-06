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

#include "small4pt7b_worldMap.h"
#include "worldmap_worldMap.h"
#include "worldmap_mask_worldMap.h"

class Clockface_worldMap: public IClockface {
  private:
    Adafruit_GFX* _display;
    CWDateTime* _dateTime;
    void updateMap();
    void croppedDraw(const unsigned short* image_array, int x, int y, int anchorX, int anchorY, int cropX, int cropY, int w, int h);
    
  public:
    Clockface_worldMap(Adafruit_GFX* display);
    void setup(CWDateTime *dateTime);
    void update();
};
