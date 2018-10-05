/**
 *
 * Descripcion: Implementacion de funciones de generacion de permutaciones
 *
 * Fichero: permutaciones.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */


#include "permutaciones.h"

/***************************************************/
/* Funcion: aleat_num Fecha:                       */
/* Autores:                                        */
/*                                                 */
/* Rutina que genera un numero aleatorio           */
/* entre dos numeros dados                         */
/*                                                 */
/* Entrada:                                        */
/* int inf: limite inferior                        */
/* int sup: limite superior                        */
/* Salida:                                         */
/* int: numero aleatorio                           */
/***************************************************/
int aleat_num(int inf, int sup)
{
int number;
  srand(rand());/*nos servira para cambiar la semilla cada vez que llamemos a la funcion */
  number = rand()%(sup-inf+1) + inf;
return number;
}

/***************************************************/
/* Funcion: genera_perm Fecha:                     */
/* Autores:                                        */
/*                                                 */
/* Rutina que genera una permutacion               */
/* aleatoria                                       */
/*                                                 */
/* Entrada:                                        */
/* int n: Numero de elementos de la                */
/* permutacion                                     */
/* Salida:                                         */
/* int *: puntero a un array de enteros            */
/* que contiene a la permutacion                   */
/* o NULL en caso de error                         */
/***************************************************/
int *genera_perm(int N)
{
  int i,a,b;
  int *perm;
  perm = (int *)malloc(sizeof(int)*(N));
  if (!perm){
    return NULL;
  }
  for (i=0 ; i<=N ; i++){
    perm[i]=i+1;
  }

  for (i=0 ; i<N ; i++){
    a=aleat_num(i, N-1);
    b = perm[i];
    perm[i] = perm[a];
    perm[a]= b;

  }
return perm;
}

/***************************************************/
/* Funcion: genera_permutaciones Fecha:            */
/* Autores:                                        */
/*                                                 */
/* Funcion que genera n_perms permutaciones        */
/* aleatorias de tamanio elementos                 */
/*                                                 */
/* Entrada:                                        */
/* int n_perms: Numero de permutaciones            */
/* int N: Numero de elementos de cada              */
/* permutacion                                     */
/* Salida:                                         */
/* int**: Array de punteros a enteros              */
/* que apuntan a cada una de las                   */
/* permutaciones                                   */
/* NULL en caso de error                           */
/***************************************************/
int** genera_permutaciones(int n_perms, int N)
{
  int i;
  int **perms;
  perms = (int**)malloc((sizeof(int))*n_perms);
  if (!perms){
    return NULL;
  }
  for (i = 0 ; i<n_perms;i++){
    perms[i] = (int *)malloc(sizeof(int)*N);
  }
for (i = 0 ; i<n_perms; i++){
  perms[i]= genera_perm(N);
}
return perms;
}
