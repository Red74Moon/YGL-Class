#pragma once
#include <string>
#include "Shape.h"

class Star : public Shape
{
public:
	Star();
	Star(int NewX, int NewY, int NewColor);
	virtual ~Star();
	inline void SetColor(int NewColor) { Color = NewColor; }
	inline int GetColor() const { return Color; }

	void Draw();

private:
	int Color;
};

