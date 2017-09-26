#include <string.h>
int menu();
float sum(float[],int,int);
float abst(float,float);
void act(float[],float[],int,float);
float suma13(float[],int);
float suma23(float[],int);
float suma18(float[],int);
float suma28(float[],int);
void ver_datos(float[],float[],int);
void present();
void act(float Xi[],float FX[],int n,float h)
{
     Xi[0]=0;
     FX[0]=Xi[0]*sqrt(1+pow(Xi[0],2));//esto cambiaria si se evalua otra integral
     for(int i=1;i<=n+1;i++)
        {
        Xi[i]=Xi[i-1]+h;
        FX[i]=Xi[i]*sqrt(1+pow(Xi[i],2));//esto cambiaria si se evalua otra integral
        }
return;
}
void integracion()
{
       int n,op,j;
       float a,b,h,suma=0,value;
       char resp[2];
       present();
       do{
       printf("\n Ingrese el extremo a:");
       scanf("%f",&a);
       printf(" Ingrese el extremo b:");
       scanf("%f",&b);
       printf("Ingrese la cantidad n que desea dividir el intervalo:");
       scanf("%d",&n);
       h=(b-a)/n;
       float Xi[n+1],FX[n+1];
       switch(menu())
             {
             case 1 :printf("\n\t\tREGLA DEL RECTANGULO");
                     act(Xi,FX,n,h);
                     printf("\nEscoja la opcion de los limites");
                     printf("\n 1. LIMITES SUPERIORES.");
                     printf("\n 2. LIMITES INFERIORES.");
                     printf("\n");
                     scanf("%d",&op);
                     switch(op)
                           {
                           case 1:suma=sum(FX,n,1);
                                  break;
                           case 2:suma=sum(FX,n,2);
                                  break;
                           default: printf("\nOPCION INCORRECTA");
                            }
                     printf("\n");
                     ver_datos(Xi,FX,n);
                     printf("\n");
                     printf("\nEl valor aproximado es:%.4f",h*suma);
                     printf("\nEl error relativo   es:%.4f\n",abst(10.2076,(h*suma)));
                      break;

             case 2 :printf("\n\t\tREGLA DEL TRAPECIO");
                     suma=0;
                     act(Xi,FX,n,h);
                     for(j=1;j<n;j++)
                        {suma=suma+FX[j];}
                     value=(0.5*h)*(FX[0]+(2*suma)+FX[n]);
                     printf("\n");
                     ver_datos(Xi,FX,n);
                     printf("\n");
                     printf("\nEl valor aproximado es:%.4f",value);
                     printf("\nEl error relativo   es:%.4f\n",abst(10.2076,value));//el valor 10.2076 cambiaria si se evalua otra integral
                      break;

             case 3 :printf("\n\t\tREGLA DE SIMPSOM 1/3");
                   if((n%2)==0){
                      act(Xi,FX,n,h);
                      value=(h/3)*(FX[0]+(4*suma13(FX,n))+(2*suma23(FX,n))+FX[n]);
                      printf("\n");
                      ver_datos(Xi,FX,n);
                      printf("\n");
                      printf("\nEl valor aproximado es:%.4f",value);
                      printf("\nEl error relativo   es:%.6f\n",abst(10.2076,value));}
                   else
                      {printf("\nEl metodo no admite segmentos impares.\n");}
                      break;

             case 4 :printf("\n\t\tREGLA DE SIMPSOM 3/8");
                    if((n%3)==0){
                       act(Xi,FX,n,h);
                       value=(3*h/8)*(FX[0]+(2*suma18(FX,n))+(3*suma28(FX,n))+FX[n]);
                       printf("\n");
                       ver_datos(Xi,FX,n);
                       printf("\n");
                       printf("\nEl valor aproximado es:%.4f",value);
                       printf("\nEl error relativo   es:%.6f\n",abst(10.2076,value));}
                    else
                       {printf("\nEl subintervalo no es multiplo de 3.\n");}
                      break;
             default: printf("\nOpcion Incorrecta");
             }
       printf("\nDesea probar otra regla de integracion. (si/no): ");
       scanf("%s",resp);
       }
       while(strcmp("si",resp)==0);
// system("pause");
}

void present()
{

       printf("\n\t\t\tIntegracion Numerica.");
       printf("\n");
       printf("\n\t\tFuncion: f(x)=x*raizcuadrada(1+x^2)");
       printf("\n");
       printf("\nIngrese el intervalo[a,b]-Limites de Integracion");
       printf("\n");
}
int menu()
{
    int op;
    printf("\n\t******REGLAS DE INTEGRACION******");
    printf("\n\t\t1. Regla del rectangulo.");
    printf("\n\t\t2. Regla del trapecio.");
    printf("\n\t\t3. Regla de Simpson 1/3.");
    printf("\n\t\t4. Regla de Simpson 3/8.");
    printf("\n");
    scanf("%d",&op);

return(op);
}
float sum(float XC[],int lim,int OP)
{
float suma=0;
      if(OP==2)//usando limites inferiores
      {for(int j=0;j<lim;j++)
        {suma=suma+XC[j];}}
      else
      {for(int j=1;j<lim+1;j++)
        {suma=suma+XC[j];}}
return(suma);
}
float abst(float real,float aprox)
{
      float aux;
      aux=(real-aprox)/real;
      if(aux>0)
         {aux=aux;}
      else
         {aux=-1*aux;}
return(aux);
}

float suma13(float XT[],int lim)
{
      float aux=0;
      for(int i=1;i<=lim-1;i++)
         {if((i%2)!=0)
           {aux=aux+XT[i];}}
return(aux);
}

float suma23(float XT[],int lim)
{
float aux=0;
      for(int i=1;i<=lim-1;i++)
         {if((i%2)==0)
           {aux=aux+XT[i];}}
return(aux);
}
float suma18(float XT[],int lim)
{
      float aux=0;
      for(int i=1;i<=lim-1;i++)
         {if((i%3)==0)
           {aux=aux+XT[i];}}
return(aux);
}

float suma28(float XT[],int lim)
{
float aux=0;
      for(int i=1;i<=lim-1;i++)
         {
         if((i%3)!=0)
           {aux=aux+XT[i];}}
return(aux);
}
void ver_datos(float VXI[],float VFXI[],int lim)
{
printf("\n\ti");
 for(int i=0;i<=lim;i++)
   {printf("\t%d",i);}
printf("\n\tXi");
 for(int i=0;i<=lim;i++)
   {printf("\t%.2f",VXI[i]);}
printf("\n\tf(xi)");
 for(int i=0;i<=lim;i++)
   {printf("\t%.4f",VFXI[i]);}
}
