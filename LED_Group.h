#pragma once

// An LED_Group represents CRGBSets that will pull from the same pixel data.
// TODO: figure out how they could be offset from each other.

#include "FastLED.h"
#include "My_Enums.h"
#include "Bug.h"

class LED_Group
{
protected:
	std::vector<CRGBSet> leds;	// Vector of CRGBSets that refer directly to parts of the LED_Fixture g_leds.
	int group_number;	// The group number. Even groups on different strips will copy each other if their group number is the same.
	int strip_number;	// The strip that this group is on.

	int size;			// The size of a group is equal to the largest CRGBSet it contains.

	int get_size();		// Calculates the size of the group.

	friend class LED_Arrangement;
	friend class LED_Arrangements;

	friend class Animation_Controller;
	friend class Animation;
	friend class LED_Fixture;
	friend class LED_Strip;

public:
	void add_to_group(LED_Group new_group);
	void add_to_group(CRGBSet new_led_set);
};

