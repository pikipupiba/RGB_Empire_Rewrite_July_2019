#include "LED_Arrangement.h"

LED_Arrangement::LED_Arrangement(Strip_Display_Mode new_strip_display_mode)
	:strip_display_mode(new_strip_display_mode),
	num_groups(0),
	size(0)
{
	START;

	END;
}

void LED_Arrangement::add(LED_Group* new_led_group)
{
	START;

	if (new_led_group->group_number < num_groups)
	{

		led_groups[new_led_group->group_number]->add_to_group(new_led_group);
	}
	else
	{

		while (num_groups < new_led_group->group_number)
		{	
			led_groups.push_back(new LED_Group(num_groups++));
		}

		led_groups.push_back(new_led_group);

		num_groups++;
	}

	recalculate_size();

	END;
}

void LED_Arrangement::add(LED_Arrangement* new_led_arrangement)
{
	START;

	for (auto& new_led_group : new_led_arrangement->led_groups)
	{
		this->add(new_led_group);
	}

	END;
}

void LED_Arrangement::extend(LED_Arrangement* new_led_arrangement)
{
	START;

	for (auto& new_led_group : new_led_arrangement->led_groups)
	{
		this->add(new_led_group->change_group_number(num_groups));

		num_groups++;
	}

	END;
}

int LED_Arrangement::recalculate_size()
{
	START;

	size = 0;

	for (auto& group : led_groups)
	{
		size += group->size;
	}

	END;

	return size;

}

void LED_Arrangement::print_info()
{
	Serial.println("      Strip Display Mode # " + (String)strip_display_mode);

	for (auto& group : led_groups)
	{
		group->print_info();
	}
}
