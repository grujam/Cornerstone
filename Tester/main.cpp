#include "stdafx.h"
#include <iostream>
#include "NetworkDevice.h"
#include "NetworkConnection.h"

int main() 
{
    CNetworkDevice::GetInstance()->Initialize();
    CNetworkConnection* pConn = CNetworkDevice::GetInstance()->CreateNetworkConnection();
    pConn->Connect("127.0.0.1", 8888);
    return 0;
}
