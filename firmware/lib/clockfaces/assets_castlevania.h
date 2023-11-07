#include <Arduino.h>
#include <gfxfont.h>

#if defined(__AVR__)
    #include <avr/pgmspace.h>
#elif defined(__PIC32MX__)
    #define PROGMEM
#elif defined(__arm__)
    #define PROGMEM
#endif

// 'castlevania_clock', 64x64px
const uint16_t _CLOCK_TOWER [] PROGMEM = {
	0x7529, 0x968b, 0x3305, 0x1182, 0x1182, 0x1182, 0x3305, 0x968b, 0x7529, 0x3305, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01e5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01a5, 0x01a5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x7529, 0x968b, 0x3305, 0x1182, 0x1182, 0x1182, 0x3305, 0x968b, 0x7529, 
	0x00c1, 0x1182, 0x1182, 0x3305, 0x3305, 0x3305, 0x1182, 0x1182, 0x00c1, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x00c1, 0x1182, 0x1182, 0x3305, 0x3305, 0x3305, 0x1182, 0x1182, 0x00c1, 
	0x3305, 0x7529, 0x3305, 0x1182, 0x1182, 0x1182, 0x3305, 0x7529, 0x3305, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x7529, 0x3305, 0x1182, 0x1182, 0x1182, 0x3305, 0x7529, 0x3305, 
	0x7529, 0x1182, 0x7529, 0x968b, 0x968b, 0x968b, 0x7529, 0x1182, 0x7529, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x7529, 0x1182, 0x7529, 0x968b, 0x968b, 0x968b, 0x7529, 0x1182, 0x7529, 
	0x3305, 0x7529, 0x3305, 0x0982, 0x0982, 0x0982, 0x3305, 0x7529, 0x3305, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x7529, 0x3305, 0x0982, 0x0982, 0x0982, 0x3305, 0x7529, 0x3305, 
	0x0000, 0x00c1, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x00c1, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x00c1, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x00c1, 0x0000, 
	0x0000, 0x7529, 0x7529, 0x968b, 0x968b, 0x968b, 0x7529, 0x7529, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x7529, 0x7529, 0x968b, 0x968b, 0x968b, 0x7529, 0x7529, 0x0000, 
	0x0000, 0x3305, 0x3305, 0x3305, 0x3305, 0x3305, 0x3305, 0x3305, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x64c8, 0x64c8, 0x64c8, 0x64c8, 
	0x64c8, 0x64c8, 0x64c8, 0x64c8, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x3305, 0x3305, 0x3305, 0x3305, 0x3305, 0x3305, 0x0000, 
	0x0000, 0x00c1, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x00c1, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x5c88, 0x4bc6, 0x3b05, 0x2a64, 0x19a3, 0x0942, 0x08e1, 
	0x08e1, 0x0942, 0x19a3, 0x2a64, 0x3b05, 0x4bc6, 0x5c88, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x00c1, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x00c1, 0x0000, 
	0x0000, 0x00c1, 0x3305, 0x0982, 0x3305, 0x0982, 0x3305, 0x00c1, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x5ca8, 0x4c06, 0x3305, 0x19a3, 0x0922, 0x0921, 0x0901, 0x08e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x08e1, 0x0901, 0x0921, 0x0922, 0x19a3, 0x3305, 0x4c06, 0x5ca8, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x00c1, 0x3305, 0x0982, 0x3305, 0x0982, 0x3305, 0x00c1, 0x0000, 
	0x0000, 0x00c1, 0x968b, 0x0982, 0x968b, 0x0982, 0x968b, 0x00c1, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x4c06, 0x32c4, 0x1182, 0x08e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x7529, 0x00e1, 0x7529, 
	0x00e1, 0x7529, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x00e1, 0x08e1, 0x1182, 0x32c4, 0x4c06, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x00c1, 0x968b, 0x0982, 0x968b, 0x0982, 0x968b, 0x00c1, 0x0000, 
	0x0000, 0x00c1, 0x7529, 0x0982, 0x7529, 0x0982, 0x7529, 0x00c1, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x5c47, 0x3b25, 0x19a2, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x968b, 0x00e1, 
	0x00e1, 0x968b, 0x00e1, 0x968b, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x19a2, 0x3b25, 0x5c47, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x00c1, 0x7529, 0x0982, 0x7529, 0x0982, 0x7529, 0x00c1, 0x0000, 
	0x0000, 0x00c1, 0x3305, 0x0982, 0x3305, 0x0982, 0x3305, 0x00c1, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x4c06, 0x2a64, 0x0922, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x7529, 0x00e1, 0x7529, 
	0x00e1, 0x7529, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x0922, 0x2a64, 0x4c06, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01a5, 0x01c5, 0x00c1, 0x3305, 0x0982, 0x3305, 0x0982, 0x3305, 0x00c1, 0x0000, 
	0x0000, 0x00c1, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x00c1, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x4bc6, 0x2203, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x2203, 0x4bc6, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x00c1, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x00c1, 0x0000, 
	0x0000, 0x00c1, 0x3305, 0x0982, 0x3305, 0x0982, 0x3305, 0x00c1, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x4bc6, 0x1a03, 0x00e1, 0x00e1, 0x7529, 0x00e1, 0x7529, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x1a03, 0x4bc6, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x00c1, 0x3305, 0x0982, 0x3305, 0x0982, 0x3305, 0x00c1, 0x0000, 
	0x0000, 0x3305, 0x968b, 0x7529, 0x968b, 0x7529, 0x968b, 0x3305, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x4c06, 
	0x2203, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x968b, 0x00e1, 0x00e1, 0x968b, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x968b, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x2203, 
	0x4c06, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x968b, 0x7529, 0x968b, 0x7529, 0x968b, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x968b, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x5c47, 0x2a64, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x7529, 0x00e1, 0x7529, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x2a64, 0x5c47, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x968b, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3b25, 0x0922, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x0922, 0x3b25, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x4c06, 0x19a2, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x19a2, 0x4c06, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x5ca8, 0x32c4, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x32c4, 0x5ca8, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x4c06, 0x1182, 0x00e1, 0x00e1, 
	0x7529, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x7529, 0x00e1, 0x7529, 
	0x00e1, 0x00e1, 0x1182, 0x4c06, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x01c5, 0x01a4, 0x3305, 0x08e1, 0x00e1, 0x00e1, 
	0x00e1, 0x968b, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x968b, 0x00e1, 0x968b, 
	0x00e1, 0x00e1, 0x08e1, 0x3305, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x01c5, 0x5c88, 0x19a3, 0x00e1, 0x00e1, 0x00e1, 
	0x7529, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x7529, 0x00e1, 0x7529, 
	0x00e1, 0x00e1, 0x00e1, 0x19a3, 0x5c88, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x01c5, 0x4bc6, 0x0922, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x0922, 0x4bc6, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x01c5, 0x3b05, 0x0921, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x0921, 0x3b05, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x64c8, 0x2a64, 0x0901, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x0901, 0x2a64, 0x64c8, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x64c8, 0x19a3, 0x08e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x08e1, 0x19a3, 0x64c8, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x64c8, 0x0942, 0x00e1, 0x00e1, 0x7529, 0x00e1, 
	0x7529, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x7529, 0x00e1, 
	0x7529, 0x00e1, 0x7529, 0x00e1, 0x0942, 0x64c8, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x64c8, 0x08e1, 0x00e1, 0x00e1, 0x968b, 0x00e1, 
	0x00e1, 0x968b, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x968b, 0x00e1, 
	0x968b, 0x00e1, 0x968b, 0x00e1, 0x08e1, 0x64c8, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x64c8, 0x08e1, 0x00e1, 0x00e1, 0x7529, 0x00e1, 
	0x7529, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x7529, 0x00e1, 
	0x7529, 0x00e1, 0x7529, 0x00e1, 0x08e1, 0x64c8, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x64c8, 0x0942, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x0942, 0x64c8, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x64c8, 0x19a3, 0x08e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x08e1, 0x19a3, 0x64c8, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x64c8, 0x2a64, 0x0901, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x0901, 0x2a64, 0x64c8, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x0143, 0x3b05, 0x0921, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x0921, 0x3b05, 0x0143, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x0143, 0x0143, 0x4bc6, 0x0922, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x0922, 0x4bc6, 0x0143, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x0143, 0x0143, 0x64e8, 0x19a3, 0x00e1, 0x00e1, 0x7529, 
	0x00e1, 0x7529, 0x00e1, 0x7529, 0x00e1, 0x7529, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x7529, 0x00e1, 0x7529, 0x00e1, 
	0x7529, 0x00e1, 0x00e1, 0x19a3, 0x5c88, 0x0143, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x00e1, 0x00e1, 0x00e1, 0x3305, 0x08e1, 0x00e1, 0x968b, 
	0x00e1, 0x968b, 0x00e1, 0x968b, 0x00e1, 0x968b, 0x00e1, 0x968b, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x968b, 0x00e1, 0x968b, 0x00e1, 
	0x968b, 0x00e1, 0x08e1, 0x3305, 0x0143, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x00e1, 0x0860, 0x00e1, 0x00e1, 0x4c06, 0x1182, 0x00e1, 0x00e1, 
	0x7529, 0x00e1, 0x00e1, 0x7529, 0x00e1, 0x7529, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x7529, 
	0x00e1, 0x00e1, 0x1182, 0x4c06, 0x0143, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x0860, 0x00e1, 0x00e1, 0x4c07, 0x32c4, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x32c4, 0x5ca8, 0x0143, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0860, 0x0143, 0x01c5, 0x01c5, 0x00e1, 0x4c06, 0x19a2, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x19a2, 0x4c06, 0x0143, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0800, 0x0860, 0x0860, 0x00e1, 0x00e1, 0x00e1, 0x3b25, 0x0922, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x0922, 0x3b25, 0x00e1, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0800, 0x0800, 0x00e1, 0x00e1, 0x00e1, 0x0860, 0x5c47, 0x2a64, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x2a64, 0x5c47, 0x0143, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0800, 0x00e1, 0x0143, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x43a6, 
	0x2203, 0x00e1, 0x00e1, 0x00e1, 0x7529, 0x00e1, 0x7529, 0x00e1, 0x7529, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x7529, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x2203, 
	0x4c06, 0x0143, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0800, 0x0860, 0x00e1, 0x0143, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x4bc6, 0x1a03, 0x00e1, 0x00e1, 0x968b, 0x00e1, 0x968b, 0x00e1, 0x968b, 0x00e1, 0x968b, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x968b, 0x00e1, 0x968b, 0x00e1, 0x00e1, 0x00e1, 0x1a03, 0x4bc6, 
	0x0143, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0800, 0x0860, 0x0143, 0x0143, 0x00e1, 0x00e1, 0x0143, 0x00e1, 
	0x00e1, 0x4bc6, 0x2203, 0x00e1, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x7529, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x00e1, 0x2203, 0x4bc6, 0x0143, 
	0x01c5, 0x0143, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0800, 0x0800, 0x00e1, 0x00e1, 0x0860, 0x0143, 0x0143, 0x0143, 
	0x0860, 0x0143, 0x32c4, 0x2a64, 0x0922, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x7529, 0x00e1, 
	0x7529, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x0922, 0x2a64, 0x4c06, 0x0143, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0800, 0x0860, 0x0860, 0x00e1, 0x0143, 0x00e1, 0x00e1, 0x0860, 
	0x01c5, 0x0143, 0x00e1, 0x5447, 0x3b25, 0x19a2, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x968b, 0x00e1, 
	0x968b, 0x00e1, 0x968b, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x19a2, 0x3b25, 0x5c47, 0x0143, 0x0143, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0800, 0x00e1, 0x00e1, 0x00e1, 0x0143, 0x00e1, 0x00e1, 0x01c5, 
	0x0143, 0x01c5, 0x01c5, 0x0143, 0x00e1, 0x4c06, 0x32c4, 0x1182, 0x08e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x7529, 
	0x00e1, 0x00e1, 0x7529, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x08e1, 0x1182, 0x32c4, 0x4c06, 0x00e1, 0x0143, 0x0143, 0x01c5, 0x0143, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0860, 0x00e1, 0x00e1, 0x00e1, 0x0860, 0x00e1, 0x00e1, 0x00e1, 
	0x01c5, 0x0143, 0x0143, 0x0143, 0x00e1, 0x00e1, 0x5ca8, 0x4c06, 0x3305, 0x19a3, 0x0922, 0x0921, 0x0901, 0x08e1, 0x00e1, 0x00e1, 
	0x00e1, 0x00e1, 0x08e1, 0x0901, 0x0921, 0x0922, 0x19a3, 0x3305, 0x4c06, 0x5ca8, 0x00e1, 0x0143, 0x01c5, 0x0143, 0x0143, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0800, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x01c5, 0x0143, 0x01c5, 0x0143, 0x00e1, 0x00e1, 0x0143, 0x0143, 0x5c88, 0x4bc6, 0x3b05, 0x2a64, 0x19a3, 0x0942, 0x08e1, 
	0x08e1, 0x0942, 0x19a3, 0x2a64, 0x3b05, 0x4bc6, 0x5c88, 0x0143, 0x0143, 0x01c5, 0x0143, 0x01c5, 0x0143, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0800, 0x0860, 0x00e1, 0x00e1, 0x0860, 0x00e1, 0x00e1, 0x00e1, 
	0x00e1, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x0143, 0x00e1, 0x00e1, 0x0143, 0x0143, 0x0143, 0x64c8, 0x64c8, 0x64c8, 0x64c8, 
	0x64c8, 0x64c8, 0x64c8, 0x64c8, 0x00e1, 0x00e1, 0x0143, 0x0143, 0x01c5, 0x0143, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01a4, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x01c5, 0x01c5, 0x01c5, 0x00e1, 0x00e1, 0x00e1, 0x00e1, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x0143, 0x00e1, 0x00e1, 0x00e1, 0x01c5, 0x0143, 0x00e1, 0x0143, 0x0143, 
	0x0143, 0x0143, 0x0143, 0x0143, 0x0143, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x00e1, 0x01c5, 0x01c5, 0x00e1, 0x0860, 0x01c5, 0x0143, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x0143, 0x0143, 0x00e1, 0x0143, 0x0143, 0x0143, 
	0x0143, 0x01c5, 0x0143, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x00e1, 0x00e1, 0x01c5, 0x0143, 0x0143, 0x00e1, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x0143, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x0982, 0x7529, 0x7529, 0x7529, 0x0982, 0x3305, 0x0000, 
	0x0000, 0x00c1, 0x00c1, 0x0982, 0x0982, 0x0982, 0x00c1, 0x00c1, 0x0860, 0x00e1, 0x01c5, 0x01c5, 0x01c5, 0x0143, 0x0143, 0x0143, 
	0x01c5, 0x0143, 0x0143, 0x0143, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x00c1, 0x00c1, 0x0982, 0x0982, 0x0982, 0x00c1, 0x00c1, 0x0000, 
	0x0000, 0x7529, 0x7529, 0x968b, 0x968b, 0x968b, 0x7529, 0x7529, 0x00e1, 0x01c5, 0x00e1, 0x0143, 0x01c5, 0x01c5, 0x0143, 0x0860, 
	0x0143, 0x00e1, 0x0143, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x00e1, 0x00e1, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x7529, 0x7529, 0x968b, 0x968b, 0x968b, 0x7529, 0x7529, 0x0000, 
	0x0000, 0x0982, 0x3305, 0x3305, 0x3305, 0x3305, 0x3305, 0x0982, 0x00e1, 0x0143, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x0143, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x00e1, 0x0143, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x0982, 0x3305, 0x3305, 0x3305, 0x3305, 0x3305, 0x0982, 0x0000, 
	0x0000, 0x00e1, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x00c1, 0x00e1, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01a4, 0x01c5, 0x00c1, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x00c1, 0x0000, 
	0x0000, 0x3305, 0x7529, 0x8e0b, 0x8e0b, 0x8e0b, 0x7529, 0x3305, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x7529, 0x8e0b, 0x8e0b, 0x7529, 0x7529, 0x3305, 0x0000, 
	0x0000, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x01c5, 0x01a5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01a5, 0x01c5, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x0000, 
	0x0000, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x0982, 0x0000, 
	0x0000, 0x0982, 0x0982, 0x3305, 0x7529, 0x3305, 0x0982, 0x0982, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x0982, 0x0982, 0x3305, 0x7529, 0x3305, 0x0982, 0x0982, 0x0000, 
	0x0000, 0x0982, 0x3305, 0x7529, 0x8e0b, 0x7529, 0x3305, 0x0982, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x0982, 0x3305, 0x7529, 0x8e0b, 0x7529, 0x3305, 0x0982, 0x0000, 
	0x0000, 0x3305, 0x7529, 0x8e0b, 0x8e0b, 0x8e0b, 0x7529, 0x3305, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 
	0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x01c5, 0x3305, 0x7529, 0x8e0b, 0x8e0b, 0x8e0b, 0x7529, 0x3305, 0x0000
};
