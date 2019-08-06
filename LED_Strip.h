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

	 int num_leds;
	 int leds_per_meter;
	 Shape shape;

	 int length_in_meters;
	 int width_in_meters;

	 CRGBSet leds;

	 friend class LED_Fixture;

 public:

	LED_Strip(int new_num_leds, int new_leds_per_meter, Shape new_shape);
	~LED_Strip();
};

#endif

