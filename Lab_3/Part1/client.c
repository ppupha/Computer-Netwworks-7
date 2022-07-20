
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 8080
   
int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    char fileName[1024];
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
       
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    printf("Connected to server\n");
    int fl = 1;
    while (fl == 1)
    {
		printf("1. List File on Server\n");
		printf("2. Send file\n");
		printf("3. Exit\n");
		printf("Input your choose:");
		int select = 0;
		scanf("%d", &select);
        while ( getchar() != '\n' );
    	switch (select) {
                case 1:
                    hello = "01";
                    send(sock , hello , strlen(hello) , 0 );
					printf("Client sent: [%s]\n", hello);

					
                    valread = read( sock , buffer, 1024);
                    if (valread == 0)
                    {
                    	printf("Server Exited\n");
                    	return 0;
                    }
                    buffer[valread] = 0;
                    printf("Client Recieved: [%s]\n",buffer );
                   	
                    char * sep = "//";
                    char * token = strtok(buffer, sep);
					printf("List File From Server:\n");
   					while( token != NULL ) 
   					{
   						if (!(strcmp(token, "..") == 0 || strcmp(token, ".") == 0))
      						printf( " %s\n", token ); //printing each token
      					token = strtok(NULL, sep);
      				}
                    
                    printf("\n\n\n");
              
                    break;
                     
                case 2: // listServer
                	hello = "02";
                	send(sock , hello , strlen(hello) , 0 );
					printf("Client sent: [%s]\n", hello);
					
					printf("Input File Name:  ");
					scanf("%s", fileName);
					send(sock , fileName , strlen(fileName) , 0 );
					printf("Client sent: [%s]\n", fileName);

					FILE *f = fopen(fileName, "wb");
					valread = read( sock , buffer, 1024);
					
                    buffer[valread] = 0;

                    int filesize = atoi(buffer);
                    printf("Client: Filesize = %d\n", filesize);
                    if (filesize == 0){
                    	printf("\n\nNo File %s in Server\n\n\n", fileName);
                    	break;
                    }
                    printf("[%s]\n",fileName);

                    if (f != NULL)
                    {
                    	printf("Start writing file\n");
                    	
                    	do
						{
							valread = read( sock , buffer, 1024);
							buffer[valread] = 0;
							printf("Client Recieved: [%s]\n",buffer );
							size_t written = fwrite(buffer, sizeof(char), valread, f);
							filesize -= valread;
						}
						while (filesize > 0);
                    	fclose(f);
                    }
                    else
                    {
                    	printf("Cant open File to write \n");
                    }
                    printf("End 2\n");
                    
					
                    break;
                case 3: // send file
                    hello = "03";
                    fl = 0;
                    break;
        }
    
    
		//send(sock , hello , strlen(hello) , 0 );
		//printf("Hello message sent\n");
		//valread = read( sock , buffer, 1024);
		//printf("%s\n",buffer );
		
	}
	return 0;
}
