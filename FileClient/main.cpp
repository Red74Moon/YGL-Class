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

	// ip주소를 넣기 위한 구조체
	SOCKADDR_IN serverAddr;

	// 1.WindSock 초기화 (윈도우용), 리눅스는 없다.
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

	// ip주소 구조체의 사이즈 만큼 초기화(0으로..)
	memset(&serverAddr, 0, sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // ip 넣는 것, 목적지 주소
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
		cout << "len =》 " << len << endl;
		if (len == 0)
		{
			break;
		}
	}
	cout << "Copy OK!" << endl;
	fclose(dst);
	dst = nullptr;
/*  -------------------------------------------------------------------------  */
	// 마무리
	closesocket(hServerSocket); // 내쪽 서버 정보 지우고...

	WSACleanup();

	return 0;
}