#include "Rainbow_Wave.h"


Rainbow_Wave::Rainbow_Wave(LED_Arrangements* new_led_arrangements)
{
	START;

	led_arrangements = new_led_arrangements;
	
	print_arrangement_info();
	
	END;
	
}

void Rainbow_Wave::draw_next_frame()
{
	START;

	for (LED_Arrangement& arrangement : led_arrangements->arrangements)
	{
		for (LED_Group& group : arrangement.led_groups)
		{
			for (CRGBSet& led_set : group.leds)
			{
				led_set.fill_rainbow(vars.hue, vars.hue_offset);
			}
		}
	}

	END;
}
