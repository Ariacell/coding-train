#include <iostream>
#include <string>
#include <cstring>
#include "platform_socket.h"

int clientSocket = -1;

int main() {
   socket_init();
   clientSocket = socket(AF_INET, SOCK_STREAM, 0);
   sockaddr_in serverAddr{};
   serverAddr.sin_family = AF_INET;
   serverAddr.sin_port = htons(PORT);
   serverAddr.sin_addr.s_addr = INADDR_ANY;
    
    if (inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) <= 0) {
        std::cerr << "Error: Invalid address/ Address not supported" << std::endl;
        return 1;
    }

    if (int code = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Error: Connection failed with code" << code  << std::endl;
        return 1;
    }

    const char* message = "Hello, server! This is a localhost message.";
    // The send() function transmits data through the socket
    send(clientSocket, message, strlen(message), 0); 
    std::cout << "Message sent to localhost server." << std::endl;

    // Optional: Receive a response from the server (similar to send, but using recv or read)
    char buffer[1024] = {0};
    recv(clientSocket, buffer, 1024, 0);
    std::cout << "Server response: " << buffer << std::endl;


    // 5. Close the socket
    socket_close(clientSocket); // use closesocket(clientSocket) on Windows
    std::cout << "Socket closed." << std::endl;

    return 0;
}
