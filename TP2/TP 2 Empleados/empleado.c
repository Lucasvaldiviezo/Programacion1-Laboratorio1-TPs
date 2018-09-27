#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
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
        printf("Ingrese nombre del empleado:");
        if(getString(auxName,128)==0)
        {
            strncpy(pEmpleado[indice].name,auxName,128);
            printf("Ingrese apellido del empleado: ");
            if(getString(auxLastName,128)==0)
            {
                strncpy(pEmpleado[indice].lastName,auxLastName,128);
                if(utn_getEntero(&auxSector,2,"Ingrese el sector del empleado: ","Ese sector no existe\n",10,-1)==0)
                {
                    pEmpleado[indice].sector=auxSector;

                    if(utn_getNumeroDecimal(&auxSalary,10,"Ingrese el salario del empleado: ","Ese no es un salario valido",4096,0)==0)
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
    indice=emp_buscarPantallaPorId(pEmpleado,limite,id);
    if(indice >= 0)
    {
        if(pEmpleado != NULL && limite >0)
        {
            printf("Ingrese el nuevo nombre del empleado:");
            if(getString(auxName,128)==0)
            {
                strncpy(pEmpleado[indice].name,auxName,128);
                printf("Ingrese el nuevo apellido del empleado: ");
                if(getString(auxLastName,128)==0)
                {
                    strncpy(pEmpleado[indice].lastName,auxLastName,128);
                    if(utn_getEntero(&auxSector,2,"Ingrese el nuevo sector del empleado: ","Ese sector no existe\n",10,-1)==0)
                    {
                        pEmpleado[indice].sector=auxSector;

                        if(utn_getNumeroDecimal(&auxSalary,10,"Ingrese el nuevo salario del empleado: ","Ese no es un salario valido",4096,0)==0)
                        {
                            pEmpleado[indice].salary=auxSalary;
                            retorno =0;
                        }

                    }

                }

            }
        }
    }else
    {
        printf("El ID no existe");
    }



    return retorno;

    return 0;
}

int emp_buscarPantallaPorId(Empleado* pEmpleado,int limite,int id)
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

int emp_borrarPantalla(Empleado* pEmpleado,int limite,int id)
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
            printf("\nEl salario del empleado es: %.2f por dia",pEmpleado[indice].salary);
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

static int generarID(void)
    {
        static int cont = -1; //es privada de la funcion, además no muere
        return ++cont;
    }
