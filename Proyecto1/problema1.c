/*
1. Calcular la traspuesta  de una matriz de elementos números enteros.
   Para esto, use tres funciones:
   Entrada (Lee los elementos de la matriz)
   traspuesta (Calcula la traspuesta de la matriz)
   Salida (Manda a escribir las 2 matrices por pantalla)
*/

#include <stdio.h>
#include <stdlib.h>

#define M 100
#define N 100

// FUNCIONES
void leer_matriz(int[][N], int*, int*);
void mostrar_matriz(int[][N], int, int);
void traspuesta(int[][N], int, int);

int main() {
  int m, n, matriz[M][N];
  leer_matriz(matriz, &m, &n);
  printf("\n MATRIZ\n");
  mostrar_matriz(matriz, m, n);
  printf("\n MATRIZ TRASPUESTA\n");
  traspuesta(matriz, m, n);
  #ifdef _WIN32
    system("pause");
  #endif
  return 0;
}

void leer_matriz(int matriz[][N],int* m, int* n) {
  int i, j, x;
  printf("Escriba el tamanyo de la matriz MxN (Max. 99x99): ");
  scanf("%2ix%2i", m, n);
  for (i = 0; i < *m; i++) {
    for (j = 0; j < *n; j++) {
      printf("Escriba el valor de la posicion (%i,%i): ", i+1, j+1);
      scanf("%i", &x);
      matriz[i][j] = x;
    }
  }
}

void traspuesta(int matriz[][N], int m, int n) {
  int i, j, mtraspuesta[M][N];
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      mtraspuesta[j][i] = matriz[i][j];
    }
  }
  mostrar_matriz(mtraspuesta, n, m);
}

void mostrar_matriz(int matriz[][N], int m, int n) {
  int i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf(" %4i ", matriz[i][j]);
    }
    printf("\n");
  }
}
