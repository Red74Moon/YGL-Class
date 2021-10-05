#include <iostream>
#include <string>

#include "player.h"
#include "Map.h"
#include "Engine.h"

using namespace std;

int main()
{
	Engine  engine;

	engine.Initailize();
	engine.Run();
	engine.Terminalize();

	return 0;
}