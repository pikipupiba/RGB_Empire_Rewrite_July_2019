#pragma once
#include "Animation.h"

#include <ArtnetWifi.h>

class Artnet :
	public Animation
{
protected:
	const Animation_Name name = _Artnet;

	ArtnetWifi artnet;
	const int startUniverse = 0;

	const int maxUniverses;
	bool* universesReceived;
	bool sendFrame;
	int previousDataLength;

public:
	Artnet(LED_Arrangements* new_led_arrangements);

	void run();

	void on_DMX_frame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data);
	static void on_DMX_frame_wrapper(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data);
};

