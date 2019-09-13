#pragma once

#include "Animation.h"

class Rainbow_Wave_With_Glitter :
	public Animation
{
protected:
	const Animation_Name name = _Rainbow_Wave_With_Glitter;

public:
	Rainbow_Wave_With_Glitter(LED_Arrangements* new_led_arrangements);
};

