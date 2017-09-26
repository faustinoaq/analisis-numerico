// #include<stdio.h>
// #include<conio.h>
void leer_puntos(float[],float[],int);
void lagrange_directa()
{
int i,n,j;
float vx,p,px;
printf("\nINTERPOLACION DIRECTA DE LAGRANGE.");
printf("\nINGRESE LA CANTIDAD DE PUNTOS A APROXIMAR:");scanf("%d",&n);
float X[n],Y[n];
leer_puntos(X,Y,n);
printf("\nINGRESE EL VALOR DE X PARA APROXIMAR A f:");scanf("%f",&vx);
px=i=0;
do
 {
 p=1;
 for(j=0;j<n;j++)
    {
    if(i!=j)
      {
      p=p*((vx-X[j])/(X[i]-X[j]));
      }
    }
 px=px+(Y[i]*p);
 i++;
 }
 while(i<n);
printf("\nEl valor aproximado de la ordenada de p(%.f):%.4f",vx,px);
// getch();
}
void leer_puntos(float VX[],float VY[],int cap)
{
int i;
printf("\nESCRIBA LOS VALORES DE LOS PUNTOS.");
for(i=0;i<cap;i++)
  {
  printf("\n\tX%d:",i+1);scanf("%f",&VX[i]);
  printf("\tY%d:",i+1);scanf("%f",&VY[i]);
  }
return;
}
