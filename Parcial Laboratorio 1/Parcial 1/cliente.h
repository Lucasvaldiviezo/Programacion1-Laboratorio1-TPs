#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "ventaAfiche.h"
typedef struct{
int ID;
char name[128];
char lastName[128];
char cuit[11];
int isEmpty;
}Cliente;

/**
    cliente_cargarForzadaIndice: realizar una carga de datos de manera automatica al iniciar el programa
    @param pCliente: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param name: guarda una cadena de caracteres recibida
    @param lastName: guarda una cadena de caracteres recibida
    @param cuit: guarda una cadena de caracteres recibida
    @return return 0 OK, -1 error.
*/
int cliente_cargarForzadaIndice(Cliente* pCliente,int limite,char* name, char* lastName,char* cuit);
/**
    cliente_cargarDatosVacio: carga un valor en el mismo campo de todas las posiciones del array recibido
    @param pCliente: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int cliente_cargarDatosVacio(Cliente* pCliente, int limite);
/**
    cliente_cargarIndice: carga valores en la posicion del array recibida
    @param pCliente: guarda el array recibido
    @param indice:guarda el int del indice donde se cargaran los datos
    @param limite: guarda el int del limite del
    @return return 0 OK, -1 error.
*/
int cliente_cargarIndice(Cliente* pCliente,int indice,int limite);
/**
    cliente_modificarIndice: recibe un ID para modificar una posicion del array
    @param pCliente: guarda el array recibido
    @param id:guarda el int recibido del ID a modificar
    @param limite: guarda el int del limite del
    @return return 0 OK, -1 error.
*/
int cliente_modificarIndice(Cliente* pCliente,int id, int limite);
/**
    cliente_borrarCliente: recibe un ID para borrar una posicion del array
    @param pCliente: guarda el array recibido
    @param limite: guarda el int del limite del
    @param id:guarda el int recibido del ID a modificar
    @return return 0 OK, -1 error.
*/
int cliente_borrarCliente(Cliente* pCliente,int limite,int id);
/**
    venta_mostrarIndice: muestra los datos de todas las posiciones del array
    @param pCliente: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int cliente_mostrarIndice(Cliente* pCliente,int limite);
/**
    cliente_mostrarUnIndice: muestra los datos de la posicion recibida en el array
    @param pCliente: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param indice: guarda el int de la posicion del array
    @return return 0 OK, -1 error.
*/
int cliente_mostrarUnIndice(Cliente* pCliente,int limite,int indice);
/**
    cliente_buscarClientePorId: recibe un ID para buscar un cliente
    @param pCliente: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param id:guarda el int de la venta a buscar
    @return return el indice del array donde esta el venta
*/
int cliente_buscarClientePorId(Cliente* pCliente,int limite,int id);
/**
    clientet_getEmptyIndex:busca dentro del array hasta encontrar un indice vacio donde cargar datos
    @param pCliente: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param indiceVacio: guarda el indice de la posicion vacia del array
    @return return 0 OK, -1 error.
*/
int cliente_getEmptyIndex(Cliente* pCliente,int limite,int* indiceVacio);
/**
    cliente_checkEmptyIndex:recibe el array para checkear si esta cargado o no
    @param pCliente: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int cliente_checkEmptyIndex(Cliente* pCliente,int limite);
int cliente_mostrarIndiceConVentas(Cliente* pCliente,int limite,Venta* pVenta,int limite2);


#endif // CLIENTE_H_INCLUDED
