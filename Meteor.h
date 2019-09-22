#pragma once

// TODO: OMG I NEED TO FIGURE OUT HOW TO MAKE THE SPARKS FALL WITH THE MAIN METEOR BODY!!!

#include "Animation.h"
class Meteor :
	public Animation
{
protected:
	const Animation_Name name = _Meteor;

public:
	Meteor(LED_Fixture* new_fixture, LED_Group* new_group);

	void erase_previous_frame();
	void calculate_frame();
};

