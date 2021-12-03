/*
	아이피나 도메인명을 입력 받아서 그에 맞는 정보를 출력하세요.
	예)
	입력 : yahoo.com
	출력 : ~~~~~~~~

	입력 : 74.6.143.26
	출력 : ~~~~~~~~
*/
#define  _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS


#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

bool IsIPAddress(char* Address)
{
	//1.1.1.1 => 7
	//255.255.255.255 => 15
	if (strlen(Address) < 7 || strlen(Address) > 15)
	{
		//도메인
		return false;
	}

	for (int i = 0; i < strlen(Address); ++i)
	{
		if (!((Address[i] >= '0' && Address[i] <= '9') || Address[i] == '.'))
		{
			//도메인
			return false;
		}
	}

	return true;
}

int main()
{
	WSAData wsaData;
	struct hostent* host;

	int Result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (Result != 0)
	{
		printf("WSAStartup");
		exit(-1);
	}

	char Address[1024] = { 0, };
	scanf("%s", Address);


	if (IsIPAddress(Address))
	{
		unsigned long addr = inet_addr(Address);

		struct hostent* host2;

		host2 = gethostbyaddr((char*)&addr, 4, AF_INET);

		printf("official : %s\n", host2->h_name);


		for (int i = 0; host2->h_aliases[i]; ++i)
		{
			printf("alias : %s\n", host2->h_aliases[i]);
		}

		printf("AF : %s\n", (host2->h_addrtype == AF_INET) ? "AF_INET" : "AF_INET6");

		for (int i = 0; host2->h_addr_list[i]; ++i)
		{
			printf("ip addr : %s\n", inet_ntoa(*(IN_ADDR*)host2->h_addr_list[i]));
		}
	}
	else
	{
		host = gethostbyname(Address);

		for (int i = 0; host->h_aliases[i]; ++i)
		{
			printf("alias : %s\n", host->h_aliases[i]);
		}

		printf("AF : %s\n", (host->h_addrtype == AF_INET) ? "AF_INET" : "AF_INET6");

		for (int i = 0; host->h_addr_list[i]; ++i)
		{
			printf("ip addr : %s\n", inet_ntoa(*(IN_ADDR*)host->h_addr_list[i]));
		}
	}

	WSACleanup();

	return 0;
}