// 플레이어는 골드와 HP와 MP를 가지고 있고, 골드를 모을 수 있습니다.
// 플레이어는 이동할 수 있고, 몬스터를 공격할 수 있습니다.
// 몬스터는 HP, MP를 가지고 있고 
// 종류에는 고블린, 멧되지, 슬라임이 있습니다.
// 몬스터는 이동 할 수 있고, 플레이어를 공격 할 수 있고, 도망 갈 수 있습니다.
// 앞의 내용을 보고 클래스의 상속을 이용하여 설계 해 보세요.

#include <iostream>

using namespace std;

class Character
{
public:
	Character()
	{
		cout << "Character 생성" << endl;
	}
	virtual ~Character()
	{
		cout << "Character 소멸" << endl;
	}

	virtual void Move() = 0;  // 순수가상함수, 상속 받아서만 만들 수 있다.
	//virtual void Attack();
	//virtual void Back();

protected:
	int Hp;
	int Mp;
	int Gold;

private:
};


class Player : public Character
{
public:
	Player()
	{
		cout << "Player 생성" << endl;
	}
	virtual ~Player()
	{
		cout << "Player 소멸" << endl;
	}

	virtual void Move() override
	{

	}
	//void Attack() override;
	//void Back()   override;

	void SetHp(int NewHp)
	{
		Hp = NewHp;
	}
	int GetHp()
	{
		return Hp;
	}

	void SetMp(int NewMp)
	{
		NewMp = Mp;
	}
	int GetMp()
	{
		return Mp;
	}

	void SetGold(int NewGold)
	{
		NewGold = Gold;
	}
	int GetGold()
	{
		return Gold;
	}
};

class Monster : public Character
{
public:
	Monster()
	{
		cout << "Monster 생성" << endl;
	}
	virtual ~Monster()
	{
		cout << "Monster 소멸" << endl;
	}

	virtual void Move() override
	{

	}
	//virtual void Attack() override;
	//virtual void Back()   override;

	//void SetHp(int NewMonsterHp)
	//{
	//	Hp = NewMonsterHp;
	//}
	//int GetHp()
	//{
	//	return Hp;
	//}

	//void SetMp(int NewMonsterMp)
	//{
	//	NewMonsterMp = Mp;
	//}
	//int GetMp()
	//{
	//	return Mp;
	//}
};

class Goblin : public Monster
{
public:
	Goblin()
	{
		cout << "Goblin 생성" << endl;
	}
	virtual ~Goblin()
	{
		cout << "Goblin 소멸" << endl;
	}

	//void Move();
};

class Hog : public Monster
{
public:
	Hog()
	{
		cout << "Hog 생성" << endl;
	}
	~Hog()
	{
		cout << "Hog 소멸" << endl;
	}

	//void Move();
};

class Slime : public Monster
{
public:
	Slime()
	{
		cout << "Slime 생성" << endl;
	}
	virtual ~Slime()
	{
		cout << "Slime 소멸" << endl;
	}

	//void Move();
};

//void Actor::Move()
//{
//	cout << "고블린 움직임" << endl;
//}

int main()
{
	Character* character = new Player();
	Character* AGoblin   = new Goblin();


	delete AGoblin;

	return 0;
}