#include <stdio.h>
#include <Windows.h>
#include <process.h>

unsigned WINAPI ThreadIncrease(void* arg);
unsigned WINAPI ThreadDecrease(void* arg);

int Gold = 0;

CRITICAL_SECTION cs; //�Ӱ迵��

int main()
{
	HANDLE ThreadHandle[2];
	unsigned int threadID;

	//CRITICAL_SECTION �ʱ�ȭ
	InitializeCriticalSection(&cs);


	ThreadHandle[0] = (HANDLE)_beginthreadex(NULL, 0, ThreadIncrease, NULL, 0, &threadID);
	ThreadHandle[1] = (HANDLE)_beginthreadex(NULL, 0, ThreadDecrease, NULL, 0, &threadID);

	WaitForMultipleObjects(2, ThreadHandle, TRUE, INFINITE);

	printf("\nGold : %d\n", Gold);

	//CRITICAL_SECTION �����
	DeleteCriticalSection(&cs); 

	return 0;
}

unsigned WINAPI ThreadIncrease(void* arg)
{
	// ������
	EnterCriticalSection(&cs);
	for (int i = 0; i < 10; ++i)
	{
		Gold = Gold + 1;
		printf("Increase Gold : %d\n", Gold);
	}
	// ���ݰ�
	LeaveCriticalSection(&cs);
	return 0;
}
unsigned WINAPI ThreadDecrease(void* arg)
{
	EnterCriticalSection(&cs);
	for (int i = 0; i < 10; ++i)
	{
		Gold = Gold - 1;
		printf("Decrease Gold : %d\n", Gold);
	}
	LeaveCriticalSection(&cs);
	return 0;
}
