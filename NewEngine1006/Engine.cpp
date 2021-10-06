#include <iostream>

#include "Engine.h"
#include "Actor.h"

using namespace std;

Engine::Engine()
{
	Init();
	cout << "초기화 합니다." << endl;
}

//엔진 종료시 제거 안된 액터 지움
Engine::~Engine()
{
	Term();
	
}

void Engine::Run()
{
	while (blsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

//Actor 생성
void Engine::SpawnActor()
{
	//Actor* newActor = new Actor();
	//Actors[0] = newActor;
	//위의 두 문장을 하나로 줄이면 아래 문장

	//Actors[CountOfActors++] = new Actor();
	Actors.push_back(new Actor());
}

//생성된 Actor 제거
void Engine::DestoryActor(int Index)
{
	delete Actors[Index];
	
	//Actors[Index] = nullptr;
	Actors.erase(Actors.begin() + Index);
}

void Engine::Init()
{
}

void Engine::BeginPlay()
{
	cout << "엔진 처음 실행입니다." << endl;
}

void Engine::Tick()
{
	if (bFirstRun)
	{
		bFirstRun = false;
		BeginPlay();
	}
}

void Engine::Input()
{
}

void Engine::Render()
{
}

void Engine::BeginOverlap()
{
}

void Engine::Term()
{
	//for (int i = 0; i < CountOfActors; ++i)
	//힙 삭제
	for (size_t i = 0; i < Actors.size(); ++i)
	{
		//if (Actors[i] != nullptr) // 지울 액터를 가리키는 인덱스가 nullptr인지 확인
		//{
		delete Actors[i];
		//}
	}
	Actors.clear();

	cout << "자료를 정리합니다." << endl;
}
