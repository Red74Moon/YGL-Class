/*
 	Client Program(TCP)

     1. TCP 5001 ��Ʈ�� �����ؼ� "give me message."�� ������ 
	    �������� �����ִ� ������ �޾� ���� Ŭ���̾�Ʈ�� ����� ������.
*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h> // Windows
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	WSAData	wsaData;

	// server socket
	SOCKET hServerSocket;

	// ip�ּҸ� �ֱ� ���� ����ü
	SOCKADDR_IN serverAddr;

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

	// host byte order : Little Endian(arm), Big Endian(intel,amd) 
	// network byte order : Big Enddian
	serverAddr.sin_family		= AF_INET; // #define AF_INET  2  // internetwork: UDP, TCP, etc.
	serverAddr.sin_addr.s_addr	= inet_addr("127.0.0.1"); // ip �ִ� ��, ������ �ּ�
	
	// Host to network short
	// Host to network long
	serverAddr.sin_port			= htons(5001); // port

	// 3. connect

	if (connect(hServerSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		cout << "Error connect" << endl;
		exit(-1);
	}

	while (1)
	{
		char message[1024] = "give me message."; //char message[] = "give me message.";
		
		//cout << "������ ������ ���� : ";
		//cin >> message;

		send(hServerSocket, message, strlen(message) + 1, 0);  //send(hServerSocket, message, sozeof(message), 0); 

		// 6.recv 
		char Buffer[1024] = { 0, };
		int recvLength = recv(hServerSocket, Buffer, sizeof(Buffer), 0);
		if (recvLength == -1) // ������ ��������...(-1)
		{
			cout << "Error recv" << endl;
			exit(-1);
		}

		// �޽��� �ޱ�
		cout << "�������� ���� ���� : " << Buffer << endl;
	}
	// ������
	closesocket(hServerSocket); // ���� ���� ���� �����...

	WSACleanup();

	return 0;
}