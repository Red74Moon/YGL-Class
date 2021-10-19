#include "Shape.h"

Shape::Shape()
{
}

Shape::Shape(int NewX, int NewY)
{
	SetX(NewX);
	SetY(NewY);
}

Shape::~Shape()
{
}

void Shape::SetX(int NewX)
{
	//X의 범위 체크 필요
	X = NewX;
}

void Shape::SetY(int NewY)
{
	Y = NewY;
}

int Shape::GetX()
{
	return X;
}

int Shape::GetY()
{
	return Y;
}
