#define _GNU_SOURCE                 //This includes some functions and extensions (CPU zero and set; sched_setaffinity)
#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <string.h>
#include <linux/unistd.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include <sys/wait.h>


int main()
{
    /*The following set of lines set cpu 0 as the working cpu, sets the current process on that cpu
      and sets the priority to be highest using SCHED_FIFO policy */

    cpu_set_t set;
    struct sched_param prio_param;
    int prio_max;

    CPU_ZERO( &set );
    CPU_SET( 0, &set );
    memset(&prio_param,0,sizeof(struct sched_param));

    if (sched_setaffinity( getpid(), sizeof( cpu_set_t ), &set ))
    {
        perror( "sched_setaffinity" );
        exit(EXIT_FAILURE);
    }

    if( (prio_max = sched_get_priority_max(SCHED_FIFO)) < 0 )
    {
        perror("sched_get_priority_max");
    }

    prio_param.sched_priority = prio_max;
    if( sched_setscheduler(getpid(),SCHED_FIFO,&prio_param) < 0 )
    {
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    }

   /*The following is the program that implements the type of prog in chapter 6 hw
     two pipes - read and write for parent and child processes, parent - writes, reads, waits;
     child reads, writes and similarly the process goes on for 10 iterations,  
     third pipe for reading and writing time stamps, and context switch time will be time of end-start / 20(2*10)*/

    int ret=-1;
    int pipe1[2];
    int pipe2[2];
    int timepipe[2];
        
    char string1[] = "Parent Str!\n";
    char string2[] = "Child Str!\n";
    char str1buffer[80];
    char str2buffer[80];
    int i=0;
    struct  timeval start,end;

    // Create an unnamed first pipe
    if (pipe(pipe1) == -1) 
    {
        fprintf(stderr, "Failed to create first pipe\n");
        return -1;
    }

    // create an unnamed Second pipe
    if (pipe(pipe2) == -1) 
    {
        fprintf(stderr, "Failed to create second pipe\n");
        return -1;
    }

    // Create an unnamed time pipe which will share in order to show time spend between processes
    if (pipe(timepipe) == -1) 
    {
        fprintf(stderr, "Failed to create time pipe\n");
        return -1;
    }


    if((ret=fork())==-1) perror("fork");
    else if(ret==0)
    {
        int n;        
        printf("Child Process is %d\n",getpid());

        for(n=0;n<10;n++)
        {
            
            read(pipe1[0], str1buffer, sizeof(str1buffer));
            printf("Received string1: %s", str1buffer);
            write(pipe2[1], string2, strlen(string2)+1);
        }

        gettimeofday(&end,0);
        n = sizeof(struct timeval);
        if( write(timepipe[1],&end,sizeof(struct timeval)) != n )
        {
            fprintf(stderr, "Child: Failed to write in time pipe\n");
            exit(EXIT_FAILURE);
        }

    }
    else
    {
        double switch_time;
        int n=-1;
        printf("Parent process is %d\n",getpid());
        gettimeofday(&start,0);
                /* Read in a string from the pipe */

        for(n=0;n<10;n++)
        {
            
            write(pipe1[1], string1, strlen(string1)+1);
            read(pipe2[0], str2buffer, sizeof(str2buffer));
            printf("Received string2: %s", str2buffer);
     }

        n = sizeof(struct timeval);
        if( read(timepipe[0],&end,sizeof(struct timeval)) != n )
        {
            fprintf(stderr, "Parent: Failed to read from time pipe\n");
            exit(EXIT_FAILURE);
        }

        wait(NULL);
        switch_time = ((end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec))/10;
        printf("context switch between two processes: %0.5lfus\n",switch_time/(20));


    }   

    return 0;
}