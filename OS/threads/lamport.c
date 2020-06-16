#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include <stdbool.h>

#define NPROCESS 4
#define	NTURN	25

bool choosing[NPROCESS] = {false};
int ticket[NPROCESS] = {0};

int maxTicket = 0;
int count = 0;

pthread_t	t1, t2, t3, t4;

void	*thread1(int x) {
	for(int i=0; i < NTURN; i++) {
		 choosing[x] = true;
     ticket[x] = maxTicket+1;
	 maxTicket=maxTicket+1;
     choosing[x] = false;

     for (int pt = 0; pt < NPROCESS; pt++){
       if (pt == x)
        continue;

        while (choosing[pt] != false);
        while(ticket[pt] != 0 && ticket[pt] < ticket[x]);
        if (ticket[pt] == ticket[x] && pt < x){
          while (ticket[pt] != 0);
        }
     }
	 printf("Thread %d in critical section, count = %d\n", x, count);
     count = count + 1;
	 printf("Thread %d exit critical section, count =  %d\n", x, count);
 		 
     ticket[x] = 0;
	}
}


void	main(void) {
	if( pthread_create(&t1, NULL, thread1, 1) != 0) {
		printf("Thread one not created. Quitting.\n");
		exit(0);
	}
	if( pthread_create(&t2, NULL, thread1, 2) != 0) {
		printf("Thread two not created. Quitting.\n");
		exit(0);
	}
  if( pthread_create(&t3, NULL, thread1, 3) != 0) {
		printf("Thread one not created. Quitting.\n");
		exit(0);
	}
	if( pthread_create(&t4, NULL, thread1, 4) != 0) {
		printf("Thread two not created. Quitting.\n");
		exit(0);
	}
	if(pthread_join(t1, NULL) != 0) {
		//perror("Thread 1 (exit) ");
		exit(0);
	}
  if(pthread_join(t2, NULL) != 0) {
		//perror("Thread 1 (exit) ");
		exit(0);
	}
  if(pthread_join(t3, NULL) != 0) {
		//perror("Thread 1 (exit) ");
		exit(0);
	}
	if(pthread_join(t4, NULL) != 0) {
		//perror("Thread 1 (exit) ");
		exit(0);
	}
	return;
}