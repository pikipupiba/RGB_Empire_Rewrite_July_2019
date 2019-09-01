#pragma once

#include "Animation.h"
#include "arduino.h"
#include <vector>
#include <typeinfo>
#include <FastLED.h>
#include "Oscillator.h"
#include "My_Enums.h"
#include "LED_Fixture.h"
#include "Animation_Controller.h"

class Rainbow_Wave_With_Glitter :
	public Animation
{
protected:
	const Animation_Name name = _Rainbow_Wave_With_Glitter;

public:
	Rainbow_Wave_With_Glitter();

	void draw_next_frame() {};
};

