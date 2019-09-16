#pragma once
// Every strip has 1 arrangement per display mode.

#include "LED_Group.h"
#include "My_Enums.h"
#include "Bug.h"

class LED_Arrangement
{
protected:
	Strip_Display_Mode strip_display_mode;	// Display modes represent different ways to run animations on a given set of leds.

	std::vector<LED_Group> led_groups;		// Each arrangement contains 1 or more groups.

	int num_groups;	// The number of groups the arrangement contains.
	int size;		// The sum of the group sizes. Represents the total amount of pixels an animation must generate.

	friend class LED_Arrangements;
	friend class Animation_Controller;
	friend class Animation;
	friend class LED_Fixture;
	friend class LED_Strip;

public:

	int get_num_groups();
	int get_size();
};

