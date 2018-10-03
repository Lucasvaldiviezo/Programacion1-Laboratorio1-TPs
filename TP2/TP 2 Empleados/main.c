#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
#define EMPLEADOS_MAX 1000
#define TEXTO_MENU "       MENU\n\
1)Cargar un empleado\n\
2)Modificar un empleado\n\
3)Borrar un empleado\n\
4)Imprimir lista de empleados\n\
5)Calcular salario: Total/Promedio/Mayores al promedio\n\
6)Salir\n\
Elija una opcion: "


int main()
{
    int indiceVacio;
    int opcion;
    int id;
    int salir=0;
    int flag=0;
    Empleado empleados[EMPLEADOS_MAX];
    emp_cargarDatosVacio(empleados,EMPLEADOS_MAX);
    emp_cargarForzadaIndice(empleados,EMPLEADOS_MAX,"Lucas","Valdiviezo",3,5000);
    emp_cargarForzadaIndice(empleados,EMPLEADOS_MAX,"Martin","Zanahoria",3,1999);
    emp_cargarForzadaIndice(empleados,EMPLEADOS_MAX,"Carlos","Peruano",2,30000);
    emp_cargarForzadaIndice(empleados,EMPLEADOS_MAX,"Anabel","Peguajo",1,11500);
    emp_cargarForzadaIndice(empleados,EMPLEADOS_MAX,"Carlos","Vibora",2,11500);
    emp_cargarForzadaIndice(empleados,EMPLEADOS_MAX,"Anabel","Zetonga",1,11500);
    emp_cargarForzadaIndice(empleados,EMPLEADOS_MAX,"Jose","Zbroso",3,11500);

    do
    {
        system("cls");
        fflush(stdin);
        if(emp_checkEmptyIndex(empleados,EMPLEADOS_MAX)==-1)
        {
            flag=1;
        }else
        {
            flag=0;
        }
        utn_getEntero(&opcion,3,TEXTO_MENU,"Esa no es una opcion valida\n",7,0);
        switch(opcion)
        {
            case 1:
                    system("cls");
                    if(emp_getEmptyIndex(empleados,EMPLEADOS_MAX,&indiceVacio)==0)
                    {
                        emp_cargarIndice(empleados,indiceVacio,EMPLEADOS_MAX);
                        break;
                    }
                    else
                    {
                        printf("No hay lugar");
                        system("pause");
                    }
                    fflush(stdin);
                    break;
                case 2:
                    if(flag==1)
                    {
                        system("cls");
                        if(utn_getEntero(&id,10,"Ingrese el ID del empleado que desea modificar: ","Ese no es un ID valido\n",EMPLEADOS_MAX,-1)==0)
                        {
                            if(emp_buscarEmpleadoPorId(empleados,EMPLEADOS_MAX,id)!= -1)
                            {
                                emp_modificarIndice(empleados,id,EMPLEADOS_MAX);
                            }else
                            {
                                printf("\nEl ID no existe\n");
                                system("pause");
                            }

                        }
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                        system("pause");
                    }
                    fflush(stdin);
                    break;
                case 3:
                     if(flag==1)
                    {
                        system("cls");
                        if(utn_getEntero(&id,10,"Ingrese el ID del empleado que desea borrar: ","Ese no es un ID valido\n",EMPLEADOS_MAX,-1)==0)
                        {
                            if(emp_buscarEmpleadoPorId(empleados,EMPLEADOS_MAX,id)!= -1)
                            {
                              emp_borrarEmpleado(empleados,EMPLEADOS_MAX,id);
                            }else
                            {
                                 printf("\nEl ID no existe\n");
                                 system("pause");
                            }
                        }
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                        system("pause");
                    }
                    fflush(stdin);
                    break;
                case 4:
                     if(flag==1)
                    {
                        system("cls");
                        emp_mostrarIndice(empleados,EMPLEADOS_MAX);
                        system("pause");
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                        system("pause");
                    }
                     fflush(stdin);
                    break;
                case 5:

                    if(flag==1)
                    {
                        system("cls");
                        emp_calcularSalario(empleados,EMPLEADOS_MAX);
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                        system("pause");
                    }
                    fflush(stdin);
                    break;
                case 6:
                salir = 1;

        }
    }while(salir==0);

    return 0;
}
