// Metodo de Runge-Kutta

int runge_kutta() {
  int n, i;
  float h, a=0, b=1, x=0, y=2, k1, k2, k3, k4;
  printf("\n\tMetodo de Runge-Kutta\n\ty(%.1f)=%.1f; y(%.1f)=?\n", a, y, b);
  printf("\ty' = x - y\n");
  printf("\nEscriba la cantidad de intervalos: ");
  input(1, "%i", &n);
  printf("\ni\txi\tyi\tk1\tk2\tk3\tk4\n");
  h = (b - a)/n;
  for (i=0; i<n; i++) {
    k1 = f(x,y);
    k2 = f(x + h/2, y + k1*h/2);
    k3 = f(x + h/2, y + k2*h/2);
    k4 = f(x + h, y + k3*h);
    printf("%i\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\n", i, x, y, k1, k2, k3, k4);
    x = x + h;
    y = y + h*(k1 + 2*k2 + 2*k3 + k4)/6;
  }
  printf("%i\t%.4f\t%.4f\n", i, x, y);
  printf("\ny(%.1f)=%.4f\n", b, y);
  return 0;
}
