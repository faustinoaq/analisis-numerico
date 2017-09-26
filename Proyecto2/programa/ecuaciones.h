// Ecuaciones a resolver

int ecuacion () {
  char opcion;
  printf("\n1. e^x + x = 0\n");
  printf("2. x^3 - 5x - 1 = 0\n");
  printf("3. e^x - 2sen(x) = 0\n");
  printf("Elija una ecuacion: ");
  // ver funcion input en utils.h
  input(1, "%[123]", &opcion);
  return opcion - '0'; // Se convierte de codigo ASCII a entero
}

float f(float x, char o) {
  // Ecuaciones de Biseccion
  switch (o) {
    case 1:
    x = exp(x) + x;
    break;
    case 2:
    x = pow(x,3) - 5*x - 1;
    break;
    case 3:
    x = exp(x) - 2*sin(x);
    break;
  }
  return x;
}

float g(float x, int o) {
  // Ecuaciones de Punto Fijo
  // f(x) de la forma x = g(x)
  switch (o) {
    case 1:
    x = -exp(x);
    break;
    case 2:
    x = cbrt(5*x + 1);
    break;
    case 3:
    // Ejemplos: -6.25 -12.55 -18.85
    x = exp(x) - 2*sin(x) + x;
    break;
  }
  return x;
}

float h(float x, int o) {
  // Ecuaciones de Newton-Raphson
  // xi = x - f(x)/f'(x)
  float f, F;
  switch (o) {
    case 1:
    f = exp(x) + x;
    F = exp(x) + 1;
    break;
    case 2:
    f = pow(x,3) - 5*x -1;
    F = 3*pow(x,2) - 5;
    break;
    case 3:
    f = exp(x) - 2*sin(x);
    F = exp(x) - 2*cos(x);
    break;
  }
  return x - (f/F);
}

float mf(float x, int o) {
  // Ecuaciones de Von-Misses f(x)
  float f;
  switch (o) {
    case 1:
    f = exp(x) + x;
    break;
    case 2:
    f = pow(x,3) - 5*x -1;
    break;
    case 3:
    f = exp(x) - 2*sin(x);
    break;
  }
  return f;
}

float mF(float x0, int o) {
  // Derivada Ecuaciones de Von-Misses F(x0)
  float F;
  switch (o) {
    case 1:
    F = exp(x0) + 1;
    break;
    case 2:
    F = 3*pow(x0,2) - 5;
    break;
    case 3:
    F = exp(x0) - 2*cos(x0);
    break;
  }
  return F;
}
