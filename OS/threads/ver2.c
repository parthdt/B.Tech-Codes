#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define	FIRST	0
#define SECOND 	1

#define	FALSE	0
#define TRUE 	1

#define	MICROSECONDS	1000

#define	NTURN	20

#define	RAND_MAX	0xFFFFFFFFu // Maximum 32-bit unsigned number

int	t1_inside = FALSE;
int	t2_inside = FALSE;
int	count=0;

pthread_t	t1, t2;

void	*thread1(void *args) {
	for(int i=0; i < NTURN; i++) {
		while(t2_inside == TRUE) {
			printf("Thread 1 waiting\n") ;
		}
		usleep((int)(3 * MICROSECONDS * ((float)arc4random()/RAND_MAX)));
		t1_inside = TRUE;
		// In critical section
		count = count + 1;
		printf("Thread 1 - Enter critical section -- %d\n", count);
		usleep((int)(1 * MICROSECONDS * ((float)arc4random()/RAND_MAX)));
		printf("Thread 1 - EXIT critical section -- %d\n", count);
		t1_inside = FALSE;
	}
}

void	*thread2(void *args) {
	for(int i=0; i < NTURN; i++) {
		//usleep((int)(2 * MICROSECONDS * ((float)arc4random()/RAND_MAX)));
		while(t1_inside == TRUE) {
			printf("Thread 2 waiting\n") ;
		}
		usleep((int)(5 * MICROSECONDS * ((float)arc4random()/RAND_MAX)));
		t2_inside = TRUE;
		printf("Thread 2 - Enter critical section -- %d\n", count);
		// In critical section
		count = count + 1;
		printf("Thread 2 - EXIT critical section -- %d\n", count);
		t2_inside = FALSE;
	}
}

void	main(void) {
	srand(time(NULL));
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
