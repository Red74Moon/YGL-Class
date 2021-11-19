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

	//1.Winsock ÃÊ±âÈ­
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
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(9190);

	//3. ip, port binding
	if (bind(hServerSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		cout << "error bind" << endl;
		exit(-1);
	}

	char message[1024] = { 0, };
	int clientLength = sizeof(clientAddr);
	int recvLength = recvfrom(hServerSocket, message, sizeof(message), 0,
		(SOCKADDR*)&clientAddr, &clientLength);
	if (recvLength == -1) // 
	{
		cout << "error : " << hServerSocket << endl;
		exit(-1);
	}

	cout << "message from client : " << message << endl;

	sendto(hServerSocket, message, recvLength + 1, 0, (SOCKADDR*)&clientAddr, clientLength);

	closesocket(hServerSocket);

	WSACleanup();

	return 0;
}