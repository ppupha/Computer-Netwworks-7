
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <dirent.h>

#define PORT 8080
#define MSG_LEN 1024


typedef struct
{
	int sock;
	struct sockaddr address;
	int addr_len;
	pthread_t thread;
} connection_t;


int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

void * process(void * ptr)
{
	char buffer[1024] = {0};
	char fileName[1024] = {0};
	int len;
	int valread;
	char *hello = "Hello from server";
	connection_t * conn;
	long addr = 0;
	printf("Enter Process\n");
	if (!ptr) pthread_exit(0); 
	conn = (connection_t *)ptr;
	int new_socket = conn->sock;
	
	/*char name[10];
	snprintf (name, sizeof(name), "out%d.txt",1);
	FILE *f = fopen(name, "wb");
	*/

	while (1){
		printf("Start While---\n" );
		valread = read( new_socket , buffer, 1024);
		buffer[valread] = 0;
		if (valread <= 0)
		{
			printf("Client Exited\n");
			close(conn->sock);
			free(conn);
			pthread_exit(0);
		}
		printf("Buffer = [%s]\n",buffer );
		if (strcmp(buffer, "01") == 0)
		{
			printf("List File");
			DIR *d;
    		struct dirent *dir;
    		d = opendir(".");
    		char fileName[1024];
    		fileName[0] = 0;
    		if (d)
    		{
        		while ((dir = readdir(d)) != NULL)
        		{
        			if (strcmp(dir->d_name, "..") == 0) continue ;
        			
            		printf("\t%s\n", dir->d_name);
            		
            		strcat(fileName, dir->d_name);
            		strcat(fileName, "//");
            		
        		}
        		strcat(fileName, "..");
        		send(new_socket , fileName , strlen(fileName) , 0 );
            	printf("Server Sent: [%s]\n", fileName);
        	closedir(d);
    		}
    		printf("End 1\n");
		}
		
		if (strcmp(buffer, "02") == 0)
		{
			printf("Start 2\n");
			printf("Sendfile");
			
				
			valread = read( new_socket , fileName, 1024);
            fileName[valread] = 0;
            printf("Sever Recieved: [%s]\n",fileName );
            
            FILE *f = fopen(fileName, "rb");
			if (f != NULL)
			{
				printf("Check in write file\n");
				fseek(f, 0, SEEK_END);
				long filesize = ftell(f);
				rewind(f);
				
				if (filesize == EOF)
					return NULL;
				char buf[MSG_LEN];
				
				snprintf (buf, sizeof(buf), "%ld",filesize);
				send(new_socket , buf , MSG_LEN, 0 );
				printf("Sent to server: [%s] \n", buf);

				
				if (filesize > 0)
				{
					char buffer[MSG_LEN];
					do
					{
						size_t num = min(filesize, sizeof(buffer));
						num = fread(buffer, 1, num, f);
						if (num < 1)
						    return NULL;
						 send(new_socket , buffer , num, 0 );
						printf("Sent to server: [%s]\n", buffer); 
						filesize -= num;
					}
					while (filesize > 0);
				}
				fclose(f);
			}	
			else
			{
				char buf[MSG_LEN];
				int filesize = 0;
				
				snprintf (buf, sizeof(buf), "%ld",filesize);
				send(new_socket , buf , MSG_LEN, 0 );
				printf("Sent to server: [%s] \n", buf);
			}
            
            
            printf("End 2\n");
            
		}
		if (strcmp(buffer, "03") == 0)
		{
			printf("Start 3\n");
			printf("Exit \n");
			//close(conn->sock);
			//free(conn);
			//sssspthread_exit(0);
			printf("End 3");
		}
		
		//fwrite(hello, sizeof(char), sizeof(hello), f);
		//send(new_socket , hello , strlen(hello) , 0 );
		//printf("Hello message sent\n");
		printf("----------------------------\n");
	}
	//ssfclose(f);
	close(conn->sock);
	free(conn);
	pthread_exit(0);
}


int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";
    connection_t * connection;
       
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
       
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
       
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("Server is listening...\ns");
    while (1){
    	printf("[1] Start While\n");
    	/* accept incoming connections */
		connection = (connection_t *)malloc(sizeof(connection_t));
		
		if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
		{
		    perror("accept");
		    exit(EXIT_FAILURE);
		}
		connection->sock = new_socket;

		pthread_create(&(connection->thread), 0, process, (void *)connection);
		pthread_detach(connection->thread);
    
    	/*
    
		if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
		{
		    perror("accept");
		    exit(EXIT_FAILURE);
		}
		while (1)
		{
			printf("[1] Waitng for client ...\n");
			valread = read( new_socket , buffer, 1024);
			printf("BUffer[1] = [%s]\n",buffer );
			//send(new_socket , hello , strlen(hello) , 0 );
			//printf("Hello message sent\n");
			printf("----------------------------\n");
		}
		*/
	}
    return 0;
}
