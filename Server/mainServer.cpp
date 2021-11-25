/*
	Server Program(TCP)
*/
#include <WinSock2.h> // Windows
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{

	WSAData	wsaData;

	// 외부에서 들어올 수 있도록 서버에 구멍을 만들어 준다.
	SOCKET hServerSocket; //h - 핸들(handle)

	// client socket, 클라이언트 접속자 수 만큼 필요
	SOCKET hClientSocket;

	// ip주소를 넣기 위한 구조체
	SOCKADDR_IN serverAddr;
	// client ip addr
	SOCKADDR_IN clientAddr;

	// 1.WindSock 초기화 (윈도우용), 리눅스는 없다.
	// 윈도우 소켓 라이브러리를 사용하겠다. 호출
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cout << "Error WSASartup" << endl;
		exit(-1);
	}

	// 2.Create Socket 구멍을 뚫을 파이프를 만든다.
	// PF_INET을 사용한다.(Protocol Famliy 프로토콜 패밀리 약자)
	// 연결지향으로 사용한다.(SOCK_STREAM와 SOCK_DGRAM-(보내는 중심) 두가지가있다.)
	// 0 보통 0을 사용
	// SOCK_STREAM : TCP로 만들어서 연결지향, 순서까지 보장해서 보내어 준다.
	// SOCK_DREAM : 택배 보내는 것과 같다. 순서보장이 없다. 
	//              중간 손실이 생길 수 있다. 앞 뒤가 바뀔 수 있다. (=UDP)
	hServerSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hServerSocket == INVALID_SOCKET) // INVALID_SOCKET ~0 
	{
		// 예외처리 부분
		cout << "Error socket" << endl;
		exit(-1);
	}

	// ip주소 구조체의 사이즈 만큼 초기화(0으로..) 사이즈 잡고 한방에 보내어 준다.
	memset(&serverAddr, 0, sizeof(serverAddr));

	serverAddr.sin_family = AF_INET; // TCP_IP 사용
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // 4바이트 IP만들어 준다. ip 넣는 곳
	serverAddr.sin_port = htons(9190); // port  (0~65535) 컴퓨터의 프로그램별 접속 번호

	// 3.ip, port binding
	//         사용하는 소켓            주소             사이즈
	// 소켓(포트) 충돌, 이미사용중, 포트는 기본적으로 동시에 사용할 수 없다. 
	if (bind(hServerSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) 
	{
		cout << "Error bind" << endl;
		exit(-1);
	}

	// 4 Linten (대기) (0 시간..)
	if (listen(hServerSocket, 0) == SOCKET_ERROR)
	{
		cout << "Error Linten" << endl;
		exit(-1);
	}

	// 5.accept - client의 접속 실제 접속시 하나를 더 만들어서 클라이언트 소켓을 만든다.

	while (1)
	{
		int clientAddrSize = sizeof(clientAddr);
		// 서버 소켓에서 클라이언드 주소를 받고, 클라이언트 주소 사이즈 
		// 클라이언트 소켓을 접속자 만큼 만들어준다. 포트는 임의 생성
		hClientSocket = accept(hServerSocket, (SOCKADDR*)&clientAddr, &clientAddrSize);
		if (hClientSocket == SOCKET_ERROR)
		{
			cout << "Error accept" << endl;
			exit(-1);
		}

		cout << "Client Connect : " << hClientSocket << endl;

		while (1)
		{
			//클라이언트에서 받는다. 
			char message[1024] = { 0, };
			int recvLength = recv(hClientSocket, message, sizeof(message), 0);
			if (recvLength == -1) // 서버랑 끊어지면...(-1)
			{
				cout << "Client Disconnect : " << hClientSocket << endl;
				closesocket(hClientSocket);
				break;
				// cout << "Error recv" << endl;
				// exit(-1);
			}

			cout << "Client Message : " << message << endl;

			// 클라이언트에서 받은 것을 되돌려준다.
			send(hClientSocket, message, recvLength + 1, 0);
		}
		// 6.send 
		//char message[] = "Hello World";
	}

	// 7.마무리
	closesocket(hClientSocket);
	closesocket(hServerSocket);
		
	// 역시 윈도우에서만 사용, 소켓청소
	WSACleanup();

	return 0;   

}