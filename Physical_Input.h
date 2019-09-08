// Physical_Input.h

// This is where all code pertaining to receiving input from physical
// buttons, knobs, encoders, and sensors is located.

#ifndef _PHYSICAL_INPUT_h
#define _PHYSICAL_INPUT_h

#include "arduino.h"

class Physical_Input
{
protected:
	bool enabled;


public:
	Physical_Input();

	void setup();

	void check();
};

#endif

