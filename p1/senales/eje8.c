#include <sys/types.h> //para pid_t
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
void manejador_clock(int sig){
    
    printf("\n--------RING;-------- \n señal %i recivida\n \n",sig);

}


int main(int argc, char ** argv){
    pid_t hijopid, childpid;
    int status;
    int i=0;
    signal(SIGALRM , manejador_clock);

while (1)
{
    if(i==0){alarm(5);
        printf("iniciando un teporizador de 5 segundos \n ");}
    if(i==1){alarm(3);
        printf("iniciando un teporizador de 3 segundos \n ");}
    if(i>1){alarm(1);
        printf("iniciando un teporizador de 1 segundos \n ");}
    pause();
    
    if(i==3){kill(getpid(),SIGKILL);}
    
    i++;
}

  
   
    exit(0);


}