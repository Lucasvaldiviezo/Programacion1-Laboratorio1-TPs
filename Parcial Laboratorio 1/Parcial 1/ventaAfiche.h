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

int venta_cargarDatosVacio(Venta* pVenta, int limite);
int venta_getEmptyIndex(Venta* pVenta,int limite,int* indiceVacio);
int venta_mostrarUnIndice(Venta* pVenta,int limite,int indice);
int venta_mostrarIndice(Venta* pVenta,int limite);
int venta_cargarIndice(Venta* pVenta,int indice,int limite,int idCliente);
int venta_modificarIndice(Venta* pVenta,int indice,int limite,int idCliente);
int venta_buscarVentaPorId(Venta* pVenta,int limite,int id);
int venta_borrarVenta(Venta* ventas,int limite,int id);
int venta_cargaForzadaVenta(Venta* pVentas,int limite,char* nombreImagen, char* zona,char* estado,int cantAfiches,int idCliente);
int venta_checkEstado(Venta* pVenta,int limite,int id,char* estado);
int venta_buscarClienteVentaPorId(Venta* pVenta,int limite,int id,int* idCliente);
int venta_cobrarVenta(Venta* pVenta,int limite,int id);
int venta_cantidadDeVentasCliente(Venta* pVenta,int limite,int id);


#endif // VENTAAFICHE_H_INCLUDED
