#include <sys/types.h> //para pid_t
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

/*
    hijo_pid = "variable " if(<0){Error} if(>0){es el apdre} if(==0){es el hijo}



*/
/*

            EStructura;
        1 creas los hijos
        2 hacen lo que tenga que hacer
        3 el padre e3spera a los hijos
*/

int main(int argc, char** argv){
//---------------comprobar los arg-------------------
    if(argc != 2 ){
        printf("error \n");
       exit(-1);
    }
//--------------crear los pid-------------------
pid_t hijo_pid, childpid;
int status;
int n = atoi(argv[1]);

for (int i = 0; i < n; i++)
{
    hijo_pid = fork(); //crear el hijo 
    if(hijo_pid<0){
        printf("error de fork ");
        exit(-1);
    }
    else if (hijo_pid ==0)
    {
       printf("soy el hijo numero %i con pid %i y mi padre tiene  PID = %i \n ",i+1,getpid(),getppid());
       printf("vamos a esperar %i0 segundos \n ",i);
       sleep(10*i);
       exit(EXIT_SUCCESS);
    }

    
}
// -------------------vamos a esperar a los hijos-------------
for (int i = 0; i < n; i++)
{
   childpid=wait(&status);
   if(childpid> 0){
    if(WIFEXITED(status)){
        printf("soy el padre y he recojido al hjio con Pid : %i estatus : %i \n",childpid,WEXITSTATUS(status));

    }
    if(WIFSIGNALED(status)){
        printf("soy el padre y  al hjio con Pid : %i  lo han matao estatus : %i \n",childpid,WTERMSIG(status));
    }

   }
   else {
    printf(
        "error de wait \n"
    );
   }
 
}

exit(0);



}
