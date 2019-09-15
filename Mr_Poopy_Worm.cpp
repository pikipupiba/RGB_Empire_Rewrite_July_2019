#include "Mr_Poopy_Worm.h"

Mr_Poopy_Worm::Mr_Poopy_Worm(LED_Arrangements* new_led_arrangements)
	:Animation(new_led_arrangements)
{
	START2;

	int num_worms = random8(3,20);

	// This is where you can combine animations.

	for (int i = 0; i < num_worms; i++)
	{
		animations.push_back(Animation::create(_Sinelon, new_led_arrangements));

		animations.back()->vars_new.range_start = i * num_leds / num_worms;
		animations.back()->vars_new.range_end = (i + 1) * num_leds / num_worms - 1;
	}

	animations.push_back(Animation::create(_Glitter, new_led_arrangements));

	END2;
}

// Use the run function to define what the animation must do every frame.
// This example is the default function in the Animation base class.

//void Mr_Poopy_Worm::run()
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

//void Mr_Poopy_Worm::erase_previous_frame()
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

//void Mr_Poopy_Worm::update_vars()
//{
//	START;
//
//	vars.brightness += vars.brightness_speed;
//	vars.brightness_speed += vars.brightness_acceleration;
//
//	vars.position += vars.speed;
//	vars.speed += vars.acceleration;
//
//	vars.hue += vars.hue_speed;
//	vars.hue_speed += vars.hue_acceleration;
//
//	vars.size += vars.size_speed;
//	vars.size_speed += vars.size_acceleration;
//
//	END;
//}


// Use calculate_frame to assign values the animation's pixel array
// by using the variables in the struct Animation_Variables vars.
// This example is from the Glitter class.

//void Mr_Poopy_Worm::calculate_frame()
//{
//	START;
//
//	for (auto& pixel : *led_set)
//	{
//		if (random(1000) < vars.density)
//		{
//			pixel = CRGB::White;
//		}
//	}
//
//	END;
//}