#include <Arduino.h>
#include <gfxfont.h>

const uint8_t minute7pt7bBitmaps_timeInWords[] PROGMEM = {
  0x00, 0x49, 0x24, 0x85, 0x40, 0x55, 0xA0, 0x48, 0x93, 0xFA, 0x44, 0x9F, 
  0xD2, 0x24, 0x11, 0xE9, 0x64, 0x78, 0x51, 0x65, 0x95, 0xE1, 0x00, 0x60, 
  0x24, 0x89, 0x41, 0x90, 0x08, 0x02, 0x61, 0x24, 0x49, 0x21, 0x80, 0x71, 
  0x12, 0x22, 0x82, 0x0A, 0xA2, 0x4A, 0x62, 0x00, 0x58, 0x2A, 0x49, 0x24, 
  0x88, 0x80, 0x88, 0x92, 0x49, 0x2A, 0x00, 0x57, 0xDD, 0xF5, 0x00, 0x21, 
  0x3E, 0x42, 0x00, 0x60, 0xF0, 0x80, 0x08, 0x44, 0x22, 0x11, 0x08, 0x80, 
  0x00, 0x74, 0x63, 0x18, 0xC6, 0x31, 0x70, 0x00, 0x59, 0x24, 0x92, 0xE0, 
  0x74, 0x42, 0x11, 0x11, 0x10, 0xF8, 0x00, 0x74, 0x42, 0x60, 0x84, 0x31, 
  0x70, 0x00, 0x19, 0x99, 0x9F, 0x11, 0x10, 0x7C, 0x21, 0xE0, 0x84, 0x31, 
  0x70, 0x00, 0x74, 0x61, 0xE8, 0xC6, 0x31, 0x70, 0x00, 0xF0, 0x42, 0x11, 
  0x10, 0x84, 0x20, 0x00, 0x74, 0x63, 0x17, 0x46, 0x31, 0x70, 0x00, 0x74, 
  0x63, 0x17, 0x84, 0x31, 0x70, 0x00, 0x84, 0x00, 0x40, 0x18, 0x00, 0x1B, 
  0x20, 0xC1, 0x80, 0xF8, 0x01, 0xF0, 0xC1, 0x82, 0x6C, 0x00, 0x74, 0x62, 
  0x22, 0x10, 0x0A, 0x20, 0x00, 0x3C, 0x42, 0x99, 0xA5, 0xA5, 0xA5, 0x9A, 
  0x40, 0x3E, 0x31, 0x28, 0x61, 0xFE, 0x18, 0x61, 0x84, 0x00, 0x7A, 0x18, 
  0x61, 0xFA, 0x18, 0x61, 0x78, 0x00, 0x3C, 0x86, 0x04, 0x08, 0x10, 0x20, 
  0x21, 0x3C, 0x00, 0x79, 0x0A, 0x0C, 0x18, 0x30, 0x60, 0xC2, 0x78, 0x00, 
  0x7E, 0x08, 0x20, 0xFA, 0x08, 0x20, 0x7C, 0x00, 0x7E, 0x08, 0x20, 0xFA, 
  0x08, 0x20, 0x80, 0x00, 0x7D, 0x06, 0x04, 0x09, 0xD0, 0x60, 0xC1, 0x7C, 
  0x00, 0x86, 0x18, 0x7F, 0x86, 0x18, 0x61, 0x84, 0x00, 0xE9, 0x24, 0x92, 
  0xE0, 0x38, 0x84, 0x21, 0x0A, 0x52, 0x60, 0x00, 0x86, 0x18, 0xA4, 0xE2, 
  0x48, 0xA1, 0x84, 0x00, 0x84, 0x21, 0x08, 0x42, 0x10, 0x78, 0x00, 0x76, 
  0x89, 0x89, 0x89, 0x89, 0x81, 0x81, 0x81, 0x81, 0x43, 0x46, 0x8C, 0x99, 
  0x32, 0x62, 0xC5, 0x84, 0x00, 0x3C, 0x42, 0x81, 0x81, 0x81, 0x81, 0x81, 
  0x42, 0x3C, 0x7A, 0x18, 0x61, 0xFA, 0x08, 0x20, 0x80, 0x00, 0x3C, 0x21, 
  0x20, 0x50, 0x28, 0x14, 0x29, 0x08, 0x7B, 0x79, 0x0A, 0x14, 0x2F, 0x90, 
  0xA1, 0x42, 0x86, 0x00, 0x7D, 0x06, 0x03, 0xE0, 0x20, 0x60, 0xC1, 0x7C, 
  0x00, 0xFE, 0x20, 0x40, 0x81, 0x02, 0x04, 0x08, 0x10, 0x00, 0x83, 0x06, 
  0x0C, 0x18, 0x30, 0x60, 0xA2, 0x38, 0x00, 0x83, 0x06, 0x0C, 0x18, 0x28, 
  0x91, 0x14, 0x10, 0x00, 0x81, 0x81, 0x81, 0x81, 0x89, 0x89, 0x89, 0x89, 
  0x76, 0x86, 0x14, 0x8C, 0x4A, 0x18, 0x61, 0x84, 0x00, 0x83, 0x06, 0x0A, 
  0x22, 0x82, 0x04, 0x08, 0x10, 0x00, 0xF8, 0x10, 0x84, 0x21, 0x08, 0x20, 
  0x7C, 0x00, 0x72, 0x49, 0x24, 0x91, 0x80, 0x84, 0x10, 0x82, 0x10, 0x42, 
  0x08, 0x00, 0xC4, 0x92, 0x49, 0x27, 0x00, 0x25, 0x90, 0xFE, 0x00, 0x90, 
  0x72, 0x28, 0xA2, 0x89, 0xD0, 0x84, 0x3D, 0x18, 0xC6, 0x2E, 0x74, 0x61, 
  0x08, 0xB8, 0x00, 0x08, 0x5F, 0x18, 0xC6, 0x2E, 0x74, 0x7D, 0x08, 0xB8, 
  0x00, 0x18, 0x92, 0x1C, 0x20, 0x82, 0x08, 0xA1, 0x00, 0x74, 0x63, 0x17, 
  0x84, 0x31, 0x70, 0x00, 0x84, 0x21, 0xE8, 0xC6, 0x31, 0xBF, 0x20, 0x22, 
  0x22, 0x22, 0xA4, 0x84, 0x23, 0x2E, 0x4A, 0x31, 0x92, 0x49, 0x2A, 0x76, 
  0x89, 0x89, 0x89, 0x89, 0x89, 0x74, 0x63, 0x18, 0xC4, 0x00, 0x74, 0x63, 
  0x18, 0xB8, 0x00, 0x74, 0x63, 0x18, 0xFA, 0x10, 0x80, 0x00, 0x74, 0x63, 
  0x18, 0xBC, 0x21, 0x08, 0x00, 0xBC, 0x88, 0x88, 0x74, 0x1C, 0x18, 0xB8, 
  0x00, 0x44, 0xF4, 0x44, 0x43, 0x8C, 0x63, 0x19, 0xB4, 0x00, 0x8C, 0x62, 
  0xA5, 0x10, 0x00, 0x89, 0x89, 0x89, 0x89, 0x89, 0x76, 0x8C, 0x5D, 0x18, 
  0xC4, 0x00, 0x8C, 0x63, 0x17, 0x84, 0x31, 0x70, 0x00, 0xF0, 0x44, 0x44, 
  0x7C, 0x00, 0x29, 0x25, 0x12, 0x48, 0x80, 0xFF, 0xF8, 0x00, 0x89, 0x24, 
  0x52, 0x4A, 0x00, 0x55, 0x00
};

