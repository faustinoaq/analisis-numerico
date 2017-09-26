/*
4. Resuelva una ecuación de segundo grado con una incógnita de la forma: ax^2+bx+c=0
   a. Lea los coeficientes a,b y c, números reales, en el programa principal
   b. Implemente  una función que indique el tipo de raíz y que calcule las mismas
      y las muestre por pantalla desde la función.
      Haga los ajustes correspondientes si a=0
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void raices(float, float, float, float*, float*, int*);

int main() {
  int i, e, comp=0;
  float a, b, c, raiz1, raiz2;
  printf("ECUACION DE SEGUNDO GRADO\n");
  printf("Escriba el valor de a: ");
  scanf("%f", &a);
  printf("Escriba el valor de b: ");
  scanf("%f", &b);
  printf("Escriba el valor de c: ");
  scanf("%f", &c);
  if (a == 0) {
    raiz1 = -c/b;
    printf("\nEcuación cuadrática con a=0 donde x = %.2f\n", raiz1);
  } else {
    raices(a, b, c, &raiz1, &raiz2, &comp);
    if (comp) {
      printf("\nEcuación cuadrática con soluciones complejas donde\n");
      printf("x1 = %.2f + i\n", raiz1);
      printf("x2 = %.2f + i\n", raiz2);
    } else {
      printf("\nEcuación cuadrática con solucion real donde\n");
      printf("x1 = %.2f y x2 = %.2f\n", raiz1, raiz2);
    }
  }
  printf("\n");
  #ifdef _WIN32
    system("pause");
  #endif
}

void raices(float a, float b, float c, float *r1, float *r2, int *comp) {
  float raiz, insqrt;
  insqrt = pow(b, 2) - (4 * a * c);
  if (insqrt < 0) {
    *comp = 1;
    insqrt *= -1;
  }
  *r1 = (-b + sqrt(insqrt))/(2*a);
  *r2 = (-b - sqrt(insqrt))/(2*a);
}
