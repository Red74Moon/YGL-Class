#pragma once
class Engine
{
public:
	Engine();
	~Engine();

	void Tick();
	void Input();
	void Redering();
	void BeginOverlap();
};


