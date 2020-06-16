#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>
#include<time.h>
#define MAXLINE 1024
#define MAX 1500    //max val of P
#define ISN 100
#define EXTRA 976 
#pragma pack(1)   // this helps to pack the struct to 5-bytes
struct packet {
int i,j,l;       //i=ISN,j=TTL,k=timstamp,l=P
struct timeval k;
};
#pragma pack(0)
//#define LISTENQ 30
	

void dg_echo(FILE *fp,int sockfd, struct sockaddr *pcliaddr, socklen_t clilen)
{
	int n;
	socklen_t len;
	int mesg[3];
	char * rbuf = (char *)malloc (MAX * sizeof (char));
	char *sbuf;
	struct packet *b;
	int flag = 1;
	for(;;){
	flag=1;
	while(flag==1) 
	{
		len = clilen;
		n = recvfrom(sockfd, rbuf, MAX, 0, pcliaddr, &len);
		//printf("Client Message:");
		b=(struct packet *)rbuf;
		//printf("%d %d %d",b->i,b->j,b->l);
		b->j-=1;
		char * sbuf = (char *) malloc(b -> l * sizeof(char));
		memcpy(sbuf,b, sizeof(struct packet));
		sendto(sockfd,sbuf,b->l,0,pcliaddr,len);
		if(b->j==1)flag=0;
	}
	}
}

int main(int argc, char **argv)
{
	int sockfd;
	struct sockaddr_in servaddr, cliaddr;

	if (argc != 2)
	{
		printf("Error: type ./a.out <IPaddress>\n");
		exit(0);

	}  

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
        //servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(8080);

	if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
	{
		printf("inet_pton error for %s\n", argv[1]);
		exit(0);
	}
                        
                        
	bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

	if(bind < 0)
	{
		printf("Bind Error\n");
		exit(0);

	}

	dg_echo(stdin,sockfd, (struct sockaddr *) &cliaddr, sizeof(cliaddr));
	

	return 0;
}




