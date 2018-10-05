/**
 *
 * Descripcion: Implementacion de funciones de ordenacion
 *
 * Fichero: ordenacion.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */


#include "ordenacion.h"
#include <stdio.h>
/***************************************************/
/* Funcion: SelectSort    Fecha:    30/09/2018     */
/* Vuestro comentario                              */
/***************************************************/

int minimo(int *tabla, int ip, int iu,int *cont);
int maximo(int *tabla, int ip, int iu,int *cont);

int SelectSort(int* tabla, int ip, int iu){
    int i,aux,min,cont;
    if (!tabla){
        return ERR;
    }
    cont = 0;
    for (i=ip ; i<iu ; i++){
        min = minimo(tabla,i,iu,&cont);
        aux = tabla[i];
        tabla[i] = tabla[min];
        tabla[min] = aux;
    }
    return cont;
}

int SelectSortInv(int* tabla, int ip, int iu){
  int i,aux,max,cont;
  if (!tabla){
      return ERR;
  }
  cont = 0 ;
  for (i=ip ; i<iu ; i++){
      max = maximo(tabla,i,iu,&cont);
      aux = tabla[i];
      tabla[i] = tabla[max];
      tabla[max] = aux;

  }
  return cont;

}

int minimo(int *tabla, int ip, int iu,int *cont){
    int min ,j;
    min = ip;
    for (j =ip+1 ; j<=iu;j++ ){
        if (tabla[j]<tabla[min]){
            min = j;
            *cont = *cont + 1;
        }
    }
    return min;
}

int maximo(int *tabla, int ip, int iu,int *cont){
    int max ,j;
    max = ip;
    for (j =ip+1 ; j<=iu; j++ ){
        if (tabla[j]>tabla[max]){
            max = j;
            *cont = *cont +1;
        }
    }
    return max;
}
