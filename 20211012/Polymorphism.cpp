// �÷��̾�� ���� HP�� MP�� ������ �ְ�, ��带 ���� �� �ֽ��ϴ�.
// �÷��̾�� �̵��� �� �ְ�, ���͸� ������ �� �ֽ��ϴ�.
// ���ʹ� HP, MP�� ������ �ְ� 
// �������� ���, �����, �������� �ֽ��ϴ�.
// ���ʹ� �̵� �� �� �ְ�, �÷��̾ ���� �� �� �ְ�, ���� �� �� �ֽ��ϴ�.
// ���� ������ ���� Ŭ������ ����� �̿��Ͽ� ���� �� ������.

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
		cout << "Character ����" << endl;
	}
	virtual ~Character()
	{
		cout << "Character �Ҹ�" << endl;
	}

	virtual void Move() = 0;  // ���������Լ�(�������̽�), 
							  // �ٷ� ������ �ȵǰ� ��� �Ŀ� ������ �ȴ�.

protected:


private:
};


class Player : public Character
{
public:
	Player()
	{
		cout << "Player ����" << endl;
	}
	virtual ~Player()
	{
		cout << "Player �Ҹ�" << endl;
	}

	virtual void Move() override
	{
		cout << "Player �̵�" << endl;
	}
};

class Monster : public Character
{
public:
	Monster()
	{
		cout << "Monster ����" << endl;
	}
	virtual ~Monster()
	{
		cout << "Monster �Ҹ�" << endl;
	}

	virtual void Move() override
	{
		cout << "Monster �̵�" << endl;
	}
};

class Goblin : public Monster
{
public:
	Goblin()
	{
		cout << "Goblin ����" << endl;
	}
	virtual ~Goblin()
	{
		cout << "Goblin �Ҹ�" << endl;
	}

	virtual void Move() override
	{
		cout << "Goblin �̵�" << endl;
	}
};

class Hog : public Monster
{
public:
	Hog()
	{
		cout << "Hog ����" << endl;
	}
	virtual ~Hog()
	{
		cout << "Hog �Ҹ�" << endl;
	}

	virtual void Move() override
	{
		cout << "Hog �̵�" << endl;
	}
};

class Slime : public Monster
{
public:
	Slime()
	{
		cout << "Slime ����" << endl;
	}
	virtual ~Slime()
	{
		cout << "Slime �Ҹ�" << endl;
	}

	virtual void Move() override
	{
		cout << "Slime �̵�" << endl;
	}
};


int main()
{
	vector<Character*> Characters;

	Characters.push_back(new Player());


	srand(static_cast<int>(time(nullptr)));

	for (size_t i = 0; i < 10; ++i)
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

	// �Ʒ� for���� �����ϴ�.
	// 
	//for (size_t i = 0; i < Characters.size(); ++i)
	//{
	//	Characters[i]->Move();
	//}

	//for (auto PlayCharacter : Characters)
	//{
	//	PlayCharacter->Move();
	//}
	// 
	//for (Character* PlayCharacter : Characters)
	//{
	//	PlayCharacter->Move();
	//}
	// 
	//for (vector<Character*>::iterator iter = Characters.begin(); iter != Characters.end(); ++iter)
	//{
	//	(*iter)->Move();
	//}
	//
	for (auto iter = Characters.begin(); iter != Characters.end(); ++iter)
	{
		(*iter)->Move();
	}

	return 0;
}