#include <Arduino.h>
#include <gfxfont.h>

const uint8_t hour8pt7bBitmaps[] PROGMEM = {
  0x00, 0xFF, 0xFF, 0xF0, 0xF0, 0xE7, 0xE7, 0xE7, 0x63, 0x42, 0x84, 0x03, 
  0x0C, 0xC3, 0x3C, 0xFF, 0xFF, 0x3C, 0xC3, 0x30, 0xCF, 0x3F, 0xFF, 0xCF, 
  0x30, 0xCC, 0x30, 0x00, 0x0C, 0x0F, 0xC7, 0xFB, 0xB7, 0xCC, 0xFB, 0x07, 
  0xF0, 0xFE, 0x0D, 0xF3, 0x3E, 0xDD, 0xFE, 0x3F, 0x03, 0x00, 0x70, 0xFE, 
  0x3D, 0x8F, 0x67, 0xFB, 0x9D, 0xC0, 0xE0, 0x70, 0x3B, 0x9D, 0xFE, 0x6F, 
  0x1B, 0xC7, 0xF0, 0xE0, 0x1C, 0x0F, 0x86, 0x31, 0x8C, 0x63, 0x0D, 0x87, 
  0xC3, 0xF0, 0xCE, 0xF1, 0xFC, 0x3B, 0x8E, 0x7F, 0xCF, 0xB0, 0xFF, 0xB5, 
  0x00, 0x19, 0x99, 0x8C, 0x63, 0x18, 0xC6, 0x30, 0xC3, 0x0C, 0x00, 0xC3, 
  0x0C, 0x31, 0x8C, 0x63, 0x18, 0xC6, 0x66, 0x60, 0x00, 0x18, 0x99, 0xDB, 
  0x7E, 0x3C, 0x7E, 0xDB, 0x99, 0x18, 0x0C, 0x03, 0x00, 0xC0, 0x30, 0xFF, 
  0xFF, 0xF0, 0xC0, 0x30, 0x0C, 0x03, 0x00, 0x33, 0x6C, 0xFF, 0xFF, 0xF0, 
  0x00, 0xC0, 0x30, 0x0C, 0x07, 0x03, 0x81, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 
  0x0E, 0x03, 0x00, 0xC0, 0x30, 0x00, 0x3F, 0x1F, 0xEE, 0x1F, 0x03, 0xC3, 
  0xF1, 0xFC, 0xEF, 0x73, 0xF8, 0xFC, 0x3C, 0x0F, 0x87, 0x7F, 0x8F, 0xC0, 
  0x31, 0xCF, 0x3C, 0x30, 0xC3, 0x0C, 0x30, 0xC3, 0x0C, 0xFF, 0xF0, 0x3F, 
  0x1F, 0xEE, 0x1F, 0x03, 0x00, 0xC0, 0x73, 0xF9, 0xFC, 0xE0, 0x30, 0x0C, 
  0x03, 0x00, 0xFF, 0xFF, 0xF0, 0x3F, 0x1F, 0xEC, 0x1F, 0x03, 0x00, 0xC0, 
  0x70, 0xF8, 0x3E, 0x01, 0xC0, 0x3C, 0x0F, 0x07, 0x7F, 0x8F, 0xC0, 0x03, 
  0x01, 0xC0, 0xF0, 0x7C, 0x3B, 0x1C, 0xCE, 0x33, 0x0C, 0xFF, 0xFF, 0xF0, 
  0x30, 0x0C, 0x03, 0x00, 0xC0, 0xFF, 0xFF, 0xFC, 0x03, 0x00, 0xFF, 0x3F, 
  0xE0, 0x1C, 0x03, 0x00, 0xC0, 0x3C, 0x0F, 0x87, 0x7F, 0x8F, 0xC0, 0x3F, 
  0x1F, 0xEE, 0x1F, 0x03, 0xC0, 0x30, 0x0F, 0xF3, 0xFE, 0xC1, 0xF0, 0x3C, 
  0x0F, 0x87, 0x7F, 0x8F, 0xC0, 0xFF, 0xFF, 0xF0, 0x0C, 0x03, 0x01, 0xC0, 
  0xE0, 0x70, 0x38, 0x0C, 0x03, 0x00, 0xC0, 0x30, 0x0C, 0x03, 0x00, 0x3F, 
  0x1F, 0xEE, 0x1F, 0x03, 0xC0, 0xF8, 0x77, 0xF9, 0xFE, 0xE1, 0xF0, 0x3C, 
  0x0F, 0x87, 0x7F, 0x8F, 0xC0, 0x3F, 0x1F, 0xEE, 0x1F, 0x03, 0xC0, 0xF8, 
  0x37, 0xFC, 0xFF, 0x00, 0xC0, 0x3C, 0x0F, 0x87, 0x7F, 0x8F, 0xC0, 0xF0, 
  0x03, 0xC0, 0x33, 0x00, 0x00, 0x03, 0x36, 0xC0, 0x0C, 0x73, 0x8C, 0x61, 
  0x0C, 0x20, 0xC1, 0x87, 0x0E, 0x1C, 0x30, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 
  0xFF, 0xFF, 0xF0, 0xC3, 0x86, 0x0C, 0x18, 0x60, 0xC1, 0x0C, 0x63, 0x9C, 
  0xE3, 0x00, 0x3F, 0x1F, 0xEE, 0x1F, 0x03, 0x00, 0xC0, 0x70, 0x38, 0x1C, 
  0x0E, 0x03, 0x00, 0x00, 0x00, 0x0C, 0x03, 0x00, 0x3F, 0x18, 0x6C, 0x0E, 
  0x69, 0xB6, 0x6D, 0x9B, 0x66, 0xDB, 0x9D, 0xB0, 0x06, 0x18, 0xFC, 0x18, 
  0x18, 0x66, 0xE7, 0xC3, 0xC3, 0xFF, 0xFF, 0xC3, 0xC3, 0xC3, 0xF9, 0xFB, 
  0x1E, 0x3C, 0x7F, 0xBF, 0x63, 0xC7, 0xFB, 0xE0, 0x38, 0x3C, 0xC6, 0xC0, 
  0xC0, 0xC0, 0xC0, 0xC0, 0xC6, 0x7C, 0x38, 0xF9, 0xFB, 0x1E, 0x3C, 0x78, 
  0xF1, 0xE3, 0xC7, 0xFB, 0xE0, 0xFF, 0xFF, 0xC0, 0xC0, 0xC0, 0xFE, 0xFE, 
  0xC0, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0xC0, 0xC0, 0xFE, 0xFE, 0xC0, 
  0xC0, 0xC0, 0xC0, 0x3C, 0x3C, 0xC3, 0xC3, 0xC0, 0xCF, 0xCF, 0xC3, 0xC3, 
  0x7E, 0x3C, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xFF, 0xFF, 0xC3, 0xC3, 0xC3, 
  0xC3, 0xFF, 0xF3, 0x0C, 0x30, 0xC3, 0x0C, 0x33, 0xFF, 0xC0, 0x1F, 0x8F, 
  0xC1, 0x80, 0xC0, 0x60, 0x30, 0x18, 0x0C, 0xC6, 0x7F, 0x0E, 0x00, 0xC7, 
  0x8F, 0x36, 0xCF, 0x1C, 0x3C, 0x6C, 0xDD, 0x8F, 0x18, 0xC0, 0xC0, 0xC0, 
  0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xFF, 0xFF, 0xC3, 0xC3, 0xE7, 0xFF, 
  0xFB, 0xDB, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xE3, 0xE3, 0xF3, 
  0xDB, 0xCF, 0xC7, 0xC7, 0xC3, 0xC3, 0x38, 0xFB, 0x1E, 0x3C, 0x78, 0xF1, 
  0xE3, 0xC6, 0xF8, 0xE0, 0xF9, 0xFB, 0x1E, 0x3C, 0x7F, 0xBE, 0x60, 0xC1, 
  0x83, 0x00, 0x3C, 0x7E, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xDB, 0xCB, 0x7F, 
  0x3E, 0xF9, 0xFB, 0x1E, 0x3C, 0x7F, 0xBE, 0x68, 0xC9, 0x9B, 0x18, 0x38, 
  0x71, 0x16, 0x3C, 0x0F, 0x0F, 0x03, 0xC6, 0xF8, 0xE0, 0x00, 0xFF, 0xFF, 
  0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xC3, 0xC3, 0xC3, 
  0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0x7E, 0x3C, 0xC3, 0xC3, 0xC3, 0xC3, 
  0xC3, 0xC3, 0xC3, 0xE7, 0x66, 0x18, 0x18, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 
  0xDB, 0xDB, 0xDB, 0xDB, 0x7E, 0x24, 0xC7, 0x8F, 0x1B, 0x63, 0x87, 0x0E, 
  0x36, 0xC7, 0x8F, 0x18, 0xC3, 0xC3, 0xC3, 0xC3, 0xE7, 0x64, 0x3C, 0x18, 
  0x18, 0x18, 0x18, 0xFF, 0xFF, 0x03, 0x06, 0x08, 0x10, 0x30, 0x40, 0x80, 
  0xFF, 0xFF, 0xFF, 0xFC, 0x30, 0xC3, 0x0C, 0x30, 0xC3, 0x0C, 0x30, 0xC3, 
  0xFF, 0xC0, 0xC0, 0x30, 0x0C, 0x03, 0x80, 0x70, 0x0E, 0x01, 0xC0, 0x38, 
  0x07, 0x00, 0xE0, 0x1C, 0x03, 0x00, 0xC0, 0x30, 0xFF, 0xF0, 0xC3, 0x0C, 
  0x30, 0xC3, 0x0C, 0x30, 0xC3, 0x0F, 0xFF, 0xC0, 0x10, 0x38, 0x6C, 0xC6, 
  0xFF, 0xFF, 0xFF, 0xE6, 0x10, 0x3F, 0x0F, 0xE0, 0x1C, 0x03, 0x3E, 0xDF, 
  0xFE, 0x1F, 0x03, 0xC0, 0xF8, 0x77, 0xFC, 0xFB, 0xC0, 0x30, 0x0C, 0x03, 
  0x38, 0xDF, 0x3E, 0xEF, 0x1F, 0x83, 0xE0, 0xF8, 0x3F, 0x1F, 0xEE, 0xDF, 
  0x33, 0x80, 0x3F, 0x1F, 0xEE, 0x1F, 0x03, 0xC0, 0x30, 0x0C, 0x03, 0x03, 
  0xE1, 0xDF, 0xE3, 0xF0, 0x00, 0x00, 0xC0, 0x30, 0x0C, 0x73, 0x3E, 0xDD, 
  0xFE, 0x3F, 0x07, 0xC1, 0xF0, 0x7E, 0x3D, 0xDF, 0x3E, 0xC7, 0x30, 0x3F, 
  0x1F, 0xEE, 0x1F, 0x03, 0xFF, 0xFF, 0xEC, 0x03, 0x00, 0xE1, 0xDF, 0xE3, 
  0xF0, 0x00, 0x0F, 0x1F, 0x18, 0xFF, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x18, 
  0x18, 0x18, 0x18, 0x18, 0x3F, 0x1F, 0xEE, 0x1F, 0x03, 0xE1, 0xDF, 0xF3, 
  0xEC, 0x03, 0x00, 0xD8, 0x77, 0xF8, 0xFC, 0xC0, 0x30, 0x0C, 0x03, 0x38, 
  0xDF, 0x3E, 0xEF, 0x1F, 0x83, 0xC0, 0xF0, 0x3C, 0x0F, 0x03, 0xC0, 0xF0, 
  0x30, 0x30, 0xC0, 0x3C, 0xF0, 0xC3, 0x0C, 0x30, 0xE1, 0xC3, 0x0C, 0x30, 
  0x0F, 0x3C, 0x30, 0xC3, 0x0C, 0x30, 0xC7, 0xFB, 0xC0, 0xC0, 0x30, 0x0C, 
  0x03, 0x03, 0xC1, 0xF0, 0xEC, 0x73, 0x38, 0xDC, 0x3F, 0x8F, 0x73, 0x8E, 
  0xC1, 0xF0, 0x30, 0xFF, 0xFF, 0xFF, 0xF0, 0xDF, 0x3F, 0xEE, 0xDF, 0x33, 
  0xCC, 0xF3, 0x3C, 0xCF, 0x33, 0xCC, 0xF3, 0x3C, 0xCC, 0x00, 0xDF, 0x3F, 
  0xEE, 0x1F, 0x03, 0xC0, 0xF0, 0x3C, 0x0F, 0x03, 0xC0, 0xF0, 0x3C, 0x0C, 
  0x00, 0x3F, 0x1F, 0xEE, 0x1F, 0x03, 0xC0, 0xF0, 0x3C, 0x0F, 0x03, 0xE1, 
  0xDF, 0xE3, 0xF0, 0x00, 0xDF, 0x3F, 0xEF, 0x1F, 0x83, 0xE0, 0xF8, 0x3F, 
  0x1F, 0xFE, 0xDF, 0x30, 0x0C, 0x03, 0x00, 0x3E, 0xDF, 0xFE, 0x3F, 0x07, 
  0xC1, 0xF0, 0x7E, 0x3D, 0xFF, 0x3E, 0xC0, 0x30, 0x0C, 0x03, 0xCF, 0x37, 
  0xEF, 0x9F, 0xC3, 0xE0, 0x30, 0x0C, 0x03, 0x00, 0xC0, 0x30, 0x0C, 0x00, 
  0x00, 0x3F, 0x1F, 0xEE, 0x1F, 0x83, 0x7C, 0x07, 0xC0, 0x7B, 0x07, 0xE1, 
  0xDF, 0xE3, 0xF0, 0x00, 0x30, 0xC3, 0x3F, 0xFC, 0xC3, 0x0C, 0x30, 0xC3, 
  0x0E, 0x1C, 0x30, 0xC0, 0xF0, 0x3C, 0x0F, 0x03, 0xC0, 0xF0, 0x3C, 0x0F, 
  0x03, 0xE1, 0xDF, 0xE3, 0xF0, 0x00, 0xC0, 0xF0, 0x3C, 0x0F, 0x03, 0xC0, 
  0xF0, 0x3E, 0x1D, 0xCE, 0x3F, 0x07, 0x80, 0xC0, 0x00, 0xC0, 0xF0, 0x3C, 
  0x0F, 0x03, 0xCC, 0xF3, 0x3C, 0xCF, 0x33, 0xED, 0xDF, 0xE3, 0x30, 0x00, 
  0xC0, 0xF8, 0x77, 0x38, 0xFC, 0x1E, 0x03, 0x01, 0xE0, 0xFC, 0x73, 0xB8, 
  0x7C, 0x0C, 0x00, 0xC0, 0xF0, 0x3C, 0x1F, 0x07, 0xC3, 0xF9, 0xF7, 0xEC, 
  0xF3, 0x00, 0xC0, 0x73, 0xF8, 0xFC, 0xFF, 0xFF, 0xF0, 0x1C, 0x0E, 0x07, 
  0x03, 0x81, 0xC0, 0xE0, 0x70, 0x3F, 0xFF, 0xFC, 0x00, 0x1C, 0x73, 0xCC, 
  0x30, 0xCE, 0x38, 0xE0, 0xC3, 0x0C, 0x3C, 0x71, 0xC0, 0xFF, 0xFF, 0xFF, 
  0xFC, 0x00, 0xE3, 0x8F, 0x0C, 0x30, 0xC1, 0xC7, 0x1C, 0xC3, 0x0C, 0xF3, 
  0x8E, 0x00, 0x71, 0x73, 0x9E, 0x8C
};

