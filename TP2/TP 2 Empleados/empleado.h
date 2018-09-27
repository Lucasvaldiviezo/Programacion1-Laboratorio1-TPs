#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#define TIPO_LED 0
#define TIPO_LCD 1

struct S_empleado{
int ID;
int sector;
char name[128];
char lastName[128];
float salary;
int isEmpty;
}typedef Empleado;

int emp_cargarDatosVacio(Empleado* pEmpleado,int limite);
int emp_cargarIndice(Empleado* pEmpleado,int indice,int limite);
int emp_mostrarIndice(Empleado* pEmpleado,int limite);
int emp_getEmptyIndex(Empleado* pEmpleado,int limite,int* indiceVacio);
int emp_modificarIndice(Empleado* pEmpleado,int id, int limite);
int emp_buscarEmpleadoPorId(Empleado* pEmpleado,int limite,int id);
int emp_borrarEmpleado(Empleado* pEmpleado,int limite,int id);
int emp_calcularSalario(Empleado* pEmpleado,int limite);
int emp_checkEmptyIndex(Empleado* pEmpleado,int limite);

#endif // EMPLEADO_H_INCLUDED
