// LED_Strip.h

// An LED Strip contains all information about a single LED strip in the physical world.

#ifndef _LED_STRIP_h
#define _LED_STRIP_h


#include "arduino.h"
#include "FastLED.h"
#include "My_Enums.h"


class LED_Strip
{
 protected:

	 int strip_index;

	 CRGBSet* leds;

	 int num_leds;
	 int leds_per_meter;
	 Shape shape;

	 int length_in_leds;
	 int width_in_leds;

	 friend class LED_Fixture;
	 friend class Pattern;

	 void print_info();

 public:

	LED_Strip(int new_strip_index, CRGBSet* leds, Strip_Parameters new_strip_parameters);
	~LED_Strip();
};

#endif

