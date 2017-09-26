// CRUV FIEC 2016
// Analisis Matematico
// Proyecto 3

#include <math.h>
#include <stdio.h>

// Metodos
#include "utils.h"
#include "lagrange_directa.h"
#include "lagrange_inversa.h"
#include "regresion.h"
#include "integracion.h"
#include "euler.h"
#include "heun.h"
#include "runge_kutta.h"

int main() {
  char respuesta, opcion;
  do {
    printf("\n\tProyecto No. 3\n");
    printf("\nParte I (Interpolacion):\n");
    printf("1. Metodo de Lagrange\n");
    printf("2. Metodo de Lagrange Inverso\n");
    printf("3. Regresion de minimos cuadrados\n");
    printf("\nParte II:\n");
    printf("4. Integracion Numerica\n");
    printf("\nParte III (EDO):\n");
    printf("5. Metodo de Euler\n");
    printf("6. Formula de Heun\n");
    printf("7. Metodo de Runge-Kutta\n");
    printf("\nElija una opcion (0 para salir): ");
    // ver funcion input en utils.h
    input(1, "%[0-7]", &opcion);
    if (opcion == '0') {
      // Opcion para salir del programa
      break;
    }
    clear();
    if (opcion == '1') {
      lagrange_directa();
    } else if (opcion == '2') {
      lagrange_inversa();
    } else if (opcion == '3') {
      regresion();
    } else if (opcion == '4') {
      integracion();
    } else if (opcion == '5') {
      euler();
    } else if (opcion == '6') {
      heun();
    } else if (opcion == '7') {
      runge_kutta();
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
