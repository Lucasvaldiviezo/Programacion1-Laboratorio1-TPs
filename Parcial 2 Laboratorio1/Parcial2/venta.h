#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "LinkedList.h"
typedef struct{
    int idVenta;
    char fechaVenta[2000];
    char codigoProducto[2000];
    int cantidad;
    float precioUnitario;
    char cuitCliente[2000];
}Venta;

Venta* venta_new();
void venta_delete(Venta* this);

Venta* venta_newConParametros(  char* idVenta,char* fechaVenta,
                                char* codigoProducto,char* cantidad,char* precioUnitario,char* cuitCliente);

int venta_setIdVenta(Venta* this,char* idVenta);
int venta_getIdVenta(Venta* this,int* idVenta);

int venta_setFechaVenta(Venta* this,char* fechaVenta);
int venta_getFechaVenta(Venta* this,char* fechaVenta);

int venta_setCodigoProducto(Venta* this,char* codigoProducto);
int venta_getCodigoProducto(Venta* this,char* codigoProducto);

int venta_setPrecioUnitario(Venta* this,char* precioUnitario);
int venta_getPrecioUnitario(Venta* this,float* precioUnitario);

int venta_setCantidad(Venta* this,char* cantidad);
int venta_getCantidad(Venta* this,int* cantidad);

int venta_setCuitCliente(Venta* this,char* cuitCliente);
int venta_getCuitCliente(Venta* this,char* cuitCliente);

int venta_buscarPorId(LinkedList* listaVentas, int idVenta);
int venta_generarArchivo(char* fileName,LinkedList* lista);
int venta_cantidadAContarTotal(void* pElement);
int venta_cantidadAContarMayor1(void* pElement);
int venta_cantidadAContarMayor2(void* pElement);
int venta_cantidadLCD(void* pElement);
#endif // VENTA_H_INCLUDED
