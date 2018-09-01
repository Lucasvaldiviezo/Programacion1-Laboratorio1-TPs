#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED

/**
    utn_getEntero: pide un entero al usuario
    @param pNum: puntero a num
    @param reint: cantidad de reintentos
    @param msg: mensaje a mostrar
    @param msgError: mensaje de error
    @param maximo: el numero maximo
    @param minimo: el numero minimo
    @return : 0 OK, -1 error.
*/

int utn_getNumeroDecimal(float* pNum, int reint, char* msg, char* msgError);
int utn_getEntero(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo);
int utn_getCaracter(char* pOpcion,char* msg, char* msgError,int reint);
int utn_suma(float *pResultado,float numero1, float numero2);
int utn_resta(float *pResultado,float numero1, float numero2);
int utn_multiplicacion(float *pResultado,float numero1, float numero2);
int utn_suma(float *pResultado,float numero1, float numero2);
#endif // OPERACIONES_H_INCLUDED
