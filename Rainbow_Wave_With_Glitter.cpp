#include "Rainbow_Wave_With_Glitter.h"

Rainbow_Wave_With_Glitter::Rainbow_Wave_With_Glitter(LED_Arrangements* new_led_arrangements)
{
	START;

	led_arrangements = new_led_arrangements;

	print_arrangement_info();

	animations.push_back(Animation::create(_Rainbow_Wave, new_led_arrangements));
	animations.push_back(Animation::create(_Glitter, new_led_arrangements));

	END;
}