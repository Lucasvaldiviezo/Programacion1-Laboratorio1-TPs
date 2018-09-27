#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
#define EMPLEADOS_MAX 1000
#define TEXTO_MENU "       \n||MENU||\n\
1)Cargar un empleado\n\
2)Imprimir lista de empleados\n\
3)Modificar un empleado\n\
4)Borrar una empleado\n\
5)Salir\n"

int main()
{
    int indiceVacio;
    int i;
    int opcion;
    int id;
    int salir=0;
    Empleado empleados[EMPLEADOS_MAX];
    emp_cargarDatosVacio(empleados,EMPLEADOS_MAX);
    do
    {
    utn_getEntero(&opcion,3,TEXTO_MENU,"Esa no es una opcion valida",6,0);
        switch(opcion)
        {
            case 1:

                    if(emp_getEmptyIndex(empleados,EMPLEADOS_MAX,&indiceVacio)==0)
                    {
                        emp_cargarIndice(empleados,indiceVacio,EMPLEADOS_MAX);
                        break;
                    }
                    else
                    {
                        printf("No hay lugar");
                    }


                    break;
                case 2:
                    for(i=0;i<EMPLEADOS_MAX;i++)
                    {
                        if(empleados[i].isEmpty==0)
                        {
                            emp_mostrarIndice(empleados,i);
                        }
                    }
                    break;
                case 3:
                    if(utn_getEntero(&id,10,"Ingrese el ID de la pantalla que desea modificar: ","Ese no es un ID valido\n",EMPLEADOS_MAX,-1)==0)
                    {
                        emp_modificarIndice(empleados,id,EMPLEADOS_MAX);
                    }
                    break;
                case 4:
                    if(utn_getEntero(&id,10,"Ingrese el ID de la pantalla que desea borrar: ","Ese no es un ID valido\n",EMPLEADOS_MAX,-1)==0)
                    {
                        emp_borrarPantalla(empleados,EMPLEADOS_MAX,id);
                    }
                    break;
                case 5:
                salir = 1;

        }
    }while(salir==0);

    return 0;
}
