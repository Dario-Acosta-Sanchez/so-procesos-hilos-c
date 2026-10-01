#include <sys/types.h> //para pid_t
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>


int main(int argc, char ** argv){
    pid_t pid = atoi(argv[1]);
    kill(pid, SIGUSR1);
    sleep(1);
    kill(pid, SIGKILL);
}