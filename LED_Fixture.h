// LED_Fixture.h

// The LED Fixture is a container class that gives the Controller a single object
// to control and the Animation class one object to display on.

// As of right now, there is only one fixture per ESP32.

// There should also be methods that can alter how animations are displayed on the fixture.
// An example would be whether an animation runs in parallel on the strips or serially.

#ifndef _LED_FIXTURE_h
#define _LED_FIXTURE_h


#include "arduino.h"
#include "FastLED.h"
#include "LED_Strip.h"

class LED_Fixture
{
 protected:

	 int num_strips;

	 Shape shape;

	 CRGBSet leds;

	 LED_Strip strips[8];

 public:
	LED_Fixture();
	~LED_Fixture();
};


#endif

