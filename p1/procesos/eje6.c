#include <sys/types.h> //para pid_t
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
// ./eje6 fichero.txt numerohijos

int main(int argc , char ** argv){
    if(argc !=3){
        printf("NUMERO DE ARGS INVALIDO \n");
        exit(-1);
    }
    pid_t hijopid,childpit;
    int status;
    int n= atoi(argv[2]);
    FILE * f = fopen(argv[1],"w");
    if(f==NULL){
        printf("error abriendo fichero \n");
        exit(-1);
    }
    for (int i = 0; i < n; i++)
    {
        
        hijopid=fork();
        if (hijopid==0)
        {
            fprintf(f,"soy el hijo numero %i , con pid = %i y mi padre es: %i \n",i,getpid(), getppid());
            fflush(f);
            exit(0);
            
        }
    }
   
    fprintf(f,"soy el padre con pid = %i \n",getpid());
    fflush(f);
    
    //esperar hijos
    for (int i = 0; i < n; i++)
    {
        childpit=wait(&status);
        if (childpit>0)
        {
            if(WIFEXITED(status)){
                fprintf(f,"soy el padre con pid = %i, he recojido al hijo  %i \n",getpid(),childpit);
                fflush(f);
            }
            if(WIFSIGNALED(status)){
                fprintf(f,"soy el padre con pid = %i, han matao al hijo  %i \n",getpid(),childpit);
                fflush(f);
            }
        }
        else {
            printf(
                "error de wait \n"
            );
           }
        
    }
    execlp("cat", "cat", argv[1], NULL);
    fclose(f);
    exit(0);
}