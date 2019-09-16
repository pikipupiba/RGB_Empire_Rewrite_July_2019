#pragma once
#include "Animation.h"
class Crazy_Time :
	public Animation
{
protected:
	const Animation_Name name = _Crazy_Time;

public:
	Crazy_Time(LED_Arrangements* new_led_arrangements);

	void calculate_frame();
};

