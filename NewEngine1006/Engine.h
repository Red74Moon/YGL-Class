#pragma once

#include <vector> 

using namespace std;

/*
	√ ±‚»≠
	√—∑·
	Tick
	BeginPlay
	Input
	Render
	BegineOverlap
*/

class Actor;

class Engine
{
public:
	Engine();
	~Engine();

	void Run();
	void SpawnActor();
	void DestoryActor(int Index);
	
private:
	void Init();
	void BeginPlay();
	void Tick();
	void Input();
	void Render();
	void BeginOverlap();
	void Term();

	//Actor* Actors[10]; 
	vector<Actor*> Actors;

	//int CountOfActors = 0;

	bool blsRunning = true;
	bool bFirstRun  = true;
};


