#pragma once

#include "Vector2D.h"

class AWall
{
public:
	AWall();
	~AWall();

private:
	// ���� ��ǥ
	FVector2D Location;

	void Render();
};

