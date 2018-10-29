#include "funciones.h"
#include "funciones2.h"

void Produce(int i, int call_flag, int msg_flag, llamadas *ptr1, mensajes *ptr2)
{
	int proc = 0;
	int total;
	call_flag = 0;
	msg_flag = 0;
	total = PRODUCCION*2;
	if (i == 0)
	{
		while(total > proc)
		{
			if (call_flag == 0)
			{
				//Seccion de llamadas
				doWait(SEM_PROD_LL,semid);
				for (int k = 0; k < 4; ++k)
				{
					switch(k){
	                    case 0:
	                        doWait(SEM_SCL_1, semid);
	                    case 1:
	                        doWait(SEM_SCL_2, semid);
	                    case 2:
	                        doWait(SEM_SCL_3, semid);
	                    case 3:
	                    	doWait(SEM_SCL_4, semid);
	                    case 4:
	                    	doWait(SEM_SCL_5, semid);
                	}
                	if (ptr1[k]->bandera != 1)
	                {
	                    strcpy(ptr1[k]->tel,"1111111111\n");
	                    ptr1[k]->bandera = 1;
	                    ptr1[k]->P_ID = 1;
	                    printf("Productor, escribio:%s en llamadas[%d]\n",ptr1[k]->tel, k);
	                    switch(k){
	                        case 0:
	                            doSignal(SEM_SCL_1, semid);
	                        case 1:
	                            doSignal(SEM_SCL_2, semid);
	                        case 2:
	                            doSignal(SEM_SCL_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCL_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCL_5, semid);
	                    	}
	                    break;
	                }
	                else{
	                    switch(k){
	                        case 0:
	                            doSignal(SEM_SCL_1, semid);
	                        case 1:
	                            doSignal(SEM_SCL_2, semid);
	                        case 2:
	                            doSignal(SEM_SCL_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCL_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCL_5, semid);
	                    }
	                }
	            }
	            proc++;
	            call_flag = 1;
	            doSignal(SEM_CONS_LL, semid);
			}
			else{
				//Seccion de mensajes
				doWait(SEM_PROD_MSG,semid);
				for (int k = 0; k < 4; ++k)
				{
					switch(k){
	                    case 0:
	                        doWait(SEM_SCM_1, semid);
	                    case 1:
	                        doWait(SEM_SCM_2, semid);
	                    case 2:
	                        doWait(SEM_SCM_3, semid);
	                    case 3:
	                    	doWait(SEM_SCM_4, semid);
	                    case 4:
	                    	doWait(SEM_SCM_5, semid);
                	}
                	if (ptr2[k]->bandera != 1)
	                {
	                    strcpy(ptr2[k]->msg,"Productor1\n");
	                    ptr2[k]->bandera = 1;
	                    ptr2[k]->P_ID = 1;
	                    printf("Productor, escribio:%s en mensajes[%d]\n",ptr2[k]->msg, k);
	                    switch(k){
	                        case 0:
	                            doSignal(SEM_SCM_1, semid);
	                        case 1:
	                            doSignal(SEM_SCM_2, semid);
	                        case 2:
	                            doSignal(SEM_SCM_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCM_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCM_5, semid);
	                    	}
	                    break;
	                }
	                else{
	                    switch(k){
	                        case 0:
	                            doSignal(SEM_SCM_1, semid);
	                        case 1:
	                            doSignal(SEM_SCM_2, semid);
	                        case 2:
	                            doSignal(SEM_SCM_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCM_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCM_5, semid);
	                    }
	                }
	            }
	            proc++;
	            msg_flag = 1;
	            call_flag = 0;
	            doSignal(SEM_CONS_MSG, semid);
			}
		}
	}
	if (i == 1)
	{
		while(total > proc)
		{
			if (call_flag == 0)
			{
				//Seccion de llamadas
				doWait(SEM_PROD_LL,semid);
				for (int k = 0; k < 4; ++k)
				{
					switch(k){
	                    case 0:
	                        doWait(SEM_SCL_1, semid);
	                    case 1:
	                        doWait(SEM_SCL_2, semid);
	                    case 2:
	                        doWait(SEM_SCL_3, semid);
	                    case 3:
	                    	doWait(SEM_SCL_4, semid);
	                    case 4:
	                    	doWait(SEM_SCL_5, semid);
                	}
                	if (ptr1[k]->bandera != 1)
	                {
	                    strcpy(ptr1[k]->tel,"2222222222\n");
	                    ptr1[k]->bandera = 1;
	                    ptr1[k]->P_ID = 2;
	                    printf("Productor, escribio:%s en llamadas[%d]\n",ptr1[k]->tel, k);
	                    switch(k){
	                        case 0:
	                            doSignal(SEM_SCL_1, semid);
	                        case 1:
	                            doSignal(SEM_SCL_2, semid);
	                        case 2:
	                            doSignal(SEM_SCL_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCL_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCL_5, semid);
	                    	}
	                    break;
	                }
	                else{
	                    switch(k){
	                        case 0:
	                            doSignal(SEM_SCL_1, semid);
	                        case 1:
	                            doSignal(SEM_SCL_2, semid);
	                        case 2:
	                            doSignal(SEM_SCL_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCL_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCL_5, semid);
	                    }
	                }
	            }
	            proc++;
	            call_flag = 1;
	            doSignal(SEM_CONS_LL, semid);
			}
			else{
				//Seccion de mensajes
				doWait(SEM_PROD_MSG,semid);
				for (int k = 0; k < 4; ++k)
				{
					switch(k){
	                    case 0:
	                        doWait(SEM_SCM_1, semid);
	                    case 1:
	                        doWait(SEM_SCM_2, semid);
	                    case 2:
	                        doWait(SEM_SCM_3, semid);
	                    case 3:
	                    	doWait(SEM_SCM_4, semid);
	                    case 4:
	                    	doWait(SEM_SCM_5, semid);
                	}
                	if (ptr2[k]->bandera != 1)
	                {
	                    strcpy(ptr2[k]->msg,"Productor2\n");
	                    ptr2[k]->bandera = 1;
	                    ptr2[k]->P_ID = 2;
	                    printf("Productor, escribio:%s en mensajes[%d]\n",ptr2[k]->msg, k);
	                    switch(k){
	                        case 0:
	                            doSignal(SEM_SCM_1, semid);
	                        case 1:
	                            doSignal(SEM_SCM_2, semid);
	                        case 2:
	                            doSignal(SEM_SCM_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCM_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCM_5, semid);
	                    	}
	                    break;
	                }
	                else{
	                    switch(k){
	                        case 0:
	                            doSignal(SEM_SCM_1, semid);
	                        case 1:
	                            doSignal(SEM_SCM_2, semid);
	                        case 2:
	                            doSignal(SEM_SCM_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCM_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCM_5, semid);
	                    }
	                }
	            }
	            proc++;
	            msg_flag = 1;
	            call_flag = 0;
	            doSignal(SEM_CONS_MSG, semid);
			}
		}
	}
	if (i == 2)
	{
		while(total > proc)
		{
			if (call_flag == 0)
			{
				//Seccion de llamadas
				doWait(SEM_PROD_LL,semid);
				for (int k = 0; k < 4; ++k)
				{
					switch(k){
	                    case 0:
	                        doWait(SEM_SCL_1, semid);
	                    case 1:
	                        doWait(SEM_SCL_2, semid);
	                    case 2:
	                        doWait(SEM_SCL_3, semid);
	                    case 3:
	                    	doWait(SEM_SCL_4, semid);
	                    case 4:
	                    	doWait(SEM_SCL_5, semid);
                	}
                	if (ptr1[k]->bandera != 1)
	                {
	                    strcpy(ptr1[k]->tel,"3333333333\n");
	                    ptr1[k]->bandera = 1;
	                    ptr1[k]->P_ID = 3;
	                    printf("Productor, escribio:%s en llamadas[%d]\n",ptr1[k]->tel, k);
	                    switch(k){
	                        case 0:
	                            doSignal(SEM_SCL_1, semid);
	                        case 1:
	                            doSignal(SEM_SCL_2, semid);
	                        case 2:
	                            doSignal(SEM_SCL_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCL_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCL_5, semid);
	                    	}
	                    break;
	                }
	                else{
	                    switch(k){
	                        case 0:
	                            doSignal(SEM_SCL_1, semid);
	                        case 1:
	                            doSignal(SEM_SCL_2, semid);
	                        case 2:
	                            doSignal(SEM_SCL_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCL_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCL_5, semid);
	                    }
	                }
	            }
	            proc++;
	            call_flag = 1;
	            doSignal(SEM_CONS_LL, semid);
			}
			else{
				//Seccion de mensajes
				doWait(SEM_PROD_MSG,semid);
				for (int k = 0; k < 4; ++k)
				{
					switch(k){
	                    case 0:
	                        doWait(SEM_SCM_1, semid);
	                    case 1:
	                        doWait(SEM_SCM_2, semid);
	                    case 2:
	                        doWait(SEM_SCM_3, semid);
	                    case 3:
	                    	doWait(SEM_SCM_4, semid);
	                    case 4:
	                    	doWait(SEM_SCM_5, semid);
                	}
                	if (ptr2[k]->bandera != 1)
	                {
	                    strcpy(ptr2[k]->msg,"Productor3\n");
	                    ptr2[k]->bandera = 1;
	                    ptr2[k]->P_ID = 3;
	                    printf("Productor, escribio:%s en mensajes[%d]\n",ptr2[k]->msg, k);
	                    switch(k){
	                        case 0:
	                            doSignal(SEM_SCM_1, semid);
	                        case 1:
	                            doSignal(SEM_SCM_2, semid);
	                        case 2:
	                            doSignal(SEM_SCM_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCM_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCM_5, semid);
	                    	}
	                    break;
	                }
	                else{
	                    switch(k){
	                        case 0:
	                            doSignal(SEM_SCM_1, semid);
	                        case 1:
	                            doSignal(SEM_SCM_2, semid);
	                        case 2:
	                            doSignal(SEM_SCM_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCM_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCM_5, semid);
	                    }
	                }
	            }
	            proc++;
	            msg_flag = 1;
	            call_flag = 0;
	            doSignal(SEM_CONS_MSG, semid);
			}
		}
	}
	if (i == 3)
	{
		while(total > proc)
		{
			if (call_flag == 0)
			{
				//Seccion de llamadas
				doWait(SEM_PROD_LL,semid);
				for (int k = 0; k < 4; ++k)
				{
					switch(k){
	                    case 0:
	                        doWait(SEM_SCL_1, semid);
	                    case 1:
	                        doWait(SEM_SCL_2, semid);
	                    case 2:
	                        doWait(SEM_SCL_3, semid);
	                    case 3:
	                    	doWait(SEM_SCL_4, semid);
	                    case 4:
	                    	doWait(SEM_SCL_5, semid);
                	}
                	if (ptr1[k]->bandera != 1)
	                {
	                    strcpy(ptr1[k]->tel,"4444444444\n");
	                    ptr1[k]->bandera = 1;
	                    ptr1[k]->P_ID = 4;
	                    printf("Productor, escribio:%s en llamadas[%d]\n",ptr1[k]->tel, k);
	                    switch(k){
	                        case 0:
	                            doSignal(SEM_SCL_1, semid);
	                        case 1:
	                            doSignal(SEM_SCL_2, semid);
	                        case 2:
	                            doSignal(SEM_SCL_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCL_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCL_5, semid);
	                    	}
	                    break;
	                }
	                else{
	                    switch(k){
	                        case 0:
	                            doSignal(SEM_SCL_1, semid);
	                        case 1:
	                            doSignal(SEM_SCL_2, semid);
	                        case 2:
	                            doSignal(SEM_SCL_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCL_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCL_5, semid);
	                    }
	                }
	            }
	            proc++;
	            call_flag = 1;
	            doSignal(SEM_CONS_LL, semid);
			}
			else{
				//Seccion de mensajes
				doWait(SEM_PROD_MSG,semid);
				for (int k = 0; k < 4; ++k)
				{
					switch(k){
	                    case 0:
	                        doWait(SEM_SCM_1, semid);
	                    case 1:
	                        doWait(SEM_SCM_2, semid);
	                    case 2:
	                        doWait(SEM_SCM_3, semid);
	                    case 3:
	                    	doWait(SEM_SCM_4, semid);
	                    case 4:
	                    	doWait(SEM_SCM_5, semid);
                	}
                	if (ptr2[k]->bandera != 1)
	                {
	                    strcpy(ptr2[k]->msg,"Productor4\n");
	                    ptr2[k]->bandera = 1;
	                    ptr2[k]->P_ID = 4;
	                    printf("Productor, escribio:%s en mensajes[%d]\n",ptr2[k]->msg, k);
	                    switch(k){
	                        case 0:
	                            doSignal(SEM_SCM_1, semid);
	                        case 1:
	                            doSignal(SEM_SCM_2, semid);
	                        case 2:
	                            doSignal(SEM_SCM_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCM_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCM_5, semid);
	                    	}
	                    break;
	                }
	                else{
	                    switch(k){
	                        case 0:
	                            doSignal(SEM_SCM_1, semid);
	                        case 1:
	                            doSignal(SEM_SCM_2, semid);
	                        case 2:
	                            doSignal(SEM_SCM_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCM_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCM_5, semid);
	                    }
	                }
	            }
	            proc++;
	            msg_flag = 1;
	            call_flag = 0;
	            doSignal(SEM_CONS_MSG, semid);
			}
		}
	}
}

