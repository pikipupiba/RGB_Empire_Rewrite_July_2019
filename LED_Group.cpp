#include "LED_Group.h"


int LED_Group::get_size()
{
	START;

	int group_num_leds = 0;
	int cur_group_num = 0;
	int total_num_leds = 0;

	for (auto& led_set : leds)
	{
		if (abs(led_set.len) > group_num_leds)
		{
			total_num_leds = abs(led_set.len);
		}
	}

	//Serial.println("number of LEDs in group = " + (String)total_num_leds);

	END;

	return total_num_leds;
}

void LED_Group::add_to_group(LED_Group new_group)
{
	for (auto& led_set : new_group.leds)
	{
		leds.push_back(led_set);
	}
}

void LED_Group::add_to_group(CRGBSet new_led_set)
{
	leds.push_back(new_led_set);
}