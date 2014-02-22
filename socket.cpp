#ifdef _WIN32
#include <winsock.h>
#include <windows.h>
#endif

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef linux
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#endif

#include "socket.h"

#define MAXBUFF	        100
#define	PORT     9999
#define	DEST_PORT  9998
#define DEST_IP    "127.0.0.1"

void Socket :: sendData(const char *str)
{
	struct sockaddr_in dest_addr;
	int sd;
	sd = socket(PF_INET, SOCK_STREAM, 0);
	dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(DEST_PORT);
    dest_addr.sin_addr.s_addr = inet_addr(DEST_IP);
    memset(&(dest_addr.sin_zero),'\0',8);
    connect(sd, (struct sockaddr*)&dest_addr, sizeof(dest_addr));
	char buffer[100];
	memset(buffer,'\0',100);
	strcpy(buffer,str);
	send(sd,buffer,strlen(buffer),0);
	printf("°e¥X %s\n",buffer);
}

void Socket :: recvData()
{
	int client = accept(sd, (struct sockaddr*)&addr, &addrlen );
    memset(recvbuffer,'\0',MAXBUFF);
    recv(client, recvbuffer, MAXBUFF, 0);
    printf("¦¬¨ì %s\n",recvbuffer);
    close(client);
}

Socket :: Socket()
{
	addrlen = sizeof(addr);
	sd = socket(PF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(&(addr.sin_zero),'\0',8);
    bind(sd, (struct sockaddr*)&addr, addrlen);
	listen(sd, 2);
}



int main(void)
{
#ifdef _WIN32
	WSADATA wsaData ;
	if( WSAStartup(MAKEWORD(1,1) , &wsaData ) != 0 )
	{
	    return 1;
    }
#endif

    Socket sok;
    while(1)
    {
        puts("main throws 5566");
        sok.sendData("5566 der di ii");
        sok.recvData();
        printf("main gets %s\n",sok.recvbuffer);
        sleep(1000);
    }

	return 0;
}
