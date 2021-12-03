#define  _CRT_SECURE_NO_WARNINGS
#define  _WINSOCK_DEPRECATED_NO_WARNINGS

#include <stdio.h>
#include <WinSock2.h>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	FILE* destinationFile = nullptr;
	SOCKET ServerSocket;
	SOCKADDR_IN ServerAddr;
	WSAData wsaData;

	int Result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (Result != 0)
	{
		printf("WSAStartup");
		exit(-1);
	}

	ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (ServerSocket == INVALID_SOCKET)
	{
		printf("socket");
		exit(-1);
	}

	memset(&ServerAddr, 0, sizeof(SOCKADDR_IN));
	ServerAddr.sin_family = PF_INET; //IP V4
	ServerAddr.sin_port = htons(12345); // 서버 포트
	ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //서버 아이피

	connect(ServerSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));

	//서버에서 보내는 연결이 끊기면 완료  정보를 보내줌.
	char Message[1024] = { 0, };
	sprintf(Message, "Client No : %d\n", ServerSocket);

	char Buffer[1024] = { 0, };
	char message[1024] = { 0, };

	int ReadLength = 0;

	while (1)
	{

		cout << "서버로 보내는 내용 : ";
		cin >> message;

		int SendLength = send(ServerSocket, message, strlen(message), 0);
		
		recv(ServerSocket, Buffer, sizeof(Buffer), 0);

		printf("From Server : %s\n", Buffer);

		Sleep(1000);
	}
	closesocket(ServerSocket);

	WSACleanup();

	return 0;
}
