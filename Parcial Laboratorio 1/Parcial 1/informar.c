#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "ventaAfiche.h"
#include "informar.h"

int informar_OrdenarClientePorNombreApellido(Cliente* pCliente, int limite)
{
    int retorno=-1;
    int i;
    int flagSwap;
    Cliente auxiliar;
    if(limite > 0 && pCliente != NULL)
    {
        retorno=0;
        do
        {
            flagSwap=0;
            for(i=0;i<limite-1;i++)
            {
                if(strcmp(pCliente[i].lastName,pCliente[i+1].lastName) > 0 ||
                  (strcmp(pCliente[i].lastName,pCliente[i+1].lastName) == 0 && strcmp(pCliente[i].name,pCliente[i+1].name)>0))
                {
                    flagSwap=1;
                    auxiliar=pCliente[i];
                    pCliente[i]=pCliente[i+1];
                    pCliente[i+1]=auxiliar;
                }
            }
        }while(flagSwap==1);

    }

    return retorno;
}
