#include <iostream>
//#include <windows.h>

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
	AActor::Render();

	//위치 지정
	//COORD Cur;
	//Cur.X = Location.X;
	//Cur.Y = Location.Y;
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	//출력
	cout << "G" << endl;
}


