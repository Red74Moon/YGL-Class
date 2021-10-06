//STL

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// 문자열 자르기

	string HelloWorld = "Hello World";
	
	int size = HelloWorld.size();
	int i;
	
	for (i = 0; i < size; ++i)
	{
		if (HelloWorld[i] == ' ')
		{
			break;
		}
	}

	for (auto S : HelloWorld)
	{
		cout << static_cast<char>(toupper(S));
	}

	cout << endl;
	cout << HelloWorld.substr(i+1, size-i) << endl;

	return 0;
}