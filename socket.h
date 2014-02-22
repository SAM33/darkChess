#ifndef SOCKET_H_INCLUDED
#define SOCKET_H_INCLUDED

class Socket {
public:
    Socket();
    recv();
    send(char*);
    char* recvbuffer[100];
private:
    int addrlen;
};

#endif
