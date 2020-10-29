#define _WIN32_WINNT 0x501
#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>
#define DEFAULT_PORT "27015"
   
int main(int argc, char const *argv[]) 
{ 
    WSADATA wsaData;
    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0){
        printf("WSAStartup failed: %d", WSAGetLastError());
        return 1;
    }


    int iResult;
    struct addrinfo *result = NULL,
                    *ptr    = NULL,
                    hints;
    
    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family     = AF_UNSPEC;
    hints.ai_socktype   = SOCK_STREAM;
    hints.ai_protocol   = IPPROTO_TCP;

    iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
    if (iResult != 0){
        printf("getaddrinfo failed: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    SOCKET ConnectSocket = INVALID_SOCKET;

    ptr = result;

    // Create a SOCKET for connecting to server
    ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
    if (ConnectSocket == INVALID_SOCKET) {
        printf("Error at socket(): &ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Connect to server.
    std::cout << "Connecting to " << ptr->ai_addr << " : " << (int)ptr->ai_addrlen << std::endl;
    iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        closesocket(ConnectSocket);
        ConnectSocket = INVALID_SOCKET;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }

    return 0; 
} 