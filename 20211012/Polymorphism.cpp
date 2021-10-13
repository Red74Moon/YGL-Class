// �÷��̾�� ���� HP�� MP�� ������ �ְ�, ��带 ���� �� �ֽ��ϴ�.
// �÷��̾�� �̵��� �� �ְ�, ���͸� ������ �� �ֽ��ϴ�.
// ���ʹ� HP, MP�� ������ �ְ� 
// �������� ���, �����, �������� �ֽ��ϴ�.
// ���ʹ� �̵� �� �� �ְ�, �÷��̾ ���� �� �� �ְ�, ���� �� �� �ֽ��ϴ�.
// ���� ������ ���� Ŭ������ ����� �̿��Ͽ� ���� �� ������.

#include <iostream>

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

	virtual void Move() = 0;  // ���������Լ�, ��� �޾Ƽ��� ���� �� �ִ�.
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
		cout << "Player ����" << endl;
	}
	virtual ~Player()
	{
		cout << "Player �Ҹ�" << endl;
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
		cout << "Monster ����" << endl;
	}
	virtual ~Monster()
	{
		cout << "Monster �Ҹ�" << endl;
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
		cout << "Goblin ����" << endl;
	}
	virtual ~Goblin()
	{
		cout << "Goblin �Ҹ�" << endl;
	}

	//void Move();
};

class Hog : public Monster
{
public:
	Hog()
	{
		cout << "Hog ����" << endl;
	}
	~Hog()
	{
		cout << "Hog �Ҹ�" << endl;
	}

	//void Move();
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

	//void Move();
};

//void Actor::Move()
//{
//	cout << "��� ������" << endl;
//}

int main()
{
	Character* character = new Player();
	Character* AGoblin   = new Goblin();


	delete AGoblin;

	return 0;
}