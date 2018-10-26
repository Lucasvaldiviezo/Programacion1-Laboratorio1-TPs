#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    Employee *auxiliarPunteroEmployee;
    int flagOnce=1;
    while(!feof(pFile))
    {
        if(flagOnce)
        {
            fscanf(pFile,"%s",bufferId);
            flagOnce=0;
        }
        else if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,
                                                    bufferNombre,
                                                    bufferHorasTrabajadas,
                                                    bufferSueldo)==4)
        {
            auxiliarPunteroEmployee=employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            if(auxiliarPunteroEmployee!=NULL)
            {
                ll_add(pArrayListEmployee,auxiliarPunteroEmployee);
            }
        }
        else
        {
            break;
        }
    }
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
