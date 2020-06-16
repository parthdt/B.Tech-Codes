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

int main()
{

	int listenfd, connfd, valread;
	struct sockaddr_in servaddr;
	int addrlen = sizeof(servaddr); 
	char buff [MAXLINE];
	char *hello = "Hello from server"; 

	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(8080);

	bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

	if(bind < 0)
	{
		printf("Bind Error\n");
		exit(0);

	}

	if(listen(listenfd, LISTENQ) < 0)
	{
		printf("Listen Error\n");
		exit(0);
	} 
while(1){
	connfd = accept(listenfd, (struct sockaddr *) &servaddr, (socklen_t*)&addrlen);

	valread = read(connfd , buff, MAXLINE+1); 
	buff[valread] = '\0';
	printf("%s\n",buff); 
	send(connfd, hello, strlen(hello), 0); 
	printf("Hello message sent\n"); 


	close(connfd);
}
	close(listenfd);

	return 0;
}
