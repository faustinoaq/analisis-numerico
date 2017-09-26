#define M 100

void ordenar() {
  int i, j, n;
  float V[N], aux;
  printf("\t\nVECTOR EN ORDEN DESCENDIENTE\n");
  printf("Escriba el tamaño del vector (Máx. 99): ");
  scanf("%i", &n);
  for (i = 0; i < n; i++) {
    printf("Escriba el valor %i del vector: ", i);
    scanf("%f", &V[i]);
  }
  if (n != 1) {
    for(i=0; i<n; i++) {
      for (j=i+1; j<n; j++) {
        if (V[i] < V[j]) {
          aux = V[i];
          V[i] = V[j];
          V[j] = aux;
        }
      }
    }
  }
  printf("\t\nVECTOR EN ORDEN DESCENDIENTE\n");
  for (i=0; i<n; i++) {
    printf(" %4.2f", V[i]);
  }
}
