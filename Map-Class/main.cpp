#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

void Input();
void MapDraw();
void Process();
void MovePlayer(int XDirection, int YDirection);
bool IsGoal();
void StatusMassge();

int Map[3][10][10] = {
	{
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,0,0,0,0,1},
		{1,0,1,0,0,0,1,0,0,1},
		{1,0,1,0,0,0,1,0,0,1},
		{1,0,1,1,0,0,1,0,0,1},
		{1,0,0,0,0,0,1,0,0,1},
		{1,0,1,1,1,0,1,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,9,1}
	},
	{
		{1,9,1,1,1,1,1,1,8,1},
		{1,0,1,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,1,0,1},
		{1,0,1,0,1,1,1,1,0,1},
		{1,0,1,0,0,0,0,0,0,1},
		{1,0,1,0,0,0,0,1,0,1},
		{1,0,1,0,0,1,1,1,0,1},
		{1,0,1,1,0,0,0,1,0,1},
		{1,0,0,0,0,0,0,1,0,1},
		{1,1,1,1,1,1,1,1,1,1}
	},
	{
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,3,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,8,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
	}

};
int PlayerX = 4;
int PlayerY = 4;

int Key;
int ZMap = 0;

bool GameStauts = true;

int main()
{
	while (GameStauts)
	{
		MapDraw();
		Input();
		Process();
		MapDraw();
	}

	cout << endl << endl << endl << "���� Ż��" << endl << endl << endl;
	return 0;
}

void Input()
{
	Key = _getch();
	if (Key == 0x00 || Key == 0xE0)
	{
		Key = _getch();
	}
}

void MapDraw()
{
	system("cls");
	// ���� �׸���
	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			if (PlayerX == X && PlayerY == Y)
			{
				cout << "P" << " ";
			}
			else if (Map[ZMap][Y][X] == 0)
			{
				cout << " " << " ";
			}
			else if (Map[ZMap][Y][X] == 1)
			{
				cout << "X" << " ";
			}
			else if (Map[ZMap][Y][X] == 9)
			{
				cout << "N" << " ";
			}
			else if (Map[ZMap][Y][X] == 3)
			{
				cout << "G" << " ";
			}
			else if (Map[ZMap][Y][X] == 8)
			{
				cout << "B" << " ";
			}
		}
		cout << endl;
	}
	//���� �޽���
	StatusMassge();
}

void Process()
{
	//Ű�Է� �м�
	switch (Key)
	{
	case 'W':
	case 'w':
	{
		MovePlayer(0, -1);
		break;
	}
	case 'S':
	case 's':
	{
		MovePlayer(0, 1);
		break;
	}
	case 'A':
	case 'a':
	{
		MovePlayer(-1, 0);
		break;
	}
	case 'D':
	case 'd':
	{
		MovePlayer(1, 0);
		break;
	}
	break;
	}

	// ���� ���� Ȯ��
	if (IsGoal())
	{
		GameStauts = false;
	}

	// ���� �� �̵�
	if (Map[ZMap][PlayerY][PlayerX] == 9)
	{
		PlayerX = PlayerY = 4;
		ZMap++;
	}

	// ���� �� �̵�
	if (Map[ZMap][PlayerY][PlayerX] == 8)
	{
		PlayerX = PlayerY = 4;
		ZMap--;
	}
}

void MovePlayer(int XDirection, int YDirection)
{
	int NewPlayerX = PlayerX + XDirection;
	int NewPlayerY = PlayerY + YDirection;

	if (Map[ZMap][NewPlayerY][NewPlayerX] == 0 ||
		Map[ZMap][NewPlayerY][NewPlayerX] == 9 || // ���� �� N
		Map[ZMap][NewPlayerY][NewPlayerX] == 8 || // ���� �� B
		Map[ZMap][NewPlayerY][NewPlayerX] == 3)   // ���� G
	{
		PlayerX = NewPlayerX;
		PlayerY = NewPlayerY;
	}
}

bool IsGoal()
{
	// 3�̸� ���� ����
	return Map[ZMap][PlayerY][PlayerX] == 3 ? true : false;
}

void StatusMassge()
{
	cout << endl << "[ N : ���� �� / B : ���� �� ]" << endl;
	cout << "[ G : ������ / P : �÷��̾� ]" << endl;
	cout << endl << "[ MAP : " << ZMap + 1 << " ]" << endl;
}



