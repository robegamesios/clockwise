#pragma once

#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Tile.h>
#include <Locator.h>
#include <Game.h>
#include <Object.h>
#include <ImageUtils.h>
#include <WiFi.h>

// Commons
#include "IClockface.h"
#include "assets_pokedex.h"
#include "Icons.h"
#include "PKMN_RBYGSC4pt7b_pokedex.h"




class Clockface_pokedex: public IClockface {
  private:
    Adafruit_GFX* _display;
    CWDateTime* _dateTime;
    char minutes[3] = {0};

  public:
    Clockface_pokedex(Adafruit_GFX* display);
    void setup(CWDateTime *dateTime);
    void update();
    void refreshDate(uint8_t weekday, uint16_t color);
    void refreshTime();
    void updatePokemon();
    void updateLoadingBar(uint8_t seconds);
};
