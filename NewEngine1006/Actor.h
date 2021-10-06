#pragma once
class Actor
{
public:
	Actor();
	~Actor();

	void Tick();
	void BeginPlay();
	void Input();
	void Rendering();
};

