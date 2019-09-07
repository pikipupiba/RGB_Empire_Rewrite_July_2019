#include "Glitter.h"

Glitter::Glitter(LED_Arrangements* new_led_arrangements)
{
	START;

	led_arrangements = new_led_arrangements;

	num_leds = led_arrangements->get_size();

	Serial.println("num leds = " + String(num_leds));

	leds = new CRGB[num_leds];

	led_set = CRGBSet(leds, num_leds);

	END;
}

void Glitter::erase_previous_frame()
{
	START;

	END;
}

void Glitter::calculate_frame()
{
	START;

	for (auto& pixel : led_set)
	{
		pixel = CRGB::White;

	}

	END;
}


