#include <assert.h>
#include <stdio.h>
#include <pthread.h>

int matrix1[4][4]={{1,0,0,0},
                  {0,1,0,0},
                  {0,0,1,0},
                  {0,0,0,1}};
int matrix2[4][4]={{1,0,0,0},
                  {0,1,0,0},
                  {0,0,1,0},
                  {0,0,0,1}};
int result[4][4]={0};

void *mythread1(void *arg) {
    int temp = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            temp+= matrix1[0][j]*matrix2[j][i];
        }
        result[0][i]=temp;
        temp=0;
    }
    printf("FIRST THREAD, FIRST ROW:");
    for(int i=0;i<4;i++){
        printf("%d ",result[0][i]);
    }
    printf("\n");
    return NULL;
}
void *mythread2(void *arg) {
    int temp = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            temp+= matrix1[1][j]*matrix2[j][i];
        }
        result[1][i]=temp;
        temp=0;

    }
    printf("SECOND THREAD, SECOND ROW:");
    for(int i=0;i<4;i++){
        printf("%d ",result[1][i]);
    }
    printf("\n");

    return NULL;
}
void *mythread3(void *arg) {
    int temp = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            temp+= matrix1[2][j]*matrix2[j][i];
        }
        result[2][i]=temp;
        temp=0;

    }
    printf("THIRD THREAD, THIRD ROW:");
    for(int i=0;i<4;i++){
        printf("%d ",result[2][i]);
    }
    printf("\n");

    return NULL;
}
void *mythread4(void *arg) {
    int temp = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            temp+= matrix1[3][j]*matrix2[j][i];
        }
        result[3][i]=temp;
        temp=0;

    }
    printf("FOURTH THREAD, FOURTH ROW:");
    for(int i=0;i<4;i++){
        printf("%d ",result[3][i]);
    }
    printf("\n");

    return NULL;
}


int main(){
    pthread_t p1,p2,p3,p4;
    pthread_create(&p1, NULL, mythread1, NULL);
    pthread_create(&p2, NULL, mythread2, NULL); 
    pthread_create(&p3, NULL, mythread3, NULL); 
    pthread_create(&p4, NULL, mythread4, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(p3, NULL);
    pthread_join(p4, NULL);

    return 0;
    
}