void Consume(int i, int call_flag, int msg_flag, llamadas *ptr1, mensajes *ptr2)
{
	int proc = 0;
	int total, subtotal;
	int id;
	char buffer[12];
	call_flag = 0;
	msg_flag = 0;
	subtotal = PRODUCCION*4;
	total = subtotal*2;
	if (i == 0)
	{
		while((total-consumido) >= 0)
		{
			if (call_flag == 0)
			{
				//Seccion de LLamadas
				doWait(SEM_CONS_LL,semid);
				for (int k = 0; k < 4; ++k)
				{
					switch(k){
	                    case 0:
	                        doWait(SEM_SCL_1, semid);
	                    case 1:
	                        doWait(SEM_SCL_2, semid);
	                    case 2:
	                        doWait(SEM_SCL_3, semid);
	                    case 3:
	                    	doWait(SEM_SCL_4, semid);
	                    case 4:
	                    	doWait(SEM_SCL_5, semid);
                	}
                	if (ptr1[k]->bandera == 1)
                	{
                		printf("Consumidor, lee:%s en llamadas[%d]\n",ptr1[k]->tel, k);
                		strcpy(buffer,ptr1[k]->tel);
                		id = ptr1[k]->P_ID;
                		Escribe_llamadas(id,buffer);
                		doWait(SEM_AUX,semid);
                		consumido++;
                		call_flag = 1;
                		doSignal(SEM_AUX,semid);
                		ptr1[k]->bandera = 0;
                		switch(k){
	                        case 0:
	                            doSignal(SEM_SCL_1, semid);
	                        case 1:
	                            doSignal(SEM_SCL_2, semid);
	                        case 2:
	                            doSignal(SEM_SCL_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCL_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCL_5, semid);
	                    }
	                    break;
                	}
                	else{
                		switch(k){
	                        case 0:
	                            doSignal(SEM_SCL_1, semid);
	                        case 1:
	                            doSignal(SEM_SCL_2, semid);
	                        case 2:
	                            doSignal(SEM_SCL_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCL_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCL_5, semid);
	                    }
                	}
				}
				doSignal(SEM_PROD_LL,semid);
			}
			else{
				//Seccion de mensajes
				doWait(SEM_CONS_MSG,semid);
				for (int k = 0; k < 4; ++k)
				{
					switch(k){
	                    case 0:
	                        doWait(SEM_SCM_1, semid);
	                    case 1:
	                        doWait(SEM_SCM_2, semid);
	                    case 2:
	                        doWait(SEM_SCM_3, semid);
	                    case 3:
	                    	doWait(SEM_SCM_4, semid);
	                    case 4:
	                    	doWait(SEM_SCM_5, semid);
                	}
                	if (ptr2[k]->bandera == 1)
                	{
                		printf("Consumidor, lee:%s en mensajes[%d]\n",ptr2[k]->msg, k);
                		strcpy(buffer,ptr2[k]->msg);
                		id = ptr2[k]->P_ID;
                		Escribe_msg(id,buffer);
                		doWait(SEM_AUX,semid);
                		consumido++;
                		call_flag = 0;
                		msg_flag = 1;
                		doSignal(SEM_AUX,semid);
                		ptr2[k]->bandera = 0;
                		switch(k){
	                        case 0:
	                            doSignal(SEM_SCM_1, semid);
	                        case 1:
	                            doSignal(SEM_SCM_2, semid);
	                        case 2:
	                            doSignal(SEM_SCM_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCM_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCM_5, semid);
	                    }
	                    break;
                	}
                	else{
                		switch(k){
	                        case 0:
	                            doSignal(SEM_SCM_1, semid);
	                        case 1:
	                            doSignal(SEM_SCM_2, semid);
	                        case 2:
	                            doSignal(SEM_SCM_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCM_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCM_5, semid);
	                    }
                	}
				}
				doSignal(SEM_PROD_MSG,semid);
			}
		}
	}
	if (i == 1)
	{
		while((total-consumido) >= 0)
		{
			if (call_flag == 0)
			{
				//Seccion de LLamadas
				doWait(SEM_CONS_LL,semid);
				for (int k = 0; k < 4; ++k)
				{
					switch(k){
	                    case 0:
	                        doWait(SEM_SCL_1, semid);
	                    case 1:
	                        doWait(SEM_SCL_2, semid);
	                    case 2:
	                        doWait(SEM_SCL_3, semid);
	                    case 3:
	                    	doWait(SEM_SCL_4, semid);
	                    case 4:
	                    	doWait(SEM_SCL_5, semid);
                	}
                	if (ptr1[k]->bandera == 1)
                	{
                		printf("Consumidor, lee:%s en llamadas[%d]\n",ptr1[k]->tel, k);
                		strcpy(buffer,ptr1[k]->tel);
                		id = ptr1[k]->P_ID;
                		Escribe_llamadas(id,buffer);
                		doWait(SEM_AUX,semid);
                		consumido++;
                		call_flag = 1;
                		doSignal(SEM_AUX,semid);
                		ptr1[k]->bandera = 0;
                		switch(k){
	                        case 0:
	                            doSignal(SEM_SCL_1, semid);
	                        case 1:
	                            doSignal(SEM_SCL_2, semid);
	                        case 2:
	                            doSignal(SEM_SCL_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCL_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCL_5, semid);
	                    }
	                    break;
                	}
                	else{
                		switch(k){
	                        case 0:
	                            doSignal(SEM_SCL_1, semid);
	                        case 1:
	                            doSignal(SEM_SCL_2, semid);
	                        case 2:
	                            doSignal(SEM_SCL_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCL_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCL_5, semid);
	                    }
                	}
				}
				doSignal(SEM_PROD_LL,semid);
			}
			else{
				//Seccion de mensajes
				doWait(SEM_CONS_MSG,semid);
				for (int k = 0; k < 4; ++k)
				{
					switch(k){
	                    case 0:
	                        doWait(SEM_SCM_1, semid);
	                    case 1:
	                        doWait(SEM_SCM_2, semid);
	                    case 2:
	                        doWait(SEM_SCM_3, semid);
	                    case 3:
	                    	doWait(SEM_SCM_4, semid);
	                    case 4:
	                    	doWait(SEM_SCM_5, semid);
                	}
                	if (ptr2[k]->bandera == 1)
                	{
                		printf("Consumidor, lee:%s en mensajes[%d]\n",ptr2[k]->msg, k);
                		strcpy(buffer,ptr2[k]->msg);
                		id = ptr2[k]->P_ID;
                		Escribe_msg(id,buffer);
                		doWait(SEM_AUX,semid);
                		consumido++;
                		call_flag = 0;
                		msg_flag = 1;
                		doSignal(SEM_AUX,semid);
                		ptr2[k]->bandera = 0;
                		switch(k){
	                        case 0:
	                            doSignal(SEM_SCM_1, semid);
	                        case 1:
	                            doSignal(SEM_SCM_2, semid);
	                        case 2:
	                            doSignal(SEM_SCM_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCM_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCM_5, semid);
	                    }
	                    break;
                	}
                	else{
                		switch(k){
	                        case 0:
	                            doSignal(SEM_SCM_1, semid);
	                        case 1:
	                            doSignal(SEM_SCM_2, semid);
	                        case 2:
	                            doSignal(SEM_SCM_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCM_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCM_5, semid);
	                    }
                	}
				}
				doSignal(SEM_PROD_MSG,semid);
			}
		}
	}
	if (i == 2)
	{
		while((total-consumido) >= 0)
		{
			if (call_flag == 0)
			{
				//Seccion de LLamadas
				doWait(SEM_CONS_LL,semid);
				for (int k = 0; k < 4; ++k)
				{
					switch(k){
	                    case 0:
	                        doWait(SEM_SCL_1, semid);
	                    case 1:
	                        doWait(SEM_SCL_2, semid);
	                    case 2:
	                        doWait(SEM_SCL_3, semid);
	                    case 3:
	                    	doWait(SEM_SCL_4, semid);
	                    case 4:
	                    	doWait(SEM_SCL_5, semid);
                	}
                	if (ptr1[k]->bandera == 1)
                	{
                		printf("Consumidor, lee:%s en llamadas[%d]\n",ptr1[k]->tel, k);
                		strcpy(buffer,ptr1[k]->tel);
                		id = ptr1[k]->P_ID;
                		Escribe_llamadas(id,buffer);
                		doWait(SEM_AUX,semid);
                		consumido++;
                		call_flag = 1;
                		doSignal(SEM_AUX,semid);
                		ptr1[k]->bandera = 0;
                		switch(k){
	                        case 0:
	                            doSignal(SEM_SCL_1, semid);
	                        case 1:
	                            doSignal(SEM_SCL_2, semid);
	                        case 2:
	                            doSignal(SEM_SCL_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCL_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCL_5, semid);
	                    }
	                    break;
                	}
                	else{
                		switch(k){
	                        case 0:
	                            doSignal(SEM_SCL_1, semid);
	                        case 1:
	                            doSignal(SEM_SCL_2, semid);
	                        case 2:
	                            doSignal(SEM_SCL_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCL_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCL_5, semid);
	                    }
                	}
				}
				doSignal(SEM_PROD_LL,semid);
			}
			else{
				//Seccion de mensajes
				doWait(SEM_CONS_MSG,semid);
				for (int k = 0; k < 4; ++k)
				{
					switch(k){
	                    case 0:
	                        doWait(SEM_SCM_1, semid);
	                    case 1:
	                        doWait(SEM_SCM_2, semid);
	                    case 2:
	                        doWait(SEM_SCM_3, semid);
	                    case 3:
	                    	doWait(SEM_SCM_4, semid);
	                    case 4:
	                    	doWait(SEM_SCM_5, semid);
                	}
                	if (ptr2[k]->bandera == 1)
                	{
                		printf("Consumidor, lee:%s en mensajes[%d]\n",ptr2[k]->msg, k);
                		strcpy(buffer,ptr2[k]->msg);
                		id = ptr2[k]->P_ID;
                		Escribe_msg(id,buffer);
                		doWait(SEM_AUX,semid);
                		consumido++;
                		call_flag = 0;
                		msg_flag = 1;
                		doSignal(SEM_AUX,semid);
                		ptr2[k]->bandera = 0;
                		switch(k){
	                        case 0:
	                            doSignal(SEM_SCM_1, semid);
	                        case 1:
	                            doSignal(SEM_SCM_2, semid);
	                        case 2:
	                            doSignal(SEM_SCM_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCM_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCM_5, semid);
	                    }
	                    break;
                	}
                	else{
                		switch(k){
	                        case 0:
	                            doSignal(SEM_SCM_1, semid);
	                        case 1:
	                            doSignal(SEM_SCM_2, semid);
	                        case 2:
	                            doSignal(SEM_SCM_3, semid);
	                        case 3:
	                        	doSignal(SEM_SCM_4, semid);
	                        case 4:
	                        	doSignal(SEM_SCM_5, semid);
	                    }
                	}
				}
				doSignal(SEM_PROD_MSG,semid);
			}
		}
	}
}

