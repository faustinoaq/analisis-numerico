// Metodo de Newton-Raphson, CRUV FIEC 2016

int newton_raphson() {
  int i=0, iter, o;
  float tol, x, xi, error;
  printf("\n\tMetodo de Newton-Raphson\n");
  // Se utiliza ecuaciones.h para elegir la ecuacion
  o = ecuacion();
  printf("\nEscriba separado por un espacio\n");
  printf("x Tolerancia Iteraciones: ");
  input(3, "%f %f %i", &x, &tol, &iter);
  // Titulo de la tabla de Iteraciones
  printf("\n\ti\txi\tf(xi)\tE\n");
  do {
    // Se utiliza la funcion h(...) de ecuaciones.h
    xi = h(x,o);
    error = fabs((xi - x)/xi);
    // Imprime los valores de la tabla de iteraciones
    printf("\t%i\t%.4f\t%.4f\t%.4f\n", i, x, xi, error);
    if (error <= tol) {
      printf("\nLa solucion es %.4f\n", xi);
      return 0;
    }
    x = xi;
    i++;
  } while (i <= iter);
  // Hay muy pocas iteraciones o la tolerancia es muy pequeña
  printf("\nNo se encontro solucion\n");
  return 0;
}
