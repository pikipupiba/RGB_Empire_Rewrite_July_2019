#pragma once

#include "arduino.h"
#include <vector>
#include <typeinfo>
#include <FastLED.h>
#include "Oscillator.h"
#include "My_Enums.h"
#include "LED_Fixture.h"
#include "Animation.h"

// Factory method gets rid of all of this.

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

	Animation* current_animation;
	Animation* next_animation;

	bool transitioning;
	float transition_total_time;
	float transition_current_time;
	float transition_speed;

public:
	Animation_Controller();

	static Animation_Controller* create();
	void print_info();

	void run();

	void change_animation(Animation_Name new_animation_name);

	void change_animation_variables(Animation_Variables new_vars);
};