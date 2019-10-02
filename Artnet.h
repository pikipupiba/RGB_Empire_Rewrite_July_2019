#pragma once

// This animation creates an Artnet recieving thing and does it.

#include "Animation.h"

#include <ArtnetWifi.h>

#include "Tasks.h"

class Artnet :
	public Animation
{
protected:
	const Animation_Name name = _Artnet;

	ArtnetWifi artnet;
	const int start_universe = 0;

	int num_universes;
	bool* universes_received;
	bool send_frame;
	int previous_data_length;

public:
	Artnet(LED_Fixture* new_fixture, LED_Group* new_group);

	void run();

	void on_DMX_frame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data);
	static void on_DMX_frame_wrapper(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data);
};

