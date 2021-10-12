#pragma once
#include "Vector2D.h"

class AActor
{
public:
	AActor();
	~AActor();

	void input();
	void Tick();
	void Render();
	void SetLocation(FVector2D NewLocatoin);
	FVector2D GetLocation();


private:
	// º®ÀÇ ÁÂÇ¥
	FVector2D Location;
};

