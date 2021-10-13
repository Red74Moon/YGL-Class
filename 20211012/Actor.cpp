#include <iostream>
#include <windows.h>

#include "Actor.h"

AActor::AActor()
{
}

AActor::~AActor()
{
}

void AActor::input()
{
}

void AActor::Tick()
{
}

void AActor::Render()
{
	// 출력 위치
	COORD Cur;
	Cur.X = Location.X;
	Cur.Y = Location.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	
	//	std::cout << "Actor Render()" << std::endl;
}

void AActor::SetLocation(FVector2D NewLocatoin)
{
	Location.X = NewLocatoin.X;
	Location.Y = NewLocatoin.Y;
}

FVector2D AActor::GetLocation()
{
	return Location;
}
