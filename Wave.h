#pragma once
#include "Animation.h"
class Wave :
	public Animation
{
protected:
	const Animation_Name name = _Wave;

public:
	Wave(LED_Fixture* new_fixture, LED_Group* new_group);

	void erase_previous_frame();
	void calculate_frame();
};

