// LED_Strip.h

// An LED Strip contains all information about a single LED strip in the physical world.

#ifndef _LED_STRIP_h
#define _LED_STRIP_h


#include "arduino.h"
#include <FastLED.h>
#include "My_Enums.h"
#include <vector>
#include "Bug.h"
#include "LED_Arrangements.h"




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

	LED_Arrangement get_led_arrangement(Strip_Display_Mode new_display_mode);

	void print_arrangement_info(Strip_Display_Mode new_display_mode);

	void reset_group(LED_Group& group);

	void next_group(LED_Group& group);

	void reset_arrangement(LED_Arrangement& arrangement);

};

#endif

