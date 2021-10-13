//»ó¼Ó

#include <iostream>

#include "Engine.h"

#include "Player.h"
#include "Floor.h"
#include "Wall.h"
#include "Goal.h"

using namespace std;

int main()
{
	UEngine Engine;

	bool Result = Engine.LoadLevel("map01.txt");
	if (Result)
	{
		cout << "fail load mapdata." << endl;
		return 1;
	}

	Engine.Run();

	return 0;
}