const GFXglyph hour8pt7bGlyphs[] PROGMEM = {
  {     0,   2,   1,   4,    1,    0 }   // ' '
 ,{     1,   2,  14,   3,    0,  -13 }   // '!'
 ,{     5,   8,   6,   9,    0,  -13 }   // '"'
 ,{    11,  10,  13,  11,    0,  -13 }   // '#'
 ,{    28,  10,  14,  11,    0,  -13 }   // '$'
 ,{    46,  10,  14,  11,    0,  -13 }   // '%'
 ,{    64,  10,  14,  11,    0,  -13 }   // '&'
 ,{    82,   3,   6,   4,    0,  -13 }   // '''
 ,{    85,   5,  14,   6,    0,  -13 }   // '('
 ,{    95,   5,  14,   6,    0,  -13 }   // ')'
 ,{   105,   8,   9,   9,    0,  -12 }   // '*'
 ,{   114,  10,  10,  11,    0,   -9 }   // '+'
 ,{   127,   4,   4,   6,    0,   -2 }   // ','
 ,{   129,   8,   2,   9,    0,   -7 }   // '-'
 ,{   131,   2,   2,   3,    0,   -1 }   // '.'
 ,{   132,  10,  14,  11,    0,  -13 }   // '/'
 ,{   150,  10,  14,  11,    0,  -13 }   // '0'
 ,{   168,   6,  14,   7,    0,  -13 }   // '1'
 ,{   179,  10,  14,  11,    0,  -13 }   // '2'
 ,{   197,  10,  14,  11,    0,  -13 }   // '3'
 ,{   215,  10,  14,  11,    0,  -13 }   // '4'
 ,{   233,  10,  14,  11,    0,  -13 }   // '5'
 ,{   251,  10,  14,  11,    0,  -13 }   // '6'
 ,{   269,  10,  14,  11,    0,  -13 }   // '7'
 ,{   287,  10,  14,  11,    0,  -13 }   // '8'
 ,{   305,  10,  14,  11,    0,  -13 }   // '9'
 ,{   323,   2,   9,   3,    0,  -10 }   // ':'
 ,{   326,   4,  11,   5,    0,  -10 }   // ';'
 ,{   332,   6,  14,   7,    0,  -13 }   // '<'
 ,{   343,  10,   6,  11,    0,   -9 }   // '='
 ,{   351,   6,  14,   7,    0,  -13 }   // '>'
 ,{   362,  10,  14,  11,    0,  -13 }   // '?'
 ,{   380,  10,  12,  11,    0,  -11 }   // '@'
 ,{   395,   8,  11,   9,    0,  -11 }   // 'A'
 ,{   406,   7,  11,   8,    0,  -11 }   // 'B'
 ,{   416,   8,  11,   9,    0,  -11 }   // 'C'
 ,{   427,   7,  11,   8,    0,  -11 }   // 'D'
 ,{   437,   8,  11,   8,    0,  -11 }   // 'E'
 ,{   448,   8,  11,   9,    0,  -11 }   // 'F'
 ,{   459,   8,  11,   9,    0,  -11 }   // 'G'
 ,{   470,   8,  11,   9,    0,  -11 }   // 'H'
 ,{   481,   6,  11,   7,    0,  -11 }   // 'I'
 ,{   490,   9,  11,  10,    0,  -11 }   // 'J'
 ,{   503,   7,  11,   8,    0,  -11 }   // 'K'
 ,{   513,   8,  11,   9,    0,  -11 }   // 'L'
 ,{   524,   8,  11,   9,    0,  -11 }   // 'M'
 ,{   535,   8,  11,   9,    0,  -11 }   // 'N'
 ,{   546,   7,  11,   8,    0,  -11 }   // 'O'
 ,{   556,   7,  11,   8,    0,  -11 }   // 'P'
 ,{   566,   8,  11,   9,    0,  -11 }   // 'Q'
 ,{   577,   7,  11,   8,    0,  -11 }   // 'R'
 ,{   587,   7,  11,   8,    0,  -11 }   // 'S'
 ,{   598,   8,  11,   9,    0,  -11 }   // 'T'
 ,{   609,   8,  11,   9,    0,  -11 }   // 'U'
 ,{   620,   8,  11,   9,    0,  -11 }   // 'V'
 ,{   631,   8,  11,   9,    0,  -11 }   // 'W'
 ,{   642,   7,  11,   8,    0,  -11 }   // 'X'
 ,{   652,   8,  11,   9,    0,  -11 }   // 'Y'
 ,{   663,   8,  11,   9,    0,  -11 }   // 'Z'
 ,{   674,   6,  15,   7,    0,  -13 }   // '['
 ,{   686,  10,  14,  11,    0,  -13 }   // '\'
 ,{   704,   6,  15,   7,    0,  -13 }   // ']'
 ,{   716,   8,   4,   9,    0,  -11 }   // '^'
 ,{   720,  12,   2,  13,    0,   -1 }   // '_'
 ,{   723,   4,   3,   6,    1,  -11 }   // '`'
 ,{   725,  10,  12,  11,    0,  -11 }   // 'a'
 ,{   740,  10,  14,  11,    0,  -13 }   // 'b'
 ,{   758,  10,  11,  11,    0,  -10 }   // 'c'
 ,{   773,  10,  14,  11,    0,  -13 }   // 'd'
 ,{   791,  10,  11,  11,    0,  -10 }   // 'e'
 ,{   806,   8,  14,   9,    0,  -13 }   // 'f'
 ,{   820,  10,  12,  11,    0,  -11 }   // 'g'
 ,{   835,  10,  14,  11,    0,  -13 }   // 'h'
 ,{   853,   6,  12,   7,    0,  -11 }   // 'i'
 ,{   862,   6,  14,   7,    0,  -13 }   // 'j'
 ,{   873,  10,  14,  11,    0,  -13 }   // 'k'
 ,{   891,   2,  14,   3,    0,  -13 }   // 'l'
 ,{   895,  10,  11,  11,    0,  -10 }   // 'm'
 ,{   910,  10,  11,  11,    0,  -10 }   // 'n'
 ,{   925,  10,  11,  11,    0,  -10 }   // 'o'
 ,{   940,  10,  12,  11,    0,  -11 }   // 'p'
 ,{   955,  10,  12,  11,    0,  -11 }   // 'q'
 ,{   970,  10,  11,  11,    0,  -10 }   // 'r'
 ,{   985,  10,  11,  11,    0,  -10 }   // 's'
 ,{  1000,   6,  14,   7,    0,  -13 }   // 't'
 ,{  1011,  10,  11,  11,    0,  -10 }   // 'u'
 ,{  1026,  10,  11,  11,    0,  -10 }   // 'v'
 ,{  1041,  10,  11,  11,    0,  -10 }   // 'w'
 ,{  1056,  10,  11,  11,    0,  -10 }   // 'x'
 ,{  1071,  10,  12,  11,    0,  -10 }   // 'y'
 ,{  1086,  10,  11,  11,    0,  -10 }   // 'z'
 ,{  1101,   6,  15,   7,    0,  -13 }   // '{'
 ,{  1113,   2,  15,   3,    0,  -13 }   // '|'
 ,{  1118,   6,  15,   7,    0,  -13 }   // '}'
 ,{  1130,   8,   4,   9,    0,   -7 }   // '~'
};

const GFXfont hour8pt7b PROGMEM = {
  (uint8_t  *)hour8pt7bBitmaps,    
  (GFXglyph *)hour8pt7bGlyphs, 0x20, 0x7e,     15 };

// Approx. 1481 bytes