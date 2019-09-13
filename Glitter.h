#pragma once

#include "Animation.h"

class Glitter :
	public Animation
{
protected:
	const Animation_Name name = _Glitter;

public:
	Glitter(LED_Arrangements* new_led_arrangements);

	void erase_previous_frame();

	void calculate_frame();

};

