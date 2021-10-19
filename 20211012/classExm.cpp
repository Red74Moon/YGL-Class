#include <iostream>

using namespace std;



class Animal
{
public:
	int Legs = 4;
	int face = 1;
	int ears = 2;

	void Sound();
	void FavoritFood();
	void Move();
};

// Cat is a Animal
class Cat : public Animal
{
public:
};

class Dog : public Animal
{
public:
	
};

class Duck : public Animal
{
public:
	int wings = 2;
};

int main()
{
	return 0;
}