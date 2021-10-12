#pragma once

#include "Vector2D.h"

class APlayer
{
public:
	APlayer();
	~APlayer();

private:
	FVector2D Locatoin;
	
	void Input();
	void Render();
	void Tick();
};

