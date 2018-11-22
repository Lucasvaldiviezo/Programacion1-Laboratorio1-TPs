#include <stdio_ext.h>
#include <stdlib.h>
#include "venta.h"
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "utn.h"

int parser_parseVentas(char* fileName, LinkedList* lista)
{

    int retorno=-1;
    char* tokenIdVenta;
    char* tokenFechaVenta;
    char* tokenCodigoProducto;
    char* tokenPrecioUnitario;
    char* tokenCantidad;
    char* tokenCuitCliente;
    char* delim=",";
    char* delim2="\n";
    int valueF;
    int contadorEntradas=0;
    char line[4000];
    Venta* auxiliarPunteroVenta;
    FILE* pFile;
    pFile=fopen(fileName,"r");
    if(pFile != NULL)
    {
        //fscanf(pFile,"%[^\n]\n",line);
        while(!feof(pFile))
        {
            valueF=fscanf(pFile,"%[^\n]\n",line);
            if(valueF!=1)
            {
                printf("El valor era distinto de 1\n");
                break;
            }
            tokenIdVenta=strtok(line, delim);
            tokenFechaVenta=strtok(NULL, delim);
            tokenCodigoProducto=strtok(NULL, delim);
            tokenCantidad=strtok(NULL, delim);
            tokenPrecioUnitario=strtok(NULL, delim);
            tokenCuitCliente=strtok(NULL, delim2);
            auxiliarPunteroVenta=venta_newConParametros(tokenIdVenta,tokenFechaVenta,tokenCodigoProducto,tokenCantidad,tokenPrecioUnitario,tokenCuitCliente);
            if(auxiliarPunteroVenta!=NULL)
            {
                contadorEntradas++;
                ll_add(lista,auxiliarPunteroVenta);
                retorno=0;
            }

        }
        printf("Se cargaron %d ventas. \n",contadorEntradas);
    }
    fclose(pFile);
    return retorno;
}

