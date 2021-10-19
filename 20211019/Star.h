#pragma once
#include "Shape.h"

class Star : public Shape
{
public:
	Star();
	Star(int NewX, int NewY, int NewColor);
	virtual ~Star();

	inline void SetColor(int NewColor) { Color = NewColor; }
	inline int GetColor() const { return Color; }

	virtual void Draw() override;

private:
	int Color;
};

