/*
	���ο� ������ ������� �մϴ�. �츮�� ������� ������ �ʱ�ȭ ����� �ֽ��ϴ�.
	�翬�� ���� ����� �ڷḦ �����մϴ�.
	�� �����ӿ� �����ϴ� �̺�Ʈ�� Tick�̶�� �մϴ�.
	������ ���� �Է��� �ް� ȭ�鿡 �������� �մϴ�.
	������ ������ �ִ� ��ü���� �浹�� ó���ϴ� �̺�Ʈ(BeginOverlop)�� �ֽ��ϴ�.
	���� ������ Actor��� ��ü�� 10�� ���� �� �ֽ��ϴ�.
	Actor�� �� �����Ӹ��� ó���ϴ� �� Tick�̶�� �մϴ�.
	Actor ���� ����� �̺�Ʈ�� BeginPlay��� �մϴ�.
	Actor�� �Է��� ó���ϰ� �������� �ϰ� �浹 ó���� �մϴ�.
*/

#include <iostream>

#include "Engine.h"
#include "Actor.h"

using namespace std;

int main()
{
	Engine* Engine1 = new Engine();
	Actor* Actor1 = new Actor();



	delete Actor1;
	delete Engine1;

	return 0;
}