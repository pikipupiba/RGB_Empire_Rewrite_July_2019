#pragma once

#include "Animation.h"
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArtnetWifi.h>

class Artnet :
	public Animation
{
protected:
	const Animation_Name name = _Artnet;

public:
	Artnet(LED_Arrangements* new_led_arrangements);

	void calculate_frame();

	void on_DMX_frame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data);
};

