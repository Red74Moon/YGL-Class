#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h>
#include <iostream>
#include <string>
#include <Windows.h>
#include <process.h>
#include <vector>
#include <string>

#pragma comment(lib, "ws2_32.lib")

using namespace std;


CRITICAL_SECTION SocketCritialSection;

unsigned WINAPI InputThread(void* arg);
//work thread, 보내는거, 입력

string UserName;
string Message;

//main Thread , 받는거
int main()
{
	SOCKET ServerSocket;
	SOCKADDR_IN ServerADDR;

	//	InitializeCriticalSection(&SocketCritialSection);

	cout << "유저네임 : ";
	getline(cin, UserName);

	WSAData WsaData;

	WSAStartup(MAKEWORD(2, 2), &WsaData);

	ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

	struct hostent* Host;
	Host = gethostbyname("work.junios.net");

	char* IPAddress = inet_ntoa(*(IN_ADDR*)Host->h_addr_list[0]);

	memset(&ServerADDR, 0, sizeof(ServerADDR));
	ServerADDR.sin_family = AF_INET;
	ServerADDR.sin_addr.s_addr = inet_addr(IPAddress);
	ServerADDR.sin_port = htons(6666);

	connect(ServerSocket, (SOCKADDR*)&ServerADDR, sizeof(ServerADDR));

	//보내는거 
	HANDLE ThreadHandle = (HANDLE)_beginthreadex(NULL, 0, InputThread, (void*)&ServerSocket, 0, NULL);

	char Buffer[1024] = { 0, };

	while (true)
	{
		int RecvLength = recv(ServerSocket, Buffer, sizeof(Buffer), 0);
		if (RecvLength <= 0)
		{
			//연결이 끊겼을때
			break;
		}
		cout << "from Server : " << Buffer << endl;
	}

	closesocket(ServerSocket);

	WSACleanup();

	return 0;
}


//work 입력 보내기
unsigned __stdcall InputThread(void* arg)
{
	char Buffer[1024] = { 0, };

	while (true)
	{
		cout << "Message : ";
		cin.getline(Buffer, sizeof(Buffer) - 1);
		Message = UserName + " : " + Buffer;

		SOCKET ServerSocket = *(SOCKET*)arg;
		send(ServerSocket, Message.c_str(), strlen(Message.c_str()) + 1, 0);
	}

	return 0;
}