
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include "socket.h"

void perror_and_exit(char *s)
{
    perror(s);
    exit(1);
}

int main(void)
{
    struct sockaddr_in server_addr;
    int sock;
    int slen = sizeof(server_addr);

    if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
        perror_and_exit("socket");

    memset((char *)&server_addr, 0, sizeof(server_addr));
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SOCK_PORT);       

    if (inet_aton(SRV_IP, &server_addr.sin_addr) == 0)
    {
        fprintf(stderr, "inet_aton() failed\n");
        exit(1);
    }

    printf("Input a number: ");
    char buf[MSG_LEN];
    fgets(buf, MSG_LEN, stdin);
    
    //sock - socket_handle
    // buf - message_buffer
    // MSG_LEN - buffer_length
    // 0 - special_flags
    // server_address - socket_address_structure
    // slen - address_structure_length
    if (sendto(sock, buf, MSG_LEN, 0, &server_addr, slen) == -1)
        perror_and_exit("sendto()");

    close(sock);
    return OK;
}
