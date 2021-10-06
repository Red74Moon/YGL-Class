#include <iostream>
#include <vector> 

using namespace std;

template<typename T>

T Add(T a, T b)
{
	return a + b;
}

int main()
{
	int c = 2;
	int d = 3;

	cout << Add<int>(c, d) << endl;
	cout << Add<float>(3.0f, 4.4f) << endl;

	return 0;
}