#include <iostream>
#include <windows.h>

#include "Goal.h"

using namespace std;

AGoal::AGoal()
{
}

AGoal::~AGoal()
{
}

void AGoal::Render()
{
	//��ġ ����
	COORD Cur;
	Cur.X = Location.X;
	Cur.Y = Location.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	//���
	cout << "G" << endl;
}


