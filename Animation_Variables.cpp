#include "Animation_Variables.h"

float Animation_Variables::operator()(Variable_Name new_var_name)
{
	return vars[new_var_name](a_value)->value;
}

Bounded_Variable* Animation_Variables::operator()(Variable_Name new_var_name, Animation_Variable_Name new_ani_var_name)
{
	return vars[new_var_name](new_ani_var_name);
}

Animation_Variables::Animation_Variables(float new_range_start, float new_range_end)
	:range_start(new_range_start),
	range_end(new_range_end)
{
	START;

	vars.push_back(Animation_Variable(brightness, 255, 0, 0, 0, 0, 255, _eor_Bounce));
	vars.push_back(Animation_Variable(position, 0, 0.2, 0, 0, range_start, range_end, _eor_Bounce));
	vars.push_back(Animation_Variable(hue, 0, 1, 0, 5, 0, 255, _eor_Loop));
	vars.push_back(Animation_Variable(size, 4, 0, 0, 0, 1, 20, _eor_Bounce));
	vars.push_back(Animation_Variable(density, 5, 0, 0, 0, 0, 1000, _eor_Bounce));
	vars.push_back(Animation_Variable(fade, 80, 0, 0, 0, 0, 255, _eor_Bounce));

	END;
}