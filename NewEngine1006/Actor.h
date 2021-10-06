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

	void ActorTick();
	void ActorBeginPlay();
	void ActorBeginOverlap();

private:
	void ActorInput();
	void ActorRendering();
};