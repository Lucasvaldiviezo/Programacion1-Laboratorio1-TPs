#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#define DATO_INVALIDO -1
#define true 1
#define false 0



int utn_inicializarArray(int* pArray,int valor, int limite)
{
    int retorno=-1;
    int i;
    if(pArray != NULL && limite >0)
    {
        for(i=0;i < limite;i++)
        {
            pArray[i]=valor;
        }
        retorno=0;
    }


    return retorno;
}

int utn_mostrarArray(float* pArray,int limite)
{
    int i;
    for(i=0;i < limite;i++)
    {
        printf("\nIndex:[%d] - Value:%.2f - Add:%p",i,pArray[i],pArray+i);
    }

    return 0;
}

int utn_calcularMaximoArray(int* pArray,int limite,int* pMaximo)
{
    int i;
    int retorno;
    int maximo;
    int flagPrimerMaximo=0;
    for(i=0;i < limite;i++)
    {
        if(pArray[i]!=DATO_INVALIDO)
        {
            if(flagPrimerMaximo == 0)
            {
                maximo = pArray[i];
                flagPrimerMaximo=1;
            }
            else if(pArray[i] > maximo)
            {
                maximo = pArray[i];
            }
        }

    }
    if(flagPrimerMaximo==0)
    {
        retorno=-2;
    }else
    {
        retorno=0;
        *pMaximo=maximo;
    }

    return retorno;
}

int utn_promedioArray(int* pArray,int limite,float* pPromedio)
{
    int i;
    int retorno;
    float suma;
    float auxpromedio;
    int cantidadValidos=0;
    int flagPrimerMaximo=0;
    for(i=0;i < limite;i++)
    {
        if(pArray[i]!=DATO_INVALIDO)
        {
            suma=suma+pArray[i];
            cantidadValidos++;
            if(flagPrimerMaximo==0)
            {
                flagPrimerMaximo=1;
            }
        }

    }
    if(flagPrimerMaximo==0)
    {
        retorno=-1;
    }else
    {
        auxpromedio=suma/(float)cantidadValidos;
        *pPromedio=auxpromedio;
        retorno=0;
    }


    return retorno;
}

int utn_calcularMinimoArray(int* pArray,int limite,int* pMinimo)
{
    int i;
    int minimo= pArray[0];
    for(i=0;i < limite;i++)
    {
        if(pArray[i] < minimo)
        {
            minimo= pArray[i];
        }
    }
    *pMinimo=minimo;
    return 0;
}

int utn_insertion(int data[],int len)
{
    int i;
    int j;
    int temp;
    for(i=1;i<len;i++)
    {
        temp=data[i];
        j=i-1;
        while(j>=0 && temp<data[j])
        {
            data[j+1]=data[j];
            j--;
        }
        data[j+1]=temp;
    }
    return 0;
}
