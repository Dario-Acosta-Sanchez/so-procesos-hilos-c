#include <sys/types.h> //para pid_t
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>


void tratarSennal(int sig){
printf("soy el hijo con pid %i con padre %i (signal %i)\n",getpid(),getppid(), sig);


}

int main(){
    pid_t hijopid, childpid;
    signal(SIGUSR1, tratarSennal);
    hijopid= fork();
    if(hijopid==0){
        while(1){
            pause();
        }

    }
    else{
        for(int i =0; i<5 ; i++)
        {
            sleep(1);
            kill(hijopid,SIGUSR1);
        }
    }
    exit(0);

}