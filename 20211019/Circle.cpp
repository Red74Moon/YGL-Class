#include "Circle.h"
#include <iostream>

Circle::Circle()
{
}

Circle::Circle(int NewX, int NewY, int NewRadius)
{
	SetX(NewX);
	SetY(NewY);
	SetRadius(NewRadius);
	Name = "원";
}

Circle::~Circle()
{
}

void Circle::Draw()
{
	std::cout << "원 그리기" << std::endl;
}
