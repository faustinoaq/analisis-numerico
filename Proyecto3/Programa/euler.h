// Metodo de Euler

float f(float x, float y) {
  // EDO
  return x - y;
}

int euler() {
  int n, i;
  float h, a=0, b=1, x=0, y=2, hf;
  printf("\n\tMetodo de Euler\n\ty(%.1f)=%.1f; y(%.1f)=?\n", a, y, b);
  printf("\ty' = x - y\n");
  printf("\nEscriba la cantidad de intervalos: ");
  input(1, "%i", &n);
  printf("\ni\tXi\tYi\thf(xi,yi)\n");
  h = (b - a)/n;
  for (i=0; i<n; i++) {
    hf = h*f(x,y);
    printf("%i\t%.4f\t%.4f\t%.4f\n", i, x, y, hf);
    y = y + hf;
    x = x + h;
  }
  printf("%i\t%.4f\t%.4f\n", i, x, y);
  printf("\ny(%.1f)=%.4f\n", b, y);
  return 0;
}
