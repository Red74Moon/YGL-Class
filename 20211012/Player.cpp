
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
    //��ġ ����, �ܼ�ȭ�鿡 Ŀ���� ���ϴ� ��ġ�� �̵��Ͽ� �ش���ġ�� ���ڸ� ���
    COORD Cur;
    Cur.X = Location.X;
    Cur.Y = Location.Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	
    //���
    std::cout << "P" << std::endl;
}

void APlayer::Tick()
{
}
