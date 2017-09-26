/*
3. Programa, que aplica una función para calcular un valor aproximado de e
   la salida la hace en el programa principal.
*/


#include <stdio.h>
#include <stdlib.h>

float e();

int main() {
  printf("\n\tCalculo del Numero de Euler\n");
  printf("El valor aprox. de e es: %f\n", e());
  #ifdef _WIN32
    system("pause");
  #endif
}

float e() {
  int i, n;
  float en=1, f=1;
  printf("\nEscriba la cantidad de iteraciones: ");
  scanf("%i", &n);
  for (i = 1; i < n; i++) {
    f *= i;
    en += 1/f;
  }
  return en;
}
