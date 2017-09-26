/*
2. Programa que lee tres valores en el programa principal y determina,
   en el programa principal, si los valores leídos corresponden a los
   lados de un triángulo si es cierto invoca a una función llamada area
   que usted debe  elaborar para  calcular el área del triángulos cuyos
   lados son los valores leídos, en caso de que los tres valores no
   formen un triángulo vuelva a leer los valores hasta que representen
   un triángulo y le envía a calcular el área, en el programa principal
   habrá un mensaje que indicara que para finalizar debe pulsar un cero.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float area(float, float, float);

int main() {
  int i, e;
  float lados[3], a, b, c;
  printf("AREA DEL TRIANGULO\n");
  do {
    for(i=0; i < 3; i++) {
      printf("Escriba el valor del lado %i (0 para salir): ", i+1);
      scanf("%f", &lados[i]);
      if (lados[i] == 0) {
        exit(0);
      }
    }
    a = lados[0];
    b = lados[1];
    c = lados[2];
    if (((a + b) > c) && ((a + c) > b) && ((b + c) > a)) {
      e = 0;
    } else {
      printf("Error: Los valores no pertenecen a los lados de un triangulo\n");
      printf("Error: Intente denuevo\n");
      e = 1;
    }
  } while(e);
  printf("El área del triángulo es %.2f\n", area(a,b,c));
  #ifdef _WIN32
    system("pause");
  #endif
  return 0;
}

float area(float a, float b, float c) {
  float s, area;
  // Calculo del area usando el semiperimetro
  s = 0.5*(a + b + c);
  area = sqrt(s*(s-a)*(s-b)*(s-c));
  return area;
}
