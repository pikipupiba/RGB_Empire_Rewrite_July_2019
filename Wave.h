#pragma once
#include "Animation.h"
class Wave :
	public Animation
{
protected:
	const Animation_Name name = _Wave;

public:
	Wave(LED_Arrangements* new_led_arrangements);

	void erase_previous_frame();
	void calculate_frame();
};

