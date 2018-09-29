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

int emp_cargarForzadaIndice(Empleado* pEmpleado,int limite,char* name, char* lastName,int sector, float salary)
{
    int retorno=-1;
    int indice;
    emp_getEmptyIndex(pEmpleado,limite,&indice);

    if(pEmpleado != NULL && limite >0)
    {
          if(indice >= 0)
          {
            strncpy(pEmpleado[indice].name,name,50);
            strncpy(pEmpleado[indice].lastName,lastName,50);
            pEmpleado[indice].sector=sector;
            pEmpleado[indice].salary=salary;
            pEmpleado[indice].ID=generarID();
            pEmpleado[indice].isEmpty=0;
            retorno =0;
          }

    }


    return retorno;
}

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
    char auxName[50];
    char auxLastName[50];
    int auxSector;
    float auxSalary;

    if(pEmpleado != NULL && limite >0)
    {
        if(utn_getNombre(auxName,"Ingrese nombre del empleado: ","Ese no es un nombre valido\n")==0)
        {
            strncpy(pEmpleado[indice].name,auxName,50);
            if(utn_getNombre(auxLastName,"Ingrese apellido del empleado: ","Ese no es un apellido valido \n")==0)
            {
                strncpy(pEmpleado[indice].lastName,auxLastName,50);
                if(utn_getEntero(&auxSector,2,"Ingrese el sector del empleado(1-Fabrica,2-Administracion,3-Tesoreria): ","Ese sector no existe\n",4,0)==0)
                {
                    pEmpleado[indice].sector=auxSector;

                    if(utn_getNumeroDecimal(&auxSalary,10,"Ingrese el salario del empleado: ","Ese no es un salario valido\n",1000000,0)==0)
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
    char auxName[50];
    char auxLastName[50];
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
                            if(utn_getNombre(auxName,"Ingrese el nuevo nombre del empleado: ","Ese no es un nombre valido\n")==0)
                            {
                                strncpy(pEmpleado[indice].name,auxName,50);
                            }
                            fflush(stdin);
                            break;
                        case 2:
                            system("cls");
                            if(utn_getNombre(auxLastName,"Ingrese el nuevo apellido del empleado: ","Ese no es un apellido valido\n")==0)
                            {
                                    strncpy(pEmpleado[indice].lastName,auxLastName,50);
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
                            if(utn_getNumeroDecimal(&auxSalary,10,"Ingrese el nuevo salario del empleado: ","Ese no es un salario valido",1000000,0)==0)
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

int emp_mostrarIndice(Empleado* pEmpleado,int limite)
{
    int retorno=-1;
    int i;
    if(pEmpleado != NULL && limite > 0)
    {
        if(emp_ordenarIndice(pEmpleado,limite)==0)
        {
            for(i=0;i<limite;i++)
            {
                if(pEmpleado[i].isEmpty==0)
                {
                    printf("\nEl ID del empleado es: %d", pEmpleado[i].ID);
                    printf("\nEl nombre del empleado es: %s",pEmpleado[i].name);
                    printf("\nEl apellido del empleado es: %s",pEmpleado[i].lastName);
                    printf("\nEl sector del empleado es: %d",pEmpleado[i].sector);
                    printf("\nEl salario del empleado es: %.2f\n",pEmpleado[i].salary);
                    retorno=0;
                }
            }
        }
    }

    return retorno;
}

int emp_ordenarIndice(Empleado* pEmpleado, int limite)
{
  int retorno=-1;
  int i;
  int j;
  int tempID;
  int tempSector;
  float tempSalary;
  char tempName[50];
  char tempLastName[50];
  if(pEmpleado != NULL && limite > 0)
  {
    for(i=1;i<limite;i++)
    {
        if(pEmpleado[i].isEmpty==0)
        {
            tempID=pEmpleado[i].ID;
            tempSector=pEmpleado[i].sector;
            tempSalary=pEmpleado[i].salary;
            strcpy(tempName,pEmpleado[i].name);
            strcpy(tempLastName,pEmpleado[i].lastName);
            j=i-1;
            while(j>=0 && tempSector<pEmpleado[j].sector /*strcmp(tempLastName,pEmpleado[j].lastName)<0*/)
            {
                pEmpleado[j+1]=pEmpleado[j];
                j--;
            }
            pEmpleado[j+1].ID=tempID;
            pEmpleado[j+1].sector=tempSector;
            pEmpleado[j+1].salary=tempSalary;
            strcpy(pEmpleado[j+1].name,tempName);
            strcpy(pEmpleado[j+1].lastName,tempLastName);

        }
    }
    retorno=0;
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

int emp_checkEmptyIndex(Empleado* pEmpleado,int limite)
{
    int i=0;
    int retorno = 0;
    if(pEmpleado != NULL && limite > 0)
    {
         while(i<limite)
        {
            if(pEmpleado[i].isEmpty==0)
            {
                retorno = -1;
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
        static int cont = -1; //es privada de la funcion, además no muere
        return ++cont;
    }
