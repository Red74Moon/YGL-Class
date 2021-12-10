/*
	Server Program(TCP)
	
	ä�� ������ Ŭ���̾�Ʈ �����

	Server : client thread

*/
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h> // Windows
#include <iostream>
#include <Windows.h>
#include <process.h>
#include <string>
#include <vector>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

//�����Ǵ� ����
//�߰� ����, �б�
vector<SOCKET> ClientList;

CRITICAL_SECTION SocketCriticalSection;

unsigned WINAPI ProcessClient(void* arg);

int main()
{

	cout << "-- Chat Server --" << endl << endl;
	SOCKET ServerSocket;
	SOCKADDR_IN ServerAddr;

	SOCKET ClientSocket;
	SOCKADDR_IN ClientAddr;

	InitializeCriticalSection(&SocketCriticalSection);

	WSAData	wsaData;

	//�ʱ�ȭ
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	//���� ����ü �ʱ�ȭ
	memset(&ServerAddr, 0, sizeof(SOCKADDR_IN));
	ServerAddr.sin_family = AF_INET; //IP V4
	ServerAddr.sin_port = htons(9190);
	ServerAddr.sin_addr.s_addr = INADDR_ANY; //�ƹ��ų�

	//���� ����
	ServerSocket = socket(PF_INET, SOCK_STREAM, 0);

	//bind
	bind(ServerSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));

	//listen
	listen(ServerSocket, 5);


	//main thread, accept
	while (true)
	{
		int ClientAddrSize = sizeof(ClientAddr);
		ClientSocket = accept(ServerSocket, (SOCKADDR*)&ClientAddr, &ClientAddrSize);

		//ClientSocket�� ���(����)
		EnterCriticalSection(&SocketCriticalSection);

		ClientList.push_back(ClientSocket);
		
		LeaveCriticalSection(&SocketCriticalSection);
		
		//worker thread
		HANDLE ThreadHandle = (HANDLE)_beginthreadex(NULL, 0, ProcessClient, (void*)&ClientSocket, 0, NULL);

		//ClientSocket ������ ó��, recv, send(Thread)
		cout << "Client Connect : " << ClientSocket << endl;
	}

	closesocket(ServerSocket);

	DeleteCriticalSection(&SocketCriticalSection);

	WSACleanup();

	return 0;
}

//worker thread, client send, recv
unsigned __stdcall ProcessClient(void* arg)
{
	SOCKET ClientSocket = *(SOCKET*)arg;
	char Buffer[1024] = { 0, };

	while(true)
	{
		int RecvLength = recv(ClientSocket, Buffer, sizeof(Buffer), 0);

		if (RecvLength <= 0)
		{
			//������ �������� ��
			closesocket(ClientSocket);
			
			EnterCriticalSection(&SocketCriticalSection);

			for (auto itr = ClientList.begin(); itr != ClientList.end(); ++itr)
			{
				if (*itr == ClientSocket)
				{
					ClientList.erase(itr);
					break;
				}
			}
			LeaveCriticalSection(&SocketCriticalSection);
		}
		else
		{
			EnterCriticalSection(&SocketCriticalSection);
			for (auto itr = ClientList.begin(); itr != ClientList.end(); ++itr)
			{
				send(*itr, Buffer, strlen(Buffer) +1 , 0);
			}
			LeaveCriticalSection(&SocketCriticalSection);
		}
	}
	return 0;
}
