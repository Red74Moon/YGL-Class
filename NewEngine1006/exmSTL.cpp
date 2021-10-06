//STL

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// 문자열 자르기, 대문자로 변경하기 //euc-kr(한글작업잘되게), utf-8(모든언어가 작업잘되게)-다국어지원

	string HelloWorld = "Hello World";
	
	int size = HelloWorld.size();
	int i;
	string Capital = "";
	string LowerCase = "";

	for (i = 0; i < size; ++i)
	{
		if (HelloWorld[i] == ' ')
		{
			break;
		}
	}

	for (auto S : HelloWorld)
	{
		Capital.push_back(toupper(S));
		cout << static_cast<char>(toupper(S));
	}
	cout << endl;
	for (auto S : HelloWorld)
	{
		LowerCase.push_back(tolower(S));
		cout << static_cast<char>(tolower(S));
	}

	cout << endl;
	cout << HelloWorld.substr(i+1, size-i) << endl;

	return 0;
}