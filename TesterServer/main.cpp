#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    SOCKET listenSocket, clientSocket;
    struct sockaddr_in serverAddr;

    WSAStartup(MAKEWORD(2, 2), &wsaData);

    listenSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(33333);

    bind(listenSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(listenSocket, 1);

    std::cout << "Waiting for client connection..." << std::endl;

    clientSocket = accept(listenSocket, NULL, NULL);
    std::cout << "Client connected!" << std::endl;

    char buffer[1024] = { 0 };

    while (strcmp(buffer, "end"))
    {
        recv(clientSocket, buffer, 1024, 0);
        std::cout << "Recv: " << buffer << std::endl;
    }

    closesocket(clientSocket);
    closesocket(listenSocket);
    WSACleanup();

    system("pause");
     
    return 0;
}