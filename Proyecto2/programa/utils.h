// Herramientas de ayuda, @faustinoaq 2016

#include <stdarg.h>
#include <stdlib.h>

// Tamanyo maximo de la matriz NxN
#define N 10

void matriz(int n, float m[][N]) {
  // Imprime una matriz
  int i, j;
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      printf("\t%.2f", m[i][j]);
    }
    printf("\t| %.2f\n", m[i][n]);
  }
}


void clear() {
  /*
  clear():
  Limpia la pantalla y es compatible con Windows y Linux
  */
  #ifdef _WIN32
    system("cls");
  #elif linux
    printf("\ec"); // caracter de escape en UNIX
  #endif
}

void input(const int i, const char * format, ...) {
  /*
  input(cantidad de variables, formato, variables por referencia):
  Permite leer de datos asegurando que la entrada sea la correcta
  */
  int n;
  char str[1024]; // Hasta 1Kbyte de caracteres
  va_list args;
  va_start (args, format);
  do {
    fgets(str, sizeof(str), stdin); // Lee la linea completa
    n = vsscanf(str, format, args); // Busca valores segun el formato
    if (n < i) { // Valores incorrectos devuelve ERROR
      printf("Error al leer\nIntente otra vez: ");
    }
  } while (n < i); // Hasta que todas las variables sean leidas
  va_end (args);
}
