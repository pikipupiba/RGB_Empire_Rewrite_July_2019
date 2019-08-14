// Pattern.h

// A Pattern is designed to run on an individual strip of LEDs meaning it will interact
// directly with the LED_Strip class.

// Arrays are used to give patterns all the variables they need to operate correctly
// and allow for future extensibility.

// Floats are used to allow super smooth transitions and antialiased output.

// This should be an interface class to allow individual patterns to be
// seperated out into children classes.

#ifndef _PATTERN_h
#define _PATTERN_h

#include "arduino.h"
#include "FastLED.h"
#include "Oscillator.h"
#include "My_Enums.h"
#include "LED_Strip.h"

class Pattern
{
 protected:

	 int pattern_ID;
	 LED_Strip* strip;

	 Animation_Parameters pattern_parameters[16];

	 Oscillator osc[16];

	 friend class Animation;

	 void update_parameters();

 public:
	Pattern(LED_Strip* new_strip);
	~Pattern();

	void print_info();

	void run();

};

typedef void(*Pattern_Function)(CRGBSet* leds, Animation_Parameters pattern_parameters[]);
typedef Pattern_Function Pattern_Function_List[];

extern Pattern_Function_List patterns;

#endif

