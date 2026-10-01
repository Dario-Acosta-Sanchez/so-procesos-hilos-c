#include <sys/types.h> //para pid_t
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

void * hilo2(void * arg){
    int * v = (int *) arg;
    int * count= malloc(sizeof(int));
    *count= v[0]+v[1];
    printf("hilo suma = %i \n",*count);
    free(arg);
    pthread_exit(count);
    
}
void * hilo5(void * arg){
    int * v = (int *) arg;
    int * count= malloc(sizeof(int));
    *count=0;
    for (int i = 0; i < 5; i++)
    {
        (*count)=(*count)+v[i];
    }
    
    printf("hilo suma = %i \n",*count);
    free(arg);
    pthread_exit(count);
    
}
int main(int argc, char **argv){
    pthread_t h;
    int  vector[10]= {1,1,1,7,1,1,1,0,1,1};
    int * result;
    int r=0;
    if (atoi(argv[1])==2)
    {
        for (int i = 0; i < 10; i+= 2)
        {
            int * aux = malloc(sizeof(int)*2);
            aux[0]=vector[i];
            aux[1]=vector[i+1];
            
                pthread_create(&h,NULL,hilo2, aux);
                pthread_join(h,(void **)&result);
                r+=*result;
                free(result);
            
            
        }
        
       printf("\n ----------------------resultado total = %i --------------------- \n ",r);
    }
    if (atoi(argv[1])==5)
    {
        for (int i = 0; i < 10; i+= 5)
        {
            int * aux = malloc(sizeof(int)*2);
            aux[0]=vector[i];
            aux[1]=vector[i+1];
            aux[2]=vector[i+2];
            aux[3]=vector[i+3];
            aux[4]=vector[i+4];

            
                pthread_create(&h,NULL,hilo5, aux);
                pthread_join(h,(void **)&result);
                r+=*result;
                free(result);
            
            
        }
        
       printf("\n ----------------------resultado total = %i --------------------- \n ",r);
    }


}