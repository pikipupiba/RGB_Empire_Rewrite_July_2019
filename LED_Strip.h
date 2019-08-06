// LED_Strip.h

#ifndef _LED_STRIP_h
#define _LED_STRIP_h


#include "arduino.h"
#include "FastLED.h"
#include "My_Enums.h"


class LED_Strip
{
 protected:

	 const int num_leds;
	 const int leds_per_meter;
	 const Shape shape;

	 const int length_in_meters;
	 const int width_in_meters;

	 friend class LED_Fixture;

 public:

	void init(int new_num_leds, int new_leds_per_meter, Shape new_shape);
};

#endif

