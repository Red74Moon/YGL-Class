#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle()
{
	SetX(0);
	SetY(0);
	SetWidth(0);
	SetHeight(0);
	Name = "�簢��";
}

Rectangle::Rectangle(int NewX, int NewY, int NewWidth, int NewHeight)
{
	SetX(NewX);
	SetY(NewY);
	SetWidth(NewWidth);
	SetHeight(NewHeight);
	Name = "�簢��";
}

Rectangle::~Rectangle()
{
}

void Rectangle::Draw()
{
	std::cout << "�簢�� �׸���" << std::endl;
	std::cout << "(" << X << "," << Y << ")" << std::endl;
	std::cout << "Width : " << Width << std::endl;
	std::cout << "Height : " << Height << std::endl;
}
