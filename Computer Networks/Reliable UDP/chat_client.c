#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>
#include<time.h>
#include<sys/time.h>
#define MAXLINE 1024
#define ISN 100
#define EXTRA 76  //used to allocate extra P-24 bytes to set overall size to P
#pragma pack(1)   // this helps to pack the struct to 5-bytes
struct packet {
int i,j,l;       //i=ISN,j=TTL,k=timstamp,l=P
struct timeval k;
};
#pragma pack(0)

//#define LISTENQ 30

//FILE *filePointer; 
//filePointer = fopen(“fileName.txt”, “w”);
//udp 

void dg_cli(FILE *fp, int sockfd, const struct sockaddr *pservaddr, socklen_t servlen,int T,int P)
{
	int n;
	char * buf = (char *)malloc (P * sizeof(char));
	//int sendline[3], recvline[3];
	struct packet a,*b;
	for(int pktno=1;pktno<=50;pktno++){
	a.i=ISN,a.j=T,a.l=P;
	gettimeofday(&a.k,NULL);
	
	//printf("\n\n%ld %ld",sizeof(b),sizeof(int));
	// sendline[0] = ISN;
	// sendline[1] = T; 
	// recvline[0] = ISN;
	// recvline[1] = T;
	while (a.j>0)
	{
		memcpy(buf,&a, sizeof(a));
		sendto(sockfd, buf, P, 0, pservaddr, servlen);
		n = recvfrom(sockfd, buf, sizeof(struct packet), 0, NULL, NULL);
		b=(struct packet *)buf;
		a.j=b->j - 1;
		//printf("\nMESSAGE received:%d %d %d",b->i,b->j,b->l);
	}
	struct timeval c;
	gettimeofday(&c,NULL);
	//printf("\n T has reached 0 for packet number:%d .",pktno);
	fprintf(fp,"%d %d %d %ld\n",pktno,T,a.l,((c.tv_sec - a.k.tv_sec)*1000000L+c.tv_usec) - a.k.tv_usec);
	// printf("Time take in microseconds is:%ld\n",
    //         ((c.tv_sec - a.k.tv_sec)*1000000L
    //        +c.tv_usec) - a.k.tv_usec
    //       );
	// 
	}
}

int main(int argc, char **argv)
{

	int sockfd;
	struct sockaddr_in servaddr;


	if (argc != 5)
	{
		printf("Error: type ./a.out <IPaddress> <T> <P> <filename>\n");
		exit(0);

	}
	else printf("Data appended into filename specified in form <packetno,T,packetsize(P),timetaken in microseconds>\n");


	FILE *f;
	f =(FILE *) fopen(argv[4],"a+");
	
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8080);

	if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
	{
		printf("inet_pton error for %s\n", argv[1]);
		exit(0);
	}
        
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	dg_cli(f, sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr),atoi(argv[2]),atoi(argv[3]));
        
	return 0;
}



