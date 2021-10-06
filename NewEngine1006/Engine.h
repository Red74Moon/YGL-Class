#pragma once

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
	void Initialize();
	void BeginPlay();
	void Tick();
	void Input();
	void Redering();
	void BeginOverlap();
	void Terminalize();

	Actor* Actors[10];

	int CountofActors = 0;
};


