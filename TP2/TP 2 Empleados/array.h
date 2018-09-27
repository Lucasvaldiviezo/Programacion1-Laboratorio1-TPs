#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

int utn_mostrarArray(float* pArray,int limite);
int utn_inicializarArray(int* pArray,int valor, int limite);
int utn_calcularMaximoArray(int* pArray,int limite,int* pMaximo);
int utn_calcularMinimoArray(int* pArray,int limite,int* pMinimo);
int utn_promedioArray(int* pArray,int limite,float* promedio);
int utn_insertion(int data[],int len);

#endif // ARRAY_H_INCLUDED
