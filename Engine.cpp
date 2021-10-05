#include "Engine.h"
#include <iostream>
using namespace std;

Engine::Engine()
{
	cout << "������ ���� �Ǿ����ϴ�." << endl;
	Initailize();
}

Engine::~Engine()
{
	Terminalize();
	cout << "������ �ı� �Ǿ����ϴ�." << endl;
}

void Engine::Initailize()
{
	cout << "�ʱ�ȭ �Ǿ����ϴ�." << endl;
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
	cout << "���� �Ǿ����ϴ�." << endl;
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
