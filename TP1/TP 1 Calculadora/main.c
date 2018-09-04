#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"

int main()
{
    float numero1=0;
    float numero2=0;
    float resultadosuma=0;
    float resultadoresta=0;
    float resultadomultiplicacion=0;
    float resultadodivision=0;
    int resultadofactoreo1=0;
    int resultadofactoreo2=0;
    int reint=10;
    int error=0;
    int opcion;
    char* respuesta;
    int salir=1;
    do
    {

                system("cls");
                fflush(stdin);
                opcion=utn_menu(numero1,numero2);

                switch(opcion)
                {
                    case 1:
                        system("cls");
                        utn_getNumeroDecimal(&numero1,reint,"Ingrese Numero 1: ","Eso no es un numero\n");
                        fflush(stdin);
                        break;
                    case 2:
                        system("cls");
                        utn_getNumeroDecimal(&numero2,reint,"Ingrese Numero 2: ","Eso no es un numero\n");
                        fflush(stdin);
                        break;
                    case 3:
                        utn_suma(&resultadosuma,numero1,numero2);
                        utn_resta(&resultadoresta,numero1,numero2);
                        utn_multiplicacion(&resultadomultiplicacion,numero1,numero2);
                        resultadofactoreo1=utn_factoreo(numero1);
                        resultadofactoreo2=utn_factoreo(numero2);
                        if(resultadofactoreo1==-1 || resultadofactoreo2==-1 )
                        {
                            error=2;
                        }

                        if(utn_division(&resultadodivision,numero1,numero2)==-1)
                        {
                            if(error==2)
                            {
                                error=3;
                            }else
                            {
                                error=1;
                            }

                        }

                        break;
                    case 4:
                        if(error==0)
                        {
                            respuesta="1)El resultado de A+B es:%.2f \n2)El resultado de A-B es:%.2f\n3)El resultado de A/B es:%.2f\n4)El resultado de A*B es: %.2f\n5)El factorial de A es: %d y El factorial de B es: %d\n";
                        }else if(error==1)
                        {
                          respuesta="1)El resultado de A+B es:%.2f \n2)El resultado de A-B es:%.2f\n3)No podes dividir por 0\n4)El resultado de A*B es: %.2f\n5)El factorial de A es: %d y El factorial de B es: %d\n";
                        }else if(error==2)
                        {
                           respuesta="1)El resultado de A+B es:%.2f \n2)El resultado de A-B es:%.2f\n3)El resultado de A/B es:%.2f\n4)El resultado de A*B es: %.2f\n5)Un numero negativo no puede ser factorizado\n";
                        }else if(error==3)
                        {
                            respuesta="1)El resultado de A+B es:%.2f \n2)El resultado de A-B es:%.2f\n3)No podes dividir por 0\n4)El resultado de A*B es: %.2f\n5)Un numero negativo no puede ser factorizado\n";
                        }
                        printf(respuesta,resultadosuma,resultadoresta,resultadodivision,resultadomultiplicacion,resultadofactoreo1,resultadofactoreo2);

                        system("pause");
                        break;
                    case 5:
                        salir=0;


                }




}while(salir==1);

return 0;

}
