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

private: // 상속 안해 줌.

protected: // 상속은 하고, 밖에서 못 봄
	//  좌표
	FVector2D Location;
};

