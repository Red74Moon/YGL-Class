#pragma once

#include <vector>

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

private:
	std::vector<AWall*> Walls;
	std::vector<AFloor*> Floors;

	APlayer* Player;
	AGoal* Goal;
	
};

