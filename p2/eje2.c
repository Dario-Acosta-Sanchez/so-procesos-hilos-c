#include <sys/types.h> //para pid_t
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

void * hilo(void * arg){
    char * nombre = (char * )arg;
    FILE *f =fopen(nombre, "r");
    if(f ==NULL){
        perror("error en fopen \n ");
    }
    int *count=malloc(sizeof(int));
    *count=0;
    char aux[1024];
    while (fgets(aux,sizeof(aux),f))
    {
        (*count )++;
    }
    fclose(f);
    pthread_exit(count);

}

int main(int argc, char ** argv){
    
    for (int i = 1; i < argc; i++)
    {
        
        
        int * valor=malloc(sizeof(int));
        pthread_t h;
        pthread_create(&h,NULL,hilo,argv[i]);
        pthread_join(h,(void **)&valor);
        printf("argumento %i , texto %s, tiene %i filas \n",i,argv[i],*valor);
        free(valor);
    }
    
    printf("terminado \n");


}