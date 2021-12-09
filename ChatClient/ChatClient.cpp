/*
	Client Program(TCP)

	ä�� ������ Ŭ���̾�Ʈ �����

	Clinet

	�Է� Thread

	��� Thread
*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h> // Windows
#include <iostream>
#include <Windows.h>
#include <process.h>
#include <string>


#pragma comment(lib, "ws2_32.lib")

unsigned WINAPI connectRecv(void* arg);
unsigned WINAPI connectSend(void* arg);

using namespace std;

HANDLE MutexHandle;
WSAData	wsaData;

// server socket
SOCKET hServerSocket;

// ip�ּҸ� �ֱ� ���� ����ü
SOCKADDR_IN serverAddr;


int main()
{
	HANDLE ThreadHandle[2];
	unsigned int threadID;

	// 1.WindSock �ʱ�ȭ (�������), �������� ����.
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cout << "Error WSASartup" << endl;
		exit(-1);
	}

	// 2.Create Socket
	hServerSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hServerSocket == INVALID_SOCKET)
	{
		cout << "Error socket" << endl;
		exit(-1);
	}

	// ip�ּ� ����ü�� ������ ��ŭ �ʱ�ȭ(0����..)
	memset(&serverAddr, 0, sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("172.16.2.52"); // ip �ִ� ��, ������ �ּ�
	serverAddr.sin_port = htons(9190); // port

	// 3. connect

	if (connect(hServerSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		cout << "Error connect" << endl;
		exit(-1);
	}
	ThreadHandle[0] = (HANDLE)_beginthreadex(NULL, 0, connectSend, NULL, 0, &threadID);
	ThreadHandle[1] = (HANDLE)_beginthreadex(NULL, 0, connectRecv, NULL, 0, &threadID);


	WaitForMultipleObjects(2, ThreadHandle, TRUE, INFINITE);
	
	CloseHandle(MutexHandle);

	// ������
	closesocket(hServerSocket); // ���� ���� ���� �����...

	WSACleanup();

	return 0;
}

unsigned WINAPI connectRecv(void* arg)
{
	WaitForSingleObject(MutexHandle, INFINITE);
	while (1)
	{
		char message[1024] = { 0, };
		
		int recvLength = recv(hServerSocket, message, sizeof(message), 0);
		if (recvLength == -1) // ������ ��������...(-1)
		{
			cout << "Error recv" << endl;
			exit(-1);
		}

		// �޽��� �ޱ�
		cout << "�������� ���� ���� : " << message << endl;
	}
	ReleaseMutex(MutexHandle);

	return 0;
}

unsigned WINAPI connectSend(void* arg)
{
	WaitForSingleObject(MutexHandle, INFINITE);
	while (1)
	{
		char message[1024] = { 0, };

		cout << "������ ������ ���� : ";
		cin >> message;

		send(hServerSocket, message, sizeof(message), 0);
	}
	ReleaseMutex(MutexHandle);
	return 0;
}
