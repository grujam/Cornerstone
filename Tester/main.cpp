#include <iostream>
#include "NetworkDevice.h"
#include "NetworkConnection.h"

int main() {

    CNetworkDevice::GetInstance()->Initialize();
    CNetworkConnection* pConn = CNetworkDevice::GetInstance()->CreateNetworkConnection();

    return 0;
}