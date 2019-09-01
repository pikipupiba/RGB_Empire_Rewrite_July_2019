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


class Glitter :
	public Animation
{
protected:
	const Animation_Name name = _Glitter;

public:
	Glitter();

	void draw_next_frame();
};

