#pragma once

// TODO: OMG I NEED TO FIGURE OUT HOW TO MAKE THE SPARKS FALL WITH THE MAIN METEOR BODY!!!

#include "Animation.h"
class Meteor :
	public Animation
{
protected:
	const Animation_Name name = _Meteor;

public:
	Meteor(LED_Arrangements* new_led_arrangements);

	void erase_previous_frame();
	void calculate_frame();
};

