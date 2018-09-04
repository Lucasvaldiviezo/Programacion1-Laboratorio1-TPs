#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"

/**
    utn_getInt:permite ingresar un numero entero y lo validar
    @param *pResultado: guarda el numero 1 ingresado luego de validarlo
    @return : 0 OK, -1 error
*/
/**
    utn_getFloat:permite ingresar un numero con coma y lo validar
    @param *pResultado: guarda el numero 1 ingresado luego de validarlo
    @return : 0 OK, -1 error
*/

static int getFloat(float* pResultado);
static int getInt(int* pResultado);

int utn_menu(float numero1,float numero2)
{
    int opcion;

    printf("1. Ingresar primer numero (A: %.2f)\n",numero1);
    printf("2. Ingresar segundo numero (B: %.2f)\n",numero2);
    printf("3. Calcular todas las operaciones\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n");
    fflush(stdin);
    utn_getEntero(&opcion,10,"Seleccione una opcion: ","Esa opcion no es valida \n",6,0);


    return opcion;
}
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

/*int utn_getCaracter(char* pOpcion,char* msg, char* msgError,int reint)
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
}*/

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

int utn_division(float *pResultado,float numero1, float numero2)
{
    int retorno = 0;
    if(numero2==0)
    {
        retorno = -1;
    }else
    {
        *pResultado=numero1/numero2;
    }
    return retorno;
}

int utn_factoreo(float numero)
{
    float i;
    float respuesta=1;

    if(numero==1 || numero ==0)
    {
        respuesta = 1;
    }else if(numero < 0)
    {
        respuesta = -1;
    }else
    {
         for (i = 1; i <= (int)numero; i++)
         {
            respuesta =respuesta * i;
         }

    }
    return respuesta;
}

void utn_texto(float resultado, char* msg)
{
    printf(msg,resultado);
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
