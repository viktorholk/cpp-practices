#define _WIN32_WINNT 0x501
#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>
#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "27015" 


int main(int argc, char const *argv[]) 
{ 
    WSADATA wsaData;
    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0){
        printf("WSAStartup failed: %d", WSAGetLastError());
        return 1;
    }

    struct addrinfo *result = NULL, *ptr = NULL, hints;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family     = AF_INET;
    hints.ai_socktype   = SOCK_STREAM;
    hints.ai_protocol   = IPPROTO_TCP;
    hints.ai_flags      = AI_PASSIVE;

    // Resolve the local address and DEFAULT_PORT to be used by the server
    if (getaddrinfo(NULL, DEFAULT_PORT, &hints, &result)){
        printf("getaddrinfo failed: %d\n", GetLastError());
        WSACleanup();
        return 1;
    }
    SOCKET listenSocket = INVALID_SOCKET;

    listenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if ( listenSocket == INVALID_SOCKET){
        printf("Error at socket(): %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    if ( bind(listenSocket, result->ai_addr, (int)result->ai_addrlen)){
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }

    if ( listen( listenSocket, SOMAXCONN ) == SOCKET_ERROR ) {
        printf("Listen failed with error: %ld\n", WSAGetLastError());
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }
    printf("Ready\n");
    
    SOCKET ClientSocket = INVALID_SOCKET;

    // Accept a client socket
    ClientSocket = accept(listenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET){
        printf("accept failed: %d\n", WSAGetLastError());
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }


} 