#pragma once

#include "My_Enums.h"

#include "Bounded_Variable.h"

// TODO: make value, speed, acceleration vector based to facilitate flexible movement profiles.

class Animation_Variable
{
protected:

public:
	Variable_Name name;

	Bounded_Variable vars[4];

	End_Of_Range eor;

	Animation_Variable(Variable_Name new_name, float new_value, float new_speed, float new_acceleration, float new_offset, float new_min, float new_max, End_Of_Range new_eor);

	Bounded_Variable* operator()(Animation_Variable_Name new_ani_var_name);

	void update();
};

