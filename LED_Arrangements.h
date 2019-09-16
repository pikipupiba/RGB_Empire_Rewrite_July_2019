#pragma once
// The selected arrangement for each strip is combined into this struct to be passed to animations and such.

#include "LED_Arrangement.h"
#include "My_Enums.h"
#include "Bug.h"

class LED_Arrangements
{
protected:
	std::vector<LED_Arrangement> arrangements;

	int num_groups;
	int size;

	friend class Animation_Controller;
	friend class Animation;
	friend class LED_Fixture;
	friend class LED_Strip;

public:
	int get_num_groups();
	int get_size();

	int get_artnet_size();

	LED_Arrangement compress();
};

