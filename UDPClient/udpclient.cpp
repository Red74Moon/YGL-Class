/*
	Client Program(UDP)
*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h> //windows
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	WSAData wsaData;

	SOCKET hServerSocket;

	SOCKADDR_IN serverAddr;

	//1.Winsock 초기화
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cout << "error WSSStarup" << endl;
		exit(-1);
	}

	//2.Create Socket
	hServerSocket = socket(PF_INET, SOCK_DGRAM, 0);
	if (hServerSocket == INVALID_SOCKET)
	{
		cout << "error socket" << endl;
		exit(-1);
	}

	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverAddr.sin_port = htons(9190);

	while (1)
	{
		char message[1024] = { 0, };
		
		cout << "서버로 보내는 내용 : ";
		cin >> message;

		int recvLength = strlen(message);
		sendto(hServerSocket, message, recvLength + 1, 0, (SOCKADDR*)&serverAddr, sizeof(serverAddr));

		memset(message, 0, 1024);

		int clientLength = sizeof(serverAddr);
		recvLength = recvfrom(hServerSocket, message, sizeof(message), 0,
			(SOCKADDR*)&serverAddr, &clientLength);
		if (recvLength == -1) // 
		{
			cout << "error : " << hServerSocket << endl;
			exit(-1);
		}

		cout << "message from server : " << message << endl;
	}
	closesocket(hServerSocket);

	WSACleanup();

	return 0;
}