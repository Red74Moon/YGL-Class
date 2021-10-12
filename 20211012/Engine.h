#pragma once

#include "Vector2D.h"
#include "Actor.h"
#include "World.h"
#include <iostream>

class UEngine
{
public: // 사용자(개발자, 다른 프로그램을 만드는 개발자)
	UEngine();
	~UEngine();

	/*
	*	엔진을 실행함
	*/

	void Run();

	void SpawnPlayer(FVector2D NewLocation);
	void SpawnWall(FVector2D NewLocation);
	void SpawnGoal(FVector2D NewLocation);
	void SpawnFloor(FVector2D NewLocation);


private: // 실제 엔진 개발자가 사용
	/* 엔진이 실행 중이면 true, 아니면 false */
	bool blsRunning = false;

	void Init();
	void Term();

	void Input();
	void Tick();
	void Render();

	class UWorld* World;  // 전방선언, 포인터로 생성(시작위치 주소). 꼭 파괴자 필요!
						 // 엔진에게 생성을 요청, 받아서 사용.(new 사용하지 않습니다.)


}; 


