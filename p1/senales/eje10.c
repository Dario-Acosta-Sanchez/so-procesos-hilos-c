#include <sys/types.h> //para pid_t
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
void manejarSennal(int sig){
    printf("recibido (sginal %i)\n", sig);

}
int main(){

    printf("mi pid es: %i \n", getpid());
    signal(SIGUSR1, manejarSennal);
    while(1){
        pause();
    }
}