#include <sys/types.h> //para pid_t
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <pthread.h>
#include <time.h>


void * hilo(void * arg){

srand(time(NULL)+pthread_self());
int a=rand()%100;
int b=rand()%100;

int *e= malloc(sizeof(int));
*e=a+b;
printf(" %i + %i = %i \n",a,b,a+b);
pthread_exit(e);
}

int main(){
    pthread_t h;
    int *valor;
    pthread_create(&h,NULL,hilo,NULL);
    pthread_join(h,(void **)&valor);
    printf("El hilo devolvió: %d \n", *valor);

}