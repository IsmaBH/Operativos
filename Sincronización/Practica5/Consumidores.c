#include "funciones.h"

int main()
{
	int status;
	int i;
	llamadas *ptr1;
	mensajes *ptr2;
	key_t llave;
	llave = ftok("/bin/ls",21);
	crear_ligar_sem(llave);
	ptr1 = crear_ligar_mem1(llave);
	ptr2 = crear_ligar_mem2(llave);
	printf("semid:%d\t memid:%d\n",semid,memid);

	for (i = 0; i < 3; i++)
	{
		pid_t pid = fork();
		switch(pid)
		{
			case -1:
				printf("error al crear el hijo\n");
				return -1;
				break;
			case 0:
				/*hijos*/
				sleep(1);
				printf("Soy el hijo numero %d con PID:%d y PPID:%d\n", i, getpid(), getppid());
				exit(0);
				break;
			default:
				/*Padre*/
				if (i == 0)
				{
					printf("Ha empezado a consumirse\n");
				}
				if (i == 2)
				{
					wait(&status);
					wait(&status);
					wait(&status);
				}
				//break;
		}
	}
	return 0;
}