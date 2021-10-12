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

private: // ��� ���� ��.

protected: 
	// ���� ��ǥ
	FVector2D Location;
};

