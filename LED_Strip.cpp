// 
// 
// 

#include "LED_Strip.h"

void LED_Strip::print_info()
{
	Serial.print("Strip #");
	Serial.print(strip_index);
	Serial.println(" Information:");

	Serial.print("   ");
	Serial.print(num_leds);
	Serial.println(" LEDs");

	Serial.print("   ");
	Serial.print(leds_per_meter);
	Serial.println(" LEDs / meter");
}

LED_Strip::LED_Strip(int new_strip_index, CRGBSet* new_leds, Strip_Parameters new_strip_parameters)
	:strip_index(new_strip_index),
	leds(new_leds),
	num_leds(new_strip_parameters.num_leds),
	leds_per_meter(new_strip_parameters.leds_per_meter),
	shape(new_strip_parameters.shape),
	length_in_leds(new_strip_parameters.length_in_leds),
	width_in_leds(new_strip_parameters.width_in_leds)
{
	LED_Thing temp_thing;
	LED_Group temp_group;
	temp_group.display_mode = Default;

	int current_position = 0;

	switch (shape)
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
}

LED_Strip::~LED_Strip()
{
	
}
