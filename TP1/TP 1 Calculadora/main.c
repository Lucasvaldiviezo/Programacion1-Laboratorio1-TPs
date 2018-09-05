#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"

int main()
{
    float numero1=0;
    float numero2=0;
    float resultadoSuma=0;
    float resultadoResta=0;
    float resultadoMultiplicacion=0;
    float resultadoDivision=0;
    float resultadoFactoreo1=0;
    float resultadoFactoreo2=0;
    int reint=10;
    int opcion;
    int salir=1;
    int mostrarResultados=0;
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
                        utn_suma(&resultadoSuma,numero1,numero2);
                        utn_resta(&resultadoResta,numero1,numero2);
                        utn_multiplicacion(&resultadoMultiplicacion,numero1,numero2);
                        resultadoFactoreo1=utn_factoreo(numero1);
                        resultadoFactoreo2=utn_factoreo(numero2);
                        utn_division(&resultadoDivision,numero1,numero2);
                        mostrarResultados=1;

                        break;
                    case 4:
                        if (mostrarResultados==1)
                        {
                            utn_texto(resultadoSuma,"1)El resultado de A+B es: %.2f \n");
                            utn_texto(resultadoResta,"2)El resultado de A-B es: %.2f \n");
                            if(numero2==0)
                            {
                                utn_texto(resultadoDivision,"3)No se puede dividir por 0\n");
                            }else
                            {
                                utn_texto(resultadoDivision,"3)El resultado de A/B es: %.2f \n");
                            }
                            utn_texto(resultadoMultiplicacion,"4)El resultado de A*B es: %.2f \n");
                            if(numero1 < 0)
                            {
                                utn_texto(resultadoFactoreo1,"5)No se puede factorear el A ya que es negativo");
                            }else
                            {
                                utn_texto(resultadoFactoreo1,"5)El factorial de A es: %.0f");
                            }
                            if(numero2 < 0)
                            {
                                utn_texto(resultadoFactoreo2," y no se puede factorear el B ya que es negativo\n");
                            }else
                            {
                                utn_texto(resultadoFactoreo2," y el factorial de B es: %.0f\n");
                            }


                            system("pause");

                        }else
                        {
                            printf("Aun no realizo el calculo de las operaciones\n");
                            system("pause");
                        }
                        break;
                    case 5:
                        salir=0;


                }




}while(salir==1);

return 0;

}
