//STL

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// ���ڿ� �ڸ���, �빮�ڷ� �����ϱ� //euc-kr(�ѱ��۾��ߵǰ�), utf-8(���� �۾��ߵǰ�)-�ٱ�������

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