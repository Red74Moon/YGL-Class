#include "Actor.h"
#include <iostream>

using namespace std;


Actor::Actor()
{
	cout << "Avtor ����" << endl;
}

Actor::~Actor()
{
	cout << "Avtor �ı�" << endl;
}

void Actor::Tick()
{
	cout << "Actor Tick" << endl;
}

void Actor::BeginPlay()
{
	cout << "Actor beginplay" << endl;
}

void Actor::Input()
{
	cout << "Actor input" << endl;
}

void Actor::Render()
{
	cout << "Actor render" << endl;
}

void Actor::BeginOverlap()
{
}
