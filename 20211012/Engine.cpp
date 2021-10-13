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
