#include "pch.h"
#include "NetworkConnection.h"
#include "string"
#include <ws2tcpip.h>
#include <winsock2.h>
#include <iostream>

void CNetworkConnection::InitializeConnection()
{
	


}

void CNetworkConnection::Connect(const std::string& InIP, const USHORT InPORT)
{
	SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
		assert(false, "Socket Create Failed.");

	sockaddr_in	addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(InPORT);
	inet_pton(AF_INET, InIP.c_str(), &addr.sin_addr.s_addr);

	int connect_result = connect(sock, (struct sockaddr*)(&addr), sizeof(addr));
	if (connect_result != SOCKET_ERROR)
	{
		std::cout << "Connection Success\n";
	}
	else
	{ 
		std::cout << "Connection Failure\n";
		closesocket(sock);
	}

}

void CNetworkConnection::Listen()
{
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in	addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(33333); // 임시 포트 값
	std::string ip = "127.0.0.1";
	inet_pton(AF_INET, ip.c_str(), &addr.sin_addr.s_addr);

	bind(sock, (struct sockaddr*)&addr, sizeof(addr));


}

void CNetworkConnection::Send()
{

}

void CNetworkConnection::Recv()
{
}
