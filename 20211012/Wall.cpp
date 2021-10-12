#include <iostream>
#include <windows.h>

#include "Wall.h"

using namespace std;

AWall::AWall()
{
}

AWall::~AWall()
{
}

void AWall::Render()
{
	//위치 지정
	COORD Cur;
	Cur.X = Location.X;
	Cur.Y = Location.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	//출력
	cout << "#" << endl;
}

//void AWall::SetLocation(FVector2D NewLocatoin)
//{
//	Location.X = NewLocatoin.X;
//	Location.Y = NewLocatoin.Y;
//}

