#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>
#include<time.h>

#define MAXLINE 1024
#define LISTENQ 30
#define PORT 8080

int main(int argc, char **argv)
{

	int listenfd, binds, connfd, valread;
	pid_t pid;
	struct sockaddr_in servaddr, cliaddr;
	socklen_t clilen; 
	char buff [MAXLINE];

	if (argc != 2)
	{
		printf("Error: type ./a.out <IPaddress>\n");
		exit(0);

	}

	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	if(listenfd < 0)
	{
		printf("Socket Error\n");
		exit(0);
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
//	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
	{
		printf("inet_pton error for %s\n", argv[1]);
		exit(0);
	}

	binds = bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

	if(binds < 0)
	{
		printf("Bind Error\n");
		exit(0);

	}

	if(listen(listenfd, LISTENQ) < 0)
	{
		printf("Listen Error\n");
		exit(0);
	} 
		clilen = sizeof(cliaddr);

		connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);
		
	if(connfd < 0)
		{
			printf("Accept Error\n");
			exit(0);
		}

	if((pid = fork()) == 0)
	{
		while(1){
			
			valread = read(connfd , buff, MAXLINE+1); 
			buff[valread] = '\0';
			fputs(buff, stdout);
			}
		close(listenfd);
		close(connfd);		
		exit(0);
		
	}
	else{
		while(1){

		
			fgets(buff,MAXLINE,stdin);
			send(connfd, buff, strlen(buff), 0); 
			
		}
		close(listenfd);
		close(connfd);		
	}
	

	// close(listenfd);

	return 0;
}
