// LED_Fixture.h

#ifndef _LED_FIXTURE_h
#define _LED_FIXTURE_h


#include "arduino.h"
#include "LED_Strip.h"

class LED_Fixture
{
 protected:

	 const int num_strips;

	 Shape shape;

	 LED_Strip strips[8];

 public:
	void init();
};


#endif

