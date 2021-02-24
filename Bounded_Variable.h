#pragma once

#include "My_Enums.h"

// TODO: make this a template class

class Bounded_Variable
{
protected:

public:
	float value;
	float min;
	float max;

	End_Of_Range eor;

	Bounded_Variable();
	Bounded_Variable(float new_value, float new_min, float new_max, End_Of_Range new_eor);

	bool is_at_eor();

	void make_positive();
	void make_negative();
};

