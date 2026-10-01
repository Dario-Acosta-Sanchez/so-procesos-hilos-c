#include <sys/types.h> //para pid_t
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <pthread.h>
#include <time.h>

//glovales
int  camisetas [5] = {11,12,13,14,15};
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

void * compra(void * arg){

    int aleatorio  = rand()%11; 
    int bloquear = pthread_mutex_lock( & mut);
    int indice = * (int *) arg;
    if (bloquear !=0)
    {
        printf("error en compras \n");
        pthread_exit(NULL);
    }
    
    camisetas[indice] -=aleatorio; 
    bloquear = pthread_mutex_unlock(& mut);
    pthread_exit(NULL);
}
void * suministro(void * arg){

    int aleatorio  = rand()%101; 
    int bloquear = pthread_mutex_lock( &mut);
    int indice = * (int *) arg;
    if (bloquear !=0)
    {
        printf("error en suministros \n");
        pthread_exit(NULL);
    }
    camisetas[indice]+=aleatorio;
    bloquear = pthread_mutex_unlock(& mut);
    pthread_exit(NULL);
}


int main(int argc, char ** argv) {
    //---------------declarar----------------
    int m , n, aux;// n = compra m = sumiinistro
    pthread_t com, sum;
    srand(time(NULL));

    //---------------linea de argumentos---------------------
        if (argc != 3){
            printf("error en el numero de argumentos ; \n");
        }
        n=atoi(argv[1]);
        m=atoi(argv[2]);
    //--------------compra------------------
    aux= pthread_create(&com, NULL,compra,&n);
    aux= pthread_join(com, NULL );
    printf("-------------compras---------------- \n");
        for (int i = 0; i < 5; i++)
        {
            printf("camisetas [%i ] = %i \n", i , camisetas[i]);
        }
        

    aux= pthread_create(&sum,NULL,suministro,&m);
    aux= pthread_join(sum,NULL);
    printf("-------------suministro---------------- \n");
    for (int i = 0; i < 5; i++)
    {
        printf("camisetas [%i ] = %i \n", i , camisetas[i]);
    }
    


}