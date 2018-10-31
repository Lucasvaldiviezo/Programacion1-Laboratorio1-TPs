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
    @param this: el espacio en memoria donde se guardara
    @param id:la cadena de caracteres con el Id
    @return 0 OK, -1 error.
*/
int employee_setId(Employee* this,char* id);
/**
    employee_getId: recibe un dato tipo Employee donde se buscara un id y se devolvera ese id
    @param this: el espacio en memoria de un dato tipo Employee donde se buscara
    @param id: el puntero a un int donde se guardara el Id a buscar
    @return 0 OK, -1 error.
*/
int employee_getId(Employee* this,int* id);
/**
    employee_setNombre: recibe un nombre para guardarlo
    @param this: el espacio en memoria donde se guardara
    @param nombre: la cadena de caracteres con el nombre
    @return 0 OK, -1 error.
*/
int employee_setNombre(Employee* this,char* nombre);
/**
    employee_getNombre: recibe un dato tipo Employee donde se buscara un nombre y se devolvera ese nombre
    @param this: el espacio en memoria de un dato tipo Employee donde se buscara
    @param nombre: una cadena de caracteres donde se guardara el nombre a buscar
    @return 0 OK, -1 error.
*/
int employee_getNombre(Employee* this,char* nombre);
/**
    employee_setHorasTrabajadas: recibe una cantidad de horas trabajadas para guardarla
    @param this: el espacio en memoria donde se guardara
    @param horasTrabajadas: la cadena de caracteres con las horas trabajadas
    @return 0 OK, -1 error.
*/
int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas);
/**
    employee_getHorasTrabajadas: recibe un dato tipo Employee donde se buscara la cantidad de horas trabajadas y se devolvera esa cantidad
    @param this: el espacio en memoria de un dato tipo Employee donde se buscara
    @param horasTrabajadas: el puntero a un int donde se guardara las horas a buscar
    @return 0 OK, -1 error.
*/
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/**
    employee_setSueldo: recibe un sueldo para guardarlo
    @param this: el espacio en memoria donde se guardara
    @param sueldo: la cadena de caracteres con el sueldo
    @return 0 OK, -1 error.
*/
int employee_setSueldo(Employee* this,char* sueldo);
/**
    employee_getSueldo: recibe un dato tipo Employee donde se buscara un sueldo y se devolvera ese sueldo
    @param this: el espacio en memoria de un dato tipo Employee donde se buscara
    @param sueldo: el puntero a un int donde se guardara el sueldo a buscar
    @return 0 OK, -1 error.
*/
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
/**
    employee_buscarPorId: recibe una LinkedList y un int con un Id para encontrar en que posicio esta ese Id o si existe
    @param arrayEmployee: el array a recorrer
    @param id: el id que se compara con los Id del array hasta encontrar el igual
    @return un int con la posicion de un array.
*/
int employee_buscarPorId(LinkedList* pArrayEmployee, int employeeId);
int employee_ordenarPorNombre(LinkedList* arrayEmployee);
/**
    employee_guardarTexto: guarda los datos del LinkedList en la ruta del archivo recibido;
    @param arrayLinkedList: recibe el array a guardar.
    @param path: nombre del archivo donde se guardaran los datos
    @return 0 OK, -1 error.
*/
int employee_guardarTexto(LinkedList* pArrayEmployee, char* path);

#endif // employee_H_INCLUDED
