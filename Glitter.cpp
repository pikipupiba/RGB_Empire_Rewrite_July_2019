#include "Glitter.h"

Glitter::Glitter(LED_Arrangements* new_led_arrangements)
{
	START;

	led_arrangements = new_led_arrangements;

	print_arrangement_info();

	END;
}

void Glitter::draw_next_frame()
{
	START;

	for (LED_Arrangement& arrangement : led_arrangements->arrangements)
	{
		for (LED_Group& group : arrangement.led_groups)
		{
			for (CRGBSet& led_set : group.leds)
			{
				for (CRGB& pixel : led_set) {
					if (rand() * 100 < vars.density)
					{
						pixel = CRGB::White;
					}
				}
			}
		}
	}

	END;
}


