/*
	새로운 엔진을 만들려고 합니다. 우리가 만들려는 엔진은 초기화 기능이 있습니다.
	당연히 엔진 종료시 자료를 정리합니다.
	매 프레임에 실행하는 이벤트를 Tick이라고 합니다.
	최초 실행시 이벤트를 BeginPlay이라고 합니다.
	엔진은 또한 입력을 받고 화면에 렌더링을 합니다.
	엔진이 가지고 있는 객체들이 충돌을 처리하는 이벤트(BeginOverlop)가 있습니다.
	만든 엔진은 Actor라는 객체를 N개 가질 수 있습니다.
	Actor는 매 프레임마다 처리하는 걸 Tick이라고 합니다.
	Actor 최초 실행시 이벤트를 BeginPlay라고 합니다.
	Actor도 입력을 처리하고 렌더링을 하고 충돌 처리를 합니다.
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

	//Actors.push_back(new Actor()); // 액터를 하나 만들어 넣는다.
	//Actors.push_back(new Actor());
	//Actors.push_back(new Actor());
	//Actors.push_back(new Actor());

	//cout << Actors.size() << endl;

	//Actors.erase(Actors.begin()+0);

	//cout << Actors.size() << endl;

	Engine* Engine1 = new Engine();
	Actor*  Actor1  = new Actor();

	(*Engine1).RunEngine();
	Actor1->BeginPlay();

	Engine1->SpawnActor();
	Engine1->SpawnActor();

	Engine1->DestoryActor(0);

	delete Actor1;
	delete Engine1;

	return 0;
}