/*
	Server Program
*/
#include <WinSock2.h> // Windows
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	WSAData	wsaData;

	SOCKET hServerSocket;

	// client socket
	SOCKET hClientSocket;

	// ip주소를 넣기 위한 구조체
	SOCKADDR_IN serverAddr;
	// client ip addr
	SOCKADDR_IN clientAddr;

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
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // ip 넣는 것
	serverAddr.sin_port = htons(9190); // port

	// 3.ip, port binding
	if (bind(hServerSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		cout << "Error bind" << endl;
		exit(-1);
	}

	// 4 Linten (대기)
	if (listen(hServerSocket, 0) == SOCKET_ERROR)
	{
		cout << "Error Linten" << endl;
		exit(-1);
	}

	// 5.accept - client의 접속
	int clientAddrSize = sizeof(clientAddr);
	hClientSocket = accept(hServerSocket, (SOCKADDR*)&clientAddr, &clientAddrSize);
	if (hClientSocket == SOCKET_ERROR)
	{
		cout << "Error accept" << endl;
		exit(-1);
	}

	// 6.send 
	char message[] = "Hello World";
	send(hClientSocket, message, sizeof(message), 0);

	closesocket(hClientSocket);
	closesocket(hServerSocket);
		
	WSACleanup();

	return 0;
}