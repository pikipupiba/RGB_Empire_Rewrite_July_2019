#pragma once
#include "My_Enums.h"
#include <vector>

std::vector<LED_Arrangement> create_linear_arrangements(CRGBSet* new_leds)
{

}

std::vector<LED_Arrangement> create_arrangements(Strip_Parameters new_strip_parameters)
{
	switch (new_strip_parameters.shape)
	{
	case Linear:
		temp_group.display_mode = Default;
		temp_thing.leds = leds;
		temp_thing.group_number = 0;
		temp_group.led_things.push_back(temp_thing);

		led_groups.push_back(temp_group);

		temp_group.led_things.clear();

		temp_group.display_mode = Middle_Out;
		temp_thing.group_number = 0;
		temp_thing.leds = &leds[leds->size() / 2, 0];
		temp_group.led_things.push_back(temp_thing);

		temp_thing.leds = &leds[leds->size() / 2, leds->size()];
		temp_group.led_things.push_back(temp_thing);

		led_groups.push_back(temp_group);
		break;

	case Folded:
		for (int i = 0; i < width_in_leds; i++)
		{
			temp_group.leds = &leds[length_in_leds * i, length_in_leds];

			if (i % 2)
			{
				temp_group.leds->reversed = true;
			}

			led_groups.push_back(temp_group);
		}
		break;

	case Panel:

		temp_group.leds = &leds[0, length_in_leds];
		temp_group.group = 1;
		led_groups.push_back(temp_group);

		temp_group.leds = &leds[length_in_leds, width_in_leds];
		temp_group.group = 0;
		led_groups.push_back(temp_group);

		temp_group.leds = &leds[length_in_leds + width_in_leds, length_in_leds];
		temp_group.leds->reversed = true;
		temp_group.group = 1;
		led_groups.push_back(temp_group);

		temp_group.leds = &leds[2 * length_in_leds + width_in_leds, width_in_leds];
		temp_group.leds->reversed = true;
		temp_group.group = 3;
		led_groups.push_back(temp_group);

		temp_group.leds = &leds[current_position, width_in_leds];
		temp_group.leds->reversed = true;
		temp_group.group = 3;
		led_groups.push_back(temp_group);

		break;

	default:
		temp_group.leds = leds;

		led_groups.push_back(temp_group);
	}
};