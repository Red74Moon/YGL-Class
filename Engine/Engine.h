#pragma once

// ������ ������ �Է��� �ް� ó���ϰ�, ȭ�鿡 �׸���.
// �츮 ������ �÷��̾ ������ �ְ� �ʵ� ������ �ִ�.
//  --������ �ʱ�ȭ �Ѵ�.			Initailize();
//  --������ �Է��� �޴´�.		Input();
//  --������ ó���Ѵ�.				Process();
//  --ȭ�鿡 �׸���.				Render();
//  --������ �����Ѵ�.(�����Ѵ�.)	Terminalize();
//   
class Engine
{
public:
	Engine();  // ������ - Default Constructor
	~Engine(); // �ı��� - Destructor

	class Player* player;
	class Map* map;

	void Run();
	
private:
	void Initailize();
	void Terminalize();

	void Input();
	void Process();
	void Render();
	
};

