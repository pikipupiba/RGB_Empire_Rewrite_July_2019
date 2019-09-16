#include "LED_Arrangements.h"

int LED_Arrangements::get_num_groups()
{
	return 0;
}

int LED_Arrangements::get_size()
{
	START;

	//int num_leds = 0;

	//for (auto& arrangement : arrangements)
	//{
	//	num_leds += arrangement.get_size();

	//}

	int group_num_leds = 0;
	int cur_group_num = 0;
	int total_num_leds = 0;

	for (auto& arrangement : arrangements)
	{
		for (auto& group : arrangement.led_groups)
		{
			if (group.group_number != cur_group_num)
			{
				total_num_leds += group_num_leds;

				group_num_leds = 0;

				cur_group_num = group.group_number;
			}


			for (auto& led_set : group.leds)
			{
				if (abs(led_set.len) > group_num_leds)
				{
					group_num_leds = abs(led_set.len);
				}
			}

		}
	}

	total_num_leds += group_num_leds;

	Serial.println("number of LEDs in arrangements = " + (String)total_num_leds);

	size = total_num_leds;

	END;

	return total_num_leds;
}

int LED_Arrangements::get_artnet_size()
{
	START;

	int num_leds = 0;

	for (auto& arrangement : arrangements)
	{
		for (auto& group : arrangement.led_groups)
		{
			for (auto& led_set : group.leds)
			{
				num_leds = abs(led_set.len);
			}
		}
	}

	END;

	return num_leds;
}

LED_Arrangement LED_Arrangements::compress()
{
	LED_Arrangement temp_arrangement;
	LED_Group temp_group;
	int max_group_number = -1;

	for (auto& arrangement : arrangements)
	{
		for (auto& group : arrangement.led_groups)
		{
			if (group.group_number > max_group_number)
			{
				temp_group.group_number = group.group_number;
				temp_arrangement.led_groups.push_back(temp_group);

				max_group_number = group.group_number;
			}

			temp_arrangement.led_groups[group.group_number].add_to_group(group);
		}
	}

	for (auto& group : temp_arrangement.led_groups)
	{
		group.size = group.get_size();
	}

	return temp_arrangement;
}
