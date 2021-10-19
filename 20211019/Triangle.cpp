#include "Triangle.h"
#include <iostream>

Triangle::Triangle()
{
	SetX(0);
	SetY(0);
	SetEdge(0);
	Name = "�ﰢ��";
}

Triangle::Triangle(int NewX, int NewY, int NewEdge)
{
	SetX(NewX);
	SetY(NewY);
	SetEdge(NewEdge);
	Name = "�ﰢ��";
}

Triangle::~Triangle()
{
}

void Triangle::Draw()
{
	std::cout << "�ﰢ�� �׸���" << std::endl;
	std::cout << "(" << X << "," << Y << ")" << std::endl;
	std::cout << "Edge : " << Edge << std::endl;

}
