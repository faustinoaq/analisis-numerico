/*
Elabore un programa que lea los elementos de una matriz
rectangular de tamaño "MxN" y realice las siguientes salidas:
a) Escribir la matriz
b) Guardar la suma de los elementos de las filas en un vector "V"
c) Mostrar la suma de los elementos de cada fila
*/

#include <stdio.h>
#include <stdlib.h>

#define M 100
#define N 100

void mostrar_matriz(int, int, float[][N]), mostrar_vec(int, float[N]);
float leer_matriz(int, int);

int main() {
  int i, j, M, N, *n, *leer_t();
  float matriz[M][N], vector[M], acum=0;
  printf("\n\tPROBLEMA 3\n");
  n = leer_t();
  M = n[0];
  N = n[1];
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      matriz[i][j] = leer_matriz(i, j);
      acum += matriz[i][j];
    }
    vector[i] = acum;
    acum = 0;
  }
  mostrar_matriz(M, N, matriz);
  mostrar_vec(M, vector);
  system("pause");
  return 0;
}

int *leer_t() {
  int *n = malloc(2 * sizeof(int));
  printf("Escriba el tamanyo de la matriz rectangular MxN: ");
  scanf("%ix%i", &n[0], &n[1]);
  return n;
}

float leer_matriz(int i, int j) {
  float n;
  printf("Escriba el valor de la posicion (%i,%i): ", i+1, j+1);
  scanf("%f", &n);
  return n;
}

void mostrar_matriz(int M, int N, float matriz[][N]) {
  int i, j;
  printf("\n\tMATRIZ\n");
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      printf("%6.2f ", matriz[i][j]);
    }
    printf("\n");
  }
}

void mostrar_vec(int M, float vector[M]) {
  int j;
  printf("\n\tSUMATORIA POR FILA\n");
  for (j = 0; j < M; j++) {
    printf("Fila %i: %.2f\n", j+1, vector[j]);
  }
}
