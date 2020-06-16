#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <assert.h>

#define loops 300
#define MAX 1000

pthread_t p,c1,c2;
sem_t empty;
sem_t full;
sem_t mutex, conmutex;

 int buffer[MAX];
 int fill = 0;
 int use = 0;

 void put(int value) {
    buffer[fill] = value; // line f1
    fill = (fill + 1) % MAX; // line f2
 }

 int get() {
    int tmp = buffer[use]; // line g1
    use = (use + 1) % MAX; // line g2
    return tmp;
 }

 void *producer(void *arg) {
    int i;
    for (i = 1; i <= 3 * loops; i++) {
        sem_wait(&empty); // line p1
        sem_wait(&mutex); // line p1.5 (MOVED MUTEX HERE...)
        put(i); // line p2
        printf("Produced 1 item\n");
        sem_post(&mutex); // line p2.5 (... AND HERE)
        sem_post(&full); // line p3
    }
 }

 void *consumer1(void *arg) {
    int i;
    for (i = 1; i <= loops; i++) {
        sem_wait(&full); // line c1
        sem_wait(&conmutex);
        sem_wait(&mutex); // line c1.5 (MOVED MUTEX HERE...)
        
        int tmp = get(); // line c2
        printf("Consumer 1, consumed 1 item\n");
        sem_post(&mutex); // line c2.5 (... AND HERE)
        sem_post(&conmutex);
        sem_post(&empty); // line c3
         }
 }
 void *consumer2(void *arg) {
    int i;
    for (i = 1; i <= loops; i++) {
        sem_wait(&full); 
        sem_wait(&conmutex);
        sem_post(&empty);
        sem_wait(&full);
        sem_wait(&mutex);
        int tmp = get(); 
        tmp = get(); 
        printf("Consumer 2, consumed 2 items\n");
        sem_post(&conmutex);
        sem_post(&mutex); 
        sem_post(&empty); 
    }
 }


 int main(int argc, char *argv[]) {
    sem_init(&empty, 0, MAX);
    sem_init(&full, 0, 0); 
    sem_init(&mutex, 0, 1); 
    sem_init(&conmutex, 0, 1);
    int success;
    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c1, NULL, consumer1, NULL);
    pthread_create(&c2, NULL, consumer2, NULL);
    pthread_join(p, NULL);
    pthread_join(c1, NULL);
    pthread_join(c2, NULL);

    
 
 }