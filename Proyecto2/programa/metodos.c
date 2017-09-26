// CRUV FIEC 2016
// Analisis Matematico

#include <math.h>
#include <stdio.h>

// Metodos
#include "utils.h"
#include "ecuaciones.h"
#include "biseccion.h"
#include "punto_fijo.h"
#include "newton_raphson.h"
#include "von_misses.h"
#include "gauss.h"
#include "gauss_jordan.h"
#include "jacobi.h"
#include "gauss_seidel.h"

int main() {
  char respuesta, opcion;
  do {
    printf("\n\tMetodos de Analisis Matematico\n");
    printf("\nParte I:\n");
    printf("1. Biseccion de Bolsano\n");
    printf("2. Punto Fijo\n");
    printf("3. Newton-Raphson\n");
    printf("4. Von-Misses\n");
    printf("\nParte II:\n");
    printf("5. Gauss\n");
    printf("6. Gauss-Jordan\n");
    printf("7. Jacobi\n");
    printf("8. Gauss-Seidel\n");
    printf("\nElija una opcion (0 para salir): ");
    // ver funcion input en utils.h
    input(1, "%[0-8]", &opcion);
    if (opcion == '0') {
      // Opcion para salir del programa
      break;
    }
    clear();
    if (opcion == '1') {
      biseccion();
    } else if (opcion == '2') {
      punto_fijo();
    } else if (opcion == '3') {
      newton_raphson();
    } else if (opcion == '4') {
      von_misses();
    } else if (opcion == '5') {
      gauss();
    } else if (opcion == '6') {
      gauss_jordan();
    } else if (opcion == '7') {
      jacobi();
    } else if (opcion == '8') {
      gauss_seidel();
    }
    printf("\n");
    printf("Desea continuar (s/n): ");
    // ver funcion input en utils.h
    input(1, "%[sn]", &respuesta);
    if (respuesta != 's') {
      opcion = 0;
    } else {
      // Borra la pantalla y regresa al menu principal
      clear();
    }
  } while (opcion != 0);
  return 0;
}
