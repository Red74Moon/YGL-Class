
#include <iostream>
#include <windows.h>

#include "Player.h"


APlayer::APlayer()
{
}

APlayer::~APlayer()
{
}

void APlayer::Input()
{
}

void APlayer::Render()
{
    //위치 지정
    COORD Cur;
    Cur.X = Location.X;
    Cur.Y = Location.Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	
    //출력
    std::cout << "P" << std::endl;
}

void APlayer::Tick()
{
}
