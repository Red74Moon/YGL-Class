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

	// �ܺο��� ���� �� �ֵ��� ������ ������ ����� �ش�.
	SOCKET hServerSocket; //h - �ڵ�(handle)

	// client socket, Ŭ���̾�Ʈ ������ �� ��ŭ �ʿ�
	SOCKET hClientSocket;

	// ip�ּҸ� �ֱ� ���� ����ü
	SOCKADDR_IN serverAddr;
	// client ip addr
	SOCKADDR_IN clientAddr;

	// 1.WindSock �ʱ�ȭ (�������), �������� ����.
	// ������ ���� ���̺귯���� ����ϰڴ�. ȣ��
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cout << "Error WSASartup" << endl;
		exit(-1);
	}

	// 2.Create Socket ������ ���� �������� �����.
	// PF_INET�� ����Ѵ�.(Protocol Famliy �������� �йи� ����)
	// ������������ ����Ѵ�.(SOCK_STREAM�� SOCK_DGRAM-(������ �߽�) �ΰ������ִ�.)
	// 0 ���� 0�� ���
	hServerSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hServerSocket == INVALID_SOCKET) // INVALID_SOCKET ~0 
	{
		// ����ó�� �κ�
		cout << "Error socket" << endl;
		exit(-1);
	}

	// ip�ּ� ����ü�� ������ ��ŭ �ʱ�ȭ(0����..) ������ ��� �ѹ濡 ������ �ش�.
	memset(&serverAddr, 0, sizeof(serverAddr));

	serverAddr.sin_family = AF_INET; // TCP_IP ���
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // 4����Ʈ IP����� �ش�. ip �ִ� ��
	serverAddr.sin_port = htons(9190); // port  (0~65535) ��ǻ���� ���α׷��� ���� ��ȣ

	// 3.ip, port binding
	//         ����ϴ� ����            �ּ�             ������
	// ����(��Ʈ) �浹, �̹̻����, ��Ʈ�� �⺻������ ���ÿ� ����� �� ����. 
	if (bind(hServerSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) 
	{
		cout << "Error bind" << endl;
		exit(-1);
	}

	// 4 Linten (���) (0 �ð�..)
	if (listen(hServerSocket, 0) == SOCKET_ERROR)
	{
		cout << "Error Linten" << endl;
		exit(-1);
	}

	// 5.accept - client�� ���� ���� ���ӽ� �ϳ��� �� ���� Ŭ���̾�Ʈ ������ �����.

	while (1)
	{
		int clientAddrSize = sizeof(clientAddr);
		// ���� ���Ͽ��� Ŭ���̾�� �ּҸ� �ް�, Ŭ���̾�Ʈ �ּ� ������ 
		// Ŭ���̾�Ʈ ������ ������ ��ŭ ������ش�. ��Ʈ�� ���� ����
		hClientSocket = accept(hServerSocket, (SOCKADDR*)&clientAddr, &clientAddrSize);
		if (hClientSocket == SOCKET_ERROR)
		{
			cout << "Error accept" << endl;
			exit(-1);
		}
		while (1)
		{
			//Ŭ���̾�Ʈ���� �޴´�. 
			char message[1024] = { 0, };
			int recvLength = recv(hClientSocket, message, sizeof(message), 0);
			if (recvLength == -1) // ������ ��������...(-1)
			{
				cout << "Client Disconnect : " << hClientSocket << endl;
				closesocket(hClientSocket);
				break;
				// cout << "Error recv" << endl;
				// exit(-1);
			}

			cout << "Client Message : " << message << endl;

			// Ŭ���̾�Ʈ���� ���� ���� �ǵ����ش�.
			send(hClientSocket, message, recvLength + 1, 0);
		}
		// 6.send 
		//char message[] = "Hello World";
	}

	// 7.������
	closesocket(hClientSocket);
	closesocket(hServerSocket);
		
	// ���� �����쿡���� ���, ����û��
	WSACleanup();

	return 0;
}