/*
	DNS Resolve
*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	SOCKADDR_IN Addr;

	WSAData wsaData;

	struct hostent* host;

	int Result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (Result != 0)
	{
		printf("WSAStartup");
		exit(-1);
	}

	host = gethostbyname("yahoo.com");

	for (int i = 0; host->h_aliases[i]; ++i)
	{
		cout << "ALiases : " << host->h_aliases[i] << endl;
	}

	cout << "AF : " << ((host->h_addrtype == AF_INET) ? "AF_INET" : "AF_INET6") << endl;

	for (int i = 0; host->h_addr_list[i]; ++i)
	{
		cout << "IP Addr : " << inet_ntoa(*(IN_ADDR*)host->h_addr_list[i]) << endl;
	}

	cout << endl << endl;
	/* ---------------------------------------------------------------- */


	memset(&Addr, 0, sizeof(SOCKADDR_IN));

	Addr.sin_addr.s_addr = inet_addr("74.6.143.26");

	unsigned long addr = inet_addr("74.6.143.26");

	struct hostent* host2;

	host2 = gethostbyaddr((char*)&Addr.sin_addr, 4, AF_INET);

	for (int i = 0; host2->h_aliases[i]; ++i)
	{
		cout << "ALiases : " << host2->h_aliases[i] << endl;
	}

	cout << "AF : " << ((host2->h_addrtype == AF_INET) ? "AF_INET" : "AF_INET6") << endl;

	for (int i = 0; host2->h_addr_list[i]; ++i)
	{
		cout << "IP Addr : " << inet_ntoa(*(IN_ADDR*)host->h_addr_list[i]) << endl;
	}
	

	WSACleanup();

	return 0;
}