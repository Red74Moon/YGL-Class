#include <stdio.h>
#include <Windows.h>
#include <process.h>

unsigned WINAPI ThreadIncrease(void* arg);
unsigned WINAPI ThreadDecrease(void* arg);

int Gold = 0;

int main()
{
	HANDLE ThreadHandle[2];
	unsigned int threadID;

	ThreadHandle[0] = (HANDLE)_beginthreadex(NULL, 0, ThreadIncrease, NULL, 0, &threadID);
	ThreadHandle[1] = (HANDLE)_beginthreadex(NULL, 0, ThreadDecrease, NULL, 0, &threadID);

	WaitForMultipleObjects(2, ThreadHandle, TRUE, INFINITE);

	printf("\nGold : %d\n", Gold);

	return 0;
}

unsigned WINAPI ThreadIncrease(void* arg)
{
	for (int i = 0; i < 1000; ++i)
	{
		Gold = Gold + 1;
		printf("Increase Gold : %d\n", Gold);
	}
	return 0;
}
unsigned WINAPI ThreadDecrease(void* arg)
{
	for (int i = 0; i < 1000; ++i)
	{
		Gold = Gold - 1;
		printf("Decrease Gold : %d\n", i);
	}
	return 0;
}
