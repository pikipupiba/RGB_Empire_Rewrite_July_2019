// Pattern.h

// A Pattern is designed to run on an individual strip of LEDs meaning it will interact
// directly with the LED_Strip class.

// Arrays are used to give patterns all the variables they need to operate correctly
// and allow for future extensibility.

// Floats are used to allow super smooth transitions and antialiased output.

// I think this should be an interface class to allow individual patterns to be
// seperated out into children classes.

#ifndef _PATTERN_h
#define _PATTERN_h

#include "arduino.h"
#include "Oscillator.h"


class Pattern
{
 protected:

	 int pattern_ID;

	 float brightness[16];

	 float position[16];
	 float speed[16];
	 float acceleration[16];

	 float hue[16];
	 float hue_speed[16];
	 float hue_acceleration[16];

	 float offset[16];
	 float size[16];
	 float size_offset[16];

	 Oscillator osc[16];

	 friend class Animation;

 public:
	Pattern();
	~Pattern();

	void run();
};

#endif

