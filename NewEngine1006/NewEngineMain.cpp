/*
	���ο� ������ ������� �մϴ�. �츮�� ������� ������ �ʱ�ȭ ����� �ֽ��ϴ�.
	�翬�� ���� ����� �ڷḦ �����մϴ�.
	�� �����ӿ� �����ϴ� �̺�Ʈ�� Tick�̶�� �մϴ�.
	���� ����� �̺�Ʈ�� BeginPlay�̶�� �մϴ�.
	������ ���� �Է��� �ް� ȭ�鿡 �������� �մϴ�.
	������ ������ �ִ� ��ü���� �浹�� ó���ϴ� �̺�Ʈ(BeginOverlop)�� �ֽ��ϴ�.
	���� ������ Actor��� ��ü�� N�� ���� �� �ֽ��ϴ�.
	Actor�� �� �����Ӹ��� ó���ϴ� �� Tick�̶�� �մϴ�.
	Actor ���� ����� �̺�Ʈ�� BeginPlay��� �մϴ�.
	Actor�� �Է��� ó���ϰ� �������� �ϰ� �浹 ó���� �մϴ�.
*/

#include <iostream>
#include <vector> // STL

#include "Engine.h"
#include "Actor.h"

using namespace std;

//int Tmep(Engine* Engine1)
//{
//	Engine1->RunEngine();
//}


int main()
{
	//vector<Actor*> Actors;

	//Actors.push_back(new Actor()); // ���͸� �ϳ� ����� �ִ´�.
	//Actors.push_back(new Actor());
	//Actors.push_back(new Actor());
	//Actors.push_back(new Actor());

	//cout << Actors.size() << endl;

	//Actors.erase(Actors.begin()+0);

	//cout << Actors.size() << endl;

	Engine* Engine1 = new Engine();
	Actor*  Actor1  = new Actor();

	(*Engine1).Run();
	Actor1->BeginPlay();

	Engine1->SpawnActor();
	Engine1->SpawnActor();

	Engine1->DestoryActor(0);

	delete Actor1;
	delete Engine1;

	return 0;
}