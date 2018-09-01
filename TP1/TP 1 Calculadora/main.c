#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"

int main()
{
    float numero1;
    float numero2;
    float resultado;
    int reint=10;
    int error=0;
    char opcion;
    char salir='n';
    //int opcion;
    do
    {


        if(utn_getNumeroDecimal(&numero1,reint,"Ingrese Numero 1: ","Eso no es un numero\n")==0)
        {
            if(utn_getNumeroDecimal(&numero2,reint,"Ingrese Numero 2: ","Eso no es un numero\n")==0)
            {
                printf("Los numeros son %.2f-%.2f\n",numero1,numero2);
            }
        }
        if(utn_getCaracter(&opcion,
            "||Operaciones||\n   A.Sumar\n   B.Restar\n   C.Multiplicar\n   D.Dividir\n   F.Factorizar\nEscriba la letra de la operacion que desea realizar: ",
            "Esa no es una opcion valida\n",reint) == 0)
            {
                switch(opcion)
                {
                    case 'a':
                        utn_suma(&resultado,numero1,numero2);
                        break;
                    case 'b':
                        utn_resta(&resultado,numero1,numero2);
                        break;
                    case 'c':
                        utn_multiplicacion(&resultado,numero1,numero2);
                        break;
                    case 'd':
                        if(utn_division(&resultado,numero1,numero2,"No se puede dividir por 0")==-1)
                        {
                            error=1;
                        };
                }

            }
        if(error == 0)
        {
            printf("\nEl Resultado es: %.2f\n\n",resultado);
        }
        printf("¿Desea realizar otra operacion?");
        scanf("%c",&salir);


    }while(salir == 'n');

return 0;

}
