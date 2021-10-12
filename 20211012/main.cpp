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
	Engine.SpawnWall(FVector2D(0, 0));
	Engine.SpawnWall(FVector2D(1, 0));
	Engine.SpawnWall(FVector2D(2, 0));
	Engine.SpawnWall(FVector2D(3, 0));
	Engine.SpawnWall(FVector2D(4, 0));
	Engine.SpawnWall(FVector2D(5, 0));
	Engine.SpawnWall(FVector2D(6, 0));
	Engine.SpawnWall(FVector2D(7, 0));
	Engine.SpawnWall(FVector2D(8, 0));
	Engine.SpawnWall(FVector2D(9, 0));

	Engine.SpawnWall(FVector2D(0, 9));
	Engine.SpawnWall(FVector2D(1, 9));
	Engine.SpawnWall(FVector2D(2, 9));
	Engine.SpawnWall(FVector2D(3, 9));
	Engine.SpawnWall(FVector2D(4, 9));
	Engine.SpawnWall(FVector2D(5, 9));
	Engine.SpawnWall(FVector2D(6, 9));
	Engine.SpawnWall(FVector2D(7, 9));
	Engine.SpawnWall(FVector2D(8, 9));
	Engine.SpawnWall(FVector2D(9, 9));

	Engine.SpawnWall(FVector2D(0, 0));
	Engine.SpawnWall(FVector2D(0, 1));
	Engine.SpawnWall(FVector2D(0, 2));
	Engine.SpawnWall(FVector2D(0, 3));
	Engine.SpawnWall(FVector2D(0, 4));
	Engine.SpawnWall(FVector2D(0, 5));
	Engine.SpawnWall(FVector2D(0, 6));
	Engine.SpawnWall(FVector2D(0, 7));
	Engine.SpawnWall(FVector2D(0, 8));
	Engine.SpawnWall(FVector2D(0, 9));

	Engine.SpawnWall(FVector2D(9, 0));
	Engine.SpawnWall(FVector2D(9, 1));
	Engine.SpawnWall(FVector2D(9, 2));
	Engine.SpawnWall(FVector2D(9, 3));
	Engine.SpawnWall(FVector2D(9, 4));
	Engine.SpawnWall(FVector2D(9, 5));
	Engine.SpawnWall(FVector2D(9, 6));
	Engine.SpawnWall(FVector2D(9, 7));
	Engine.SpawnWall(FVector2D(9, 8));
	Engine.SpawnWall(FVector2D(9, 9));

	Engine.SpawnFloor(FVector2D(1, 1));

	Engine.SpawnPlayer(FVector2D(2, 2));
	
	Engine.SpawnGoal(FVector2D(1, 1));

	Engine.Run();
	
	//delete Engine;

	return 0;
}