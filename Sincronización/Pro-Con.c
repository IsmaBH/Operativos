#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEM_HIJO 0
#define SEM_PADRE 1

void doSignal(int semid, int numSem) {
    struct sembuf operacion; //Signal
    operacion.sem_num = numSem;
    operacion.sem_op = 1;
    operacion.sem_flg = 0;

    if (semop(semid, &operacion, 1) == -1) {
        perror(NULL);
        perror("Error al hacer Signal");
    }
}

void doWait(int semid, int numSem) {
    struct sembuf operacion;
    operacion.sem_num = numSem; /* Sobre el primero, ... */
    operacion.sem_op = -1; /* ... un wait (resto 1) */
    operacion.sem_flg = 0;

    if (semop(semid, &operacion, 1) == -1) {
        perror(NULL);
        perror("Error al hacer el Wait");
    }
}

int main(int argc, char **argv)
{
    int i = 20, semid;
    pid_t pid;
    key_t llave;

    llave = ftok(argv[0],'K');
    if((semid = semget(llave,2,IPC_CREAT | 0600)) == -1)
    {
        perror("semget");
        exit(-1);
    }
    else
    {
        /*inicializamos los semáforos*/
        /*cerramos el semáforo del proceso hijo*/
        semctl(semid,SEM_HIJO,SETVAL,0);
        /*Abrimos el semáforo del proceso padre*/
        semctl(semid,SEM_PADRE,SETVAL,1);

        for (int i = 0; i < count; ++i)
        {
            /* code */
        }

        if((pid = fork()) == -1)
        {
            perror("fork");
            exit(-1);
        }
        else if(pid == 0)
        {
            while(i)
            {
                /*cerramos el semáforo del proceso hijo*/
                doWait(semid,SEM_HIJO);
                printf("soy el proceso hijo id:%d y consumo i = %d\n"
                        ,getpid(),i--);
                sleep(2);
                /*Abrimos el semáforo del proceso padre*/
                doSignal(semid,SEM_PADRE);
            }
            
            /*borramos el semáforo*/
            semctl(semid,0,IPC_RMID,0);
        }
        else
        {
            while(i)
            {
                /*cerramos el semáforo del proceso padre*/
                doWait(semid,SEM_PADRE);

                printf("proceso padre id:%d, produsco  i = %d\n\n",getpid(),i--);
                /*Abrimos el semáforo del proceso hijo*/
                doSignal(semid,SEM_HIJO);
            }
            /*borrado del semáforo*/
            semctl(semid,0,IPC_RMID,0);
        }
    }
    return 0;
}
