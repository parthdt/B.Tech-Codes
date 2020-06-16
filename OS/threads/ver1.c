#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define	FIRST	0
#define SECOND 	1

#define	NTURN	100

int	turn = FIRST;
int	count=0;

pthread_t	t1, t2;

void	*thread1(void *args) {
	for(int i=0; i < NTURN; i++) {
		while(turn != FIRST) ;
		// In critical section
		count = count + 1;
		printf("Thread 1 in critical section -- %d\n", count);
		turn = SECOND;
	}
}

void	*thread2(void *args) {
	for(int i=0; i < NTURN; i++) {
		while(turn != SECOND) ;
		// In critical section
		count = count + 1;
		printf("Thread 2 in critical section -- %d\n", count);
		turn = FIRST;
	}
}

void	main(void) {
	if( pthread_create(&t1, NULL, thread1, NULL) != 0) {
		printf("Thread one not created. Quitting.\n");
		exit(0);
	}
	if( pthread_create(&t2, NULL, thread2, NULL) != 0) {
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
	return;
}
