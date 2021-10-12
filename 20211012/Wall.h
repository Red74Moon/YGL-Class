#pragma once

#include "Vector2D.h"
#include "Actor.h"

class AWall : public AActor
{
public:
	AWall();
	~AWall();

	void Input();
	void Tick();
	void Render();
};

