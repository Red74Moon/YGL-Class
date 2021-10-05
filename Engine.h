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
	Engine(); // ������ - Default Constructor
	~Engine(); // �ı��� - Destructor

	void Run();
	
private:
	void Initailize();
	void Terminalize();

	void Input();
	void Process();
	void Render();
	
};

