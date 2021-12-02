/*
	Client Program(TCP)
*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

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

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // ip �ִ� ��, ������ �ּ�
	serverAddr.sin_port = htons(9190); // port

	// 3. connect

	if (connect(hServerSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		cout << "Error connect" << endl;
		exit(-1);
	}
/*  -------------------------------------------------------------------------  */
	FILE* dst;

	char buf[1024] = "";
	int len = 0;

	dst = fopen("Tree_copy.png", "wb");

	while (1)
	{
		memset(buf, 0, sizeof(buf));
		recv(hServerSocket, buf, sizeof(buf), 0);
			
		len = fwrite(buf, sizeof(char), sizeof(buf), dst);
		fflush(dst);
		cout << "len =�� " << len << endl;
		if (len == 0)
		{
			break;
		}
	}
	cout << "Copy OK!" << endl;
	fclose(dst);
	dst = nullptr;
/*  -------------------------------------------------------------------------  */
	// ������
	closesocket(hServerSocket); // ���� ���� ���� �����...

	WSACleanup();

	return 0;
}