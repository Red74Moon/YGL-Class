#include <iostream>

#include "Engine.h"
#include "Actor.h"

using namespace std;

Engine::Engine()
{
	cout << "�ʱ�ȭ �մϴ�." << endl;
}

//���� ����� ���� �ȵ� ���� ����
Engine::~Engine()
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

void Engine::RunEngine()
{
	
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
