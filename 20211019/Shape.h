#pragma once
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

private:
	int X;
	int Y;
};
