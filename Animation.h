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
#include "My_Enums.h"
#include "LED_Fixture.h"

constexpr int max_number_of_patterns = 8;
constexpr int max_number_of_parameters = 32;

class Animation
{
 protected:

	 int animation_ID;

	 LED_Fixture* fixture;

	 Pattern* pattern[max_number_of_patterns];

	 int num_patterns;

	 Animation_Parameters animation_parameters[max_number_of_parameters];

	 Oscillator osc[max_number_of_parameters];

	 friend class Pattern;

	 void update_vars();

 public:

	Animation(LED_Fixture* new_fixture);
	~Animation();

	void print_info();

	void run();

};

#endif

