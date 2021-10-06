#include <iostream>

#include "Engine.h"

using namespace std;

Engine::Engine()
{
	cout << "초기화 합니다." << endl;
}

Engine::~Engine()
{
	cout << "자료를 정리합니다." << endl;
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
