#include "Circle.h"
#include <iostream>

Circle::Circle()
{
	SetX(0);
	SetY(0);
	SetRadius(0);
	Name = "��";
}

Circle::Circle(int NewX, int NewY, int NewRadius)
{
	SetX(NewX);
	SetY(NewY);
	SetRadius(NewRadius);
	Name = "��";
}

Circle::~Circle()
{
}

void Circle::Draw()
{
	std::cout << "�� �׸���" << std::endl;
	std::cout << "(" << X << "," << Y << ")" << std::endl;
	std::cout << "Radius : " << Radius << std::endl;

}
