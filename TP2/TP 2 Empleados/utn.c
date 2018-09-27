#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

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
static int isFloat(char* pBuffer);
static int isInt(char* pBuffer);
static int isLetra(char* pBuffer);
static int getString(char* pBufferString,int limite);


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
int utn_getNumeroDecimal(float *pNum, int reint, char* msg, char* msgError,float maximo,float minimo)
{
    float buffer;
    int retorno = -1;

    if(pNum != NULL && msg != NULL && msgError !=NULL && minimo<=maximo && reint >= 0)
    {

        do
        {
            reint--;
            printf("%s",msg);
            if(getFloat(&buffer) == 0 &&
                buffer <= maximo && buffer >= minimo )
            {
                    *pNum = buffer;
                    retorno = 0;
                    break;

            }else
            {
                printf("%s",msgError);
                fflush(stdin);
            }


        }while(reint >= 0);

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

int static getString(char* pBufferString,int limite)
{
    fflush(stdin);
    fgets(pBufferString,limite,stdin);
    if(pBufferString[strlen(pBufferString)-1]=='\n')
    {
        pBufferString[strlen(pBufferString)-1]='\0';
    }
    return 0;
}

int utn_getNombre(char* pNombre,char* msg,char* msgError)
{
    int retorno=-1;
    int max=50;
    char buffer[max];
    if(pNombre != NULL && msg != NULL && msgError!=NULL)
    {
        printf("%s",msg);
        if(getString(buffer,max)==0 && isLetra(buffer)==0)
        {
            retorno=0;
            strncpy(pNombre,buffer,max);
        }else
        {
            printf("%s",msgError);
            system("pause");
        }
    }
    return retorno;
}

static int isLetra(char* pBuffer)
{
    int i=0;
    int retorno=0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] < 'A' || pBuffer[i] > 'z')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}

static int getFloat(float* pResultado)
{
    int retorno=-1;
    char bufferString[4096];
if(pResultado != NULL)
{
  if(getString(bufferString,4096) == 0 && isFloat(bufferString)==0)
    {

        *pResultado=atof(bufferString);
        retorno=0;

    }
}

    return retorno;
}

static int getInt(int* pResultado)
{
        int retorno=-1;
        char bufferString[4096];
    if(pResultado != NULL)
    {
      if(getString(bufferString,4096) == 0 && isInt(bufferString)==0)
        {

            *pResultado=atoi(bufferString);
            retorno=0;

        }
    }
    return retorno;
}

static int isFloat(char* pBuffer)
{
    int i=0;
    int retorno=0;
    int contadorPuntos=0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] == '.' && contadorPuntos==0)
        {
            contadorPuntos++;
            i++;
            continue;
        }
        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}

static int isInt(char* pBuffer)
{
    int i=0;
    int retorno=0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}


