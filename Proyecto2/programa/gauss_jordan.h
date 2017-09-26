// Metodo de Gauss, CRUV FIEC 2016

int gauss_jordan() {
  char t;
  int n, i, j, k, mayor;
  float m[N][N], x[N], aux, pivote;
  printf("\n\tMetodo de Gauss-Jordan\n");
  printf("\nEscriba el tamayo de la matriz NxN (Maximo 9): ");
  input(1, "%[1-9]", &t);
  n = t - '0'; // Se convierte de codigo ASCII a entero
  for (i=0; i<n; i++) {
    printf("\nPara la ecuacion %i escriba:\n", i+1);
    for (j=0; j<n; j++) {
      printf("Coeficiente (%i,%i): ", i+1, j+1);
      input(1, "%f", &m[i][j]);
    }
    printf("Termino libre (%i,%i): ", i+1, j+1);
    input(1, "%f", &m[i][n]);
  }
  printf("\n\tMatriz Ampliada\n");
  for (i=0; i<n; i++) {
    printf("\n\tTabla %i\n", i+1);
    matriz(n, m);

    // Busca la mayor fila
    aux = fabs(m[i][i]);
    mayor = i;
    for (k=i+1; k<n; k++) {
      if (fabs(m[k][i]) > aux) {
        aux = fabs(m[k][i]);
        mayor = k;
      }
    }

    // Intercambia la fila mayor
    if (i < n-1) {
      for (k=i; k<=n; k++) {
        aux = m[mayor][k];
        m[mayor][k] = m[i][k];
        m[i][k] = aux;
      }
    }

    // Se fija si el elemento pivote es cero
    pivote = m[i][i];
    if (pivote == 0) {
      printf("\nEl sistema no tiene solucion unica\n");
      return 0;
    }

    // Se divide toda la fila por el pivote
    for (j=i; j<=n; j++) {
      m[i][j] /= pivote;
    }

    // Vuelve cero los demas elementos
    for (k=0; k<n; k++) {
      aux = m[k][i];
      for (j=i; j<=n; j++) {
        if (k != i) {
          m[k][j] -= aux*m[i][j];
        }
      }
    }
  }
  printf("\n\tMatriz Identica\n");
  matriz(n, m);
  printf("\nSolucion: \n");
  for (i=0; i<n; i++) {
    printf("x[%i]=%.4f\n", i, m[i][n]);
  }
  return 0;
}
