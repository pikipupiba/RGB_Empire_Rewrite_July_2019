#include "My_Enums.h"

int LED_Arrangement::get_size()
{
	START;

	int num_leds = 0;

	for (auto& group : led_groups)
	{
		num_leds += abs(group.leds[0].len);

	}

	//Serial.println("number of LEDs in arrangement = " + (String)num_leds);

	END;

	return num_leds;
}

int LED_Arrangements::get_size()
{
	START;

	int num_leds = 0;

	for (auto& arrangement : arrangements)
	{
		num_leds += arrangement.get_size();

	}

	END;

	return num_leds;
}