void Escribe_llamadas(int id, char* buffer)
{
	FILE* fichero;
	switch(id)
	{
		case 1:
			doWait(SEM_SCU1_1,semid);
			fichero = fopen("Usuario1_llamadas.txt","a");
			fputs(buffer,fichero);
			fclose(fichero);
			doSignal(SEM_SCU1_1,semid);
			break;
		case 2:
			doWait(SEM_SCU2_1,semid);
			fichero = fopen("Usuario2_llamadas.txt","a");
			fputs(buffer,fichero);
			fclose(fichero);
			doSignal(SEM_SCU2_1,semid);
			break;
		case 3:
			doWait(SEM_SCU3_1,semid);
			fichero = fopen("Usuario3_llamadas.txt","a");
			fputs(buffer,fichero);
			fclose(fichero);
			doSignal(SEM_SCU3_1,semid);
			break;
		case 4:
			doWait(SEM_SCU4_1,semid);
			fichero = fopen("Usuario4_llamadas.txt","a");
			fputs(buffer,fichero);
			fclose(fichero);
			doSignal(SEM_SCU4_1,semid);
			break;
	}
}

void Escribe_msg(int id, char* buffer)
{
	FILE* fichero;
	switch(id)
	{
		case 1:
			doWait(SEM_SCU1_2,semid);
			fichero = fopen("Usuario1_msg.txt","a");
			fputs(buffer,fichero);
			fclose(fichero);
			doSignal(SEM_SCU1_2,semid);
			break;
		case 2:
			doWait(SEM_SCU2_2,semid);
			fichero = fopen("Usuario2_msg.txt","a");
			fputs(buffer,fichero);
			fclose(fichero);
			doSignal(SEM_SCU2_2,semid);
			break;
		case 3:
			doWait(SEM_SCU3_2,semid);
			fichero = fopen("Usuario3_msg.txt","a");
			fputs(buffer,fichero);
			fclose(fichero);
			doSignal(SEM_SCU3_2,semid);
			break;
		case 4:
			doWait(SEM_SCU4_2,semid);
			fichero = fopen("Usuario4_msg.txt","a");
			fputs(buffer,fichero);
			fclose(fichero);
			doSignal(SEM_SCU4_2,semid);
			break;
	}
}