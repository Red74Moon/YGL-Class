#include "Star.h"

Star::Star()
{
	SetX(0);
	SetY(0);
	SetColor(0);
	Name = "별";
}

Star::Star(int NewX, int NewY, int NewColor)
{
	SetX(NewX);
	SetY(NewY);
	SetColor(NewColor);
	Name = "별";
}

Star::~Star()
{
}

void Star::Draw()
{
	std::cout << "별 그리기" << std::endl;
	std::cout << "(" << X << "," << Y << ")" << std::endl;
	std::cout << "Color : " << Color << std::endl;
}
