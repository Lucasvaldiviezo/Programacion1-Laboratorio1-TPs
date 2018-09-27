#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
#define EMPLEADOS_MAX 1000
#define TEXTO_MENU "       MENU\n\
1)Cargar un empleado\n\
2)Imprimir lista de empleados\n\
3)Modificar un empleado\n\
4)Borrar una empleado\n\
5)Mostrar: Total de los salarios, promedio de los salarios y salarios por encima del promedio\n\
6)Salir\n\
Elija una opcion: "


int main()
{
    int indiceVacio;
    int i;
    int opcion;
    int id;
    int salir=0;
    int flag=0;
    Empleado empleados[EMPLEADOS_MAX];
    emp_cargarDatosVacio(empleados,EMPLEADOS_MAX);
    do
    {
        system("cls");
        fflush(stdin);
        utn_getEntero(&opcion,3,TEXTO_MENU,"Esa no es una opcion valida",7,0);
        switch(opcion)
        {
            case 1:
                    system("cls");
                    if(flag == 0)
                    {
                        flag=1;
                    }
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
                        for(i=0;i<EMPLEADOS_MAX;i++)
                        {
                            if(empleados[i].isEmpty==0)
                            {
                                emp_mostrarIndice(empleados,i);
                            }
                        }
                        system("pause");
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
                        if(utn_getEntero(&id,10,"Ingrese el ID del empleado que desea modificar: ","Ese no es un ID valido\n",EMPLEADOS_MAX,-1)==0)
                        {
                            emp_modificarIndice(empleados,id,EMPLEADOS_MAX);
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
                        if(utn_getEntero(&id,10,"Ingrese el ID de la pantalla que desea borrar: ","Ese no es un ID valido\n",EMPLEADOS_MAX,-1)==0)
                        {
                            emp_borrarEmpleado(empleados,EMPLEADOS_MAX,id);
                        }
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                        system("pause");
                    }
                    fflush(stdin);
                    break;
                case 5:
                    system("cls");
                    if(flag==1)
                    {
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
