#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>

#define MAXLINE 1024
#define PORT 8080

int main(int argc, char **argv)
{
	int sockfd, n,valread;
	pid_t pid;
	char recvline[MAXLINE+1];
	struct sockaddr_in servaddr;
	//char *hello = "Hello from PARTH";
	
	if(argc != 2)
	{
		printf("Error: type ./a.out <IPaddress>\n");
		exit(0);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(sockfd < 0)
	{
		printf("socket error\n");
		exit(0);
	}
	else
		printf("socket created\n");	
	
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8080);

	if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
	{
		printf("inet_pton error for %s\n", argv[1]);
		exit(0);
	}

	if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
	{
		printf("connect error\n");
		exit(0);
	}
    if((pid = fork()) == 0)   //child is reading
	{
		while(1){
			
			valread = read(sockfd, recvline, MAXLINE+1); 
			recvline[valread] = '\0';
			fputs(recvline, stdout);
			}
		close(sockfd);
		exit(0);
		
	}
	else{
		while(1){

		
			fgets(recvline,MAXLINE,stdin);
			send(sockfd, recvline, strlen(recvline), 0); 
			
		}
		close(sockfd);		
	}
	
	return 0;
}
