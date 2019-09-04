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
#include <vector>
#include <typeinfo>
#include <FastLED.h>
#include "Oscillator.h"
#include "My_Enums.h"
#include "LED_Fixture.h"
#include "Bug.h"


// Factory method eliminates this.
//extern std::vector<Animation_Class_And_Name> animation_list;


class Animation
{
 protected:

	// Every animation should have a unique name.
	// "Base" is t he name of the interface.
	Animation_Name name = _Base;

	// Unique ID for each animation object. Base animation has ID = 0.
	const int animation_ID;

	// Moved this to the Animation_Controller class.
	// Vector that contains all children of this interface. Push onto this vector in the header of each child.
	//static std::vector<Animation> animation_list;

	// The current total number of animation objects.
	static int num_animations;

	// Vector to contain any other animation objects this one creates.
	std::vector<Animation*> animations;

	// A pointer to the fixture object that contains all necessary information about the LEDs.
	//LED_Fixture* fixture;

	LED_Arrangements* led_arrangements;

	// A struct that contains all the variables associated with the animation.
	Animation_Variables vars;

	//friend class Animation_Controller;

	void update_vars();

 public:

	Animation();
	
	Animation(LED_Arrangements* new_led_arrangements);

	static Animation* create(Animation_Name new_animation_name, LED_Arrangements* new_led_arrangements);

	virtual ~Animation();

	// Print out all relevant animation information.
	void print_info();

	void print_arrangement_info();

	// Do whatever is necessary to advance the animation to the next frame.
	void run();

	// Erase the previous frame to allow seemless overlapping of animations.
	void erase_previous_frame();


	// Generate the next frame of the animation.
	virtual void draw_next_frame() = 0;

};

//std::vector<boost::variant<first, second> > vec2;
//std::vector<std::unique_ptr<Animation>> vec3;

#include "All_Animations.h"

#endif

