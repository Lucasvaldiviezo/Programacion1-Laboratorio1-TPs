#ifndef INFORMAR_H_INCLUDED
#define INFORMAR_H_INCLUDED

/**
    informar_promedioAfiches: recibe el array de ventas y suma la cantidad de afiches por venta para sacar un promedio
    @param pVenta: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param promedioAfiches: recibe un puntero a un float donde guardar el promedio
    @return return @return return 0 OK, -1 error.
*/
int informar_promedioAfiches(Cliente* pCliente,int limite,Venta* pVenta,int limite2);
int informar_OrdenarVentaPorZona(Venta* pVenta, int limite);
int informar_clienteMenosVentasACobrar(Cliente* pCliente,int limite, Venta* pVenta,int limite2);
int informar_clienteMenosVentasCobradas(Cliente* pCliente,int limite, Venta* pVenta,int limite2);
int informar_clienteMenosVentas(Cliente* pCliente,int limite, Venta* pVenta,int limite2);
int informar_cantidadAfichesZona(Venta* pVenta,int limite, int* cantAficheZonaSur,int* cantAficheZonaEste,int* cantAficheZonaOeste,int* cantAficheZonaNorte);
int informar_mostrarZonaConMasAfiches(Venta* pVenta,int limite);
int informar_clienteCantAfichesUnCliente(Venta* pVenta,int limite,int idCliente);
int informar_clienteConMenosAfiches(Cliente* pCliente,int limite,Venta* pVenta,int limite2);
int informar_mostrarAfichePorZona(Venta* pVenta,int limite);
int informar_clienteCantAfichesMayor(Cliente* pCliente,int limite,Venta* pVenta,int limite2,int valorComparativo);
int informar_clienteCantAfichesUnClienteACobrar(Venta* pVenta,int limite,int idCliente);
int informar_clienteMasAfichesACobrar(Cliente* pCliente,int limite, Venta* pVenta,int limite2);
#endif // INFORMAR_H_INCLUDED
