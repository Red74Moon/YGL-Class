#include <stdio.h>
#include <Windows.h>
#include <process.h>
#include <time.h>

unsigned WINAPI ThreadIncrease(void* arg);
unsigned WINAPI ThreadDecrease(void* arg);

int Gold = 0;

//커널 오브젝트로 작업
HANDLE MutexHandle;

int main()
{
	HANDLE ThreadHandle[2];
	unsigned int threadID;

	clock_t startTime;
	clock_t endTime;

	startTime = clock();

	/*-----------------------------------------------------------------*/
	WCHAR MultexName[] = L"무조건더하기";
	MutexHandle = CreateMutex(NULL, FALSE, MultexName);
	if (GetLastError() == ERROR_ALERTED)
	{
		printf("이미 실행중입니다.");
		return -1;
	}

	Sleep(3000);
	/*-----------------------------------------------------------------*/

	ThreadHandle[0] = (HANDLE)_beginthreadex(NULL, 0, ThreadIncrease, NULL, 0, &threadID);
	ThreadHandle[1] = (HANDLE)_beginthreadex(NULL, 0, ThreadDecrease, NULL, 0, &threadID);

	WaitForMultipleObjects(2, ThreadHandle, TRUE, INFINITE);

	printf("\nGold : %d\n", Gold);

	CloseHandle(MutexHandle);

	endTime = clock();

	printf("\nElapsed Time : %f\n", (double)(endTime -startTime));

	return 0;
}

unsigned WINAPI ThreadIncrease(void* arg)
{
	WaitForSingleObject(MutexHandle, INFINITE);
	for (int i = 0; i < 7000000; ++i)
	{
		Gold = Gold + 1;
	}
	ReleaseMutex(MutexHandle);
	return 0;
}
unsigned WINAPI ThreadDecrease(void* arg)
{
	WaitForSingleObject(MutexHandle, INFINITE);
	for (int i = 0; i < 7000000; ++i)
	{
		Gold = Gold - 1;
	}
	ReleaseMutex(MutexHandle);
	return 0;
}