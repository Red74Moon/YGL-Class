#include <iostream>
#include <vector> 

using namespace std;

template<typename T, typename T1, typename T2>

T2 Add(T a, T1 b)
{
	return static_cast<T>(a + b);
}

// template class -- ���°� �ٲ�� Ŭ����
template<typename T>  // vector�� �̷��� �����̴�.
class NumberStore
{
public:
	T Store[100];
};

//�Լ� �����ε�
int Add(int a, int b)
{
	return a + b;
}

float Add(float a, float b)
{
	return a + b;
}

int main()
{
	NumberStore<int> IntStore;
	NumberStore<float> FloatStore;

	FloatStore.Store[0] = 10.0f;
	IntStore.Store[0] = 10;

	int c = 2;
	int d = 3;

	cout << Add<int, int, int>(c, d) << endl;
	cout << Add<int, float, float>(2, 3.0f) << endl;

	cout << FloatStore.Store[0] << endl;
	cout << IntStore.Store[0] << endl;

	return 0;
}