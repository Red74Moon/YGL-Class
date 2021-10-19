#include "Star.h"

Star::Star()
{
}

Star::Star(int NewX, int NewY, int NewColor)
{
	SetX(NewX);
	SetY(NewY);
	SetColor(NewColor);
	Name = "��";
}

Star::~Star()
{
	SetX(0);
	SetY(0);
	SetColor(0);
	Name = "��";

}

void Star::Draw()
{
	std::cout << "�� �׸���" << std::endl;
	std::cout << "(" << X << "," << Y << ")" << std::endl;
	std::cout << "Color : " << Color << std::endl;
}
