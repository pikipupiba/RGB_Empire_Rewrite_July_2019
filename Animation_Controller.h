#pragma once

#include "arduino.h"
#include <vector>
#include <typeinfo>
#include "FastLED.h"
#include "Oscillator.h"
#include "My_Enums.h"
#include "LED_Fixture.h"
#include "Animation.h"

// Factory method gets rid of all of this.
// Would still like a dynamically built list of animations, however.
// for some insight on how to maybe do this, visit
// https://www.reddit.com/r/Cplusplus/comments/cxli09/help_creating_a_vector_of_derived_classes/

// Define Animation_Class as a pointer to an animation object.
//typedef Animation* Animation_Class;

// Combine the pointer with an identifiable name.
//typedef struct Animation_Class_And_Name
//{
//	Animation_Class actual_class;
//	String name;
//};

// Create array of those structs to select an animation object from.
//static std::vector<Animation_Class_And_Name> animation_list;


class Animation_Controller
{
private:
	LED_Fixture* fixture;

	Animation* current_animation;
	Animation* next_animation;

	Transition_Type transition_type;
	bool transitioning;
	int transition_total_time;
	long transition_start_time;

	bool* mask;
	int num_tDissolved;

	// All speeds will be scaled as though they were running at this rate.
	// For example, if an animation is currently running at 200 fps, all speeds are cut in half.
	// If an animation is running at 50 fps, all speeds are doubled.
	const int target_fps = 100;

public:
	Animation_Controller(LED_Fixture* new_fixture);

	static Animation_Controller create(LED_Fixture* new_fixture);

	void print_info();

	void run();

	void start_animation();

	void change_animation(Animation_Name new_animation_name);

	void erase_prev_frame();

	void show();

	void transition_Fade();

	void transition_Wipe();

	void transition_Dissolve();
};