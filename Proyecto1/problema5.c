/*
5. Resuelva un sistema de ecuaciones de la forma
  ax + by = c
  dx + ey = f
  a,b,c,d,e,f en R

a. Implemente una función que lo resuelva indicando si hay solución
   única(rectas secantes), si hay múltiples soluciones(rectas coincidentes)
   o si no hay solución(rectas paralelas)
*/

#include<stdio.h>
#include <stdlib.h>

void resolver(float,float,float,float,float,float);

int main() {
  float a,b,c,d,e,f;
  printf("\nRESOLVER ECUACIONES LINEALES ");
  printf("(2 incognitas)\n");
  printf("\nEscriba los valores de la primera ecuacion:\n");
  scanf("%f %f %f", &a, &b, &e);
  printf("\nEscriba los valores de la segunda ecuación:\n");
  scanf("%f %f %f", &c, &d, &f);
  resolver(a,b,c,d,e,f);
  printf("\n");
  #ifdef _WIN32
    system("pause");
  #endif
  return 0;
}

void resolver(float a, float b,float c,float d,float e,float f) {
  float x, y, determinante;
  determinante = a*d - b*c;
  if (determinante != 0) {
    printf("\nLa solución del sistema es única (rectas secantes):");
    x = (e*d - b*f)/determinante;
    y = (a*f - e*c)/determinante;
    printf("\n\tx = %.2f\n", x);
    printf("\ty = %.2f\n", y);
  } else if ((a/c) == (e/f)) {
    printf("\nLa solución del sistema es multiple \n(rectas coincidentes)\n");
  } else {
    printf("\nEl sistema no tiene solucion\n(rectas paralelas)\n");
  }
}
