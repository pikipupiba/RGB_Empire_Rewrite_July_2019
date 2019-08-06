// Animation.h

#ifndef _ANIMATION_h
#define _ANIMATION_h

#include "arduino.h"
#include "Pattern.h"

class Animation
{
 protected:
	 int animation_ID;

	 float brightness[24];

	 float position[24];
	 float speed[24];
	 float acceleration[24];

	 float hue[24];
	 float hue_speed[24];
	 float hue_acceleration[24];

	 float offset[24];
	 float size[24];
	 float size_offset[24];

	 Oscillator osc[24];

	 friend class Pattern;

 public:
	void init();

	void run();

	void update_vars();
};

#endif

