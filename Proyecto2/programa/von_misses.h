// Metodo de Von-Misses, CRUV FIEC 2016

int von_misses() {
  int i=0, iter, o;
  float tol, x, xi, x0, error, f, F;
  printf("\n\tMetodo de Von-Misses\n");
  // Se utiliza ecuaciones.h para elegir la ecuacion
  o = ecuacion();
  printf("\nEscriba separado por un espacio\n");
  printf("x Tolerancia Iteraciones: ");
  input(3, "%f %f %i", &x, &tol, &iter);
  x0 = x;
  // Se utiliza x0 para calcular f'(x0)
  F = mF(x0, o);
  // Titulo de la tabla de Iteraciones
  printf("\n\ti\txi\tf(xi)\tE\n");
  do {
    // Se utiliza la funcion mf(...) de ecuaciones.h
    f = mf(x,o);
    // Se calcula el nuevo x utilizando x - f(x)/f'(x)
    xi = x - f/F;
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
