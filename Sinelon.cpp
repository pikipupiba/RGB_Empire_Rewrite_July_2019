#include "Sinelon.h"

Sinelon::Sinelon(LED_Arrangements* new_led_arrangements)
	:Animation(new_led_arrangements)
{
	START;

	vars.range_end = num_leds - 1;

	END;
}

// Use the run function to define what the animation must do every frame.
// This example is the default function in the Animation base class.

//void Sinelon::run()
//{
//	START;
//
//	erase_previous_frame();
//
//	update_vars();
//
//	calculate_frame();
//
//	for (auto& animation : animations) {
//		THING;
//		animation->run();
//	}
//
//	END;
//}



// Use erase_previous_frame to define how the animation resets itself after each frame.
// This example is the default function in the Animation base class.

//void Sinelon::erase_previous_frame()
//{
//	START;
//
//	for (auto& pixel : *led_set)
//	{
//		pixel = CRGB::Black;
//	}
//
//	END;
//}



// Update the animation variables to calculate the next frame.
// This example is the (incomplete) default function in the Animation base class.

void Sinelon::update_vars()
{
	START;

	vars.brightness += vars.brightness_speed;
	vars.brightness_speed += vars.brightness_acceleration;

	vars.position += vars.speed;
	vars.speed += vars.acceleration;

	//P(vars.position);
	//P(vars.speed);
	//P(vars.position + vars.speed);

	vars.hue += vars.hue_speed;
	vars.hue_speed += vars.hue_acceleration;

	vars.size += vars.size_speed;
	vars.size_speed += vars.size_acceleration;

	//Animation::update_vars();

	float new_start = vars.position - vars.size / 2;
	float new_end = vars.position + vars.size / 2;
	
	if (new_start < vars.range_start)
	{
		if (vars.speed < 0)
		{
			vars.speed = -vars.speed;
		}
	}
	else if (new_end > vars.range_end - 1)
	{
		if (vars.speed > 0)
		{
			vars.speed = -vars.speed;
		}
	}

	vars.start = new_start;
	vars.end = new_end;

	END;
}


// Use calculate_frame to assign values the animation's pixel array
// by using the variables in the struct Animation_Variables vars.
// This example is from the Glitter class.

void Sinelon::calculate_frame()
{
	START;

	leds[(int)vars.start] += CHSV(vars.hue, 255, vars.brightness * (1 - (vars.start - (long)vars.start)));

	if (vars.start < vars.end) {
		for (int i = vars.start + 1; i < vars.end - 1; i++) {
			leds[i] = CHSV(vars.hue, 255, vars.brightness);
		}
	}
	else {
		for (int i = vars.start + 1; i <= vars.range_end; i++) {
			leds[i] += CHSV(vars.hue, 255, vars.brightness);
		}
		for (int i = vars.end - 1; i >= (int)vars.range_start && vars.end > 1; i--) {
			leds[i] += CHSV(vars.hue, 255, vars.brightness);
		}
	}

	leds[(int)vars.end] += CHSV(vars.hue, 255, vars.brightness * (vars.end - (long)vars.end));

	//if (reflect) {
	//	leds[NUM_LEDS - (int)vars.start - 1] += CHSV(hue, 255, brightness * (1 - (vars.start - (long)vars.start)));

	//	for (int i = vars.start + 1; i < vars.end - 1; i++) {
	//		leds[NUM_LEDS - i - 1] += CHSV(hue, 255, brightness);
	//	}
	//	leds[NUM_LEDS - (int)vars.end - 1] += CHSV(hue, 255, brightness * (vars.end - (long)vars.end));
	//}

	END;
}