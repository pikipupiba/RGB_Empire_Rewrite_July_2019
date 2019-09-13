#include "Artnet.h"

Artnet::Artnet(LED_Arrangements* new_led_arrangements)
{
}

void Artnet::calculate_frame()
{
}

void Artnet::on_DMX_frame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data)
{
	for (int i = 0; i < length / 3; i++)
	{
		//int led = i + (universe - startUniverse) * (previousDataLength / 3);
		if (i < numLedsPerStrip)
			leds[universe][i] = CRGB(data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
	}

	FastLED.show();

	dmx_recieved[universe] = true;

	int frame_completed = true;

	for (int i = 0; i < numStrips; i++)
	{
		if (!dmx_recieved[i])
		{
			frame_completed = false;
		}
	}

	if (frame_completed)
	{
		fps(1);

		for (int i = 0; i < 8; i++)
		{
			dmx_recieved[i] = false;
		}
	}
}
