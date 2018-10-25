#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

static int isValidNombre(char* nom);
static int isValidId(char* employeeId);
static int isValidHorasTrabajadas(char* horasTrabajadas);
static int isValidSueldo(char* sueldo);

Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}
Employee* employee_newConParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* p;
    p=employee_new();
    if(p!=NULL)
    {
        if( employee_setNombre(p,nombreStr)==-1 ||
            employee_setId(p,idStr)==-1)
        {
            employee_delete(p);
        }
    }
    return p;
}
int employee_delete(Employee* this)
{
    int retorno=-1;
    if(this!=NULL)
    {
        free(this);
        retorno=0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;
    //validar!!
    if(this != NULL && isValidNombre(nombre))
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    //validar!!
    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno=0;
    }
    return retorno;
}

static int isValidNombre(char* nombre)
{
    return 1;
}

int employee_setId(Employee* this,char* id)
{
    int retorno=-1;
    //validar!!
    if(this != NULL && isValidId(id)==0)
    {
        this->id=atoi(id);
        retorno=0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    //validar!!
     if(this != NULL && id!= NULL)
     {
        *id=this->id;
        retorno=0;
     }
    return retorno;
}

static int isValidId(char* employeeId)
{
    int i=0;
    int retorno=0;
    while(employeeId[i] != '\0')
    {
        if(employeeId[i] < '0' || employeeId[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas)
{
    int retorno=-1;
    //validar!!
    if(this != NULL && isValidHorasTrabajadas(horasTrabajadas)==0)
    {
        this->horasTrabajadas=atoi(horasTrabajadas);
        retorno=0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    //validar!!
     if(this != NULL && horasTrabajadas!= NULL)
     {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
     }
    return retorno;
}

static int isValidHorasTrabajadas(char* horasTrabajadas)
{
    int i=0;
    int retorno=0;
    while(horasTrabajadas[i] != '\0')
    {
        if(horasTrabajadas[i] < '0' || horasTrabajadas[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}

int employee_setSueldo(Employee* this,char* sueldo)
{
    int retorno=-1;
    //validar!!
    if(this != NULL && isValidSueldo(sueldo)==0)
    {
        this->sueldo=atoi(sueldo);
        retorno=0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    //validar!!
     if(this != NULL && sueldo!= NULL)
     {
        *sueldo=this->sueldo;
        retorno=0;
     }
    return retorno;
}

static int isValidSueldo(char* sueldo)
{
    int i=0;
    int retorno=0;
    while(sueldo[i] != '\0')
    {
        if(sueldo[i] < '0' || sueldo[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}

int employee_buscarLugarVacio(Employee* arrayEmployee[], int limite)
{
    int retorno=-1;
    int i;
    if(arrayEmployee != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayEmployee[i] == NULL)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int employee_inicializarArray(Employee* arrayEmployee[], int limite)
{
    int retorno=-1;
    int i;
    if(arrayEmployee!=NULL)
    {
        retorno=0;
        for(i=0;i<limite;i++)
        {
            arrayEmployee[i]=NULL;
        }
    }


    return retorno;
}

int employee_buscarPorId(Employee* arrayEmployee[], int limite, int employeeId)
{
    int retorno=-1;
    int i;
    Employee* auxEmployee;
    if(arrayEmployee!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            auxEmployee=arrayEmployee[i];
            if(auxEmployee!=NULL && auxEmployee->id == employeeId)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
