#include "Glitter.h"

Glitter::Glitter(LED_Fixture* new_fixture, LED_Group* new_group)
	:Animation(new_fixture, new_group)
{
	START;

	vars(fade, a_value)->value = 100;

	END;
}

void Glitter::erase_previous_frame()
{
	START;

	led_set->fadeToBlackBy(vars(fade) * speed_scale_factor);

	END;
}

void Glitter::calculate_frame()
{
	START;

	for (auto& pixel : *led_set)
	{
		if (random(1000) < vars(density) * speed_scale_factor)
		{
			pixel = CRGB::White;
		}
	}

	END;
}


