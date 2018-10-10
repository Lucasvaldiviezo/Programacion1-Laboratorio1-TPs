#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "ventaAfiche.h"
#include "informar.h"
#define CLIENTES_MAX 100
#define VENTAS_MAX 1000
#define TEXTO_MENU "       \nMENU\n\
1)Cargar un cliente\n\
2)Modificar un cliente\n\
3)Borrar un cliente\n\
4)Agregar Venta\n\
5)Modificar Venta\n\
6)Cobrar Venta\n\
7)Imprimir lista de clientes\n\
8)Salir\n\
        \nINFORMES\n\
9)Ciente con menos ventas a Cobrar\n\
10)Cliente con menos ventas Cobradas\n\
11)Cliente con menos ventas\n\
12)Zona con mas afiches\n\
13)Cliente con menos afiches comprados\n\
14)Cliente con mas afiches a cobrar\n\
15)Cliente con cantidad de afiches mayor a 500\n\
16)Listar cantidad de afiches por zona\n\
17)Promedio Afiches\n\
18)Listar ventas ordenedas por Zona\n\
Elija una opcion: "


int main()
{
    int indiceVacio;
    int opcion;
    int id;
    int idAuxiliar;
    int salir=0;
    int flag=0;
    Cliente clientes[CLIENTES_MAX];
    Venta ventas[VENTAS_MAX];
    cliente_cargarDatosVacio(clientes,CLIENTES_MAX);
    venta_cargarDatosVacio(ventas,VENTAS_MAX);
    cliente_cargarForzadaIndice(clientes,CLIENTES_MAX,"Lucas","Valdiviezo","20400914983");
    cliente_cargarForzadaIndice(clientes,CLIENTES_MAX,"Antonio","Valdiviezo","20400914983");
    cliente_cargarForzadaIndice(clientes,CLIENTES_MAX,"Martin","Bottani","20410491485");
    cliente_cargarForzadaIndice(clientes,CLIENTES_MAX,"Nicolas","Alvarez","20301619981");
    venta_cargaForzadaVenta(ventas,VENTAS_MAX,"Hola.jpg","ZONA SUR","A cobrar",120,0);
    venta_cargaForzadaVenta(ventas,VENTAS_MAX,"Chau.jpg","ZONA OESTE","A cobrar",3000,0);
    venta_cargaForzadaVenta(ventas,VENTAS_MAX,"EAAAA.jpg","ZONA NORTE","Cobrada",50,1);
    venta_cargaForzadaVenta(ventas,VENTAS_MAX,"SOYMAYOR.jpg","ZONA NORTE","A cobrar",70,1);
    venta_cargaForzadaVenta(ventas,VENTAS_MAX,"Miravos.jpg","ZONA ESTE","A cobrar",9,2);
    venta_cargaForzadaVenta(ventas,VENTAS_MAX,"Ewww.jpg","ZONA ESTE","A cobrar",200,2);
    venta_cargaForzadaVenta(ventas,VENTAS_MAX,"Altoke.jpg","ZONA SUR","Cobrada",501,2);
    do
    {
        __fpurge(stdin);
        if(cliente_checkEmptyIndex(clientes,CLIENTES_MAX)==-1)
        {
            flag=1;
        }else
        {
            flag=0;
        }
        utn_getEntero(&opcion,3,TEXTO_MENU,"Esa no es una opcion valida\n",19,0);
        switch(opcion)
        {
            case 1:

                    if(cliente_getEmptyIndex(clientes,CLIENTES_MAX,&indiceVacio)==0)
                    {
                        if(cliente_cargarIndice(clientes,indiceVacio,CLIENTES_MAX)==0)
                        {
                            cliente_mostrarUnIndice(clientes,CLIENTES_MAX,indiceVacio);
                        }
                    }
                    else
                    {
                        printf("No hay lugar\n");
                    }
                    break;
                case 2:
                    if(flag==1)
                    {
                        if(utn_getEntero(&id,10,"\nIngrese el ID del cliente que desea modificar: ","Ese no es un ID valido\n",CLIENTES_MAX,-1)==0)
                        {
                            if(cliente_buscarClientePorId(clientes,CLIENTES_MAX,id)!= -1)
                            {
                                cliente_modificarIndice(clientes,id,CLIENTES_MAX);
                            }else
                            {
                                printf("\nEl ID no existe\n");
                            }

                        }
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                    }
                    break;
                case 3:
                     if(flag==1)
                    {
                        if(utn_getEntero(&id,10,"\nIngrese el ID del cliente que desea borrar: ","Ese no es un ID valido\n",CLIENTES_MAX,-1)==0)
                        {
                            if(cliente_buscarClientePorId(clientes,CLIENTES_MAX,id)!= -1)
                            {
                              cliente_borrarCliente(clientes,CLIENTES_MAX,id);
                              venta_borrarVenta(ventas,VENTAS_MAX,id);
                            }else
                            {
                                 printf("\nEl ID no existe\n");
                            }
                        }
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                    }
                    break;
                case 4:
                    if(flag==1)
                    {
                        if(utn_getEntero(&id,10,"\nIngrese el ID del cliente al que desea vender: ","Ese no es un ID valido\n",CLIENTES_MAX,-1)==0
                        && cliente_buscarClientePorId(clientes,CLIENTES_MAX,id)!= -1)
                        {
                            if(venta_getEmptyIndex(ventas,VENTAS_MAX,&indiceVacio)==0)
                            {
                                if(venta_cargarIndice(ventas,indiceVacio,VENTAS_MAX,id)==0)
                                {
                                    venta_mostrarUnIndice(ventas,VENTAS_MAX,indiceVacio);
                                }
                            }else
                            {
                                printf("No hay lugar\n");
                            }
                        }
                    }
                    else
                    {
                        printf("\n||No hay datos cargados||\n");
                    }
                    break;
                case 5:
                    if(flag==1)
                    {
                        venta_mostrarIndice(ventas,VENTAS_MAX);
                        if(utn_getEntero(&id,10,"\nIngrese el ID de la venta: ","Ese no es un ID valido\n",VENTAS_MAX,-1)==0
                             && venta_buscarVentaPorId(ventas,VENTAS_MAX,id)!= -1 )
                        {
                            if(venta_checkEstado(ventas,VENTAS_MAX,id,"A cobrar")==0)
                            {
                                venta_modificarIndice(ventas,indiceVacio,VENTAS_MAX,id);
                            }else
                            {
                                printf("\nEsa venta esta cobrada por lo que no se puede modificar \n");
                            }

                        }


                    }
                    else
                    {
                        printf("\n||No hay datos cargados||\n");
                    }
                    break;
                case 6:
                    if(flag==1)
                    {
                        venta_mostrarIndice(ventas,VENTAS_MAX);
                        if(utn_getEntero(&id,10,"\nIngrese el ID de la venta: ","Ese no es un ID valido\n",VENTAS_MAX,-1)==0
                             && venta_buscarVentaPorId(ventas,VENTAS_MAX,id)!= -1 )
                        {
                            if(venta_buscarClienteVentaPorId(ventas,VENTAS_MAX,id,&idAuxiliar)==0)
                            {
                                printf("ID: %d",idAuxiliar);
                                indiceVacio=cliente_buscarClientePorId(clientes,CLIENTES_MAX,idAuxiliar);
                                if(cliente_mostrarUnIndice(clientes,CLIENTES_MAX,indiceVacio)==0)
                                {
                                    venta_cobrarVenta(ventas,VENTAS_MAX,id);
                                }

                            }
                        }

                    }
                    else
                    {
                        printf("\n||No hay datos cargados||\n");
                    }
                    break;
                case 7:
                     if(flag==1)
                    {
                        cliente_mostrarIndiceConVentas(clientes,CLIENTES_MAX,ventas,VENTAS_MAX);
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                    }
                    break;
                case 8:
                salir = 1;
                    break;
                case 9:
                    if(flag==1)
                    {
                        informar_clienteMenosVentasACobrar(clientes,CLIENTES_MAX,ventas,VENTAS_MAX);
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                    }
                    break;
                case 10:
                    if(flag==1)
                    {
                        informar_clienteMenosVentasCobradas(clientes,CLIENTES_MAX,ventas,VENTAS_MAX);
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                    }
                    break;
                case 11:
                    if(flag==1)
                    {
                        informar_clienteMenosVentas(clientes,CLIENTES_MAX,ventas,VENTAS_MAX);
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                    }
                break;
                case 12:
                    if(flag==1)
                    {
                        informar_mostrarZonaConMasAfiches(ventas,VENTAS_MAX);
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                    }
                break;
                case 13:
                    if(flag==1)
                    {
                        informar_clienteConMenosAfiches(clientes,CLIENTES_MAX,ventas,VENTAS_MAX);
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                    }
                    break;
                case 14:
                    if(flag==1)
                    {
                        informar_clienteMasAfichesACobrar(clientes,CLIENTES_MAX,ventas,VENTAS_MAX);
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                    }
                    break;
                case 15:
                    if(flag==1)
                    {
                        informar_clienteCantAfichesMayor(clientes,CLIENTES_MAX,ventas,VENTAS_MAX,500);
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                    }
                    break;
                case 16:
                    if(flag==1)
                    {
                        informar_mostrarAfichePorZona(ventas,VENTAS_MAX);
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                    }
                    break;
                case 17:
                    if(flag==1)
                    {
                        informar_promedioAfiches(clientes,CLIENTES_MAX,ventas,VENTAS_MAX);
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                    }
                    break;
                case 18:
                     if(flag==1)
                    {
                        informar_OrdenarVentaPorZona(ventas,VENTAS_MAX);
                        venta_mostrarIndice(ventas,VENTAS_MAX);
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                    }

        }
    }while(salir==0);

    return 0;
}
