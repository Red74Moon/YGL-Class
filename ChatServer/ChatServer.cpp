/*
	Server Program(TCP)
	
	채팅 서버와 클라이언트 만들기

	Server

	client thread


*/
#include <WinSock2.h> // Windows
#include <iostream>
#include <Windows.h>
#include <process.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

unsigned WINAPI accept(void* arg);

HANDLE MutexHandle;
SOCKET ServerSocket;
SOCKET ClientSocket;
// ip주소를 넣기 위한 구조체
SOCKADDR_IN ServerAddr;
// client ip addr
SOCKADDR_IN ClientAddr;
WSAData	wsaData;

fd_set Reads;
fd_set Copys;

int main()
{
	HANDLE ThreadHandle;
	unsigned int threadID;

	MutexHandle = CreateMutex(NULL, FALSE, NULL);


	ThreadHandle = (HANDLE)_beginthreadex(NULL, 0, accept, NULL, 0, &threadID);

	WaitForSingleObject(ThreadHandle, INFINITE);
	
	CloseHandle(MutexHandle);

	// 7.마무리
	closesocket(ClientSocket);
	closesocket(ServerSocket);

	// 역시 윈도우에서만 사용, 소켓청소
	WSACleanup();

	return 0;
}

unsigned WINAPI accept(void* arg)
{
	fd_set Reads;
	fd_set Copys;
	WaitForSingleObject(MutexHandle, INFINITE);

	int Result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (Result != 0)
	{
		printf("WSAStartup");
		exit(-1);
	}

	ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (ServerSocket == INVALID_SOCKET)
	{
		printf("socket");
		exit(-1);
	}

	FD_ZERO(&Reads);
	FD_SET(ServerSocket, &Reads);

	memset(&ServerAddr, 0, sizeof(SOCKADDR_IN));
	ServerAddr.sin_family = PF_INET; //IP V4
	ServerAddr.sin_port = htons(9190);
	ServerAddr.sin_addr.s_addr = INADDR_ANY; //아무거나

	bind(ServerSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));

	listen(ServerSocket, 5);

	TIMEVAL timeout;
	timeout.tv_sec = 5;
	timeout.tv_usec = 5000;

	while (1)
	{
		Copys = Reads;

		int fd_num = select(0, &Copys, 0, 0, &timeout);
		if (fd_num == SOCKET_ERROR)
		{
			break;
		}

		if (fd_num == 0)
		{
			continue;
			//다른 서버 로직
		}

		for (int i = 0; i < Reads.fd_count; ++i)
		{
			//이벤트가 일어나면 처리
			if (FD_ISSET(Reads.fd_array[i], &Copys))
			{
				if (Reads.fd_array[i] == ServerSocket)
				{
					int ClientAddrLength = sizeof(ClientAddr);
					ClientSocket = accept(ServerSocket, (SOCKADDR*)&ClientAddr, &ClientAddrLength);
					FD_SET(ClientSocket, &Reads);
					printf("connection client : %d\n", ClientSocket);
				}
				else
				{
					//클라이언트 데이터 처리
					char Buffer[1024] = { 0, };
					int RecvLength = 0;
					RecvLength = recv(Reads.fd_array[i], Buffer, sizeof(Buffer), 0);
					if (RecvLength == 0)
					{
						//close connection
						FD_CLR(Reads.fd_array[i], &Reads);
						closesocket(Reads.fd_array[i]);
						printf("close connection : %d\n", Reads.fd_array[i]);
					}
					else
					{
						for (int j = 0; j < Reads.fd_count; ++j)
						{
							if (Reads.fd_array[j] != ServerSocket)
							{
								send(Reads.fd_array[j], Buffer, RecvLength, 0);
							}
						}
					}
				}
			}
		}
	}

	closesocket(ServerSocket);
	ReleaseMutex(MutexHandle);
	return 0;
}
