#include "Artnet.h"

void* pt2Object;



Artnet::Artnet(LED_Arrangements* new_led_arrangements)
	:Animation(new_led_arrangements),
	maxUniverses((num_leds * 3) / 512 + (((num_leds * 3) % 512) ? 1 : 0))
{
	START;

	universesReceived = new bool[maxUniverses];
	bool sendFrame = 1;
	int previousDataLength = 0;
	
	artnet.begin();
	artnet.setArtDmxCallback(Artnet::on_DMX_frame_wrapper);

	pt2Object = (void*) this;

	END;
}

void Artnet::run()
{
	START;

	artnet.read();

	END;
}

void Artnet::on_DMX_frame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data)
{
	START;

	for (int i = 0; i < length / 3; i++)
	{
		//int led = i + (universe - startUniverse) * (previousDataLength / 3);
		if (i < 144)
		{
			leds[i + universe * 144] = CRGB(data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
		}
	}

	END;
}


void Artnet::on_DMX_frame_wrapper(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data)
{
	START;

	// explicitly cast to a pointer to Classname
	Artnet* mySelf = (Artnet*)pt2Object;

	// call member
	mySelf->on_DMX_frame(universe, length, sequence, data);

	END;
}