#include <iostream>
#include <string>
#include <fstream>

#include "Engine.h"

#include "Player.h"
#include "Goal.h"
#include "Wall.h"
#include "Floor.h"

//#include <vector>

UEngine::UEngine()
{
	Init(); 
}

UEngine::~UEngine()
{
	Term();
}

void UEngine::Run()
{
	World->Run();
}

bool UEngine::LoadLevel(std::string filename)
{
	std::ifstream fin;
	std::string line;

	fin.open("map01.txt");

	if (!fin.is_open())
	{
		return false;
	}

	int Y = 0;

	while (!fin.eof())
	{
		getline(fin, line);

		for (size_t X = 0; X < line.length(); ++X)
		{
			if (line[X] == '#')
			{
				SpawnWall(FVector2D(X, Y));
			}
			else if (line[X] == ' ')
			{
				SpawnFloor(FVector2D(X, Y));
			}
			else if (line[X] == 'P')
			{
				SpawnPlayer(FVector2D(X, Y));
			}
			else if (line[X] == 'G')
			{
				SpawnGoal(FVector2D(X, Y));
			}		
		}
		Y++;
	}
	fin.close();
	return false;
}

void UEngine::SpawnPlayer(FVector2D NewLocation)
{
	//생성
	APlayer* NewPlayer = new APlayer();
	NewPlayer->SetLocation(NewLocation);
	//저장
	World->AddPlayer(NewPlayer);
}

void UEngine::SpawnWall(FVector2D NewLocation)
{
	//생성
	AWall* NewWall = new AWall();
	NewWall->SetLocation(NewLocation);
	//저장
	World->AddWall(NewWall);
}

void UEngine::SpawnGoal(FVector2D NewLocation)
{
}

void UEngine::SpawnFloor(FVector2D NewLocation)
{
	//생성
	AFloor* NewFloor = new AFloor();
	NewFloor->SetLocation(NewLocation);
	//저장
	World->AddFloor(NewFloor);
}

void UEngine::Init()
{
	World = new UWorld();  // 엔진이 시작될때 만들어 달라
}

void UEngine::Term()
{
	if (World != nullptr)
	{
		delete World;
		World = nullptr;
	}
}

void UEngine::Input()
{
}

void UEngine::Tick()
{
}

void UEngine::Render()
{
}
