#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <WinSock2.h>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	FILE* sourceFile = nullptr;

	SOCKET ServerSocket;
	SOCKET ClientSocket;

	SOCKADDR_IN ServerAddr;
	SOCKADDR_IN ClientAddr;

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
	ServerAddr.sin_port = htons(12345);
	ServerAddr.sin_addr.s_addr = INADDR_ANY; //아무거나

	bind(ServerSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));

	listen(ServerSocket, 5);

	while (1)
	{
		int ClientAddrLength = sizeof(ClientAddr);
		ClientSocket = accept(ServerSocket, (SOCKADDR*)&ClientAddr, &ClientAddrLength);

		sourceFile = fopen("Tree_Copy.png", "wb");

		char Buffer[1024] = { 0, };
		int RecvLength = 0;
		while ((RecvLength = recv(ClientSocket, Buffer, sizeof(Buffer), 0)) != 0)
		{
			fwrite(Buffer, sizeof(char), RecvLength, sourceFile);
			cout << "RecvLength => " << RecvLength << endl;
			memset(Buffer, 0, sizeof(Buffer));
		}

		char Message[] = "End Of file.";
		send(ClientSocket, Message, sizeof(Message), 0);
		
		fclose(sourceFile);

		closesocket(ClientSocket);
		cout << "disconnect" << endl;
	}

	closesocket(ServerSocket);

	WSACleanup();

	return 0;
}

