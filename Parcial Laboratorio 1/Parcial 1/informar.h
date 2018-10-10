#ifndef INFORMAR_H_INCLUDED
#define INFORMAR_H_INCLUDED
/**
    informar_OrdenarClientePorNombreApellido: recibe el array de cliente y lo ordena por apellido y nombre
    @param pCliente: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return @return return 0 OK, -1 error.
*/
int informar_OrdenarClientePorApellidoNombre(Cliente* pCliente, int limite);
/**
    informar_cantAfichesMayor: recibe el array de ventas y verifica que ventas tiene mas afiches que el numero recibido
    @param pVenta: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param valorComparativo: guarda el int del numero a comparar
    @return return @return return 0 OK, -1 error.
*/
int informar_cantAfichesMayor(Venta* pVenta, int limite,int valorComparativo);
/**
    informar_cantAfichesMenor: recibe el array de ventas y verifica que ventas tiene menos afiches que el numero recibido
    @param pVenta: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param valorComparativo: guarda el int del numero a comparar
    @return return @return return 0 OK, -1 error.
*/
int informar_cantAfichesMenor(Venta* pVenta, int limite,int valorComparativo);
/**
    informar_promedioAfiches: recibe el array de ventas y suma la cantidad de afiches por venta para sacar un promedio
    @param pVenta: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param promedioAfiches: recibe un puntero a un float donde guardar el promedio
    @return return @return return 0 OK, -1 error.
*/
int informar_promedioAfiches(Venta* pVenta, int limite,float* promedioAfiches);

#endif // INFORMAR_H_INCLUDED
