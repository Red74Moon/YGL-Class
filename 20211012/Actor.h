#pragma once
#include "Vector2D.h"

class AActor
{
public:
	AActor();
	~AActor();

	void input();
	void Tick();
	virtual void Render(); // �ڽ��� ���� �Լ��� ������ �ڽİ��� ����Ѵ�.

	//Accessor
	void SetLocation(FVector2D NewLocatoin);
	FVector2D GetLocation();

private: // ��� ���� ��.

protected: // ����� �ϰ�, �ۿ��� �� ��
	//  ��ǥ
	FVector2D Location;
};

