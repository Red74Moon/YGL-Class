/*
	Client Program(TCP)

	채팅 서버와 클라이언트 만들기

	Clinet : 입력 Thread, 출력 Thread
*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h> // Windows
#include <iostream>
#include <Windows.h>
#include <process.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

//공유되는 정보
//추가 삭제, 읽기

CRITICAL_SECTION SocketCriticalSection;

unsigned WINAPI InputThread(void* arg);

//work thread : 입력, 보내는 거 
//main thread : 받는 거

int main()
{
	cout << "-- Chat Client --" << endl << endl;
	SOCKET ServerSocket;
	SOCKADDR_IN ServerAddr;

	WSAData	wsaData;

	//초기화
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	//소켓 생성
	ServerSocket = socket(PF_INET, SOCK_STREAM, 0);

	//client 구조체 초기화
	memset(&ServerAddr, 0, sizeof(SOCKADDR_IN));
	ServerAddr.sin_family = AF_INET; //IP V4
	ServerAddr.sin_port = htons(9160);
	ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //아무거나

	connect(ServerSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));

	//보내는거 
	HANDLE ThreadHandle = (HANDLE)_beginthreadex(NULL, 0, InputThread, (void*)&ServerSocket, 0, NULL);

	//받는거
	char Buffer[1024] = { 0, };

	while (true)
	{
		int RecvLength = recv(ServerSocket, Buffer, sizeof(Buffer), 0);

		if (RecvLength <= 0)
		{
			//연결이 끊어졌을 때
			break;
		}
		cout << "From Server : " << Buffer << endl;
	}
	closesocket(ServerSocket);

	WSACleanup();

	return 0;
}

//work 입력 보내기
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

