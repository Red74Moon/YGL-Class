#pragma once

#include "Vector2D.h"

class AFloor
{
public:
	AFloor();
	~AFloor();

private:
	FVector2D Location;

	void Render();
};

