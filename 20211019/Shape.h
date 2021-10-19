#pragma once
#include <iostream>
#include <string>

class Shape
{
public:
	Shape();
	Shape(int NewX, int NewY);
	virtual ~Shape();

	virtual void Draw() = 0;

	virtual void SetX(int NewX);
	virtual void SetY(int NewY);

	virtual int GetX();
	virtual int GetY();

	inline std::string GetName() { return Name; }

protected:
	int X;
	int Y;

	std::string Name;
};
