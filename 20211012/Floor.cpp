#include <iostream>
#include <windows.h>

#include "Floor.h"

AFloor::AFloor()
{
}

AFloor::~AFloor()
{
}

void AFloor::Render()
{
    //��ġ ����
    COORD Cur;
    Cur.X = Location.X;
    Cur.Y = Location.Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	std::cout << " " << std::endl;
}


