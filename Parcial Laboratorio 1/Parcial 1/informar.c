#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "ventaAfiche.h"
#include "informar.h"

int informar_OrdenarClientePorApellidoNombre(Cliente* pCliente, int limite)
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

int informar_cantAfichesMayor(Venta* pVenta, int limite,int valorComparativo)
{

    int retorno = -1;
    int i;
    int flag=0;
    if(pVenta != NULL && limite > 0)
    {
        retorno=0;
        for(i=0;i<limite;i++)
        {
            if(pVenta[i].isEmpty==0 && pVenta[i].cantAfiches > valorComparativo)
            {
                venta_mostrarUnIndice(pVenta,limite,i);
                flag=1;
            }
        }

    }
    if(flag==0)
    {
        printf("Ninguna venta supera la cantidad de %d afiches",valorComparativo);
    }

    return retorno;
}

int informar_cantAfichesMenor(Venta* pVenta, int limite,int valorComparativo)
{

    int retorno = -1;
    int i;
    int flag=0;
    if(pVenta != NULL && limite > 0)
    {
        retorno=0;
        for(i=0;i<limite;i++)
        {
            if(pVenta[i].isEmpty==0 && pVenta[i].cantAfiches < valorComparativo)
            {
                venta_mostrarUnIndice(pVenta,limite,i);
                flag=1;
            }
        }

    }
    if(flag==0)
    {
        printf("Ninguna venta es menor a la cantidad de %d afiches",valorComparativo);
    }

    return retorno;
}

int informar_promedioAfiches(Venta* pVenta, int limite,float* promedioAfiches)
{

    int retorno = -1;
    int i;
    float afichesTotal=0;
    float cantVentas=0;
    if(pVenta != NULL && limite > 0)
    {
        retorno=0;
        for(i=0;i<limite;i++)
        {
            if(pVenta[i].isEmpty==0)
            {
                afichesTotal=afichesTotal+pVenta[i].cantAfiches;
                cantVentas++;
            }
        }

    }

    *promedioAfiches=afichesTotal/cantVentas;

    return retorno;
}

