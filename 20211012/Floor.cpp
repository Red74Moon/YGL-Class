#include <iostream>

#include "Floor.h"

AFloor::AFloor()
{
}

AFloor::~AFloor()
{
}

void AFloor::Render()
{
    AActor::Render();

    //위치 지정
    //COORD Cur;
    //Cur.X = Location.X;
    //Cur.Y = Location.Y;
    //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	std::cout << " " << std::endl;
}


