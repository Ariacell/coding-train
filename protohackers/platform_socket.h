#include <string>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#endif

inline void socket_init() {
#ifdef _WIN32
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif
}

inline void socket_shutdown(int fd) {
    #ifdef _WIN32
    shutdown(fd, SD_BOTH);
#else
    shutdown(fd, SHUT_RDWR);
#endif
}

inline void socket_close(int s) {
#ifdef _WIN32
    closesocket(s);
    WSACleanup();
#else
    close(s);
#endif
}


const int PORT = 12345;
const int MAX_CLIENTS = 100;
const int BUFFER_SIZE = 1024;

struct ClientInfo {
    int socket;
    std::string nickname;
    std::string room;
};