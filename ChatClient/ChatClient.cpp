/*
	Client Program(TCP)

	ä�� ������ Ŭ���̾�Ʈ �����

	Clinet : �Է� Thread, ��� Thread
*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h> // Windows
#include <iostream>
#include <Windows.h>
#include <process.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

//�����Ǵ� ����
//�߰� ����, �б�

CRITICAL_SECTION SocketCriticalSection;

unsigned WINAPI InputThread(void* arg);

//work thread : �Է�, ������ �� 
//main thread : �޴� ��

int main()
{
	cout << "-- Chat Client --" << endl << endl;
	SOCKET ServerSocket;
	SOCKADDR_IN ServerAddr;

	WSAData	wsaData;

	//�ʱ�ȭ
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	//���� ����
	ServerSocket = socket(PF_INET, SOCK_STREAM, 0);

	//client ����ü �ʱ�ȭ
	memset(&ServerAddr, 0, sizeof(SOCKADDR_IN));
	ServerAddr.sin_family = AF_INET; //IP V4
	ServerAddr.sin_port = htons(9160);
	ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //�ƹ��ų�

	connect(ServerSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));

	//�����°� 
	HANDLE ThreadHandle = (HANDLE)_beginthreadex(NULL, 0, InputThread, (void*)&ServerSocket, 0, NULL);

	//�޴°�
	char Buffer[1024] = { 0, };

	while (true)
	{
		int RecvLength = recv(ServerSocket, Buffer, sizeof(Buffer), 0);

		if (RecvLength <= 0)
		{
			//������ �������� ��
			break;
		}
		cout << "From Server : " << Buffer << endl;
	}
	closesocket(ServerSocket);

	WSACleanup();

	return 0;
}

//work �Է� ������
unsigned __stdcall InputThread(void* arg)
{
	char Buffer[1024] = { 0, };
	while(true)
	{	
		cout << "Message : ";
		cin.getline(Buffer, sizeof(Buffer) - 1);

		SOCKET ServerSocket = *(SOCKET*)arg;

		send(ServerSocket, Buffer, strlen(Buffer) + 1, 0);
	}
	return 0;
}

