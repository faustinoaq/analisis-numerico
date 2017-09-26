/*
Elabore un programa que lea los elementos (números reales) de una matriz
cuadrada de tamaño "N" y realice las siguientes salidas:
a) Escribir la matriz
b) Escriba el mayor elemento de la Matriz
c) Determine la cantidad de ceros en la diagonal principal
*/


#include <stdio.h>
#include <stdlib.h>

#define M 100
#define N 100

void mostrar_matriz(int, float[][N]), mostrar_mayor(int, float[][N]), contar_ceros(int, float [][N]);
float matriz[N][N], leer_matriz(int, int);

int main() {
  int i, j, N, leer_t();
  float mayor;
  printf("\n\tPROBLEMA 2\n");
  N = leer_t();
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      matriz[i][j] = leer_matriz(i, j);
    }
  }
  mostrar_matriz(N, matriz);
  mostrar_mayor(N, matriz);
  contar_ceros(N, matriz);
  system("pause");
  return 0;
}

int leer_t() {
  int n;
  printf("Escriba el tamanyo de la matriz cuadrada: ");
  scanf("%i", &n);
  return n;
}

float leer_matriz(int i, int j) {
  float n;
  printf("Escriba el valor de la posicion (%i,%i): ", i+1, j+1);
  scanf("%f", &n);
  return n;
}

void mostrar_matriz(int N, float matriz[][N]) {
  int i, j;
  printf("\n\tMATRIZ\n");
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%8.2f ", matriz[i][j]);
    }
    printf("\n");
  }
}

void mostrar_mayor(int N, float matriz[][N]) {
  int i, j;
  float mayor=matriz[0][0];
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (matriz[i][j] > mayor) {
        mayor = matriz[i][j];
      }
    }
  }
  printf("\nEl mayor elemento de la matriz es %.2f\n", mayor);
}

void contar_ceros(int N, float matriz[][N]) {
  int i, count=0;
  for (i = 0; i < N; i++) {
    if (matriz[i][i] == 0) {
      count++;
    }
  }
  printf("La cantidad de ceros en la diagonal principal es %i\n", count);
}
