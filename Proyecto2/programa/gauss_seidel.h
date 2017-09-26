// Metodo de Gauss-Seidel, CRUV FIEC 2016

int gauss_seidel() {
  char t;
  int i, j, m, n, iter;
  float xi[N], x[N], coef[N][N], l[N], aux, d1=0, d2=0, tol, error;
  printf("\n\tMetodo de Gauss-Seidel\n");
  printf("Escriba el tamayo de la matriz NxN (Maximo 9): ");
  input(1, "%[1-9]", &t);
  n = t - '0'; // convierte de codigo ASCII a entero
  printf("Escriba la cantidad de iteraciones: ");
  input(1, "%d", &iter);
  printf("Escriba la Tolerancia: ");
  input(1, "%f", &tol);
  printf("\nEscriba los valores iniciales de:\n");
  for (i=0; i<n; i++) {
    printf("x[%i]: ", i+1);
    input(1, "%f", &x[i]);
    xi[i]=x[i];
  }
  for (i=0; i<n; i++) {
    printf("\nPara la ecuacion %i escriba:\n", i+1);
    for (j=0; j<n; j++) {
      printf("Coeficiente (%i,%i): ", i+1, j+1);
      input(1, "%f", &coef[i][j]);
    }
    printf("Termino libre (%i,%i): ", i+1, j+1);
    input(1, "%f", &l[i]);
  }
  printf("\n\tTabla de iteraciones\n\n");
  printf("i");
  for (i=0; i<n; i++) {
    printf("\tx[%d]",i+1);
  }
  printf("\tD1\tD2\tError\n");

  for (m=0; m<iter; m++) {
    printf("%i", m);
    for (i=0;i<n;i++) {
      aux=l[i];
      for (j=0;j<n;j++) {
        if(i != j) {
          aux -= coef[i][j]*xi[j];
        }
      }
      xi[i] = aux/coef[i][i];
      printf("\t%.4f", xi[i]);
      d1 += pow((xi[i] - x[i]),2);
      d2 += pow(xi[i], 2);
      x[i] = xi[i];
    }
    d1 = sqrt(d1);
    d2 = sqrt(d2);
    error = d1/d2;
    printf("\t%.4f\t%.4f\t%.4f\n", d1, d2, error);
    if (error <= tol) {
      printf("\nLa solucion es:\n");
      for (i=0; i<n; i++) {
        printf("x[%d] = %.4f\n",i,xi[i]);
      }
      return 0;
    }
    d1=0;
    d2=0;
  }
  printf("\nNo se llego a la solucion\n");
  return 0;
}
