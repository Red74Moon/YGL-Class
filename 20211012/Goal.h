#pragma once
#include "Vector2D.h"

class AGoal
{
public:
	AGoal();
	~AGoal();
private:
	FVector2D Location;

	void Render();

};

