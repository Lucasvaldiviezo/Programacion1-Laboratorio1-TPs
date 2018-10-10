#ifndef VENTAAFICHE_H_INCLUDED
#define VENTAAFICHE_H_INCLUDED
typedef struct{
int ID;
int cantAfiches;
char nombreImagen[128];
char zona[128];
char estado[30];
int idCliente;
int isEmpty;
}Venta;
/**
    venta_cargarForzadaVenta: realizar una carga de datos de manera automatica al iniciar el programa
    @param pVenta: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param nombreImagen: guarda una cadena de caracteres recibida
    @param zona: guarda una cadena de caracteres recibida
    @param estado: guarda una cadena de caracteres recibida
    @param cantAfiches: guarda un int recibido
    @param idCliente: guarda un int recibido
    @return return 0 OK, -1 error.
*/
int venta_cargaForzadaVenta(Venta* pVentas,int limite,char* nombreImagen, char* zona,char* estado,int cantAfiches,int idCliente);
/**
    venta_cargarDatosVacio: carga un valor en el mismo campo de todas las posiciones del array recibido
    @param pVenta: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int venta_cargarDatosVacio(Venta* pVenta, int limite);
/**
    venta_getEmptyIndex:busca dentro del array hasta encontrar un indice vacio donde cargar datos
    @param pVenta: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param indiceVacio: guarda el indice de la posicion vacia del array
    @return return 0 OK, -1 error.
*/
int venta_getEmptyIndex(Venta* pVenta,int limite,int* indiceVacio);
/**
    venta_mostrarUnIndice: muestra los datos de la posicion recibida en el array
    @param pVenta: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param indice: guarda el int de la posicion del array
    @return return 0 OK, -1 error.
*/
int venta_mostrarUnIndice(Venta* pVenta,int limite,int indice);
/**
    venta_mostrarIndice: muestra los datos de todas las posiciones del array
    @param pVenta: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int venta_mostrarIndice(Venta* pVenta,int limite);
/**
    venta_cargarIndice: carga valores en la posicion del array recibida
    @param pVenta: guarda el array recibido
    @param limite: guarda el int del limite del
    @param idCliente:guarda el int recibido del ID para crear la venta
    @return return 0 OK, -1 error.
*/
int venta_cargarIndice(Venta* pVenta,int indice,int limite,int idCliente);
/**
    venta_modificarIndice: recibe un ID para modificar una posicion del array
    @param pVenta: guarda el array recibido
    @param limite: guarda el int del limite del
    @param idCliente:guarda el int recibido del ID a modificar
    @return return 0 OK, -1 error.
*/
int venta_modificarIndice(Venta* pVenta,int indice,int limite,int idCliente);
/**
    venta_buscarVentaPorId: recibe un ID para buscar una venta
    @param pVenta: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param id:guarda el int de la venta a buscar
    @return return el indice del array donde esta el venta
*/
int venta_buscarVentaPorId(Venta* pVenta,int limite,int id);
/**
    venta_borrarVenta: recibe un ID para borrar una venta
    @param pVenta: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param id:guarda el int de la venta a borrar
    @return return 0 OK, -1 error.
*/
int venta_borrarVenta(Venta* ventas,int limite,int id);
/**
    venta_checkEstado: revisa el estado actual de una venta
    @param pVenta: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param id:guarda el int de la venta
    @param estado:guarda la cadena de caracteres a comparar
    @return return 0 OK, -1 error.
*/
int venta_checkEstado(Venta* pVenta,int limite,int id,char* estado);
/**
    venta_buscarClienteVentaPorId: recorre el array de ventas y devuelve a que cliente pertenece
    @param pVenta: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param id:guarda el int de la venta a buscar
    @param idCliente:guarda el int del cliente devuelvo
    @return return 0 OK, -1 error.
*/
int venta_buscarClienteVentaPorId(Venta* pVenta,int limite,int id,int* idCliente);
/**
    venta_cobrarVenta: cambia el estado de una venta a Cobrado
    @param pVenta: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param id:guarda el int de la venta a buscar
    @return return 0 OK, -1 error.
*/
int venta_cobrarVenta(Venta* pVenta,int limite,int id);
/**
    venta_cantidadDeVentasCliente
    @param pVenta: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param idCliente:guarda el int del cliente de la venta a buscar
    @return return 0 OK, -1 error.
*/
int venta_cantidadDeVentasCliente(Venta* pVenta,int limite,int idCliente);


#endif // VENTAAFICHE_H_INCLUDED
