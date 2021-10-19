#include "Triangle.h"
#include <iostream>

Triangle::Triangle()
{
	SetX(0);
	SetY(0);
	SetEdge(0);
	Name = "»ï°¢Çü";
}

Triangle::Triangle(int NewX, int NewY, int NewEdge)
{
	SetX(NewX);
	SetY(NewY);
	SetEdge(NewEdge);
	Name = "»ï°¢Çü";
}

Triangle::~Triangle()
{
}

void Triangle::Draw()
{
	std::cout << "»ï°¢Çü ±×¸®±â" << std::endl;
	std::cout << "(" << X << "," << Y << ")" << std::endl;
	std::cout << "Edge : " << Edge << std::endl;

}
