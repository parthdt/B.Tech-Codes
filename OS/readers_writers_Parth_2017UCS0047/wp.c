#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<assert.h>
#include<unistd.h> 

#define MAXTHREADS 100


sem_t lock,rMutex,wMutex,readTry;
sem_t lock,rMutex,wMutex,readTry;


int rCount = 0,wCount = 0;
int rTotal, wTotal, total;
int tCount = 0;

int rr[MAXTHREADS]={0},ww[MAXTHREADS]={0};

int readCount = 0, writeCount = 0;
int criticalValue = 0;

void *writer(int wid){
    sem_wait(&wMutex);
        writeCount++;
        if(writeCount==1)sem_wait(&readTry);
    sem_post(&wMutex);
    sem_wait(&lock);
    ww[wid-1]=1;
    printf("\n\n\tIn Writer Thread %d\n",wid);
    criticalValue++;
    printf("\n\tWroteValue = %d",criticalValue);
    for(int i=0;i<rCount;i++){
        if(rr[i]==-1)printf("\nReader %d is waiting.",i+1);

    }
    for(int i=0;i<wCount;i++){
        if(ww[i]==-1)printf("\nWriter %d is waiting.",i+1);

    }
    sem_post(&lock);
    sem_wait(&wMutex);
        writeCount--;
        if(writeCount==0)sem_post(&readTry);
    sem_post(&wMutex);
    

}

void *reader(int rid){
    sem_wait(&readTry);
    sem_wait(&rMutex);
    readCount++;
    if(readCount==1)
        sem_wait(&lock);
    sem_post(&rMutex);
    sem_post(&readTry);
    printf("\n\n\tIn Reader Thread %d\n",rid);
    rr[rid-1]=1;
    printf("\n\tRead Value = %d",criticalValue);

    for(int i=0;i<rCount;i++){
        if(rr[i]==-1)printf("\nReader %d is waiting.",i+1);

    }
    for(int i=0;i<wCount;i++){
        if(ww[i]==-1)printf("\nWriter %d is waiting.",i+1);

    }
    sem_wait(&rMutex);
    readCount--;
    if(readCount==0)
        sem_post(&lock);
    sem_post(&rMutex);
}

int main(){
    
    sem_init(&lock, 0, 1);
    sem_init(&rMutex,0,1);
    sem_init(&wMutex,0,1);
    sem_init(&readTry,0,1);
    
    pthread_t r[MAXTHREADS],w[MAXTHREADS];

    printf("\nEnter no. of readers:");scanf("%d",&rTotal);
    printf("\nEnter no. of writers:");scanf("%d",&wTotal);

    
    for(int i=0;i<rTotal;i++){
        rCount++;
        rr[i]=-1;
        pthread_create(&r[i],NULL,reader,rCount);
    }
    for(int i=0;i<wTotal;i++){
        wCount++;
        ww[i]=-1;
        pthread_create(&w[i],NULL,writer,wCount);
    }
    
    for(int i=0;i<rTotal;i++){
        pthread_join(r[i],NULL);
        rr[i]=0;
    }
    for(int i=0;i<wTotal;i++){
        pthread_join(w[i],NULL);
        ww[i]=0;
    }
    return 0;
}