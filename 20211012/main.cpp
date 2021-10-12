//»ó¼Ó

#include <iostream>
#include "Engine.h"

using namespace std;

int main()
{
	UEngine* Engine = new UEngine();

	Engine->Run();

	delete Engine;

	return 0;
}