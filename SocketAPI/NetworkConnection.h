#pragma once
#include <string>
#include "Macros.h"

class SOCKET_API CNetworkConnection
{
public:
	void InitializeConnection();

	void Connect(const std::string& InIP, const USHORT InPORT);
	void Listen();
	void Send();
	void Recv();
};