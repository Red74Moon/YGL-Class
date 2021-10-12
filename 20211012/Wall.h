#pragma once

#include "Vector2D.h"

class AWall
{
public:
	AWall();
	~AWall();

private:
	// º®ÀÇ ÁÂÇ¥
	FVector2D Location;

	void Render();
};

