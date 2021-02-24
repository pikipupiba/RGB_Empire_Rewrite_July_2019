// Oscillator.h

// Oscillators will perform much of the same function as FastLED's built in beatsin
// functions with a few more key abilities.

// 1: Fractional BPMs
// 2: Smooth transitions between different BPMs
// 3: Built in combinations of harmonics for various output behaviors for a set BPM
// 4: Can be intrinsically linked to a variable anywhere in the code

// TODO: FASTLED DOES THIS! saccum1516 is the way of the future.

#ifndef _OSCILLATOR_h
#define _OSCILLATOR_h

#include "arduino.h"
#include "FastLED.h"

class Oscillator
{
 protected:

	 accum88 BPM;
	 saccum78 min;
	 saccum78 max;

 public:
	Oscillator(accum88 new_BPM, saccum78 new_min, saccum78 new_max);
	~Oscillator();

	float O1(saccum1516 offset);
};

#endif

