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

	void RunEngine();
	void SpawnActor();
	void DestoryActor(int Index);
	
private:
	void Init();
	void BeginPlay();
	void Tick();
	void Input();
	void Reder();
	void BeginOverlap();
	void Term();

	//Actor* Actors[10]; 
	vector<Actor*> Actors;

	int CountOfActors = 0;
};


