#include "My_Enums.h"

int LED_Arrangement::get_num_groups()
{
	START;

	int cur_group_num = -1;
	int total_num_groups = 0;


	for (auto& group : led_groups)
	{
		if (group.group_number != cur_group_num)
		{
			total_num_groups++;

			cur_group_num = group.group_number;
		}
	}

	Serial.println("number of Groups in arrangement = " + (String)total_num_groups);

	END;

	return total_num_groups;
}

int LED_Arrangement::get_size()
{
	START;

	int group_num_leds = 0;
	int cur_group_num = 0;
	int total_num_leds = 0;

	for (auto& group : led_groups)
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

	total_num_leds += group_num_leds;

	Serial.println("number of LEDs in arrangement = " + (String)total_num_leds);

	END;

	return total_num_leds;
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

	END;

	return total_num_leds;
}

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
