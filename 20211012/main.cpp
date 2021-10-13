//»ó¼Ó

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Engine.h"
#include "Player.h"
#include "Floor.h"
#include "Wall.h"
#include "Goal.h"

using namespace std;
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;

int main()
{
	ifstream fin; 
	fin.open("map01.txt"); 
	string line; 
	while (!fin.eof()) 
	{ 
		getline(fin, line); 
		cout << line << endl; 
	} 
	fin.close();


}