#include "funciones.h"

void analiza(int opt, int fd1, char *myfifo1)
{
	char tam[4];
    char IDPROC[3];
	char estado1[6] = "1P";
    char estado2[5] = "2P";
    char estado3[2] = "3S";
    char estado5[2] = "5P";
	char * orden = "fin\n";
	switch(opt)
	{
		case 1:
			printf("Tamaño de memoria requerido(kbytes): ");
			scanf("%s", tam);
			//Preguntamos al administrador si hay mem disponible
			fd1 = open(myfifo1,O_WRONLY);
			//La "P" pregunta por la memoria principal
			strcat(estado1,tam);
			write(fd1, estado1, sizeof(estado1));
			//Cerramos para poder obtener una respuesta
			close(fd1);
	        break;
		case 2:
            printf("Id del proceso a Eliminar: ");
            scanf("%s", IDPROC);
            //Preguntamos al administrador si existe el proceso solicitado en RAM
            fd1 = open(myfifo1,O_WRONLY);
            //La "P" pregunta por la memoria principal
            strcat(estado2,IDPROC);
            write(fd1, estado2, sizeof(estado2));
            //Cerramos para poder obtener una respuesta
            close(fd1);
            break;
		case 3:
            //Preguntamos al administrador si existe el proceso solicitado en RAM
            fd1 = open(myfifo1,O_WRONLY);
            //La "S" pregunta por la memoria secundaria
            write(fd1, estado3, sizeof(estado3));
            //Cerramos para poder obtener una respuesta
            close(fd1);
            break;
		//case 4:
		case 5:
            //Preguntamos al administrador por el estado de las paginas
            fd1 = open(myfifo1,O_WRONLY);
            write(fd1, estado5, sizeof(estado5));
            //Cerramos para poder obtener una respuesta
            close(fd1);
            break;
		//case 6:
		//case 7:
		case 0:
			fd1 = open(myfifo1,O_WRONLY);
			strcpy(str4,orden);
			write(fd1, str4, sizeof(str4));
			close(fd1);
			printf("Termine la administracion\n");
			break;
	}
}

int administra(char *str1, int fd1, char * myfifo1, unsigned char ** Dir_RAM, unsigned char ** Dir_SWAP, lista *L, int ram, int swap)
{
	int i,j = 0;
	int memoria, vejez = 0; 
    int contador_aux = 0;
    char aux1 = 'P';
    char mem[3];
    char proc[3];
    int id_aux;
    posicion p1,p2,p3;
    elemento e1,e2;

	int packet = strlen(str1);
    char opt = str1[0];
    char tipo = str1[1];
    switch(opt)
    {
    	case '1':
            memcpy(mem, str1 + 2, 3);
            memoria = atoi(mem);    
            // Imprimimos el mensaje obtenido
            printf("Soy el cliente 1 y recibi el mensaje: %s\n", str1); 
            printf("Memoria solicitada:%d\n", memoria);
            printf("Opcion solicitada: %c\n", opt);
            close(fd1);
            if (aux1 == tipo)
            {
                 if (memoria <= ram)
                 {
                    process++;
                 	//Aqui haria las operaciones para crear el proceso
                    p1 = First(&L[0]);
                    for (i=1;i<=Size(&L[0]);i++)
                    {
                        e1=Position(&L[0],p1);
                        if (e1.ID_PROCESO == 0)
                        {
                            contador_aux = contador_aux + e1.PAG_TAM;
                            e1.ID_PROCESO = process;
                            e1.TTL = process;
                            Replace(&L[0], p1, e1);
                            if (contador_aux >= memoria)
                            {
                                ram = ram - contador_aux;
                                printf("Creacion exitosa\n");
                                printf("RAM restante: %d\n", ram);
                                return ram;
                                break;
                            }
                        }
                        p1=Following(&L[0],p1);
                    }
                 }else{
                    printf("No hay memoria suficiente en la principal\n");
		        	printf("Haga swap de alguno de los procesos existentes\n");
		        	printf("o elimine alguno de los existentes\n");
                    return ram;
                    break;
                 }
            }
            break;
    	case '2':
            memcpy(proc, str1+2,3);
            id_aux = atoi(proc);
            close(fd1);
            //Imprimimos el ID del proceso a eliminar
            printf("Proceso a eliminar: %d\n", id_aux);
            //Aqui haria las operaciones para eliminar el proceso
            p1 = First(&L[0]);
            for (i=1;i<=Size(&L[0]);i++)
            {
                e1=Position(&L[0],p1);
                if (e1.ID_PROCESO == id_aux)
                {
                    contador_aux = contador_aux + e1.PAG_TAM;
                    e1.ID_PROCESO = 0;
                    e1.TTL = 0;
                    Replace(&L[0], p1, e1);
                }
                p1=Following(&L[0],p1);
            }
            ram = ram + contador_aux;
            printf("Se elimino con exito\n");
            printf("RAM restante: %d\n", ram);
            return ram;
    		break;
    	case '3':
            //Aqui son las operaciones para encontrar al proceso mas viejo
            for (int k = 1; k <= process; ++k)
            {
                p1 = First(&L[0]);
                for (i=1;i<=Size(&L[0]);i++)
                {
                    e1=Position(&L[0],p1);
                    if (e1.TTL == k)
                    {
                        vejez == e1.TTL;
                        break;
                    }
                    p1=Following(&L[0],p1);
                }
                if (vejez != 0)
                {
                    break;
                }
            }
    	case '4':
    	case '5':
            //Con esto imprimimos las paginas
            p1 = First(&L[0]);
            for (i=1;i<=Size(&L[0]);i++)
            {
                printf("Pagina %d:\n", i);
                e1=Position(&L[0],p1);
                printf("\tID de pagina:%d\n",e1.ID_PAGINA);
                printf("\tID de memoria fisica:%d\n",e1.ID_MEM_FISICA);
                printf("\tID de proceso:%d\n",e1.ID_PROCESO);
                printf("\tTTL:%d\n",e1.TTL);
                printf("\tNumero de segmento:%d\n",e1.NO_SEGMENTO);
                printf("\tTamaño de pagina:%d\n",e1.PAG_TAM);
                p1=Following(&L[0],p1);
            }
            break;
    	case '6':
    	case '7':
    		break;
    }
}