#include "LED_Group.h"

LED_Group::LED_Group(int new_group_number)
	:group_number(new_group_number),
	size(0)
{

}


void LED_Group::add_to_group(LED_Group* new_group)
{
	for (auto& led_set : new_group->leds)
	{
		leds.push_back(led_set);

		if (abs(led_set->len) > size)
		{
			size = abs(led_set->len);
		}
	}
}

void LED_Group::add_to_group(CRGBSet* new_led_set)
{
	leds.push_back(new_led_set);
	
	if (abs(new_led_set->len) > size)
	{
		size = abs(new_led_set->len);
	}
}

int LED_Group::recalculate_size()
{
	START;

	int temp_size = 0;

	size = 0;
	total_size = 0;

	for (auto& led_set : leds)
	{
		temp_size = abs(led_set->len);

		total_size += temp_size;

		if (temp_size > size)
		{
			size = temp_size;
		}
	}

	END;

	return size;
}

int LED_Group::get_size()
{
	return size;
}

void LED_Group::print_info()
{
	Serial.println("            Group # " + (String)group_number);

	int i = 0;

	for (auto& led_set : leds)
	{
		Serial.println("                  CRGBSet # " + (String)i++ + " contains " + (String)abs(led_set->len) + " leds");
	}
}

LED_Group* LED_Group::change_group_number(int new_group_number)
{
	group_number = new_group_number;

	return this;
}
