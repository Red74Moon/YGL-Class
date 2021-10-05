#include <iostream>

#include "Engine.h"
#include "player.h"
#include "Map.h"
using namespace std;

Engine::Engine()
{
	cout << "엔진이 생성 되었습니다." << endl;
	Initailize();
}

Engine::~Engine()
{
	Terminalize();
	cout << "엔진이 파괴 되었습니다." << endl;
}

void Engine::Initailize()
{
	cout << "초기화 되었습니다." << endl;
}

//1Frame 생성 1/60s
void Engine::Run()
{
	while (true)
	{
		Input();
		Process();
		Render();
	}
}

void Engine::Terminalize()
{
	cout << "종료 되었습니다." << endl;
}

void Engine::Input()
{
	cout << "입력 받는다." << endl;
}

void Engine::Process()
{
	cout << "처리 받는다." << endl;
}

void Engine::Render()
{
	cout << "렌더링 받는다." << endl;
}
