#include <iostream>

#include "Engine.h"
#include "Actor.h"

using namespace std;

Engine::Engine()
{
	cout << "초기화 합니다." << endl;
}

//엔진 종료시 제거 안된 액터 지움
Engine::~Engine()
{
	for (int i = 0; i < CountOfActors; ++i)
	{
		if (Actors[i] != nullptr) // 지울 액터를 가리키는 인덱스가 nullptr인지 확인
		{
			delete Actors[i];
		}
	}
	cout << "자료를 정리합니다." << endl;
}

void Engine::RunEngine()
{
	
}

//Actor 생성
void Engine::SpawnActor()
{
	//Actor* newActor = new Actor();
	//Actors[0] = newActor;
	//위의 두 문장을 하나로 줄이면 아래 문장

	Actors[CountOfActors++] = new Actor();
}

//생성된 Actor 제거
void Engine::DestoryActor(int Index)
{
	delete Actors[Index];
	Actors[Index] = nullptr;
}

void Engine::Init()
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

void Engine::Reder()
{
}

void Engine::BeginOverlap()
{
}

void Engine::Term()
{
}
