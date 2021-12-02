/*
	Server Program(TCP)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <WinSock2.h> // Windows
#include <iostream>
#include <stdio.h>

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
	// SOCK_STREAM : TCP�� ���� ��������, �������� �����ؼ� ������ �ش�.
	// SOCK_DREAM : �ù� ������ �Ͱ� ����. ���������� ����. 
	//              �߰� �ս��� ���� �� �ִ�. �� �ڰ� �ٲ� �� �ִ�. (=UDP)
	hServerSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hServerSocket == INVALID_SOCKET) // INVALID_SOCKET ~0 
	{
		// ����ó�� �κ�
		cout << "Error socket" << endl;
		exit(-1);
	}

	// ip�ּ� ����ü�� ������ ��ŭ �ʱ�ȭ(0����..) ������ ��� �ѹ濡 ������ �ش�.
	memset(&serverAddr, 0, sizeof(serverAddr));

	serverAddr.sin_family = AF_INET; // TCP_IP ���(IPv4)
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
	cout << "Ok Linten" << endl;
	// 5.accept - client�� ���� ���� ���ӽ� �ϳ��� �� ���� Ŭ���̾�Ʈ ������ �����.

	while (1)
	{

		int clientAddrSize = sizeof(clientAddr);


		hClientSocket = accept(hServerSocket, (SOCKADDR*)&clientAddr, &clientAddrSize); // ���� ������ �ش�. 
		if (hClientSocket == SOCKET_ERROR)
		{
			cout << "Error accept" << endl;
			exit(-1);
		}

		cout << "Ok accept" << endl;
/*  -------------------------------------------------------------------------  */

		//������ ��ġ�� �˷��ִ� ����ü
		FILE* src;

		char buf[1024] = "";
		int len = 0;

		src = fopen("Tree.png", "rb");

		cout << "Ok file open" << endl;

		while (1)
		{
			memset(buf, 0, sizeof(src));
			len = fread(buf, sizeof(char), sizeof(buf), src);
			cout << "len =�� " << len << endl;
			if (len == 0)
			{
				break;
			}
			send(hClientSocket, buf, sizeof(buf), 0);
		}
		fclose(src);
		src = nullptr;
/*  -------------------------------------------------------------------------  */
	}

	// 7.������
	closesocket(hClientSocket);
	closesocket(hServerSocket);

	// ���� �����쿡���� ���, ����û��
	WSACleanup();

	return 0;
}