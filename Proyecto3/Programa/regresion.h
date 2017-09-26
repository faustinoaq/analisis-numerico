    // #include<stdio.h>
    // #include<conio.h>
    // #include<math.h>
    #define MAXC 10
    void ver_sol(float[],int lim);
    void sust_atras(float A[][MAXC],float[],float[],int n);
    void elim_adel(float MATA[][MAXC],float[],int n);
    void leer_puntos3(float[],float[],int);
    void cal_xi(float[],int,float[],int);
    void carg_term_ind(float[],float[],float[],float[],int,int);
    void carg_mat(float MAT[][MAXC],int,float[],float[],int);
    float bondad(float[],float[],int,float[],int);
    void regresion()
    {
    int m,n;
    printf("\n\tREGRESION DE MINIMOS CUADRADOS.");
    printf("\nINGRESE LA CANTIDAD DE PUNTOS A AJUSTAR:");scanf("%d",&n);
    printf("INGRESE EL GRADO AL QUE DESEA AJUSTAR EL POLINOMIO:");scanf("%d",&m);
    if(n>=(m+1)){
        float X[n],Y[n];//vectores para los puntos
        leer_puntos3(X,Y,n);//leemos los puntos.
        float MAT[MAXC][MAXC],TERM[m+1],SOL[m+1];//matriz de datos y vectores para terminos   	indep y la solucion
        float Xi[(2*(m-1))+1];//declaro mi vector para el c�lculo de los Xi
        cal_xi(X,m,Xi,n);
        carg_term_ind(TERM,Xi,X,Y,m,n);//cargamos los terminos independientes
        carg_mat(MAT,n,Xi,X,m);//cargamos la matriz con los valores,
        elim_adel(MAT,TERM,m+1);//eliminamos hacia adelante
        sust_atras(MAT,SOL,TERM,m+1);//sustituimos hacia atras y agregamos la solucion a el vector 	SOL
        printf("\n--->Los coeficientes del polinomio son:");
        ver_sol(SOL,m+1);//vemos los coeficientes del polinomio
        printf("\n\tLA BONDAD ES:%.4f",bondad(X,Y,n,SOL,m));}//lim=grado);
    else
        {printf("\n!Imposible la Regresion.!");}//ver solucion
    // getch();
    }
void leer_puntos3(float VX[],float VY[],int cap)
{
int i;
printf("\n\t===> ESCRIBA LOS VALORES DE LOS PUNTOS.\n");
for(i=0;i<cap;i++)
  {printf("\n\tX%d:",i+1);scanf("%f",&VX[i]);
  printf("\tY%d:",i+1);scanf("%f",&VY[i]);}
return;
}

void cal_xi(float VX[],int grado,float VXI[],int cap)
{
int i,j;
float suma;
    for(j=0;j<((2*(grado-1))+1);j++)
       {
       suma=0;
       for(i=0;i<cap;i++)
          {suma=suma+pow(VX[i],j+2);}
       VXI[j]=suma;}
return;
}
void carg_term_ind(float IND[],float VXI[],float X[],float Y[],int grado,int n)
{
          int i,h,j;
          float sumx=0,sumy=0,sum,xsum=0;
     for(int h=0;h<n;h++)
       {    xsum=xsum+(X[h]*Y[h]);
            sumy=sumy+Y[h];}

     if(grado==1)
       {IND[0]=sumy;//este estar bien siempre
       IND[1]=xsum;}
     else
      {
       IND[0]=sumy;//este estar bien siempre
       IND[1]=xsum;
       for(i=2;i<=grado;i++)
          {
          sum=0;
          for(j=0;j<n;j++)
             {sum=sum+(pow(X[j],i)*Y[j]);}
          IND[i]=sum;
          }
      }
}
void carg_mat(float MT[MAXC][MAXC],int n,float VXI[],float VX[],int grad)
{
     int i,j,l,k,y;
     float sumx=0;
     for(i=0;i<n;i++)
        {sumx=sumx+VX[i];}
     if(grad==1)
     {
     MT[0][0]=n;
     MT[0][1]=MT[1][0]=sumx;
     MT[1][1]=VXI[0];
     }
     else
     {
     MT[0][0]=n;
     MT[0][1]=MT[1][0]=sumx;
//     MT[1][1]=VXI[0];
       for(j=2;j<(grad+1);j++)
         {MT[0][j]=VXI[j-2];}

       for(l=1;l<(grad+1);l++)
         {MT[1][l]=VXI[l-1];}

       for(k=2;k<=grad;k++)
          {
          for(y=0;y<=grad;y++)
             {MT[k][y]=VXI[y];}
          }
     }
}

//
void ver_sol(float MS[],int lim)
{
 printf("\n------------------------------------------------");
 for(int i=0;i<lim;i++)
 {printf("\n\t\tA%d:%.4f",i,MS[i]);}
 printf("\n------------------------------------------------");
 if((lim-1)==1)
    {printf("\n\t\ty= %.4f %.4fx",MS[0],MS[1]);
printf("\n------------------------------------------------");
    }
 else
    {
    printf("\n\t\ty= %.4f %.4fx",MS[0],MS[1]);
    for(int j=2;j<lim;j++)
      {printf(" %.4fx^%d",MS[j],j);}
    }
printf("\n------------------------------------------------");
return;
}
void sust_atras(float A[][MAXC],float XC[],float B[],int n)
{
 	 int i,j;
 	 float suma;
 	 i=n-1;
 	 while(i>=0)
 	 {
	 suma=0;
	 j=i+1;
	  while(j<n)
	       {
		   suma=suma+(A[i][j]*XC[j]);
		   j++;
		   }
	  XC[i]=(B[i]-suma)/A[i][i];
	  i=i-1;
     }
return;
}
void elim_adel(float MATA[][MAXC],float MATB[],int n)
{
  int i,j,k;
  float aux1,aux2,piv;
  k=0;
      do
      {
          i=k+1;
          do
           {
           piv=MATA[i][k]/MATA[k][k];
           j=k+1;//o j=k;si se quiere asignar los ceros
            do
             {
		  	 aux1=MATA[i][j]-(piv*MATA[k][j]);
		  	 MATA[i][j]=aux1;
		  	 j++;
  		     }
  		     while(j<n);
	       aux2=MATB[i]-(piv*MATB[k]);
	       MATB[i]=aux2;
           i++;
           }
           while(i<n);
      k++;
      }
      while(k<n);
return;
}
float bondad(float X[],float Y[],int np,float SOL[],int lim)
{
int i,j,k;
float bond,aux,aux2,FXI[np];

  if((lim)==1)
   {
   bond=0;
   for(i=0;i<np;i++)
     {bond=bond+(pow(((SOL[0]+(SOL[1]*X[i]))-Y[i]),2));}
   }

  else
   {
   for(i=0;i<np;i++)
      {
      aux2=SOL[0]+(SOL[1]*X[i]);
      aux=0;
      for(j=2;j<=lim;j++)
         {aux=aux+(SOL[j]*pow(X[i],j));}
      FXI[i]=aux2+aux;
      }
   bond=0;
   for(k=0;k<np;k++)
      {bond=bond+pow((FXI[k]-Y[k]),2);}
   }
return(bond);
}
