// Oscillator.h

// Oscillators will perform much of the same function as FastLED's built in beatsin
// functions with a few more key abilities.

// 1: Fractional BPMs
// 2: Smooth transitions between different BPMs
// 3: Built in combinations of harmonics for various output behaviors for a set BPM
// 4: Can be intrinsically linked to a variable anywhere in the code

#ifndef _OSCILLATOR_h
#define _OSCILLATOR_h

#include "arduino.h"

class Oscillator
{
 protected:

	 float BPM;

 public:
	Oscillator();
	~Oscillator();
};

#endif

