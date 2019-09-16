#pragma once
#include "Animation.h"
class Solid_Color :
	public Animation
{

protected:
	const Animation_Name name = _Solid_Color;

public:
	Solid_Color(LED_Arrangements* new_led_arrangements);


	void calculate_frame();
};

