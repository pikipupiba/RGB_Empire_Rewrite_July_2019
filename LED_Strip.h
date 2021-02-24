// LED_Strip.h

// An LED Strip contains all information about a single LED strip in the physical world.

#ifndef _LED_STRIP_h
#define _LED_STRIP_h


#include "arduino.h"
#include <FastLED.h>
#include "My_Enums.h"
#include <vector>
#include "Bug.h"
#include "LED_Arrangement.h"


class LED_Strip
{
 protected:

	 int strip_index;

	 CRGBSet* leds;

	 Strip_Parameters strip_parameters;

	 Strip_Display_Mode strip_display_mode;

	 std::vector<LED_Arrangement*> arrangements;

	 friend class LED_Fixture;

	 void print_info();
	 

 public:

	LED_Strip(int new_strip_index, CRGBSet* leds, Strip_Parameters new_strip_parameters);
	~LED_Strip();

	LED_Arrangement* get_led_arrangement(Strip_Display_Mode new_strip_display_mode);

	LED_Arrangement* arrangement();

	LED_Arrangement* operator[](Strip_Display_Mode new_strip_display_mode);

	void print_arrangement_info(Strip_Display_Mode new_display_mode);
};

#endif

