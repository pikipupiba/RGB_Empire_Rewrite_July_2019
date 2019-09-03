// LED_Strip.h

// An LED Strip contains all information about a single LED strip in the physical world.

#ifndef _LED_STRIP_h
#define _LED_STRIP_h


#include "arduino.h"
#include <FastLED.h>
#include "My_Enums.h"
#include <vector>


struct LED_Group
{
	std::vector<CRGBSet> leds;
	int group_number;
};

struct LED_Arrangement
{
	Strip_Display_Mode strip_display_mode;
	std::vector<LED_Group> led_groups;
};

struct LED_Arrangements
{
	std::vector<LED_Arrangement> arrangements;
};


class LED_Strip
{
 protected:

	 int strip_index;

	 CRGBSet* leds;

	 Strip_Parameters strip_parameters;

	 LED_Arrangements led_arrangements;

	 friend class LED_Fixture;

	 void print_info();

	 void create_arrangements();
	 void create_linear_arrangements();
	 void create_folded_arrangements();
	 void create_panel_arrangements();
	 void create_polygon_arrangements();
	 

 public:

	LED_Strip(int new_strip_index, CRGBSet* leds, Strip_Parameters new_strip_parameters);
	~LED_Strip();

	LED_Arrangement* get_led_arrangement(Strip_Display_Mode new_display_mode);

};

#endif

