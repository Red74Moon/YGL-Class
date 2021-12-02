/*
	Server Program(TPC)

	2. TCP 5001 포트로 접속을 허용하는 서버를 만들어서 
	  서버가 클라이언트에 "show me the money."를 보내서 
	  클라이언트에서 보내주는 서버를 만들어 보세요.
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
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)  // &wsaData : 초기화 할때 쓰인다..
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
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // ip 넣는 것 host to network long
	serverAddr.sin_port = htons(5001); // port

	// 3.ip, port binding
	//bind(hServerSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)  // 
	if (bind(hServerSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		cout << "Error bind" << endl; // cout << GetLastError() << endl; 에러번호 출력
		exit(-1);
	}

	// 4 Linten (대기)
	if (listen(hServerSocket, 0) == SOCKET_ERROR) 
	{
		cout << "Error Linten" << endl;
		exit(-1);
	}

	// 5.accept - client의 접속, 교환수 역활
	int clientAddrSize = sizeof(clientAddr);
	
	//blocking
	//accept(hServerSocket, (SOCKADDR*)&clientAddr, &clientAddrSize)
	
	hClientSocket = accept(hServerSocket, (SOCKADDR*)&clientAddr, &clientAddrSize); // 연결 정보를 준다. 
	if (hClientSocket == SOCKET_ERROR)
	{
		cout << "Error accept" << endl;
		exit(-1);
	}

	// 6.send 
	char message[1024] = "show me the money.";
	send(hClientSocket, message, sizeof(message), 0);

	//memset(message, 0, 1024);
	char Buffer[1024] = { 0, };

	//blocking
	recv(hClientSocket, Buffer, sizeof(message), 0);
	
	cout << Buffer;
	
	closesocket(hClientSocket);
	closesocket(hServerSocket);

	WSACleanup();

	return 0;
}
