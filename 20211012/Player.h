#pragma once

//#include "Vector2D.h"
#include "Actor.h"

class APlayer : public AActor //상속
{
public:
	APlayer();
	~APlayer();

	 void Render() override; // 부모에게 같은 함수가 있다.
};

