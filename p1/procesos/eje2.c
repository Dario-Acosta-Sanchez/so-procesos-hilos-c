#include <sys/types.h> //para pid_t
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int main (int argc , char ** argv ){

//----------------comprobar argumentos-------------------
    
    if(argc =! 2){
        printf("Error de argumentos \n");
        exit(-1);
    }
//---------------crear hisjo-----------------
    pid_t hijo_pid, childpid;
    int status, n = atoi(argv[1]);
    for (int i = 0; i < n; i++)
    {
        hijo_pid=fork();
        if (hijo_pid<0)
        {
            printf("Error \n");
        }
        else if(hijo_pid ==0 ){
            printf("soy el hijo numero %i con pid %i y mi padre tiene  PID = %i \n ",i+1,getpid(),getppid());

        }
        else {
            printf("soy el papa del papa del papa... \n");
            childpid=wait(&status);
        if (childpid>0) // todo ha ido bien, tienes que ver el status de tu hijo, si lo han matado o no
        {
            if (WIFEXITED(status))
            {
                printf("soy el padre: %i y he recojido al hjio con Pid : %i estatus : %i \n",getpid(),childpid,WEXITSTATUS(status));
            }
            else if (WIFSIGNALED(status)){
                printf("soy el padre: %i y  al hjio con Pid : %i  lo han matao estatus : %i \n",getpid(),childpid,WTERMSIG(status));
            }
        }
        else {
            printf(
                "error de wait \n"
                
            );
            exit(-1);}
            break;
        }
        

    }
//-----------------esperar a los hijos------------

    
    

exit(0);

}