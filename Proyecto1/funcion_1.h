
#define N 100

void leer() {
  int i, j, cont=0, n, V[N];
  printf("\t\nVECTOR\n");
  printf("Escriba el tamaño del vector (Máx. 99): ");
  scanf("%i", &n);
  for (i = 0; i < n; i++) {
    printf("Escriba el valor %i del vector: ", i);
    scanf("%i", &V[i]);
    for (j = 0; j <= i; j++) {
      if (V[j] == V[i]) {
        cont++;
      }
    }
    printf("\t\nFrecuencia de %i: %i vez(es)\n\n", V[i], cont);
    cont=0;
  }
}
