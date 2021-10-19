#pragma once
#include "Shape.h"

class Trangle : public Shape
{
public:
	Trangle();
	virtual ~Trangle();

	virtual void Draw() override;
};