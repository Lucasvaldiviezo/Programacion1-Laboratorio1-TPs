#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;
/**
    employee_new: crea un nuevo espacio en memoria con una variable de tipo Employee
    @return direccion de memoria creada.
*/
Employee* employee_new();
/**
    employee_newParametros: crea un nuevo espacio en memoria y guarda datos en un tipo Employee
    @param idStr: cadena de caracteres con el id a guardar
    @param nombreStr: cadena de caracteres con el nombre a guardar
    @param horasTrabajadasStr: cadena de caracteres con las horas trabajadas a guardar
    @param sueldoStr: cadena de caracteres con el sueldo a guardar
    @return direccion de memoria creada.
*/
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
/**
    employee_delete: borra un espacio en memoria
    @param this:el espacio en memoria a borrar
    @return 0 OK, -1 error.
*/
int employee_delete(Employee* this);
/**
    employee_setId: recibe un Id para guardarlo
    @param this:el espacio en memoria donde se guardara
    @param id:la cadena de caracteres con el Id
    @return 0 OK, -1 error.
*/
int employee_setId(Employee* this,char* id);
int employee_buscarPorId(LinkedList* pArrayEmployee, int employeeId);
/**
    employee_setNombre: recibe un nombre para guardarlo
    @param this:el espacio en memoria donde se guardara
    @param nombre:la cadena de caracteres con el nombre
    @return 0 OK, -1 error.
*/
int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
/**
    employee_mostrar: lista todo el contenido del array LinkedLista
    @param arrayLinkedList: recibe el array a mostrar
*/
void employee_mostrar(LinkedList* arrayLinkedList);
/**
    employee_alta: agrega nuevos datos al array LinkedList.
    @param arrayLinkedList: recibe el array en el que se cargaran los datos.
    @return 0 OK, -1 error.
*/
int employee_alta(LinkedList* arrayEmployee);
/**
    employee_modificacion: modifica datos actuales al array LinkedList.
    @param arrayLinkedList: recibe el array en el que se modificara el dato.
    @return 0 OK, -1 error.
*/
int employee_modificar(LinkedList* arrayEmployee);
/**
    employee_borrar: borra datos actuales al array LinkedList.
    @param arrayLinkedList: recibe el array en el que se borrara el dato.
    @return 0 OK, -1 error.
*/
int employee_borrar(LinkedList* arrayEmployee);
int employee_ordenarPorNombre(LinkedList* arrayEmployee);
/**
    employee_guardarTexto: guarda los datos del LinkedList en la ruta del archivo recibido;
    @param arrayLinkedList: recibe el array a guardar.
    @param path: nombre del archivo donde se guardaran los datos
    @return 0 OK, -1 error.
*/
int employee_guardarTexto(LinkedList* pArrayEmployee, char* path);

#endif // employee_H_INCLUDED
