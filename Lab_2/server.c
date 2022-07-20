#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#include "socket.h"

void perror_and_exit(char *s)
{
	perror(s);
	exit(1);
}

char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
 
void strev(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}
 
char* fromDeci(char res[], int base, int inputNum)
{
	
    int index = 0;  
    
    while (inputNum > 0)
    {
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';
 
    strev(res);

    return res;
}

void output(char *b)
{
    int n = atoi(b);
    
    char res[100];
                
    printf("Decimal: %d\n", n); // 10
    printf("Binary: %s\n", fromDeci(res, 2, n)); // 2
    printf("Octal: %o\n", n); // 8
    printf("Hexadecimal: %x\n", n); // 16
    printf("Seven-th: %s\n", fromDeci(res, 7, n));  // 7
}


int main(void)
{
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int sock;
    int slen = sizeof(client_addr);

    printf("Server started - Waiting for Client\n");

	// AF_INET - семейство TCP/IP
	// SOCK_DGRAM - тип сокета датаграммы
	// IPPROTO_UPD - протокол UDP
    if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
        perror_and_exit("socket");

    memset((char *)&server_addr, 0, sizeof(server_addr));
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SOCK_PORT);
    // INADDR_ANY - все адреса локального хоста
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    //bind - позволяет программам связать локальный адрес 	(совокупность адресов локального компьютера и номера порта) с сокетом.
    //sock - socket_handle
    // server_add - local_socket_Address
    //sizeof(server_addr) - address_length
    
    if (bind(sock, &server_addr, sizeof(server_addr)) == -1)
        perror_and_exit("bind");

	char buf[MSG_LEN];
    while (1)
    {
        if (recvfrom(sock, buf, MSG_LEN, 0, &client_addr, &slen) == -1)
            perror_and_exit("recvfrom()");
        
        output(buf);
	}
	printf("Hello ");
	//close(sock);
	return OK;
}
