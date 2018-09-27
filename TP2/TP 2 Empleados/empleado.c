#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
#define MENU_MODIFICAR "Ingrese la opcion que desea modificar:\n\
1)Nombre\n\
2)Apellido\n\
3)Sector\n\
4)Salario\n\
5)Terminar\n\
Elija:"
static int generarID(void);

int emp_cargarDatosVacio(Empleado* pEmpleado, int limite)
{
    int retorno=-1;
    int i;
    if(pEmpleado != NULL && limite >0)
    {
        for(i=0;i<limite;i++)
        {
            pEmpleado[i].isEmpty=-1;
        }
        retorno=0;
    }

    return retorno;
}
int emp_cargarIndice(Empleado* pEmpleado,int indice,int limite)
{
    int retorno=-1;
    char auxName[128];
    char auxLastName[128];
    int auxSector;
    float auxSalary;

    if(pEmpleado != NULL && limite >0)
    {
        printf("Ingrese nombre del empleado: ");
        if(getString(auxName,128)==0)
        {
            strncpy(pEmpleado[indice].name,auxName,128);
            printf("Ingrese apellido del empleado: ");
            if(getString(auxLastName,128)==0)
            {
                strncpy(pEmpleado[indice].lastName,auxLastName,128);
                if(utn_getEntero(&auxSector,2,"Ingrese el sector del empleado(1-Fabrica,2-Administracion,3-Tesoreria): ","Ese sector no existe\n",4,0)==0)
                {
                    pEmpleado[indice].sector=auxSector;

                    if(utn_getNumeroDecimal(&auxSalary,10,"Ingrese el salario del empleado: ","Ese no es un salario valido\n",10000,0)==0)
                    {
                        pEmpleado[indice].salary=auxSalary;
                        pEmpleado[indice].ID=generarID();
                        pEmpleado[indice].isEmpty=0;
                        retorno =0;

                    }

                }

            }

        }
    }


    return retorno;
}

int emp_modificarIndice(Empleado* pEmpleado,int id, int limite)
{
    int retorno=-1;
    char auxName[128];
    char auxLastName[128];
    int auxSector;
    float auxSalary;
    int indice;
    int opcion;
    int salir;
    indice=emp_buscarEmpleadoPorId(pEmpleado,limite,id);
    if(indice >= 0)
    {
        if(pEmpleado != NULL && limite >0)
        {
            do
            {
                system("cls");
                fflush(stdin);
                if(utn_getEntero(&opcion,10,MENU_MODIFICAR,"Esa no es una opcion valida\n",6,0)==0)
                {
                    switch(opcion)
                    {
                        case 1:
                            system("cls");
                            printf("Ingrese el nuevo nombre del empleado: ");
                            if(getString(auxName,128)==0)
                            {
                                strncpy(pEmpleado[indice].name,auxName,128);
                            }
                            fflush(stdin);
                            break;
                        case 2:
                            system("cls");
                            printf("Ingrese el nuevo apellido del empleado: ");
                            if(getString(auxLastName,128)==0)
                            {
                                    strncpy(pEmpleado[indice].lastName,auxLastName,128);
                            }
                            fflush(stdin);
                            break;
                        case 3:
                            system("cls");
                            if(utn_getEntero(&auxSector,2,"Ingrese el nuevo sector del empleado(1-Fabrica,2-Administracion,3-Tesoreria): ","Ese sector no existe\n",4,0)==0)
                            {
                                pEmpleado[indice].sector=auxSector;
                            }
                            fflush(stdin);
                            break;
                        case 4:
                            system("cls");
                            if(utn_getNumeroDecimal(&auxSalary,10,"Ingrese el nuevo salario del empleado: ","Ese no es un salario valido",10000,0)==0)
                            {
                                pEmpleado[indice].salary=auxSalary;
                            }
                            fflush(stdin);
                            break;
                        case 5:
                            salir=1;
                    }

                 }
            }while(salir==0);
            retorno=0;

        }

    }else
    {
        printf("El ID no existe\n");
        system("pause");
    }
    return retorno;
    return 0;
}

int emp_buscarEmpleadoPorId(Empleado* pEmpleado,int limite,int id)
{
    int retorno=-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if(pEmpleado[i].isEmpty==0)
        {
            if(pEmpleado[i].ID==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int emp_borrarEmpleado(Empleado* pEmpleado,int limite,int id)
{
    int retorno=-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if(pEmpleado[i].isEmpty==0)
        {
            if(pEmpleado[i].ID==id)
            {
                pEmpleado[i].isEmpty=-1;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int emp_mostrarIndice(Empleado* pEmpleado,int indice)
{
    int retorno=-1;
    if(pEmpleado != NULL && indice > -1)
    {
        if(pEmpleado[indice].isEmpty==0)
        {
            printf("\nEl ID del empleado es: %d", pEmpleado[indice].ID);
            printf("\nEl nombre del empleado es: %s",pEmpleado[indice].name);
            printf("\nEl apellido del empleado es: %s",pEmpleado[indice].lastName);
            printf("\nEl sector del empleado es: %d",pEmpleado[indice].sector);
            printf("\nEl salario del empleado es: %.2f\n",pEmpleado[indice].salary);
            retorno=0;
        }
        else
        {
            printf("Esta Vacio");
        }
    }

    return retorno;
}
int emp_getEmptyIndex(Empleado* pEmpleado,int limite,int* indiceVacio)
{
    int i=0;
    int retorno = -1;
    if(pEmpleado != NULL && limite > 0)
    {
         while(i<limite)
        {
            if(pEmpleado[i].isEmpty==-1)
            {
                *indiceVacio=i;
                retorno = 0;
                break;
            }
            i++;
        }
    }

    return retorno;
}

int emp_calcularSalario(Empleado* pEmpleado,int limite)
{
    int retorno=-1;
    int i;
    float total=0;
    float cantSalarios=0;
    int cantMayorPromedio=0;
    float promedio;
    int flag=0;

    if(pEmpleado != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pEmpleado[i].isEmpty==0)
            {
                total=total + pEmpleado[i].salary;
                cantSalarios++;
            }
        }

        promedio=total/cantSalarios;

        for(i=0;i<limite;i++)
        {
            if(pEmpleado[i].isEmpty==0)
            {
                if(pEmpleado[i].salary>promedio)
                {
                    cantMayorPromedio++;
                    flag=1;
                }
            }
        }

    }

    if(cantSalarios > 0)
    {
        printf("El total de los salarios es: %.2f",total);
        printf(" y el promedio es: %.2f\n",promedio);
    }else
    {
        printf("No hay salarios cargados\n");
        system("pause");
    }
    if(flag==1)
    {
        printf("La cantidad de salarios que superan el promedio es de: %d\n",cantMayorPromedio);
        system("pause");
    }else
    {
        printf("Ningun salario supera el promedio");
        system("pause");
    }
    return retorno;
}

static int generarID(void)
    {
        static int cont = -1; //es privada de la funcion, adem�s no muere
        return ++cont;
    }
