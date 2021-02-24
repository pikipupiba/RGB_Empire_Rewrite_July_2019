#include "Bounded_Variable.h"

Bounded_Variable::Bounded_Variable()
{
}

Bounded_Variable::Bounded_Variable(float new_value, float new_min, float new_max, End_Of_Range new_eor)
	:value(new_value),
	min(new_min),
	max(new_max),
	eor(new_eor)
{
	//START;
	//END;
}

bool Bounded_Variable::is_at_eor()
{
	//START;

	if (value < min)
	{
		switch (eor)
		{
		case _eor_Default:	// same as loop
		case _eor_Loop:
			value = max;
			break;
		case _eor_Bounce:
			value = min;
			break;
		case _eor_Stop:
			value = min;
		default:	// same as _Loop
			value = max;
		}
		//END;

		return true;
	}
	else if (value > max)
	{
		switch (eor)
		{
		case _eor_Default:	// same as loop
		case _eor_Loop:
			value = min;
			break;
		case _eor_Bounce:
			value = max;
			break;
		case _eor_Stop:
			value = max;
		default:	// same as _Loop
			value = min;
		}

		//END;

		return true;
	}
	else
	{
		//END;

		return false;
	}

}

void Bounded_Variable::make_positive()
{
	START;

	value = value < 0 ? -value : value;

	END;
}

void Bounded_Variable::make_negative()
{
	START;

	value = value > 0 ? -value : value;

	END;
}