
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
}
