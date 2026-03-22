#pragma once
#include <string>
#include <mutex>
#include <vector>
#include "Macros.h"

class CNetworkConnection;
class SOCKET_API CNetworkDevice
{
private:
    CNetworkDevice() : m_socket(INVALID_SOCKET) {} // »ý¼ºÀÚ private

public:
    static CNetworkDevice* GetInstance();

    void Initialize();

    CNetworkConnection* CreateNetworkConnection();

private:
    static CNetworkDevice* m_Instance;
    static std::mutex m_mutex;
    SOCKET m_socket;

    std::vector<CNetworkConnection*> Connections;
};
