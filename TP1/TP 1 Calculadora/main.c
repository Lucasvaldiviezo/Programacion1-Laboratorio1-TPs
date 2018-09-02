#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"

int main()
{
    float numero1;
    float numero2;
    float resultado;
    float resultado2;
    int reint=10;
    int error=0;
    char opcion;
    int salir;
    char* respuesta;
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
            "||Operaciones||\n   A.Sumar\n   B.Restar\n   C.Multiplicar\n   D.Dividir\n   E.Factorizar\nEscriba la letra de la operacion que desea realizar: ",
            "Esa no es una opcion valida\n",reint) == 0)
            {
                switch(opcion)
                {
                    case 'a':
                        utn_suma(&resultado,numero1,numero2);
                        respuesta="El resultado de la suma %.2f+%.2f es:  %.2f\n\n";
                        break;
                    case 'b':
                        utn_resta(&resultado,numero1,numero2);
                        respuesta="El resultado de la resta %.2f-%.2f es:  %.2f\n\n";
                        break;
                    case 'c':
                        utn_multiplicacion(&resultado,numero1,numero2);
                        respuesta="El resultado de la multiplicacion %.2f*%.2f es:  %.2f\n\n";
                        break;
                    case 'd':
                        if(utn_division(&resultado,numero1,numero2,"No se puede dividir por 0")==-1)
                        {
                            error=1;
                        };
                        respuesta="El resultado de la division %.2f/%.2f es:  %.2f\n\n";
                        break;
                    case 'e':
                        resultado=utn_factoreo(numero1);
                        resultado2=utn_factoreo(numero2);
                        respuesta="El resultado de la factorizacion de %.2f y de %.2f es: %.2f y %.2f\n\n";

                }

            }
        if(error == 0)
        {
            printf(respuesta,numero1,numero2,resultado,resultado2);

        }

        if(utn_getEntero(&salir,reint,"¿Desea realizar otra operacion? 1.Si/2.No: ","\nEsa no es una opcion valida\n",3,0)==0)
        {
            if(salir == 1)
            {
                system("cls");
            }else
            {
                printf("\nHasta la proxima\n");
            }


        }



    }while(salir==1);

return 0;

}
