#include <stdio.h>
#include <Windows.h>
#include <process.h>

struct Test
{
	int a;
	int b;
};

unsigned WINAPI Thread(void* arg);

int main()
{
	Test test;

	test.a = 10;
	test.b = 20;

	HANDLE ThreadHandle;
	unsigned int threadID;

	ThreadHandle = (HANDLE)_beginthreadex(NULL, 0, Thread, &test, 0, &threadID);

	if (ThreadHandle == 0)
	{
		//can't create Thread
		printf("Error(Can't create Thread)");
		exit(-1);
	}

	printf("handle : %d\n", (int)ThreadHandle);

	Sleep(3000); // Sleep이 없으면 시작은 되었으나 함수가 실행되기전 끝나서 출력이 되지 않는다.

	return 0;
}

unsigned WINAPI Thread(void* arg)
{
	printf("Thread Start : %d\n", *(int*)arg);

	return 0;
}
