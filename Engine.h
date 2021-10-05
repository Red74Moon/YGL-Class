#pragma once
// ������ ������ �Է��� �ް� ó���ϰ�, ȭ�鿡 �׸���.
//  --������ �ʱ�ȭ �Ѵ�.			Initailize();
//  --������ �Է��� �޴´�.		Input();
//  --������ ó���Ѵ�.				Process();
//  --ȭ�鿡 �׸���.				Render();
//  --������ �����Ѵ�.(�����Ѵ�.)	Terminalize();
//   
class Engine
{
public:
	void Initailize();
	void Run();
	void Terminalize();

private:
	void Input();
	void Process();
	void Render();
};

