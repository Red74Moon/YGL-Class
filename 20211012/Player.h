#pragma once

#include "Vector2D.h"
#include "Actor.h"

class APlayer : public AActor //���
{
public:
	APlayer();
	~APlayer();

	void Input();
	void Tick();
	void Render();
	


};
