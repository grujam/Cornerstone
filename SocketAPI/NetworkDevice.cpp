#include "pch.h"
#include "NetworkDevice.h"
#include <iostream>
#include <ws2tcpip.h>
#include "NetworkConnection.h"

CNetworkDevice* CNetworkDevice::m_Instance = nullptr;
std::mutex CNetworkDevice::m_mutex;

CNetworkDevice* CNetworkDevice::GetInstance() {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (m_Instance == nullptr) {
        m_Instance = new CNetworkDevice();
    }
    return m_Instance;
}

void CNetworkDevice::Initialize()
{
    WSADATA wsaData;
    SOCKET connectSocket;
    struct sockaddr_in serverAddr;

    WSAStartup(MAKEWORD(2, 2), &wsaData);

    connectSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(33333);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
}

CNetworkConnection* CNetworkDevice::CreateNetworkConnection()
{
    return new CNetworkConnection();
}

