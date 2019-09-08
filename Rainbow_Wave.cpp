#include "Rainbow_Wave.h"


Rainbow_Wave::Rainbow_Wave(LED_Arrangements* new_led_arrangements)
	:Animation(new_led_arrangements)
{
	START;

	//Serial.println("what the heck = " + led_set.len);
	
	END;
	
}

void Rainbow_Wave::calculate_frame()
{
	START;

	//vars.hue_offset = beatsin8(5, 1, 20);

	//for (LED_Arrangement& arrangement : led_arrangements->arrangements)
	//{
	//	for (LED_Group& group : arrangement.led_groups)
	//	{
	//		for (CRGBSet& led_set : group.leds)
	//		{
	//			led_set.fill_rainbow(vars.hue, vars.hue_offset);
	//		}
	//	}
	//}

	led_set->fill_rainbow(vars.hue, vars.hue_offset);
	//fill_rainbow(leds, num_leds, vars.hue, vars.hue_offset);

	END;
}
