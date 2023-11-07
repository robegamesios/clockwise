#ifndef CLOCKFACE_SETUP_H
#define CLOCKFACE_SETUP_H

#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include "IClockface.h"  
#include "CWDateTime.h"
#include <CWPreferences.h>
#include <Clockface.h>
#include <Clockface_mario.h>
#include <Clockface_pacman.h>
#include <Clockface_timeInWords.h>
#include <Clockface_worldMap.h>
#include <Clockface_pokedex.h>
#include <Clockface_castlevania.h>

extern MatrixPanel_I2S_DMA *dma_display;
extern IClockface *clockface;
extern CWDateTime cwDateTime;

void setupClockface();
void automaticBrightControl();
void displaySetup(bool swapBlueGreen, uint8_t displayBright);
void createClockface();

#endif  // CLOCKFACE_SETUP_H
