#include <sys/types.h> //para pid_t
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <pthread.h>
#define ITERACIONES 1000000
int contador = 0;   // variable global compartida

void* incrementar(void* arg) {
    for (int i = 0; i < ITERACIONES; i++) {
        contador++;   // acceso concurrente NO protegido
    }
    return NULL;
}

int main() {
    pthread_t h1, h2;

    pthread_create(&h1, NULL, incrementar, NULL);
    pthread_create(&h2, NULL, incrementar, NULL);

    pthread_join(h1, NULL);
    pthread_join(h2, NULL);

    printf("Valor final del contador: %d\n", contador);

}   