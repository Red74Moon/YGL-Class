#include "Engine.h"
#include "World.h"

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
