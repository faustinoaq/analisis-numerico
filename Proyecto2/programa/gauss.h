// Metodo de Gauss, CRUV FIEC 2016

int gauss() {
  char t;
  int n, i, j, k, mayor;
  float m[N][N], x[N], aux;
  printf("\n\tMetodo de Gauss\n");
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

    if (i < n-1) {
      // Intercambia la fila mayor
      for (k=i; k<=n; k++) {
        aux = m[mayor][k];
        m[mayor][k] = m[i][k];
        m[i][k] = aux;
      }
    }

    // Se fija si el elemento pivote es cero
    if (m[i][i] == 0) {
      printf("\nEl sistema no tiene solucion unica\n");
      return 0;
    }

    // Vuelve cero los elementos debajo
    for (k=i+1; k<n; k++) {
      aux = m[k][i];
      for (j=i; j<=n; j++) {
        m[k][j] -= aux*(m[i][j]/m[i][i]);
      }
    }
  }

  // Busca los valores reemplazando hacia atras
  printf("\nSolucion: \n");
  for (i=n-1; i>=0; i--) {
    x[i] = m[i][n]/m[i][i];
    printf("x[%i]=%.4f\n", i, x[i]);
    for (k=i-1; k>=0; k--) {
      m[k][n] -= m[k][i] * x[i];
    }
  }
  return 0;
}
