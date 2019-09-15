#include "Glitter.h"

Glitter::Glitter(LED_Arrangements* new_led_arrangements)
	:Animation(new_led_arrangements)
{
	START;

	END;
}

void Glitter::erase_previous_frame()
{
	START;

	led_set->fadeToBlackBy(vars_new.fade.value.value * speed_scale_factor);

	END;
}

void Glitter::calculate_frame()
{
	START;

	for (auto& pixel : *led_set)
	{
		if (random(1000) < vars_new.density.value.value * speed_scale_factor)
		{
			pixel = CRGB::White;
		}
	}

	END;
}


