// Animation.h

// An Animation is designed to coordinate patterns on multiple strips of LEDs
// meaning it will interact directly with the LED_Fixture class.

// Arrays are used to give animations all the variables they need to operate
// correctly and allow for future extensibility.

// Floats are used to allow super smooth transitions and antialiased output.

// I think this should be an interface class to allow individual animations
// to be seperated out into children classes.

#ifndef _ANIMATION_h
#define _ANIMATION_h

#include "arduino.h"
#include "Pattern.h"
#include "Oscillator.h"

class Animation
{
 protected:

	 int animation_ID;

	 float brightness[32];

	 float position[32];
	 float speed[32];
	 float acceleration[32];

	 float hue[32];
	 float hue_speed[32];
	 float hue_acceleration[32];

	 float offset[32];
	 float size[32];
	 float size_offset[32];

	 Oscillator osc[32];


	 friend class Pattern;

	 void update_vars();

 public:

	Animation();
	~Animation();

	void run();

};

#endif

