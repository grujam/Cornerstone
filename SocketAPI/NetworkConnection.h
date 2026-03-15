#pragma once

#include <string>

class CNetworkConnection
{
public:
	void InitializeConnection();

	void Connect(const std::string& InIP, const USHORT InPORT);
	void Listen();
	void Send();
	void Recv();
};