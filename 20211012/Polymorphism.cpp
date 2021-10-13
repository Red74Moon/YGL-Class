// 플레이어는 골드와 HP와 MP를 가지고 있고, 골드를 모을 수 있습니다.
// 플레이어는 이동할 수 있고, 몬스터를 공격할 수 있습니다.
// 몬스터는 HP, MP를 가지고 있고 
// 종류에는 고블린, 멧되지, 슬라임이 있습니다.
// 몬스터는 이동 할 수 있고, 플레이어를 공격 할 수 있고, 도망 갈 수 있습니다.
// 앞의 내용을 보고 클래스의 상속을 이용하여 설계 해 보세요.

#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

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

	virtual void Move() = 0;  // 순수가상함수(인터페이스), 
							  // 바로 생성이 안되고 상속 후에 생성이 된다.
	//virtual void Attack();
	//virtual void Back();

protected:
	//int Hp;
	//int Mp;
	//int Gold;

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
		cout << "Player 이동" << endl;
	}
	//void Attack() override;
	//void Back()   override;

	//void SetHp(int NewHp)
	//{
	//	Hp = NewHp;
	//}
	//int GetHp()
	//{
	//	return Hp;
	//}

	//void SetMp(int NewMp)
	//{
	//	NewMp = Mp;
	//}
	//int GetMp()
	//{
	//	return Mp;
	//}

	//void SetGold(int NewGold)
	//{
	//	NewGold = Gold;
	//}
	//int GetGold()
	//{
	//	return Gold;
	//}
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
		cout << "Monster 이동" << endl;
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

	virtual void Move() override
	{
		cout << "Goblin 이동" << endl;
	}
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

	virtual void Move() override
	{
		cout << "Hog 이동" << endl;
	}
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

	virtual void Move() override
	{
		cout << "Slime 이동" << endl;
	}
};


int main()
{
	vector<Character*> Characters;

	Characters.push_back(new Player());


	srand(time(nullptr));

	for (size_t i=0; i < 10; ++i)
	{
		int Type = rand() % 3;
		if (Type == 0)
		{
			Characters.push_back(new Goblin());
		}
		else if (Type == 1)
		{
			Characters.push_back(new Slime());
		}
		else 
		{
			Characters.push_back(new Hog());
		}
	}

	//for (size_t i = 0; i < Characters.size(); ++i)
	//{
	//	Characters[i]->Move();
	//}

	//for (auto PlayCharacter : Characters)
	//{
	//	PlayCharacter->Move();
	//}

	for (auto iter = Characters.begin(); iter != Characters.end(); ++iter)
	{
		(*iter)->Move();
	}


	return 0;
}