#include <iostream>

#include "Engine.h"
#include "Actor.h"

using namespace std;

Engine::Engine()
{
	cout << "�ʱ�ȭ �մϴ�." << endl;
}

Engine::~Engine()
{
	for (int i = 0; i < CountofActors; ++i)
	{
		if (Actors[i] != nullptr)
		{
			delete Actors[i];
		}
	}
	cout << "�ڷḦ �����մϴ�." << endl;
}

void Engine::RunEngine()
{
	
}

void Engine::SpawnActor()
{
	//Actor* newActor = new Actor();
	//
	//Actors[0] = newActor;

	Actors[CountofActors++] = new Actor();
}

void Engine::DestoryActor(int Index)
{
	delete Actors[Index];
	Actors[Index] = nullptr;
}

void Engine::Initialize()
{
}

void Engine::BeginPlay()
{
}

void Engine::Tick()
{
}

void Engine::Input()
{
}

void Engine::Redering()
{
}

void Engine::BeginOverlap()
{
}

void Engine::Terminalize()
{
}
