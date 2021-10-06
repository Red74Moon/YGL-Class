#pragma once
/*
	BeginOverlap
	BeginPlay
	Tick
	Input
	Render
*/
class Actor
{
public:
	Actor();
	~Actor();

	void Tick();
	void BeginPlay();
	void BeginOverlap();

private:
	void Input();
	void Render();
};