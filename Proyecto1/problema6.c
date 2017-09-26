/*
6. Diseñe tres funciones: 
- Lea un valor entero y cargue los elementos enteros de un vector V de capacidad N.
  Determine la frecuencia del valor leído en el vector V.

- Lea números naturales y determine si los valores leídos son primos o compuestos
  el programa finaliza cuando se introduce el número 1.

- Ordena descendentemente los elementos de un vector de número reales de capacidad N.
*/

#include <stdio.h>
#include <stdlib.h>

// Librerias con las funciones creadas
#include "funcion_1.h"
#include "funcion_2.h"
#include "funcion_3.h"

int main() {
  int o;
  do {
    printf("\n\n\tMENU DE OPCIONES\n\n");
    printf("1. Determinar frecuencia\n");
    printf("2. Numero Primo\n");
    printf("3. Ordenar Vector\n");
    printf("0. Salir\n");
    printf("Elija una opcion: ");
    scanf("%i", &o);
    // SE VERIFICA LA OPCION Y SE LLAMA LA FUNCION
    // CORRESPONDIENTE
    if (o == 1) {
      leer();
    } else if (o == 2) {
      primo();
    } else if (o == 3) {
      ordenar();
    }
  } while(o != 0);
  printf("\n\n");
  #ifdef _WIN32
    system("pause");
  #endif
  return 0;
}
