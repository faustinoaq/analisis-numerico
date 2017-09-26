// #include<stdio.h>
// #include<conio.h>
void leer_puntos2(float[],float[],int);
void lagrange_inversa()
{
int i,n,j;
float vy,p,py;
printf("\nINTERPOLACION INVERSA DE LAGRANGE.");
printf("\nINGRESE LA CANTIDAD DE PUNTOS A APROXIMAR:");scanf("%d",&n);
float X[n],Y[n];
leer_puntos2(X,Y,n);
printf("\nINGRESE EL VALOR DE Y PARA APROXIMAR A f:");scanf("%f",&vy);
py=i=0;
do
 {
 p=1;
 for(j=0;j<n;j++)
    {
    if(i!=j)
      {
      p=p*((vy-Y[j])/(Y[i]-Y[j]));
      }
    }
 py=py+(X[i]*p);
 i++;
 }
 while(i<n);
printf("\nEl valor aproximado de la abscissa de p(%.f):%.4f",vy,py);
// getch();
}
void leer_puntos2(float VX[],float VY[],int cap)
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
