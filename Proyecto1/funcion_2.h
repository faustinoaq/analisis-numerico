
void primo () {
  int n, es_primo, i;
  printf("\t\nNUMERO PRIMO\n");
  do {
    es_primo=1;
    printf("Escriba un numero natural (1 para salir): ");
    scanf("%i", &n);
    if (n > 1) {
      if (n == 2) {
        continue;
      } else if (n % 2 == 0) {
        es_primo = 0;
      } else {
        for(i=3; (i*i) <= n; i += 2){
          if (n % i == 0 ) {
            es_primo = 0;
            break;
          }
        }
      }
      if (es_primo) {
        printf("El numero %i es primo\n", n);
      } else if (n >= 4){
        printf("El numero %i es compuesto\n", n);
      }
    } else if (n < 1) {
      printf("Error: Introduzca un numero natural\n");
    } else {
      break;
    }
  } while(n != 1);
}
