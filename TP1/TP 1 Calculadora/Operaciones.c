#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"

//static int getInt(int* pResultado);
static int getFloat(float* pResultado);
static int getInt(int* pResultado);


int utn_getNumeroDecimal(float *pNum, int reint, char* msg, char* msgError)
{
    float auxiliarNum;
    int retorno = -1;
    for(;reint>0;reint--)
    {
        printf(msg);
        if(getFloat(&auxiliarNum) == 0)
        {
            *pNum = auxiliarNum;
            retorno = 0;
            break;


        }else
        {
            printf(msgError);
            fflush(stdin);
        }
    }

    return retorno;
}
int utn_getEntero(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo)
{
    int auxiliarNum;
    int retorno = -1;
    for(;reint>0;reint--)
    {
        printf(msg);
        if(getInt(&auxiliarNum) == 0)
        {
            if(auxiliarNum > minimo && auxiliarNum < maximo)
            {
                *pNum = auxiliarNum;
                retorno = 0;
                break;

            }else
            {
                printf(msgError);
            }


        }else
        {
            printf(msgError);
            fflush(stdin);
        }
    }


    return retorno;
}

int utn_getCaracter(char* pOpcion,char* msg, char* msgError,int reint)
{
    char opcion;
    int retorno=-1;


    for(;reint > 0;reint--)
    {
        printf(msg);
        scanf("%s",&opcion);
        if(opcion=='a' || opcion=='b'||opcion=='c'|| opcion=='d' || opcion=='e')
        {
            *pOpcion = opcion;
            retorno = 0;
            break;
        }else
        {
            printf(msgError);
        }
    }
    return retorno;
}

int utn_suma(float *pResultado,float numero1,float numero2)
{

    *pResultado=numero1+numero2;

    return 0;
}

int utn_resta(float *pResultado,float numero1, float numero2)
{

    *pResultado=numero1-numero2;

    return 0;
}

int utn_multiplicacion(float *pResultado,float numero1, float numero2)
{

    *pResultado=numero1*numero2;

    return 0;
}

int utn_division(float *pResultado,float numero1, float numero2,char* msgError)
{
    int retorno = 0;
    if(numero2==0)
    {
        printf(msgError);
        retorno = -1;
    }else
    {
        *pResultado=numero1/numero2;
    }
    return retorno;
}

int utn_factoreo(float numero)
{
    float respuesta;
    if(numero==1 || numero ==0)
    {
        respuesta = 1;
    }else
    {
        respuesta=numero*utn_factoreo(numero-1);
    }
    return respuesta;
}

static int getFloat(float* pResultado)
{
    int ret=-1;
    float num;

    if(scanf("%f",&num)==1)
    {
        *pResultado = num;
        ret=0;
    }
    return ret;
}

static int getInt(int* pResultado)
{
    int ret=-1;
    int num;

    if(scanf("%d",&num)==1)
    {
        *pResultado = num;
        ret=0;
    }
    return ret;
}
