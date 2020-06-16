#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10000                                         //array size

typedef struct _lock_t                                  //defining my_struct, flag is used for lock mechanism
{
    int flag;                                           
}my_struct;

int testAndSet (my_struct* oldPtr, int new)             //The following testAndSet and lock implementation has been referenced from  
{                                                       //OS - Three Easy Pieces (ARPACI-DUSSEAU)
    int old;
    #pragma omp atomic capture
    {
        old = oldPtr->flag;
        oldPtr->flag = new;
    }
    return old;
}

void mylock_init(my_struct *lock)
{
    lock->flag = 0;
}

void mylock_lock(my_struct *lock)
{
    while(testAndSet(lock,1) == 1);
}

void mylock_unlock(my_struct *lock)
{
    lock->flag = 0;
}

void mylock_destroy(my_struct *lock)
{
    free(lock);
}

int main()
{
    int arr[N];
    int i=0,sum=0;
    for(i=0;i<N;i++)arr[i]=1;
    my_struct *lock = malloc(sizeof(my_struct));
    mylock_init(lock);

    //omp_set_num_threads(10);                          //Uncomment this stratement to set num of threads
    //for(i=0;i<N;i++)printf("%d",arr[i]);              //Uncomment this statement to check array value

    #pragma omp parallel for default (shared) private (i)
    for(i=0;i<N;i++)
    {
        mylock_lock(lock);                              //uncomment lock, unlock statements and you'll
        sum+=arr[i];                                    //almost definitely find the wrong sum
        mylock_unlock(lock);
    }

    printf("Testing lock implentation... \nSum of array of size %d filled with 1s is : %d\n", N, sum);
    mylock_destroy(lock);

    return 0;
}

