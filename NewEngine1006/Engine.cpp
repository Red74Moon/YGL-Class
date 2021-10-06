#include <iostream>

#include "Engine.h"
#include "Actor.h"

using namespace std;

Engine::Engine()
{
	Init();
	cout << "�ʱ�ȭ �մϴ�." << endl;
}

//���� ����� ���� �ȵ� ���� ����
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

//Actor ����
void Engine::SpawnActor()
{
	//Actor* newActor = new Actor();
	//Actors[0] = newActor;
	//���� �� ������ �ϳ��� ���̸� �Ʒ� ����

	//Actors[CountOfActors++] = new Actor();
	Actors.push_back(new Actor());
}

//������ Actor ����
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
	cout << "���� ó�� �����Դϴ�." << endl;
}

void Engine::Tick()
{
	if (bFirstRun)
	{
		bFirstRun = false;
		BeginPlay();
	}
	cout << "���� Tick �����Դϴ�." << endl;
	for (size_t i = 0; i < Actors.size(); ++i)
	{
		Actors[i]->Tick(); 
	}
}

void Engine::Input()
{
	for (size_t i = 0; i < Actors.size(); ++i)
	{
		Actors[i]->Input();
	}
	cout << "������ �Է� �����Դϴ�." << endl;
}

void Engine::Render()
{
	for (size_t i = 0; i < Actors.size(); ++i)
	{
		Actors[i]->Render();
	}
	cout << "������ ������ �����Դϴ�." << endl;
}

void Engine::BeginOverlap()
{
}

void Engine::Term()
{
	//for (int i = 0; i < CountOfActors; ++i)
	//�� ����
	for (size_t i = 0; i < Actors.size(); ++i)
	{
		//if (Actors[i] != nullptr) // ���� ���͸� ����Ű�� �ε����� nullptr���� Ȯ��
		//{
		delete Actors[i];
		//}
	}
	Actors.clear();

	cout << "�ڷḦ �����մϴ�." << endl;
}
