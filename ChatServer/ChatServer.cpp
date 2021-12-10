/*
	Server Program(TCP)
	
	채팅 서버와 클라이언트 만들기

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

//공유되는 정보
//추가 삭제, 읽기
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

	//초기화
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	//서버 구조체 초기화
	memset(&ServerAddr, 0, sizeof(SOCKADDR_IN));
	ServerAddr.sin_family = AF_INET; //IP V4
	ServerAddr.sin_port = htons(9190);
	ServerAddr.sin_addr.s_addr = INADDR_ANY; //아무거나

	//소켓 생성
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

		//ClientSocket을 기록(저장)
		EnterCriticalSection(&SocketCriticalSection);

		ClientList.push_back(ClientSocket);
		
		LeaveCriticalSection(&SocketCriticalSection);
		
		//worker thread
		HANDLE ThreadHandle = (HANDLE)_beginthreadex(NULL, 0, ProcessClient, (void*)&ClientSocket, 0, NULL);

		//ClientSocket 데이터 처리, recv, send(Thread)
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
			//연결이 끊어졌을 때
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
