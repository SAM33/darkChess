#ifndef SOCKET_H_INCLUDED
#define SOCKET_H_INCLUDED

class Socket {
public:
    Socket();
    void recvData();
    void sendData(const char*);
    char recvbuffer[100];
private:
    unsigned int addrlen;
    int sd;
	struct sockaddr_in addr;
};

#endif
