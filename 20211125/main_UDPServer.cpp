/*
	Server Program(UDP)

	4. UDP 1234로 접속을 허용하는 서버를 만들어서 "what ary u doing now." 
	   접속한 클라이언트에 "what ary u doing now." 메세지를 보내서 
	   클라이언트가 보내주는 서버를 만들어 보세요.
*/

#include <WinSock2.h> //windows
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	WSAData wsaData;

	SOCKET hServerSocket;

	SOCKADDR_IN serverAddr;
	SOCKADDR_IN clientAddr;

	//1.Winsock 초기화
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cout << "error WSSStarup" << endl;
		exit(-1);
	}

	hServerSocket = socket(PF_INET, SOCK_DGRAM, 0);
	if (hServerSocket == INVALID_SOCKET)
	{
		cout << "error socket" << endl;
		exit(-1);
	}

	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(1234);

	//3. ip, port binding
	if (bind(hServerSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		cout << "error bind" << endl;
		exit(-1);
	}

	while (1)
	{
		char message[1024] = { "what ary u doing now."};
		int clientLength = sizeof(clientAddr);
		int recvLength = recvfrom(hServerSocket, message, sizeof(message), 0,
			(SOCKADDR*)&clientAddr, &clientLength);
		if (recvLength == -1) // 
		{
			cout << "Client Disconnect  : " << hServerSocket << endl;
			closesocket(hServerSocket);
		}

		cout << "message from client : " << message << endl;

		sendto(hServerSocket, message, recvLength + 1, 0, (SOCKADDR*)&clientAddr, clientLength);
	}
	closesocket(hServerSocket);

	WSACleanup();

	return 0;
}