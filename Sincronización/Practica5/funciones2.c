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
	                    strcpy(ptr1[k]->tel,"1111111111");
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
	                    strcpy(ptr2[k]->msg,"Productor1");
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
	                    strcpy(ptr1[k]->tel,"2222222222");
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
	                    strcpy(ptr2[k]->msg,"Productor2");
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
	                    strcpy(ptr1[k]->tel,"3333333333");
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
	                    strcpy(ptr2[k]->msg,"Productor3");
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
	                    strcpy(ptr1[k]->tel,"4444444444");
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
	                    strcpy(ptr2[k]->msg,"Productor4");
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