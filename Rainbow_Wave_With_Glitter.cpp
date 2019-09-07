#include "Rainbow_Wave_With_Glitter.h"

Rainbow_Wave_With_Glitter::Rainbow_Wave_With_Glitter(LED_Arrangements* new_led_arrangements)
{
	START;

	led_arrangements = new_led_arrangements;

	num_leds = led_arrangements->get_size();

	Serial.println("num leds = " + String(num_leds));

	leds = new CRGB[num_leds];

	THING;
	led_set = CRGBSet(leds, num_leds);
	THING;
	/*for (auto& pixel : led_set)
	{
		pixel.Black;
	}*/
	THING;
	animations.push_back(Animation::create(_Rainbow_Wave, new_led_arrangements));
	THING;
	animations.push_back(Animation::create(_Glitter, new_led_arrangements));

	END;
}