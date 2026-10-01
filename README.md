# Sistemas Operativos · Procesos, señales e hilos en C

Prácticas de **Sistemas Operativos** (2.º de Ingeniería Informática, Universidad de Córdoba) sobre la API POSIX en Linux.

## Contenido

| Carpeta | Tema | Llamadas principales |
|---|---|---|
| `p1/procesos` | Creación de procesos, árboles de procesos y ejecución de programas | `fork`, `wait`/`waitpid`, `execlp`, `execvp` |
| `p1/senales` | Comunicación entre procesos mediante señales y temporizadores | `signal`, `kill`, `alarm` |
| `p2` | Programación con hilos | `pthread_create`, `pthread_join` |
| `p3` | Sincronización y exclusión mutua: simulación de compras concurrentes sobre un stock compartido | `pthread_mutex_lock` / `unlock` |

## Compilar

```bash
gcc -pthread p3/eje1.c -o eje1
./eje1
```

![C](https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=black&style=flat) ![Linux](https://img.shields.io/badge/Linux-FCC624?logo=linux&logoColor=black&style=flat) ![POSIX](https://img.shields.io/badge/POSIX-threads-555?style=flat)
