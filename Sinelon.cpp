#include "Sinelon.h"

Sinelon::Sinelon(LED_Arrangements* new_led_arrangements)
	:Animation(new_led_arrangements)
{
	START;

	vars_new.range_end = num_leds - 1;

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

	Animation::update_vars();
	
	float new_start = vars_new.position.value.value - vars_new.size.value.value / 2;
	float new_end = vars_new.position.value.value + vars_new.size.value.value / 2;
	
	if (new_start < vars_new.range_start)
	{
		vars_new.position.speed.make_positive();
	}
	if (new_end > vars_new.range_end - 1)
	{
		vars_new.position.speed.make_negative();
	}

	if (new_start < 0)
	{
		new_start = 0;
	}
	if (new_end > num_leds - 1)
	{
		new_end = num_leds - 1;
	}

	start = new_start;
	end = new_end;

	END;
}


// Use calculate_frame to assign values the animation's pixel array
// by using the variables in the struct Animation_Variables vars.
// This example is from the Glitter class.

void Sinelon::calculate_frame()
{
	START;
	//MEM;
	//leds[(int)vars.start] += CHSV(vars.hue, 255, vars.brightness * (1 - (vars.start - (long)vars.start)));

	//if (vars.start < vars.end) {
	//	for (int i = vars.start + 1; i < vars.end - 1; i++) {
	//		leds[i] = CHSV(vars.hue, 255, vars.brightness);
	//	}
	//}
	//else {
	//	for (int i = vars.start + 1; i <= vars.range_end; i++) {
	//		leds[i] += CHSV(vars.hue, 255, vars.brightness);
	//	}
	//	for (int i = vars.end - 1; i >= (int)vars.range_start && vars.end > 1; i--) {
	//		leds[i] += CHSV(vars.hue, 255, vars.brightness);
	//	}
	//}

	//leds[(int)vars.end] += CHSV(vars.hue, 255, vars.brightness * (vars.end - (long)vars.end));

	//P(animation_ID);
	//P(vars_new.position.name);

	//P(vars_new.position.value.value);
	//P(vars_new.position.speed.value);
	//P(vars_new.hue.value.value);
	//P(vars_new.size.value.value);
	//P(start);
	//P(end);


	leds[(int)start] += CHSV(vars_new.hue.value.value, 255, vars_new.brightness.value.value * (1 - (start - (int)start)));

	if (start < end) {
		for (int i = start + 1; i < end - 1; i++) {
			leds[i] = CHSV(vars_new.hue.value.value, 255, vars_new.brightness.value.value);
		}
	}
	else {
		for (int i = start; i <= vars_new.range_end; i++) {
			leds[i] += CHSV(vars_new.hue.value.value, 255, vars_new.brightness.value.value);
		}
		for (int i = end; i >= (int)vars_new.range_start && end > 1; i--) {
			leds[i] += CHSV(vars_new.hue.value.value, 255, vars_new.brightness.value.value);
		}
	}

	leds[(int)end] += CHSV(vars_new.hue.value.value, 255, vars_new.brightness.value.value * (end - (int)end));

	//MEM;
	END;
}