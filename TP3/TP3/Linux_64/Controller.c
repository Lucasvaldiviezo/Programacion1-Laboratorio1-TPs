#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    pFile=fopen(path,"r");
    if(pFile != NULL && parser_EmployeeFromText(pFile,pArrayListEmployee)==0)
    {
       printf("||DATOS CARGADOS EN TEXTO||\n");
       retorno=0;
    }else
    {
        printf("No se pudieron cargar los datos en texto\n");
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    pFile=fopen(path,"rb");
    if(pFile!=NULL && parser_EmployeeFromBinary(pFile,pArrayListEmployee)==0)
    {
        printf("||DATOS CARGADOS POR BINARIO||\n");
        retorno=0;
    }else
    {
        printf("No se cargaron los datos en binario\n");
    }
    fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(employee_alta(pArrayListEmployee)==0)
    {
        printf("\n||Se ha agregado el empleado||\n");
        retorno=0;
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(employee_modificar(pArrayListEmployee)==0)
    {
        printf("\n||Se ha modificado el empleado||\n");
        retorno=0;
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(employee_borrar(pArrayListEmployee)==0)
    {
        printf("\n||Se ha borrado el empleado||\n");
        retorno=0;
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    employee_mostrar(pArrayListEmployee);
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(employee_guardarTexto(pArrayListEmployee,path)==0)
    {
        printf("||Los datos se guardaron en el archivo de texto||\n");
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(employee_guardarBinario(pArrayListEmployee,path)==0)
    {
        printf("||Los datos se guardaron en el archivo binario||\n");
        retorno=0;
    }
    return retorno;
}

