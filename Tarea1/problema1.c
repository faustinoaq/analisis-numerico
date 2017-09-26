/*
Elabore un programa que lea la capacidad "N" de un vector "V" de elementos
números enteros y calcule la suma de los elementos pares de dicho vector.
a) Mostrar Lista
b) Mostrar suma
*/

#include <stdio.h>
#include <stdlib.h>

int leer_cap();
int leer_vec(int);
void mostrar_vec(int, int[]);
void mostrar_sum(int, int[]);

int main() {
  int n, i;  
  printf("\n\tPROBLEMA 1\n");
  n = leer_cap();
  int v[n];
  for (i = 0; i < n; i++) {
    v[i] = leer_vec(i);
  }
  mostrar_vec(n, v);
  mostrar_sum(n, v);
  system("pause");
  return 0;
}

int leer_cap() {
  int n;
  printf("Escriba la capacidad del vector: ");
  scanf("%i", &n);
  return n;
}

int leer_vec(int i) {
  int v;
  printf("Escriba el valor %i del vector: ", i+1);
  scanf("%i", &v);
  return v; 
}

void mostrar_vec(int n, int v[]) {
  int i;
  printf("\n\tVECTOR\n");
  for (i = 0; i < n; i++) {
    printf("%4i", v[i]);
  }
  printf("\n");
}

void mostrar_sum(int n, int v[]) {
  int i, acum=0;
  for (i = 0; i < n; i++) {
    if (v[i] % 2 == 0) {
      acum += v[i];
    }
  }
  printf("La suma de los elementos pares es %i\n", acum);
}
