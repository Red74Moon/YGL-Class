#include "Engine.h"
#include <iostream>
using namespace std;

void Engine::Initailize()
{
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
	cout << "종료한다." << endl;
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
