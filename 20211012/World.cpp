
#include "World.h"

#include "Floor.h"
#include "Goal.h"
#include "Wall.h"
#include "Player.h"

#include <iostream>

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

	if (Player != nullptr) // �÷��̾� �����Ͱ� ����ġ�� �޸� ������ ���� �ع�
	{
		delete Player;
		Player = nullptr;
	}

	if (Goal != nullptr) // ������ �����Ͱ� ����ġ�� �޸� ������ ���� �ع�
	{
		delete Goal;
		Goal = nullptr;
	}
}

void UWorld::Run()
{
	while (true)
	{
		//Input
		//Tick
		

		//Render ���� �׷��ֱ� 
		for (size_t i = 0; i < Walls.size(); ++i)
		{
			if (Walls[i] != nullptr)
			{
				Walls[i]->Render();
			}
		}

		for (size_t i = 0; i < Floors.size(); ++i)
		{
			if (Floors[i] != nullptr)
			{
				Floors[i]->Render();
			}
		}

		if (Player != nullptr)
		{
			Player->Render();
		}

		if (Goal != nullptr)
		{
			Goal->Render();
		}
	}
}

void UWorld::AddPlayer(APlayer* NewPlayer) // ����ó�� �ʿ��ϴ�. �÷��̾ �ִµ� �� ����� �ֱ� �����̴�.
{
	Player = NewPlayer;
}

void UWorld::AddWall(AWall* NewWall)
{
	Walls.push_back(NewWall);
}

void UWorld::AddFloor(AFloor* NewFloor)
{
	Floors.push_back(NewFloor);
}

void UWorld::AddGoal(AGoal* NewGoal)
{
	Goal = NewGoal;
}


