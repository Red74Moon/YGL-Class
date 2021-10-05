#pragma once
// 엔진은 유저의 입력을 받고 처리하고, 화면에 그린다.
//  --엔진은 초기화 한다.			Initailize();
//  --유저의 입력을 받는다.		Input();
//  --정보를 처리한다.				Process();
//  --화면에 그린다.				Render();
//  --엔진은 정리한다.(종료한다.)	Terminalize();
//   
class Engine
{
public:
	Engine(); // 생성자 - Default Constructor
	~Engine(); // 파괴자 - Destructor

	void Run();
	
private:
	void Initailize();
	void Terminalize();

	void Input();
	void Process();
	void Render();
	
};

