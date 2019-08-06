// Physical_Input.h

// This is where all code pertaining to receiving input from physical
// buttons, knobs, encoders, and sensors is located.

#ifndef _PHYSICAL_INPUT_h
#define _PHYSICAL_INPUT_h

#include "arduino.h"

extern bool physical_input_enabled;

void setup_physical_input();

void check_physical_input();


#endif

