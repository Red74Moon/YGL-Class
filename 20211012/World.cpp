
#include "World.h"
#include "Floor.h"
#include "Goal.h"
#include "Wall.h"
#include "Player.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
	Term();
}

void UWorld::Init()
{
}

void UWorld::Term()
{
	for (size_t i = 0; i < Walls.size(); ++i)
	{
		if (Walls[i] != nullptr)
		{
			delete Walls[i];
			Walls[i] = nullptr;
		}
	}
	Walls.clear();

	for (size_t i = 0; i < Floors.size(); ++i)
	{
		if (Floors[i] != nullptr)
		{
			delete Floors[i];
			Floors[i] = nullptr;
		}
	}
	Floors.clear();

	if (Player != nullptr) // 플레이어 포인터가 가르치는 메모리 번지의 값을 해방
	{
		delete Player;
		Player = nullptr;
	}

	if (Goal != nullptr) // 목적지 포인터가 가르치는 메모리 번지의 값을 해방
	{
		delete Goal;
		Goal = nullptr;
	}
}

void UWorld::Run()
{
}
