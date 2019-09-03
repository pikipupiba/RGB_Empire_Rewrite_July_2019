#pragma once
#include "Animation.h"
class Dancing_Sisters :
	public Animation
{
protected:
	const Animation_Name name = _Dancing_Sisters;

public:
	Dancing_Sisters();

	void draw_next_frame();
};

