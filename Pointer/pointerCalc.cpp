#include <iostream>

using namespace std;
class Result
{
public:
	int Add;
	int Mul;
	int Div;
	int Min;

	void Execute();
};

void Calculate(int a, int b, Result* ResultPointer)
{
	ResultPointer->Add = a + b;
	(*ResultPointer).Mul = a - b;
	(*ResultPointer).Div = a * b;
	(*ResultPointer).Min = a / b;
	ResultPointer->Execute();
}

int main()
{	
	Result r1;

	

	Result* ResultPointer = new Result();
	int* IntPointer = new int();


	Calculate(2, 3, ResultPointer);

	cout << (*ResultPointer).Add << endl;
	cout << ResultPointer->Add << endl;


	delete ResultPointer;
	delete IntPointer;

	return 0;
}

void Result::Execute()
{
}