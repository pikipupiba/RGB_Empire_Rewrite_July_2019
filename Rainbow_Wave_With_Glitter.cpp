#include "Rainbow_Wave_With_Glitter.h"

Rainbow_Wave_With_Glitter::Rainbow_Wave_With_Glitter()
{
	animations.push_back(Animation::create(_Rainbow_Wave));
	animations.push_back(Animation::create(_Glitter));
}