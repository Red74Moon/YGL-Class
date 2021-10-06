#pragma once

#include "Actor.h"

class Engine
{
public:
	Engine();
	~Engine();

	void Tick();
	void Input();
	void Redering();
	void BeginOverlap();
	
	Actor actor[10];
	
};


