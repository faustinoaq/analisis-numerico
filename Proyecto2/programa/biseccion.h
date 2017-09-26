// Metodo de Biseccion, CRUV FIEC 2016

int biseccion() {
  int i=0, iter, o;
  float a, b, tol, x, xi, error;
  printf("\n\tMetodo de Biseccion de Bolsano\n");
  o = ecuacion();
  printf("\nEscriba separado por un espacio\n");
  printf("a b Tolerancia Iteraciones: ");
  input(4, "%f %f %f %i", &a, &b, &tol, &iter);
  if (f(a, o)*f(b, o) < 0) {
    // Titulo de la tabla de iteraciones
    printf("\n i\ta\tb\txi\tf(a)\tf(b)\tf(xi)\tf(a)f(xi) E\n");
    do {
      xi = (a + b)/2;
      // Valores de la tabla de iteraciones
      printf(" %i\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f",\
      i, a, b, xi, f(a,o), f(b,o), f(xi,o));
      // Se busca el nuevo valor para a y b
      if (f(a,o)*f(xi,o) < 0) {
        b = xi;
        printf("\t(-)");
      } else if (f(a,o)*f(xi,o) > 0) {
        a = xi;
        printf("\t(+)");
      } else {
        // Devuelve la solucion si hay raiz exacta
        printf("\nLa solucion es %.4f\n", xi);
        return 0;
      }
      // Solo se busca el error despues de la primera iteracion
      if (i > 0) {
        error = fabs((xi - x)/xi);
        printf("\t  %.4f\n", error);
        if (error <= tol) {
          printf("\nLa solucion es %.4f\n", xi);
          return 0;
        }
      } else {
        printf("\t  ---\n");
      }
      x = xi;
      i++;
    } while (i <= iter);
  } else {
    // El intervalo [a,b] no satisface la ecuacion
    printf("\nValores de a b incorrectos\n");
    return 0;
  }
  // Hay muy pocas iteraciones o la tolerancia es muy pequeña
  printf("\nNo se encontro solucion\n");
  return 0;
}
