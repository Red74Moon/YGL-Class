#include "Engine.h"
#include <iostream>
using namespace std;

void Engine::Initailize()
{
}

//1Frame ���� 1/60s
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
	cout << "�����Ѵ�." << endl;
}

void Engine::Input()
{
	cout << "�Է� �޴´�." << endl;
}

void Engine::Process()
{
	cout << "ó�� �޴´�." << endl;
}

void Engine::Render()
{
	cout << "������ �޴´�." << endl;
}
