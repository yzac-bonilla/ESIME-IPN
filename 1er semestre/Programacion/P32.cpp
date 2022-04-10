/* Padilla Márquez Victor de Franco
	Grupo: 1CM8
   Problema 3.2
*/

#include<conio.h>
#include<stdio.h>
#define nf 30
#define nc 30

int leer(void);
void leemat(int,int,float [nf][nc]);
void impmat(int,int,float [nf][nc]);
float sumaperi(int,int,float[nf][nc]);

void main(void)
{
	int m,n;
   float a[nf][nc],sp;
   clrscr();
   printf("\n\tDa el numero de filas \n\tm = ");
   m=leer();
   printf("\n\tDa el numero de columnas \n\tn = ");
   n=leer();
   printf("\n\tDa los elementos de la matriz: ");
   leemat(m,n,a);
   printf("\n\t\t\tMATRIZ DADA: ");
   impmat(m,n,a);
   sp=sumaperi(m,n,a);
   printf("\n\n\tLa suma de lo elementos de la periferia de la matriz A[%d]x[%d] es: \n\tS = %.2f",m,n,sp);
   getch();
}

int leer(void)
{
	int R;
   scanf("%d",&R);
   return(R);
}

void leemat(int m,int n,float a[nf][nc])
{
	int i,j;
   for(i=1;i<=m;i++)
   	for(j=1;j<=n;j++)
      	scanf("%f",&a[i][j]);
}

void impmat(int m,int n,float a[nf][nc])
{
	int i,j;
   	for(i=1;i<=m;i++)
      {
      	printf("\n\n\t");
         for(j=1;j<=n;j++)
         	printf("\t%.2f",a[i][j]);
      }
}

float sumaperi(int m, int n,float a[nf][nc])
{
	float s=0,st=0;
   int i,j;
   	for(j=1;j<=n;j++)
      {
         s=0;
      	s+=a[1][j];
         st+=s;
      }

   if(m!=1)
   {
   	for(j=1;j<=n;j++)
      {
         s=0;
      	s+=a[m][j];
         st+=s;
      }
   }

      for(i=2;i<m;i++)
      {
         s=0;
      	s+=a[i][1];
         st+=s;
      }

      for(i=2;i<m;i++)
      {
         s=0;
      	s+=a[i][n];
         st+=s;
      }

   return(st);
}
