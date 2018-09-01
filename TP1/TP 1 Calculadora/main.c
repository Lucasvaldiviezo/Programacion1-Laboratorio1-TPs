#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"

int main()
{
    float numero1;
    float numero2;
    float resultado;
    int reint=10;
    //char* opcion;
    int opcion;
    if(utn_getNumeroDecimal(&numero1,reint,"Ingrese Numero 1: ","Eso no es un numero\n")==0)
    {
        if(utn_getNumeroDecimal(&numero2,reint,"Ingrese Numero 2: ","Eso no es un numero\n")==0)
        {
            printf("Los numeros son %.2f-%.2f\n",numero1,numero2);
        }
    }
    if(utn_getEntero(&opcion,reint,
        "Escriba a continuacion el numero de la operacion que desea realizar\n1.sumar\n2.restar\n3.multiplicar\n4.dividir\n5.factorizar\nElija:",
        "Esa no es una opcion valida\n",0,6) == 0)
        {
            switch(opcion)
            {
                case 1:
                    utn_suma(&resultado,numero1,numero2);
                    break;
                case 2:
                    utn_resta(&resultado,numero1,numero2);
                    break;
                case 3:
                    utn_multiplicacion(&resultado,numero1,numero2);

            }

        }

    printf("El resultado es: %.2f",resultado);
    return 0;
}
