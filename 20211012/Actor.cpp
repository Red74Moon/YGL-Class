#include <iostream>

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
	std::cout << "Actor Render()" << std::endl;
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