const GFXglyph minute7pt7bGlyphs_timeInWords[] PROGMEM = {
  {     0,   2,   1,   2,    0,    0 }   // ' '
 ,{     1,   3,   9,   4,    1,   -8 }   // '!'
 ,{     5,   4,   3,   5,    1,   -8 }   // '"'
 ,{     7,   7,   8,   8,    1,   -8 }   // '#'
 ,{    14,   6,  11,   7,    1,   -8 }   // '$'
 ,{    23,  10,   9,  11,    1,   -8 }   // '%'
 ,{    35,   7,   9,   7,    0,   -8 }   // '&'
 ,{    44,   2,   3,   3,    1,   -8 }   // '''
 ,{    45,   3,  11,   4,    1,   -8 }   // '('
 ,{    50,   3,  11,   4,    1,   -8 }   // ')'
 ,{    55,   5,   5,   6,    1,   -8 }   // '*'
 ,{    59,   5,   5,   6,    1,   -6 }   // '+'
 ,{    63,   2,   2,   3,    1,    0 }   // ','
 ,{    64,   4,   1,   5,    1,   -3 }   // '-'
 ,{    65,   1,   1,   2,    1,    0 }   // '.'
 ,{    66,   5,   9,   6,    1,   -8 }   // '/'
 ,{    73,   5,   9,   6,    1,   -8 }   // '0'
 ,{    80,   3,   9,   4,    1,   -8 }   // '1'
 ,{    84,   5,   9,   6,    1,   -8 }   // '2'
 ,{    91,   5,   9,   6,    1,   -8 }   // '3'
 ,{    98,   4,   9,   5,    1,   -8 }   // '4'
 ,{   103,   5,   9,   6,    1,   -8 }   // '5'
 ,{   110,   5,   9,   6,    1,   -8 }   // '6'
 ,{   117,   5,   9,   6,    1,   -8 }   // '7'
 ,{   124,   5,   9,   6,    1,   -8 }   // '8'
 ,{   131,   5,   9,   6,    1,   -8 }   // '9'
 ,{   138,   1,   6,   2,    1,   -5 }   // ':'
 ,{   140,   2,   7,   2,    0,   -5 }   // ';'
 ,{   143,   5,   5,   6,    1,   -6 }   // '<'
 ,{   147,   5,   4,   6,    1,   -6 }   // '='
 ,{   150,   5,   5,   6,    1,   -5 }   // '>'
 ,{   154,   5,   9,   6,    1,   -8 }   // '?'
 ,{   161,   8,   9,  10,    1,   -7 }   // '@'
 ,{   170,   6,   9,   8,    1,   -8 }   // 'A'
 ,{   178,   6,   9,   8,    1,   -8 }   // 'B'
 ,{   186,   7,   9,   9,    1,   -8 }   // 'C'
 ,{   195,   7,   9,   9,    1,   -8 }   // 'D'
 ,{   204,   6,   9,   8,    1,   -8 }   // 'E'
 ,{   212,   6,   9,   8,    1,   -8 }   // 'F'
 ,{   220,   7,   9,   9,    1,   -8 }   // 'G'
 ,{   229,   6,   9,   8,    1,   -8 }   // 'H'
 ,{   237,   3,   9,   5,    1,   -8 }   // 'I'
 ,{   241,   5,   9,   6,    1,   -8 }   // 'J'
 ,{   248,   6,   9,   8,    1,   -8 }   // 'K'
 ,{   256,   5,   9,   7,    1,   -8 }   // 'L'
 ,{   263,   8,   9,  10,    1,   -8 }   // 'M'
 ,{   272,   7,   9,   9,    1,   -8 }   // 'N'
 ,{   281,   8,   9,  10,    1,   -8 }   // 'O'
 ,{   290,   6,   9,   8,    1,   -8 }   // 'P'
 ,{   298,   9,   8,  10,    1,   -7 }   // 'Q'
 ,{   307,   7,   9,   8,    1,   -8 }   // 'R'
 ,{   316,   7,   9,   9,    1,   -8 }   // 'S'
 ,{   325,   7,   9,   9,    1,   -8 }   // 'T'
 ,{   334,   7,   9,   9,    1,   -8 }   // 'U'
 ,{   343,   7,   9,   9,    1,   -8 }   // 'V'
 ,{   352,   8,   9,  10,    1,   -8 }   // 'W'
 ,{   361,   6,   9,   8,    1,   -8 }   // 'X'
 ,{   369,   7,   9,   9,    1,   -8 }   // 'Y'
 ,{   378,   6,   9,   8,    1,   -8 }   // 'Z'
 ,{   386,   3,  11,   4,    1,   -8 }   // '['
 ,{   391,   5,   9,   6,    1,   -8 }   // '\'
 ,{   398,   3,  11,   4,    0,   -8 }   // ']'
 ,{   403,   4,   3,   5,    0,   -7 }   // '^'
 ,{   405,   7,   1,   8,    1,    1 }   // '_'
 ,{   407,   2,   2,   4,    1,   -7 }   // '`'
 ,{   408,   6,   6,   7,    1,   -5 }   // 'a'
 ,{   413,   5,   8,   7,    1,   -7 }   // 'b'
 ,{   418,   5,   6,   7,    1,   -5 }   // 'c'
 ,{   423,   5,   8,   7,    1,   -7 }   // 'd'
 ,{   428,   5,   6,   7,    1,   -5 }   // 'e'
 ,{   433,   6,  10,   6,    0,   -6 }   // 'f'
 ,{   441,   5,   9,   6,    1,   -5 }   // 'g'
 ,{   448,   5,   8,   7,    1,   -7 }   // 'h'
 ,{   453,   1,   8,   3,    1,   -7 }   // 'i'
 ,{   454,   4,  10,   4,    0,   -7 }   // 'j'
 ,{   459,   5,   8,   7,    1,   -7 }   // 'k'
 ,{   464,   3,   8,   4,    0,   -7 }   // 'l'
 ,{   467,   8,   6,  10,    1,   -5 }   // 'm'
 ,{   473,   5,   6,   7,    1,   -5 }   // 'n'
 ,{   478,   5,   6,   7,    1,   -5 }   // 'o'
 ,{   483,   5,   9,   7,    1,   -5 }   // 'p'
 ,{   490,   5,   9,   7,    1,   -5 }   // 'q'
 ,{   497,   4,   6,   6,    1,   -5 }   // 'r'
 ,{   500,   5,   6,   7,    1,   -5 }   // 's'
 ,{   505,   4,   8,   5,    0,   -7 }   // 't'
 ,{   509,   5,   6,   7,    1,   -5 }   // 'u'
 ,{   514,   5,   6,   7,    1,   -5 }   // 'v'
 ,{   519,   8,   6,  10,    1,   -5 }   // 'w'
 ,{   525,   5,   6,   7,    1,   -5 }   // 'x'
 ,{   530,   5,   9,   7,    1,   -5 }   // 'y'
 ,{   537,   5,   6,   7,    1,   -5 }   // 'z'
 ,{   542,   3,  11,   4,    0,   -8 }   // '{'
 ,{   547,   1,  13,   3,    1,   -8 }   // '|'
 ,{   550,   3,  11,   4,    0,   -8 }   // '}'
 ,{   555,   3,   3,   4,    1,   -7 }   // '~'
};

const GFXfont minute7pt7b_timeInWords PROGMEM = {
  (uint8_t  *)minute7pt7bBitmaps_timeInWords,   
  (GFXglyph *)minute7pt7bGlyphs_timeInWords, 0x20, 0x7e, 12};

// Approx. 1061 bytes