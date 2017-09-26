// Metodo de Euler Mejorado

int heun() {
  int n, i;
  float h, a=0, b=1, x=0, yi=2, y0, k1, k2;
  printf("\n\tMetodo de Heun\n\ty(%.1f)=%.1f; y(%.1f)=?\n", a, yi, b);
  printf("\ty' = x - y\n");
  printf("\nEscriba la cantidad de intervalos: ");
  input(1, "%i", &n);
  printf("\ni\tXi\tYi\tf(x,y)\ty0\tyi\n");
  h = (b - a)/n;
  for (i=0; i<n; i++) {
    k1 = f(x,yi);
    y0 = yi + h*k1;
    printf("%i\t%.4f\t%.4f\t%.4f\t%.4f", i, x, yi, k1, y0);
    x = x + h;
    k2 = f(x,y0);
    printf("\t%.4f\n", k2);
    yi = yi + h*(k1 + k2)/2;
  }
  printf("%i\t%.4f\t%.4f\n", i, x, yi);
  printf("\ny(%.1f)=%.4f\n", b, yi);
  return 0;
}
