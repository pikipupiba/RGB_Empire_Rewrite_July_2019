#include "Mr_Poopy_Worm.h"

Mr_Poopy_Worm::Mr_Poopy_Worm(LED_Fixture* new_fixture, LED_Group* new_group)
	:Animation(new_fixture, new_group)
{
	START;

	int num_worms = random8(3,15);

	// This is where you can combine animations.

	for (int i = 0; i < num_worms; i++)
	{
		animations.push_back(Animation::create(_Sinelon, fixture, new_group));

		animations.back()->vars.range_start = i * num_leds / num_worms;
		animations.back()->vars.range_end = (i + 1) * num_leds / num_worms - 1;
	}

	animations.push_back(Animation::create(_Glitter, fixture, new_group));

	END;
}