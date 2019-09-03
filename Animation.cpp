// 
// 
// 

#include "Animation.h"

// Update the animation variables to calculate the next frame.
void Animation::update_vars()
{
	vars.brightness += vars.brightness_speed;
	vars.brightness_speed += vars.brightness_acceleration;

	vars.position += vars.speed;
	vars.speed += vars.acceleration;

	vars.hue += vars.hue_speed;
	vars.hue_speed += vars.hue_acceleration;

	vars.size += vars.size_speed;
	vars.size_speed += vars.size_acceleration;
}

Animation::Animation()
	:animation_ID(num_animations++)
{

}

Animation::Animation(std::vector<LED_Arrangement*> new_led_arrangements)
	:animation_ID(num_animations++)
{
	led_arrangements = new_led_arrangements;
}


Animation* Animation::create(Animation_Name new_animation_name, LED_Arrangements* new_led_arrangements)
{
	START;

	switch (new_animation_name)
	{
	case _Default:						return new Rainbow_Wave_With_Glitter(new_led_arrangements);
	case _Rainbow_Wave:					return new Rainbow_Wave(new_led_arrangements);
	case _Glitter:						return new Glitter(new_led_arrangements);
	case _Rainbow_Wave_With_Glitter:	return new Rainbow_Wave_With_Glitter(new_led_arrangements);
	//case _Random_Rainbow_Wave:			return new Random_Rainbow_Wave;
	default:							return new Rainbow_Wave(new_led_arrangements);
	}

	MEM;

	END;
}

Animation::~Animation()
{
}

void Animation::print_info()
{
	Serial.print("Animation #");
	Serial.print(animation_ID);
	Serial.println(" Information:");

	Serial.print("   Position = ");
	Serial.println(vars.position);

	Serial.print("   Hue = ");
	Serial.println(vars.hue);
}

void Animation::run()
{
	START;

	erase_previous_frame();

	update_vars();

	draw_next_frame();

	for (auto& animation : animations) {
		animation->run();
	}


	END;
}

void Animation::erase_previous_frame()
{
	END;

	for (auto& led_set : leds) {
		led_set->fill_solid(CRGB::Black);
	}

	END;
}