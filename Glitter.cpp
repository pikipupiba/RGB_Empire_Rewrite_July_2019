#include "Glitter.h"

Glitter::Glitter()
{
}

void Glitter::draw_next_frame()
{
	for (auto& led_set : leds) {
		for (CRGB & pixel : *led_set) {
			if (rand() * 100 < vars.density)
			{
				pixel = CRGB::White;
			}
		}
	}
}


