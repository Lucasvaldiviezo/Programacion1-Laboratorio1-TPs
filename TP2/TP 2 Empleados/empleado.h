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
int emp_mostrarIndice(Empleado* pEmpleado,int indice);
int emp_getEmptyIndex(Empleado* pEmpleado,int limite,int* indiceVacio);
int emp_modificarIndice(Empleado* pEmpleado,int id, int limite);
int emp_buscarPantallaPorId(Empleado* pEmpleado,int limite,int id);
int emp_borrarPantalla(Empleado* pEmpleado,int limite,int id);

#endif // EMPLEADO_H_INCLUDED
