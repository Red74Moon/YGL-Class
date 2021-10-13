#pragma once

#include <vector>
#include "Vector2D.h"

class APlayer;
class AFloor;
class AGoal;
class AWall;

class UWorld
{
public:
	UWorld();
	~UWorld();

	void Init();
	void Term();
	void Run();

	void AddPlayer(APlayer* NewPlayer);
	void AddWall(AWall* NewWall);
	void AddFloor(AFloor* NewFloor);
	void AddGoal(AGoal* NewGoal);

private:
	std::vector<AWall*> Walls;
	std::vector<AFloor*> Floors;

	APlayer* Player;
	AGoal* Goal;
};

