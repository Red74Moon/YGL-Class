#include "Engine.h"
#include "World.h"
#include "Actor.h"

#include <vector>

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
