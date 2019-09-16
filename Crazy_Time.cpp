#include "Crazy_Time.h"

Crazy_Time::Crazy_Time(LED_Arrangements* new_led_arrangements)
	:Animation(new_led_arrangements)
{
	START;

	vars(position, a_value)->eor = _eor_Bounce;
	vars(position, a_speed)->eor = _eor_Bounce;
	vars(position, a_acceleration)->eor = _eor_Bounce;

	vars(position, a_acceleration)->value = 0.02;

	vars(position, a_speed)->min = -2;
	vars(position, a_speed)->max = 2;

	vars(size, a_value)->eor = _eor_Bounce;
	vars(size, a_speed)->eor = _eor_Bounce;
	vars(size, a_acceleration)->eor = _eor_Bounce;

	vars(size, a_acceleration)->value = 0.01;
	vars(size, a_value)->max = 30;

	vars(size, a_speed)->min = -1;
	vars(size, a_speed)->max = 1;

	vars(hue, a_value)->eor = _eor_Loop;
	vars(hue, a_speed)->eor = _eor_Bounce;
	vars(hue, a_acceleration)->eor = _eor_Bounce;

	vars(hue, a_speed)->min = -1;
	vars(hue, a_speed)->max = 1;

	vars(hue, a_acceleration)->value = 0.01;

	END;
}

void Crazy_Time::calculate_frame()
{
	float new_start = vars(position) - vars(size) / 2;
	float new_end = vars(position) + vars(size) / 2;

	if (new_start < 0)
	{
		new_start = 0;
	}
	if (new_end > num_leds - 1)
	{
		new_end = num_leds - 1;
	}

	float start = new_start;
	float end = new_end;

	leds[(int)start] += CHSV(vars(hue), 255, vars(brightness) * (1 - (start - (int)start)));

	if (start < end) {
		for (int i = start + 1; i < end - 1; i++) {
			leds[i] = CHSV(vars(hue), 255, vars(brightness));
		}
	}
	else {
		for (int i = start; i <= vars.range_end; i++) {
			leds[i] += CHSV(vars(hue), 255, vars(brightness));
		}
		for (int i = end; i >= (int)vars.range_start && end > 1; i--) {
			leds[i] += CHSV(vars(hue), 255, vars(brightness));
		}
	}

	leds[(int)end] += CHSV(vars(hue), 255, vars(brightness) * (end - (int)end));
}
