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
/**
    emp_cargarForzadaIndice: realizar una carga de datos de manera automatica al iniciar el programa
    @param pEmpleado: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param name: guarda una cadena de caracteres recibida
    @param lastName: guarda una cadena de caracteres recibida
    @param sector: guarda un int recibido
    @param sector: guarda un float recibido
    @return return 0 OK, -1 error.
*/
int emp_cargarForzadaIndice(Empleado* pEmpleado,int limite,char* name, char* lastName,int sector, float salary);
/**
    emp_cargarDatosVacio: carga un valor en el mismo campo de todas las posiciones del array recibido
    @param pEmpleado: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int emp_cargarDatosVacio(Empleado* pEmpleado,int limite);
/**
    emp_cargarDatosVacio: carga valores en la posicion del array recibida
    @param pEmpleado: guarda el array recibido
    @param indice: guarda el int de la posicion del array
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int emp_cargarIndice(Empleado* pEmpleado,int indice,int limite);
/**
    emp_mostrarIndice: muestra los datos de todas las posiciones del array
    @param pEmpleado: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int emp_mostrarIndice(Empleado* pEmpleado,int limite);
/**
    emp_getEmptyIndex:busca dentro del array hasta encontrar un indice vacio donde cargar datos
    @param pEmpleado: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param indiceVacio: guarda el indice de la posicion vacia del array
    @return return 0 OK, -1 error.
*/
int emp_getEmptyIndex(Empleado* pEmpleado,int limite,int* indiceVacio);
/**
    emp_modificarIndice: recibe un ID para modificar una posicion del array
    @param pEmpleado: guarda el array recibido
    @param id:guarda el int recibido del ID a modificar
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int emp_modificarIndice(Empleado* pEmpleado,int id, int limite);
/**
    emp_buscarEmpleadoPorID: recibe un ID para buscar un empleado
    @param pEmpleado: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param id:guarda el int del empleado a buscar
    @return return el indice del array donde esta el empleado
*/
int emp_buscarEmpleadoPorId(Empleado* pEmpleado,int limite,int id);
/**
    emp_borrarEmpleado: recibe un ID para borrar un empleado
    @param pEmpleado: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param id:guarda el int del empleado a borrar
    @return return 0 OK, -1 error.
*/
int emp_borrarEmpleado(Empleado* pEmpleado,int limite,int id);
/**
    emp_calcularSalario: recibe el array de empleados y realizar operaciones con el salario
    (total, promedio y salarios mayores al promedio)
    @param pEmpleado: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int emp_calcularSalario(Empleado* pEmpleado,int limite);
/**
    emp_checkEmptyIndex:recibe el array para checkear si esta cargado o no
    @param pEmpleado: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int emp_checkEmptyIndex(Empleado* pEmpleado,int limite);
/**
    emp_ordenarEmpleadoPorSectorApellid:recibe el array para ordenarlo con Burbujeo por Sector y Apellido
    @param pEmpleado: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int emp_ordenarEmpleadoPorSectorApellido(Empleado* pEmpleado, int limite);

#endif // EMPLEADO_H_INCLUDED
