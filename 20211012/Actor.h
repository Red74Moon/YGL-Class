#pragma once
#include "Vector2D.h"

//��� X
// public: ��� ��� ����
//private: ���� ���  �����

//���
//public: ��� ��� ����, ��� ����
//private: ���� ���  �����, ��� ������
//protected: ���� ��� �����, ��� ����

//�������� �۾��Ѵ�.
// ������ �ִ� class�߿��� ��� �� Ŭ������ ����
// ��� �� class�� ��� �޾Ƽ� ���ϴ� class�� �����
// ���� ���� class�� �� ��� ������ �߰�

class AActor
{
public:
	AActor();
	~AActor();

	void input();
	void Tick();
	virtual void Render(); // �ڽ��� ���� �Լ��� ������ �ڽİ��� ����Ѵ�.
						   // override

	//Accessor
	void SetLocation(FVector2D NewLocatoin);
	FVector2D GetLocation();

private: // ��� ���� ��.

protected: // ����� �ϰ�, �ۿ��� ���� �Ұ�
	//  ��ǥ
	FVector2D Location;
};

