#pragma once
#include "Vector2D.h"

//상속 X
// public: 모두 사용 공개
//private: 나만 사용  비공개

//상속
//public: 모두 사용 공개, 상속 해줌
//private: 나만 사용  비공개, 상속 안해줌
//protected: 가족 사용 비공개, 상속 해줌

//엔진으로 작업한다.
// 엔진에 있는 class중에서 사용 할 클래스를 선택
// 사용 할 class를 상속 받아서 원하는 class를 만들고
// 새로 만든 class에 새 기능 구현을 추가

class AActor
{
public:
	AActor();
	~AActor();

	void input();
	void Tick();
	virtual void Render(); // 자식이 같은 함수가 있으면 자식것을 사용한다.
						   // override

	//Accessor
	void SetLocation(FVector2D NewLocatoin);
	FVector2D GetLocation();

private: // 상속 안해 줌.

protected: // 상속은 하고, 밖에서 접속 불가
	//  좌표
	FVector2D Location;
};

