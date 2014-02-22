#ifndef SOCKET_H_INCLUDED
#define SOCKET_H_INCLUDED

class Socket {
public:
    Socket();
    void recvData();
    void sendData(const char*);
    char recvbuffer[100];
private:
    unsigned int __addrlen;
    int __recvSocket;
	struct sockaddr_in __addr;
};

#endif
