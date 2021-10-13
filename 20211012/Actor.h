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

	//Accessor
	void SetLocation(FVector2D NewLocatoin);
	FVector2D GetLocation();

private: // »ó¼Ó ¾ÈÇØ ÁÜ.

protected: 
	//  ÁÂÇ¥
	FVector2D Location;
};

