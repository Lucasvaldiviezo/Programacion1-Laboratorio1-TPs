#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "ventaAfiche.h"
#define MENU_MODIFICAR "\nIngrese la opcion que desea modificar:\n\
1)Nombre\n\
2)Apellido\n\
3)Cuit\n\
4)Terminar\n\
Elija:"
static int generarID(void);

int cliente_cargarForzadaIndice(Cliente* pCliente,int limite,char* name, char* lastName,char* cuit)
{
    int retorno=-1;
    int indice;
    cliente_getEmptyIndex(pCliente,limite,&indice);

    if(pCliente != NULL && limite >0)
    {
          if(indice >= 0)
          {
            strncpy(pCliente[indice].name,name,50);
            strncpy(pCliente[indice].lastName,lastName,50);
            strncpy(pCliente[indice].cuit,cuit,50);
            pCliente[indice].ID=generarID();
            pCliente[indice].isEmpty=0;
            retorno =0;
          }

    }


    return retorno;
}

int cliente_cargarDatosVacio(Cliente* pCliente, int limite)
{
    int retorno=-1;
    int i;
    if(pCliente != NULL && limite >0)
    {
        for(i=0;i<limite;i++)
        {
            pCliente[i].isEmpty=-1;
        }
        retorno=0;
    }

    return retorno;
}

int cliente_cargarIndice(Cliente* pCliente,int indice,int limite)
{
    int retorno=-1;
    char auxName[50];
    char auxLastName[50];
    char auxCuit[12];

    if(pCliente != NULL && limite >0)
    {
        if(utn_getNombre(auxName,"Ingrese nombre del cliente: ","Ese no es un nombre valido\n")==0)
        {
            strncpy(pCliente[indice].name,auxName,50);
            if(utn_getNombre(auxLastName,"Ingrese apellido del cliente: ","Ese no es un apellido valido \n")==0)
            {
                strncpy(pCliente[indice].lastName,auxLastName,50);
                if(utn_getCUIT(auxCuit,"Ingrese el cuit del cliente: ","Ese cuit no es valido\n")==0)
                {
                    strncpy(pCliente[indice].cuit,auxCuit,50);
                    pCliente[indice].ID=generarID();
                    pCliente[indice].isEmpty=0;
                    retorno =0;

                }

            }

        }
    }


    return retorno;
}

int cliente_modificarIndice(Cliente* pCliente,int id, int limite)
{
    int retorno=-1;
    char auxName[50];
    char auxLastName[50];
    char auxCuit[12];
    int indice;
    int opcion;
    int salir;
    indice=cliente_buscarClientePorId(pCliente,limite,id);
    if(indice >= 0)
    {
        if(pCliente != NULL && limite >0)
        {
            do
            {
                if(utn_getEntero(&opcion,10,MENU_MODIFICAR,"Esa no es una opcion valida\n",5,0)==0)
                {
                    switch(opcion)
                    {
                        case 1:
                            if(utn_getNombre(auxName,"\nIngrese el nuevo nombre del cliente: ","Ese no es un nombre valido\n")==0)
                            {
                                strncpy(pCliente[indice].name,auxName,50);
                            }
                            break;
                        case 2:
                            if(utn_getNombre(auxLastName,"\nIngrese el nuevo apellido del cliente: ","Ese no es un apellido valido\n")==0)
                            {
                                    strncpy(pCliente[indice].lastName,auxLastName,50);
                            }

                            break;
                        case 3:
                            if(utn_getCUIT(auxCuit,"\nIngrese el nuevo cuit del cliente: ","Ese cuit no es valido \n")==0)
                            {
                                strncpy(pCliente[indice].cuit,auxCuit,50);
                            }
                            break;
                        case 4:
                            salir=1;
                    }

                 }
            }while(salir==0);
            retorno=0;

        }

    }else
    {
        printf("El ID no existe\n");
    }
    return retorno;
    return 0;
}

int cliente_borrarCliente(Cliente* pCliente,int limite,int id)
{
    int retorno=-1;
    int i;
    int pNum;

    for(i=0;i<limite;i++)
    {
        if(pCliente[i].isEmpty==0 && pCliente[i].ID==id && utn_getEntero(&pNum,3,"\nDesea borrarlo realmente?(1:Si, 2:No): ","Esa opcion no es valida",3,0)==0)
        {
            if(pNum==1)
            {
                pCliente[i].isEmpty=-1;
                retorno=0;
                break;
            }else
            {
                printf("\n||No se borro el cliente||\n");
            }
        }
    }
    return retorno;
}

int cliente_mostrarIndice(Cliente* pCliente,int limite)
{
    int retorno=-1;
    int i;
    if(pCliente != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pCliente[i].isEmpty==0)
            {
                printf("\nEl ID del cliente es: %d", pCliente[i].ID);
                printf("\nEl nombre del cliente es: %s",pCliente[i].name);
                printf("\nEl apellido del cliente es: %s",pCliente[i].lastName);
                printf("\nEl cuit del cliente es: %s\n\n",pCliente[i].cuit);
                retorno=0;
            }
        }

    }

    return retorno;
}

int cliente_mostrarIndiceConVentas(Cliente* pCliente,int limite,Venta* pVenta,int limite2)
{
    int retorno=-1;
    int i;
    int cantVentas;
    if(pCliente != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pCliente[i].isEmpty==0)
            {
                cantVentas=venta_cantidadDeVentasCliente(pVenta,limite2,pCliente[i].ID);
                printf("\nEl ID del cliente es: %d", pCliente[i].ID);
                printf("\nEl nombre del cliente es: %s",pCliente[i].name);
                printf("\nEl apellido del cliente es: %s",pCliente[i].lastName);
                printf("\nEl cuit del cliente es: %s",pCliente[i].cuit);
                printf("\nLa cantidad de ventas a cobrar que tiene es: %d\n\n",cantVentas);
                retorno=0;
            }
        }

    }

    return retorno;
}

int cliente_mostrarUnIndice(Cliente* pCliente,int limite,int indice)
{
    int retorno=-1;
    if(pCliente != NULL && limite > 0 && indice >= 0)
    {
        if(pCliente[indice].isEmpty==0)
        {
            printf("\n-El ID del cliente es: %d", pCliente[indice].ID);
            printf("\n-El nombre del cliente es: %s",pCliente[indice].name);
            printf("\n-El apellido del cliente es: %s",pCliente[indice].lastName);
            printf("\n-El cuit del cliente es: %s\n",pCliente[indice].cuit);
            retorno=0;
        }

    }

    return retorno;
}


int cliente_buscarClientePorId(Cliente* pCliente,int limite,int id)
{
    int retorno=-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if(pCliente[i].isEmpty==0)
        {
            if(pCliente[i].ID==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int cliente_getEmptyIndex(Cliente* pCliente,int limite,int* indiceVacio)
{
    int i=0;
    int retorno = -1;
    if(pCliente != NULL && limite > 0)
    {
         while(i<limite)
        {
            if(pCliente[i].isEmpty==-1)
            {
                *indiceVacio=i;
                retorno = 0;
                break;
            }
            i++;
        }
    }

    return retorno;
}

int cliente_checkEmptyIndex(Cliente* pCliente,int limite)
{
    int i=0;
    int retorno = 0;
    if(pCliente != NULL && limite > 0)
    {
         while(i<limite)
        {
            if(pCliente[i].isEmpty==0)
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }

    return retorno;
}

static int generarID(void)
{
        static int cont = -1;
        return ++cont;
}
