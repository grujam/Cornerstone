#pragma once
#include <winsock2.h>
#include <string>
#include <mutex>
#include <vector>

class CNetworkConnection;

class CNetworkDevice
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