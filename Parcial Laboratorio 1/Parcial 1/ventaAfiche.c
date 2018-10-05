#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "ventaAfiche.h"

static int generarID(void);

int venta_cargaForzadaVenta(Venta* pVentas,int limite,char* nombreImagen, char* zona,char* estado,int cantAfiches,int idCliente)
{
    int retorno=-1;
    int indice;
    venta_getEmptyIndex(pVentas,limite,&indice);

    if(pVentas != NULL && limite >0)
    {
          if(indice >= 0)
          {
            strncpy(pVentas[indice].nombreImagen,nombreImagen,50);
            strncpy(pVentas[indice].zona,zona,50);
            strncpy(pVentas[indice].estado,estado,50);
            pVentas[indice].cantAfiches=cantAfiches;
            pVentas[indice].idCliente=idCliente;
            pVentas[indice].ID=generarID();
            pVentas[indice].isEmpty=0;
            retorno =0;
          }

    }


    return retorno;
}

int venta_cargarDatosVacio(Venta* pVenta, int limite)
{
    int retorno=-1;
    int i;
    if(pVenta != NULL && limite >0)
    {
        for(i=0;i<limite;i++)
        {
            pVenta[i].isEmpty=-1;
        }
        retorno=0;
    }

    return retorno;
}

int venta_getEmptyIndex(Venta* pVenta,int limite,int* indiceVacio)
{
    int i=0;
    int retorno = -1;
    if(pVenta != NULL && limite > 0)
    {
         while(i<limite)
        {
            if(pVenta[i].isEmpty==-1)
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

int venta_mostrarUnIndice(Venta* pVenta,int limite,int indice)
{
    int retorno=-1;
    if(pVenta != NULL && limite > 0 && indice >= 0)
    {
        if(pVenta[indice].isEmpty==0)
        {
            printf("\n-El ID de la venta es: %d", pVenta[indice].ID);
            printf("\n-LA cantidad de afiches es: %d", pVenta[indice].cantAfiches);
            printf("\n-El nombre del archivo es: %s",pVenta[indice].nombreImagen);
            printf("\n-La zona es: %s",pVenta[indice].zona);
            printf("\n-El ID del cliente es: %d",pVenta[indice].idCliente);
            printf("\n-El estado es: %s\n",pVenta[indice].estado);
            retorno=0;
        }

    }

    return retorno;
}

int venta_mostrarIndice(Venta* pVenta,int limite)
{
    int retorno=-1;
    int i;
    if(pVenta != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pVenta[i].isEmpty==0)
            {
                printf("\n-El ID de la venta es: %d", pVenta[i].ID);
                printf("\n-LA cantidad de afiches es: %d", pVenta[i].cantAfiches);
                printf("\n-El nombre del archivo es: %s",pVenta[i].nombreImagen);
                printf("\n-La zona es: %s",pVenta[i].zona);
                printf("\n-El ID del cliente es: %d",pVenta[i].idCliente);
                printf("\n-El estado es: %s\n",pVenta[i].estado);
                retorno=0;
            }
        }

    }

    return retorno;
}

int venta_cargarIndice(Venta* pVenta,int indice,int limite,int idCliente)
{
    int retorno=-1;
    char auxNombreImagen[50];
    char auxZona[50];
    int auxCantAfiches;

    if(pVenta != NULL && limite >0)
    {
        if(utn_getEnteroSinLimites(&auxCantAfiches,5,"\nIngrese la cantidad de afiches que desea: ","Esa no es una cantidad valido\n")==0)
        {
            pVenta[indice].cantAfiches=auxCantAfiches;
            if(utn_getNombre(auxNombreImagen,"Ingrese el nombre de la imagen para el afiche: ","Ese no es un nombre valido \n")==0)
            {
                strncpy(pVenta[indice].nombreImagen,auxNombreImagen,50);
                if(utn_getNombre(auxZona,"Ingrese la zona donde quiere pegar los afiches: ","Ese cuit no es valido\n")==0)
                {
                    strncpy(pVenta[indice].zona,auxZona,50);
                    pVenta[indice].ID=generarID();
                    pVenta[indice].idCliente=idCliente;
                    strncpy(pVenta[indice].estado,"A cobrar",50);
                    pVenta[indice].isEmpty=0;
                    retorno =0;

                }

            }

        }
    }


    return retorno;
}

int venta_modificarIndice(Venta* pVenta,int indice,int limite,int idCliente)
{
    int retorno=-1;
    char auxZona[50];
    int auxCantAfiches;

    if(pVenta != NULL && limite >0)
    {
        if(utn_getEnteroSinLimites(&auxCantAfiches,5,"\nIngrese la nueva cantidad de afiches que desea: ","Esa no es una cantidad valido\n")==0)
        {
            pVenta[indice].cantAfiches=auxCantAfiches;
            if(utn_getNombre(auxZona,"Ingrese la zona donde quiere pegar los afiches: ","Ese cuit no es valido\n")==0)
            {
                    strncpy(pVenta[indice].zona,auxZona,50);
                    strncpy(pVenta[indice].estado,"A cobrar",50);
                    retorno =0;
            }

        }


    }


    return retorno;
}

int venta_borrarVenta(Venta* pVenta,int limite,int id)
{
    int retorno=-1;
    int i;
    for(i=0;i<limite;i++)
    {
        if(pVenta[i].isEmpty==0 && pVenta[i].idCliente==id)
        {

                pVenta[i].isEmpty=-1;
        }
    }
    return retorno;
}

int venta_buscarVentaPorId(Venta* pVenta,int limite,int id)
{
    int retorno=-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if(pVenta[i].isEmpty==0)
        {
            if(pVenta[i].ID==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int venta_buscarClienteVentaPorId(Venta* pVenta,int limite,int id,int* idCliente)
{
    int retorno=-1;
    int i;
    for(i=0;i<limite;i++)
    {
        if(pVenta[i].isEmpty==0)
        {
            if(pVenta[i].ID==id)
            {
                *idCliente=pVenta[i].idCliente;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
int venta_obtenerIdCliente(Venta* pVenta,int limite,int id)
{
    int retorno=-1;
    int i;
    int indice;
    indice=venta_buscarVentaPorId(pVenta,limite,id);
    for(i=0;i<limite;i++)
    {
        if(pVenta[indice].isEmpty==0)
        {

                retorno=pVenta[indice].idCliente;
        }
    }
    return retorno;
}
int venta_checkEstado(Venta* pVenta,int limite,int id, char* estado)
{
    int retorno=-1;
    int i;
    int indice;
    indice=venta_buscarVentaPorId(pVenta,limite,id);
    for(i=0;i<limite;i++)
    {
        if(pVenta[indice].isEmpty==0)
        {
            if(strcmp(estado,pVenta[indice].estado)==0)
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int venta_cobrarVenta(Venta* pVenta,int limite,int id)
{
    int retorno=-1;
    int i;
    int pNum;

    for(i=0;i<limite;i++)
    {
        if(pVenta[i].isEmpty==0 && pVenta[i].ID==id  && strcmp(pVenta[i].estado,"A cobrar")==0 && utn_getEntero(&pNum,3,"\nDesea cobrar la venta realmente?(1:Si, 2:No): ","Esa opcion no es valida",3,0)==0)
        {
            if(pNum==1)
            {
                strcpy(pVenta[i].estado,"Cobrada");
                retorno=0;
                break;
            }else
            {
                printf("\n||No se cobro la venta||\n");
            }
        }

    }
    return retorno;
}

int venta_cantidadDeVentasCliente(Venta* pVenta,int limite,int id)
{
    int retorno=0;
    int i;


    for(i=0;i<limite;i++)
    {
        if(pVenta[i].isEmpty==0 && pVenta[i].idCliente==id && strcmp(pVenta[i].estado,"A cobrar")==0)
        {
            retorno++;
        }
    }
    return retorno;
}
static int generarID(void)
{
        static int cont = -1;
        return ++cont;
}
