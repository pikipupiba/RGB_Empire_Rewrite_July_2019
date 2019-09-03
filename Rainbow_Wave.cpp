#include "Rainbow_Wave.h"


Rainbow_Wave::Rainbow_Wave()
{
	
}

void Rainbow_Wave::draw_next_frame()
{
	START;

	switch (vars.display_mode)
	{
	case Parallel:
		for (auto& led_set : leds) {
			led_set->fill_rainbow(vars.hue, vars.hue_offset);
		}
		break;
	case Sequential:
		{
			int offset = 0;

			for (auto& led_set : leds) {
				led_set->fill_rainbow(vars.hue + offset, vars.hue_offset);

				offset += led_set->size() % (int)vars.hue_offset;
			}
		}
	
		break;
	default:
		for (auto& led_set : leds) {
			led_set->fill_rainbow(vars.hue, vars.hue_offset);
		}
	}

	END;
}
