// 
// 
// 

#include "Animation.h"

int Animation::num_animations;

// Update the animation variables to calculate the next frame.
// The default way exactly as you would expect.
// You can change this in the specific animation if you want.
// TODO currently incomplete
void Animation::update_vars()
{
	START;

	//vars.brightness += vars.brightness_speed;
	//vars.brightness_speed += vars.brightness_acceleration;

	//vars.position += vars.speed;
	//vars.speed += vars.acceleration;

	//vars.hue += vars.hue_speed;
	//vars.hue_speed += vars.hue_acceleration;

	//vars.size += vars.size_speed;
	//vars.size_speed += vars.size_acceleration;

	//vars.density += vars.density_speed;
	//vars.density_speed += vars.density_acceleration;

	//vars.fade += vars.fade_speed;
	//vars.fade_speed += vars.fade_acceleration;

	//vars.start = vars.position - vars.size / 2;
	//vars.end = vars.position + vars.size / 2;

	vars_new.brightness.update();
	vars_new.position.update();
	vars_new.hue.update();
	vars_new.size.update();
	vars_new.density.update();
	vars_new.fade.update();

	//if (vars.palette_cycle != 0)
	//{
	//	unsigned long now = millis();

	//	// abs() allows palette_cycle to be positive or negative0
	//	if (now - vars.palette_last_time > abs(vars.palette_cycle))
	//	{
	//		vars.palette_next_ID = next(vars.palette_current_ID, vars.palette_cycle, vars.palette_mask);
	//	}
	//}

	//nblendPaletteTowardPalette(vars.palette_current, vars.palette_next, vars.palette_cycle_speed);

	END;
}

void Animation::erase_previous_frame()
{
	START;

	for (auto& pixel : *led_set)
	{
		pixel = CRGB::Black;
	}

	END;
}

Animation::Animation(LED_Arrangements* new_led_arrangements)
	:animation_ID(num_animations++),
	led_arrangements(new_led_arrangements),
	num_leds(led_arrangements->get_size()),
	leds(new CRGB[num_leds]),
	led_set(new CRGBSet(leds, num_leds)),
	vars_new(Animation_Variables(0,num_leds - 1)),
	compressed_arrangement(led_arrangements->compress())
{
	START;

	Serial.println("what the heck = " + (String)led_set->len);

	fill_solid(leds, num_leds, CRGB::Black);

	MEM;
	END;
}


Animation* Animation::create(Animation_Name new_animation_name, LED_Arrangements* new_led_arrangements)
{
	START;

	END;

	switch (new_animation_name)
	{
	case _Default:
		return new Mr_Poopy_Worm(new_led_arrangements);
	case _Rainbow_Wave:
		return new Rainbow_Wave(new_led_arrangements);
	case _Glitter:
		return new Glitter(new_led_arrangements);
	case _Rainbow_Wave_With_Glitter:
		return new Rainbow_Wave_With_Glitter(new_led_arrangements);
	//case _Random_Rainbow_Wave:			return new Random_Rainbow_Wave;
	case _Sinelon:
		return new Sinelon(new_led_arrangements);
	case _Mr_Poopy_Worm:
		return new Mr_Poopy_Worm(new_led_arrangements);
	case _Artnet:
		return new Artnet(new_led_arrangements);
	default:
		return new Rainbow_Wave(new_led_arrangements);
	}
}

Animation::~Animation()
{
	START;

	//print_info();

	for (auto& animation : animations)
	{
		delete animation;
	}

	delete leds;

	delete led_set;

	MEM;
	END;
}

void Animation::print_info()
{
	START;

	Serial.print("Animation #");
	Serial.print(animation_ID);
	Serial.println(" Information:");

	Serial.print("   Position = ");
	//Serial.println(vars.position);

	Serial.print("   Hue = ");
	//Serial.println(vars.hue);

	END;
}

void Animation::print_arrangement_info()
{
	START;

	int i = 0;

	Serial.println("LED Arrangement Info for the Current Animation");

	for (auto& arrangement : led_arrangements->arrangements)
	{
		THING;

		for (auto& group : arrangement.led_groups)
		{
			Serial.println("      LED_Arrangement #" + (String)i++);
			for (auto& led_set : group.leds)
			{
				Serial.println("            -" + (String)led_set.len + " LEDs");
			}
		}
	}

	END;
}

void Animation::run()
{
	START;
	//MEM;

	erase_previous_frame();

	update_vars();

	calculate_frame();

	for (auto& animation : animations) {
		animation->run();
	}

	//MEM;
	END;
}

//void Animation::erase_previous_frame()
//{
//	START;
//
//	for (LED_Arrangement& arrangement : led_arrangements->arrangements)
//	{
//		for (LED_Group& group : arrangement.led_groups)
//		{
//			for (CRGBSet& led_set : group.leds)
//			{
//				led_set.fill_solid(CRGB::Black);
//			}
//		}
//	}
//
//	END;
//}

void Animation::calculate_frame()
{
	START;
	//MEM;

	//MEM;
	END;
}

int Animation::next(int cur, int dir, bool mask[])
{
	START;

	int mask_size = sizeof(mask);
	int next = cur;
	bool finished = false;

	int increment;

	if (dir > 0)
	{
		increment = 1;
	}
	else
	{
		increment = -1;
	}

	do
	{
		next = (next + increment);

		// Keep next within the bounds of the mask array.
		if (next > mask_size - 1)
		{
			next = 0;
		}
		else if (next < 0)
		{
			next = mask_size - 1;
		}

		if (mask[next])			// found the next available index
		{
			finished = true;
		}
		else if (next == cur)	// have gone all the way around the mask array
		{
			finished = true;
		}
	}
	while (!finished);

	END;

	return next;
}

CRGB* Animation::next_frame()
{
	START;

	for (auto& animation : animations)
	{
		CRGB* next_frame = animation->next_frame();
		//CRGBSet next_frame_set = CRGBSet(next_frame, animation->num_leds);

		for (int i = 0; i < animation->num_leds - 1; i++)
		{
			leds[i] +=  next_frame[i];
		}
	}

	END;

	return leds;

	
}
