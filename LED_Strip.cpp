// 
// 
// 

#include "LED_Strip.h"

void reset_group(LED_Group& group)
{
	group.group_number = 0;

	group.leds.clear();
}

void next_group(LED_Group& group)
{
	group.group_number++;

	group.leds.clear();
}

void reset_arrangement(LED_Arrangement& arrangement)
{
	arrangement.led_groups.clear();
}

void LED_Strip::create_arrangements()
{
	START;

	switch (strip_parameters.shape)
	{
	case Linear:

		create_linear_arrangements();
		break;

	case Folded:
		
		create_folded_arrangements();
		break;

	case Panel:

		create_panel_arrangements();
		break;

	default:
		create_linear_arrangements();
	}

	END;
};

void LED_Strip::create_linear_arrangements()
{
	START;

	LED_Arrangement temp_arrangement;
	LED_Group temp_group;


	temp_arrangement.strip_display_mode = Default_Strip;
	reset_group(temp_group);
	reset_arrangement(temp_arrangement);
	
	temp_group.leds.push_back(*leds);

	temp_arrangement.led_groups.push_back(temp_group);

	led_arrangements.arrangements.push_back(temp_arrangement);


	temp_arrangement.strip_display_mode = Left_To_Right;
	// Same as Default
	led_arrangements.arrangements.push_back(temp_arrangement);


	temp_arrangement.strip_display_mode = Around;
	// Same as Default
	led_arrangements.arrangements.push_back(temp_arrangement);


	temp_arrangement.strip_display_mode = Middle_Out;
	reset_group (temp_group);
	reset_arrangement(temp_arrangement);


	temp_group.leds.push_back(leds[0](leds->len, 0));
	temp_group.leds.push_back(leds[0](leds->len / 2, leds->size()));

	temp_arrangement.led_groups.push_back(temp_group);

	led_arrangements.arrangements.push_back(temp_arrangement);

	MEM;
	END;
}

void LED_Strip::create_folded_arrangements()
{
	START;

	LED_Arrangement temp_arrangement;
	LED_Group temp_group;

	temp_arrangement.strip_display_mode = Default_Strip;
	reset_group(temp_group);
	reset_arrangement(temp_arrangement);

	for (int i = 0; i < strip_parameters.width_in_leds; i++)
	{
		THING;

		if (i % 2 == 1)
		{
			temp_group.leds.push_back(leds[0](strip_parameters.length_in_leds * (i + 1) - 1, strip_parameters.length_in_leds * i));
		}
		else
		{
			temp_group.leds.push_back(leds[0](strip_parameters.length_in_leds * i, strip_parameters.length_in_leds * (i + 1) - 1));
		}
	}

	temp_arrangement.led_groups.push_back(temp_group);

	led_arrangements.arrangements.push_back(temp_arrangement);


	temp_arrangement.strip_display_mode = Left_To_Right;
	// Same as Default
	led_arrangements.arrangements.push_back(temp_arrangement);


	temp_arrangement.strip_display_mode = Around;
	reset_group(temp_group);
	reset_arrangement(temp_arrangement);

	temp_group.leds.push_back(*leds);

	temp_arrangement.led_groups.push_back(temp_group);

	led_arrangements.arrangements.push_back(temp_arrangement);

	temp_arrangement.strip_display_mode = Middle_Out;
	reset_group(temp_group);
	reset_arrangement(temp_arrangement);

	temp_group.leds.push_back(leds[0](strip_parameters.length_in_leds / 2 - 1, 0));

	temp_group.leds.push_back(leds[0](strip_parameters.length_in_leds / 2, strip_parameters.length_in_leds - 1));

	temp_group.leds.push_back(leds[0](strip_parameters.length_in_leds * 3 / 2 - 1, strip_parameters.length_in_leds));

	temp_group.leds.push_back(leds[0](strip_parameters.length_in_leds * 3 / 2, strip_parameters.length_in_leds * 2 - 1));

	temp_arrangement.led_groups.push_back(temp_group);

	led_arrangements.arrangements.push_back(temp_arrangement);

	MEM;
	END;
}

void LED_Strip::create_panel_arrangements()
{
}

void LED_Strip::create_polygon_arrangements()
{
}

void LED_Strip::print_info()
{
	Serial.print("Strip #");
	Serial.print(strip_index);
	Serial.println(" Information:");

	Serial.print("   ");
	Serial.print(strip_parameters.num_leds);
	Serial.println(" LEDs");

	Serial.print("   ");
	Serial.print(strip_parameters.leds_per_meter);
	Serial.println(" LEDs / meter");
}


LED_Strip::LED_Strip(int new_strip_index, CRGBSet* new_leds, Strip_Parameters new_strip_parameters)
	:strip_index(new_strip_index),
	leds(new_leds),
	strip_parameters(new_strip_parameters)
{
	START;

	create_arrangements();

	MEM;

	END;
}

LED_Strip::~LED_Strip()
{
	
}

LED_Arrangement LED_Strip::get_led_arrangement(Strip_Display_Mode new_display_mode)
{
	START;

	for (auto& arrangement : led_arrangements.arrangements)
	{
		if (arrangement.strip_display_mode == new_display_mode)
		{
			return arrangement;
		}
	}

	return led_arrangements.arrangements[Default_Strip];

	END;
}

void LED_Strip::print_arrangement_info(Strip_Display_Mode new_display_mode)
{
	START;

	Serial.println("LED Arrangement Info for Strip #" + (String)strip_index);

	for (auto& arrangement : led_arrangements.arrangements)
	{
		if (arrangement.strip_display_mode == new_display_mode)
		{
			int i = 0;

			for (auto& group : arrangement.led_groups)
			{
				Serial.println("      LED_Group #" + (String)i++);
				for (auto& led_set : group.leds)
				{
					Serial.println("            -" + (String)led_set.len + "LEDs");
				}
			}
		}
	}

	END;
}
