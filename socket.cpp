#include <winsock.h>
#include <stdio.h>
#include <unistd.h>
#include <windows.h>

#include "socket.h"

#define MAXBUFF	        100
#define	PORT     9999
#define	DEST_PORT  9998
#define DEST_IP    "127.0.0.1"

void Socket :: send(char *str)
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

void Socket :: recv()
{
	int client = accept(sd, (struct sockaddr*)&addr, &addrlen );
    memset(recvbuffer,'\0',MAXBUFF);
    recv(client, recvbuffer, MAXBUFF, 0);
    printf("¦¬¨ì %s\n",recvbuffer);
    close(client);
}

Socket :: Socket()
{
	struct sockaddr_in addr;
	int sd;
	addrlen = sizeof(addr);
	int client;
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
	WSADATA wsaData ;
	if( WSAStartup(MAKEWORD(1,1) , &wsaData ) == 0 )
	{
	    Socket sok;
	    while(1)
        {
            puts("main throws 5566");
            sok.send("5566 der di ii");
            recv();
            printf("main gets %s\n",recvbuffer);
            sleep(1000);
        }
	}
	return 0;
}
