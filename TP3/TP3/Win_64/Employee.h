#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
int employee_delete(Employee* this);

int employee_setId(Employee* this,char* id);
int employee_buscarPorId(LinkedList* pArrayEmployee, int employeeId);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void employee_mostrar(LinkedList* arrayLinkedList);
int employee_alta(LinkedList* arrayEmployee);
int employee_modificar(LinkedList* arrayEmployee);
int employee_borrar(LinkedList* arrayEmployee);

#endif // employee_H_INCLUDED
