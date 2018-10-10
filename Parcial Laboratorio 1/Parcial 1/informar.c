#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "ventaAfiche.h"
#include "informar.h"

int informar_OrdenarVentaPorZona(Venta* pVenta, int limite)
{
    int retorno=-1;
    int i;
    int flagSwap;
    Venta auxiliar;
    if(limite > 0 && pVenta != NULL)
    {
        retorno=0;
        do
        {
            flagSwap=0;
            for(i=0;i<limite-1;i++)
            {
                if(strcmp(pVenta[i].zona,pVenta[i+1].zona) > 0 ||
                (strcmp(pVenta[i].zona,pVenta[i+1].zona) == 0 && strcmp(pVenta[i].nombreImagen,pVenta[i+1].nombreImagen)>0))
                {
                    flagSwap=1;
                    auxiliar=pVenta[i];
                    pVenta[i]=pVenta[i+1];
                    pVenta[i+1]=auxiliar;
                }
            }
        }while(flagSwap==1);

    }

    return retorno;
}

int informar_clienteMenosVentasACobrar(Cliente* pCliente,int limite, Venta* pVenta,int limite2)
{
  int retorno=-1;
    int i;
    int cantVentasMenores;
    int clienteAImprimir;
    int cantVentasActual;
    if(pCliente != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pCliente[i].isEmpty==0 && i==0)
            {
                cantVentasMenores=venta_cantidadDeVentasClienteACobrar(pVenta,limite2,pCliente[i].ID);
                clienteAImprimir=i;
            }else if(pCliente[i].isEmpty==0)
            {
                cantVentasActual=venta_cantidadDeVentasClienteACobrar(pVenta,limite2,pCliente[i].ID);
                if(cantVentasActual < cantVentasMenores)
                {
                    cantVentasMenores=cantVentasActual;
                    clienteAImprimir=i;
                }
            }
        }
                printf("\nEl ID del cliente con menos ventas es: %d", pCliente[clienteAImprimir].ID);
                printf("\nEl nombre del cliente con menos ventas es: %s",pCliente[clienteAImprimir].name);
                printf("\nEl apellido del cliente con menos ventas es: %s",pCliente[clienteAImprimir].lastName);
                printf("\nEl cuit del cliente con menos ventas es: %s",pCliente[clienteAImprimir].cuit);
                printf("\nLa cantidad de ventas a cobrar que tiene es: %d\n\n",cantVentasMenores);
                retorno=0;

    }

    return retorno;
}

int informar_clienteMenosVentasCobradas(Cliente* pCliente,int limite, Venta* pVenta,int limite2)
{
  int retorno=-1;
    int i;
    int cantVentasMenores;
    int clienteAImprimir;
    int cantVentasActual;
    if(pCliente != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pCliente[i].isEmpty==0 && i==0)
            {
                cantVentasMenores=venta_cantidadDeVentasClienteCobradas(pVenta,limite2,pCliente[i].ID);
                clienteAImprimir=i;
            }else if(pCliente[i].isEmpty==0)
            {
                cantVentasActual=venta_cantidadDeVentasClienteACobrar(pVenta,limite2,pCliente[i].ID);
                if(cantVentasActual < cantVentasMenores)
                {
                    cantVentasMenores=cantVentasActual;
                    clienteAImprimir=i;
                }
            }
        }
                printf("\nEl ID del cliente con menos ventas es: %d", pCliente[clienteAImprimir].ID);
                printf("\nEl nombre del cliente con menos ventas es: %s",pCliente[clienteAImprimir].name);
                printf("\nEl apellido del cliente con menos ventas es: %s",pCliente[clienteAImprimir].lastName);
                printf("\nEl cuit del cliente con menos ventas es: %s",pCliente[clienteAImprimir].cuit);
                printf("\nLa cantidad de ventas cobradas que tiene es: %d\n\n",cantVentasMenores);
                retorno=0;

    }

    return retorno;
}

int informar_clienteMenosVentas(Cliente* pCliente,int limite, Venta* pVenta,int limite2)
{
  int retorno=-1;
    int i;
    int cantVentasMenores;
    int clienteAImprimir;
    int cantVentasActual;
    if(pCliente != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pCliente[i].isEmpty==0 && i==0)
            {
                cantVentasMenores=venta_cantidadDeVentas(pVenta,limite2,pCliente[i].ID);
                clienteAImprimir=i;
            }else if(pCliente[i].isEmpty==0)
            {
                cantVentasActual=venta_cantidadDeVentas(pVenta,limite2,pCliente[i].ID);
                if(cantVentasActual < cantVentasMenores)
                {
                    cantVentasMenores=cantVentasActual;
                    clienteAImprimir=i;
                }
            }
        }
                retorno=0;
                printf("\nEl ID del cliente con menos ventas es: %d", pCliente[clienteAImprimir].ID);
                printf("\nEl nombre del cliente con menos ventas es: %s",pCliente[clienteAImprimir].name);
                printf("\nEl apellido del cliente con menos ventas es: %s",pCliente[clienteAImprimir].lastName);
                printf("\nEl cuit del cliente con menos ventas es: %s",pCliente[clienteAImprimir].cuit);
                printf("\nLa cantidad de ventas que tiene es: %d\n\n",cantVentasMenores);


    }

    return retorno;
}

