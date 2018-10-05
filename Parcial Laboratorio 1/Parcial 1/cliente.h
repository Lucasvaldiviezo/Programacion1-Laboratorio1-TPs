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

int cliente_cargarForzadaIndice(Cliente* pCliente,int limite,char* name, char* lastName,char* cuit);
int cliente_cargarDatosVacio(Cliente* pCliente, int limite);
int cliente_cargarIndice(Cliente* pCliente,int indice,int limite);
int cliente_modificarIndice(Cliente* pCliente,int id, int limite);
int cliente_borrarCliente(Cliente* pCliente,int limite,int id);
int cliente_mostrarIndice(Cliente* pCliente,int limite);
int cliente_mostrarUnIndice(Cliente* pCliente,int limite,int indice);
int cliente_buscarClientePorId(Cliente* pCliente,int limite,int id);
int cliente_getEmptyIndex(Cliente* pCliente,int limite,int* indiceVacio);
int cliente_checkEmptyIndex(Cliente* pCliente,int limite);
int cliente_mostrarIndiceConVentas(Cliente* pCliente,int limite,Venta* pVenta,int limite2);


#endif // CLIENTE_H_INCLUDED
