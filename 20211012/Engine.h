#pragma once
class UEngine
{
public: // �����(������, �ٸ� ���α׷��� ����� ������)
	UEngine();
	~UEngine();

	/*
	*	������ ������
	*/

	void Run();

private: // ���� ���� �����ڰ� ���
	/* ������ ���� ���̸� true, �ƴϸ� false */
	bool blsRunning = false;

	void Init();
	void Term();

	void Input();
	void Tick();
	void Render();

	class UWorld* World;  // ���漱��, �����ͷ� ����(������ġ �ּ�). �� �ı��� �ʿ�!
						 // �������� ������ ��û, �޾Ƽ� ���.(new ������� �ʽ��ϴ�.)


}; 

