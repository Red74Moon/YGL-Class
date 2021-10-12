//»ó¼Ó

#include <iostream>
#include "Engine.h"

#include "Player.h"
#include "Floor.h"
#include "Wall.h"
#include "Goal.h"

using namespace std;


int main()
{
	//UEngine* Engine = new UEngine();
	UEngine Engine;

	FVector2D NewLocation;
	
	NewLocation.X = 1;
	NewLocation.Y = 1;



	Engine.Run();
	
	//delete Engine;

	return 0;
}