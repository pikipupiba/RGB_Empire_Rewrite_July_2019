#include "Rainbow_Wave_With_Glitter.h"

Rainbow_Wave_With_Glitter::Rainbow_Wave_With_Glitter(LED_Fixture* new_fixture, LED_Group* new_group)
	:Animation(new_fixture, new_group)
{
	START;

	animations.push_back(Animation::create(_Rainbow_Wave, fixture, new_group));
	animations.push_back(Animation::create(_Glitter, fixture, new_group));

	END;
}