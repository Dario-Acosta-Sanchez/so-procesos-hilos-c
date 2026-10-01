#include <sys/types.h> //para pid_t
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
int main(int argc, char ** argv){

    if(argc < 3){
        printf("error parametros \n ");
        exit(-1);
    }
    pid_t childpid, hijo_pid , hijo_pid2;
    int status;
    int aux;


        hijo_pid= fork();
        if (hijo_pid==0)
        {
            printf("soy el hijo con pid %i ",getpid());
           
            printf("abriendo calculadora \n");
            execlp(argv[1], argv[1], NULL); //argv 1 = gnome-calculator


            exit(0);
            
        }
        if(hijo_pid>0){
            printf("soy el padre con pid = %i \n",getpid());
            
        }
        
        hijo_pid2 = fork();
  
        if(hijo_pid2==0){
            printf("soy el hijo con pid = %i \n",getpid());
            
            printf("abriendo editor de textos \n");
            int n = argc - 2; // número de archivos + editor
            char **args = malloc(sizeof(char*) * (n + 2));
            args[0] = argv[2];          // programa/editor
            for (int i = 0; i < n; i++) {
                args[i + 1] = argv[i + 2]; // archivos
            }
            args[n + 1] = NULL;
            
            execvp(argv[2], args);
            perror("exec editor falló");
            exit(1);
            
        }


    // -------------------vamos a esperar a los hijos-------------
for (int i = 1; i < argc; i++)
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