#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle()
{
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
}
