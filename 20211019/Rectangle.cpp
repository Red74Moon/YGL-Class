#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle()
{
	SetX(0);
	SetY(0);
	SetWidth(0);
	SetHeight(0);
	Name = "사각형";
}

Rectangle::Rectangle(int NewX, int NewY, int NewWidth, int NewHeight)
{
	SetX(NewX);
	SetY(NewY);
	SetWidth(NewWidth);
	SetHeight(NewHeight);
	Name = "사각형";
}

Rectangle::~Rectangle()
{
}

void Rectangle::Draw()
{
	std::cout << "사각형 그리기" << std::endl;
	std::cout << "(" << X << "," << Y << ")" << std::endl;
	std::cout << "Width : " << Width << std::endl;
	std::cout << "Height : " << Height << std::endl;
}
