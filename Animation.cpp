// 
// 
// 

#include "Animation.h"

// Update the animation variables to calculate the next frame.
void Animation::update_vars()
{

}

Animation::Animation(LED_Fixture* new_fixture)
	:fixture(new_fixture)
{
	num_patterns = fixture->num_strips;

	for (int i = 0; i < num_patterns; i++)
	{
		pattern[i] = new Pattern(fixture->led_strips[i]);
	}

}

Animation::~Animation()
{
}

void Animation::print_info()
{
	animation_ID = 0;

	for (int i = 0; i < num_patterns; i++)
	{
		pattern[i]->print_info();
	}
}

void Animation::run()
{
	update_vars();

	//animations[animation_ID](fixture, animation_parameters);

	for (int i = 0; i < num_patterns; i++)
	{
		pattern[i]->run();
	}
}

// This is my first attempt at using the new animation class for its intended purpose.
// I have noticed a few things I need to alter about the data structure to make this work the way I would like.
//		1. Patterns should probably be owned at the strip level as opposed to be the animation.

//void alt_bpm_rainbow(LED_Fixture* fixture, Animation_Parameters animation_parameters[])
//{
//	static bool started = false;
//
//	if (started == false)
//	{
//		for (int i = 0; i < num_patterns; i++)
//		{
//			pattern[i] = new Pattern(fixture->led_strips[i]);
//		}
//	}
//}
//
//Animation_Function_List animations = {	//just_rainbow,
//										//just_rainbowWithGlitter,
//										//just_bpm,
//										alt_bpm_rainbow
//
//};