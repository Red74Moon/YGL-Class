/*
 	Client Program(TCP)

     1. TCP 5001 포트로 접속해서 "give me message."를 보내서 
	    서버에서 보내주는 정보를 받아 오는 클라이언트를 만들어 보세요.
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

	// host byte order : Little Endian(arm), Big Endian(intel,amd) 
	// network byte order : Big Enddian
	serverAddr.sin_family		= AF_INET; // #define AF_INET  2  // internetwork: UDP, TCP, etc.
	serverAddr.sin_addr.s_addr	= inet_addr("127.0.0.1"); // ip 넣는 것, 목적지 주소
	
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
		
		//cout << "서버로 보내는 내용 : ";
		//cin >> message;

		send(hServerSocket, message, strlen(message) + 1, 0);  //send(hServerSocket, message, sozeof(message), 0); 

		// 6.recv 
		char Buffer[1024] = { 0, };
		int recvLength = recv(hServerSocket, Buffer, sizeof(Buffer), 0);
		if (recvLength == -1) // 서버랑 끊어지면...(-1)
		{
			cout << "Error recv" << endl;
			exit(-1);
		}

		// 메시지 받기
		cout << "서버에서 받은 내용 : " << Buffer << endl;
	}
	// 마무리
	closesocket(hServerSocket); // 내쪽 서버 정보 지우고...

	WSACleanup();

	return 0;
}