int informar_mostrarZonaConMasAfiches(Venta* pVenta,int limite)
{
    int cantAficheZonaEste;
    int cantAficheZonaOeste;
    int cantAficheZonaNorte;
    int cantAficheZonaSur;

    informar_cantidadAfichesZona(pVenta,limite,&cantAficheZonaSur,&cantAficheZonaEste,&cantAficheZonaOeste,&cantAficheZonaNorte);
    if(cantAficheZonaEste > cantAficheZonaNorte
        && cantAficheZonaEste > cantAficheZonaOeste
        && cantAficheZonaEste > cantAficheZonaSur)
        {
            printf("\nLa zona con mas afiches es Zona Este con: %d afiches\n",cantAficheZonaEste);
        }else if(cantAficheZonaSur > cantAficheZonaNorte
        && cantAficheZonaSur > cantAficheZonaOeste
        && cantAficheZonaSur > cantAficheZonaEste)
        {
            printf("\nLa zona con mas afiches es Zona Sur con: %d afiches\n",cantAficheZonaSur);
        }else if(cantAficheZonaNorte > cantAficheZonaSur
        && cantAficheZonaNorte > cantAficheZonaOeste
        && cantAficheZonaNorte > cantAficheZonaEste)
        {
            printf("\nLa zona con mas afiches es Zona Norte con: %d afiches\n",cantAficheZonaNorte);
        }else
        {
            printf("\nLa zona con mas afiches es Zona Oeste con: %d afiches\n",cantAficheZonaOeste);
        }

    return 0;
}
int informar_mostrarAfichePorZona(Venta* pVenta,int limite)
{
    int cantAficheZonaEste;
    int cantAficheZonaOeste;
    int cantAficheZonaNorte;
    int cantAficheZonaSur;

    informar_cantidadAfichesZona(pVenta,limite,&cantAficheZonaSur,&cantAficheZonaEste,&cantAficheZonaOeste,&cantAficheZonaNorte);
        printf("\nLa cantidad de afiches en Zona Este son: %d afiches\n",cantAficheZonaEste);
        printf("\nLa cantidad de afiches es Zona Sur son: %d afiches\n",cantAficheZonaSur);
        printf("\nLa cantidad de afiches es Zona Norte son: %d afiches\n",cantAficheZonaNorte);
        printf("\nLa cantidad de afiches afiches es Zona Oeste son: %d afiches\n",cantAficheZonaOeste);


    return 0;
}

int informar_cantidadAfichesZona(Venta* pVenta,int limite, int* cantAficheZonaSur,int* cantAficheZonaEste,int* cantAficheZonaOeste,int* cantAficheZonaNorte)
{
    int retorno=-1;
    int i;
    int auxCantAficheZonaSur=0;
    int auxCantAficheZonaEste=0;
    int auxCantAficheZonaOeste=0;
    int auxCantAficheZonaNorte=0;
    if(pVenta != NULL && limite > 0)
    {
        retorno=0;
        for(i=0;i<limite;i++)
        {
            if(pVenta[i].isEmpty==0)
            {
                if(strcmp(pVenta[i].zona,"ZONA SUR")==0)
                {
                    auxCantAficheZonaSur=auxCantAficheZonaSur + pVenta[i].cantAfiches;
                }else if(strcmp(pVenta[i].zona,"ZONA NORTE")==0)
                {
                    auxCantAficheZonaNorte=auxCantAficheZonaNorte + pVenta[i].cantAfiches;
                }else if(strcmp(pVenta[i].zona,"ZONA ESTE")==0)
                {
                    auxCantAficheZonaEste=auxCantAficheZonaEste + pVenta[i].cantAfiches;
                }else if(strcmp(pVenta[i].zona,"ZONA OESTE")==0)
                {
                    auxCantAficheZonaOeste=auxCantAficheZonaOeste + pVenta[i].cantAfiches;
                }

            }
        }
        *cantAficheZonaEste=auxCantAficheZonaEste;
        *cantAficheZonaNorte=auxCantAficheZonaNorte;
        *cantAficheZonaOeste=auxCantAficheZonaOeste;
        *cantAficheZonaSur=auxCantAficheZonaSur;
    }
    return retorno;
}

