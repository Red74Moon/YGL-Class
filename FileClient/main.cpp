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
	ServerAddr.sin_port = htons(12345); // ���� ��Ʈ
	ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //���� ������

	connect(ServerSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));

	destinationFile = fopen("Tree.png", "rb");

	char Buffer[1024] = { 0, };
	int ReadLength = 0;

	while ((ReadLength = fread(Buffer, sizeof(char), sizeof(Buffer), destinationFile)) != 0)
	{
		int SendLength = send(ServerSocket, Buffer, ReadLength, 0);
		cout << "Lenght => " << SendLength << endl;
	}

	shutdown(ServerSocket, SD_SEND);

	//�������� ������ ������ ����� �Ϸ�  ������ ������.

	recv(ServerSocket, Buffer, sizeof(Buffer), 0);

	cout << "from server : " << Buffer << endl;

	fclose(destinationFile);
	closesocket(ServerSocket);

	WSACleanup();

	return 0;
}


