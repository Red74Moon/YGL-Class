
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
    //위치 지정, 콘솔화면에 커서를 원하는 위치로 이동하여 해당위치에 문자를 출력
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