int informar_clienteCantAfichesUnCliente(Venta* pVenta,int limite,int idCliente)
{
    int totalAfiches=0;
    int i;


    for(i=0;i<limite;i++)
    {
        if(pVenta[i].isEmpty==0 && pVenta[i].idCliente==idCliente)
        {
            totalAfiches=totalAfiches+pVenta[i].cantAfiches;
        }
    }
    return totalAfiches;
}
int informar_clienteCantAfichesUnClienteACobrar(Venta* pVenta,int limite,int idCliente)
{
    int totalAfiches=0;
    int i;


    for(i=0;i<limite;i++)
    {
        if(pVenta[i].isEmpty==0 && pVenta[i].idCliente==idCliente && strcmp(pVenta[i].estado,"A cobrar")==0)
        {
            totalAfiches=totalAfiches+pVenta[i].cantAfiches;
        }
    }
    return totalAfiches;
}
int informar_clienteConMenosAfiches(Cliente* pCliente,int limite,Venta* pVenta,int limite2)
{
    int retorno=-1;
    int cantAfichesMenores=0;
    int i;
    int cantAfichesActual=0;
    int clienteAImprimir;

    for(i=0;i<limite;i++)
    {
        if(pCliente[i].isEmpty==0)
        {
            if(i==0)
            {
                cantAfichesMenores=informar_clienteCantAfichesUnCliente(pVenta,limite2,pCliente[i].ID);
                clienteAImprimir=i;
            }else
            {
                cantAfichesActual=informar_clienteCantAfichesUnCliente(pVenta,limite2,pCliente[i].ID);
                if(cantAfichesActual < cantAfichesMenores)
                {
                    cantAfichesMenores=cantAfichesActual;
                    clienteAImprimir=i;
                }
            }

        }
    }
                retorno=0;
                printf("\nEl ID del cliente con menos afiches es: %d", pCliente[clienteAImprimir].ID);
                printf("\nEl nombre del cliente con menos afiches es: %s",pCliente[clienteAImprimir].name);
                printf("\nEl apellido del cliente con menos afiches es: %s",pCliente[clienteAImprimir].lastName);
                printf("\nEl cuit del cliente con menos afiches es: %s",pCliente[clienteAImprimir].cuit);
                printf("\nLa cantidad de afiches que tiene es: %d\n\n",cantAfichesMenores);

    return retorno;
}

int informar_clienteCantAfichesMayor(Cliente* pCliente,int limite,Venta* pVenta,int limite2,int valorComparativo)
{
    int retorno=-1;
    int totalAfiches=0;
    int i;

    if(pCliente != NULL && limite > 0 && pVenta != NULL && limite2 > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pCliente[i].isEmpty==0)
            {
                totalAfiches=informar_clienteCantAfichesUnCliente(pVenta,limite2,pCliente[i].ID);
                if(totalAfiches>valorComparativo)
                {
                    retorno=0;
                    printf("\nEl ID del cliente es: %d", pCliente[i].ID);
                    printf("\nEl nombre del cliente es: %s",pCliente[i].name);
                    printf("\nEl apellido del cliente es: %s",pCliente[i].lastName);
                    printf("\nEl cuit del cliente es: %s",pCliente[i].cuit);
                    printf("\nLa cantidad de afiches que tiene es: %d\n\n",totalAfiches);
                }
            }
        }
    }
    return retorno;
}

int informar_promedioAfiches(Cliente* pCliente,int limite,Venta* pVenta,int limite2)
{
    int retorno=-1;
    float AfichesActual=0;
    float totalAfiches=0;
    float cantClientes=0;
    float promedioAfiches;
    int i;

    if(pCliente != NULL && limite > 0 && pVenta != NULL && limite2 > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pCliente[i].isEmpty==0)
            {
                AfichesActual=informar_clienteCantAfichesUnCliente(pVenta,limite2,pCliente[i].ID);
                totalAfiches=totalAfiches+AfichesActual;
                cantClientes++;
            }
        }
    }
    promedioAfiches=totalAfiches/cantClientes;
    printf("\nEl promedio de afiches por cliente es: %.2f\n",promedioAfiches);
    return retorno;
}

int informar_clienteMasAfichesACobrar(Cliente* pCliente,int limite, Venta* pVenta,int limite2)
{
  int retorno=-1;
    int i;
    int cantAfichesMayores;
    int clienteAImprimir;
    int cantAfichesActual;
    if(pCliente != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pCliente[i].isEmpty==0 && i==0)
            {
                cantAfichesMayores=informar_clienteCantAfichesUnClienteACobrar(pVenta,limite2,pCliente[i].ID);
                clienteAImprimir=i;
            }else if(pCliente[i].isEmpty==0)
            {
                cantAfichesActual=informar_clienteCantAfichesUnClienteACobrar(pVenta,limite2,pCliente[i].ID);
                if(cantAfichesActual > cantAfichesMayores)
                {
                    cantAfichesMayores=cantAfichesActual;
                    clienteAImprimir=i;
                }
            }
        }
                retorno=0;
                printf("\nEl ID del cliente con mas afiches a cobrar es: %d", pCliente[clienteAImprimir].ID);
                printf("\nEl nombre del cliente con mas afiches a cobrar es: %s",pCliente[clienteAImprimir].name);
                printf("\nEl apellido del cliente con mas afiches a cobrar es: %s",pCliente[clienteAImprimir].lastName);
                printf("\nEl cuit del cliente con mas afiches a cobrar es: %s",pCliente[clienteAImprimir].cuit);
                printf("\nLa cantidad de afiches que tiene es: %d\n\n",cantAfichesMayores);


    }

    return retorno;
}


