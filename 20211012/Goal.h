#pragma once

#include "Vector2D.h"
#include "Actor.h"

class AGoal : public AActor
{
public:
	AGoal();
	~AGoal();

	void Input();
	void Tick();
	void Render();
};
