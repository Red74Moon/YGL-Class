#pragma once
#include "Vector2D.h"

class AActor
{
public:
	AActor();
	~AActor();

	void input();
	void Tick();
	virtual void Render(); // 자식이 같은 함수가 있으면 자식것을 사용한다.

	//Accessor
	void SetLocation(FVector2D NewLocatoin);
	FVector2D GetLocation();

private: // 상속 안해 줌.

protected: // 상속은 하고, 밖에서 못 봄
	//  좌표
	FVector2D Location;
};

