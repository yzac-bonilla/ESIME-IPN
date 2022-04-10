/*Padilla Márquez Victor de Franco
	Grupo: 1CM8
   Boleta: PP13042182
   Generar la matriz
*/

#include<conio.h>
#include<stdio.h>
#define nf 30
#define nc 30


void impmat(int,float [nf][nc]);
void identidad(int,float [nf][nc]);
int leer(void);

void main(void)
{
  int m;
  float a[nf][nc];
  clrscr();
  printf("\n\tDa el numero de filas y columnas \n\tm = ");
  m=leer();
  identidad(m,a);
  printf("\n\tMATRIZ GENERADA ");
  impmat(m,a);
  getch();
}

void impmat(int m,float a[nf][nc])
{
	int i,j;
   for(i=1;i<=m;i++)
    {
   	printf("\n\n\t");
   	for(j=1;j<=m;j++)
      	printf("\t%.0f",a[i][j]);
     }
}

void identidad(int m,float a[nf][nc])
{
	int i,j;
   for(i=1;i<=m;i++)
   	for(j=1;j<=m;j++)
      	if(i==j)
         	a[i][j]=0;
         else
         	a[i][j]=i;
}

int leer(void)
{
	int R;
   scanf("%d",&R);
   return(R);
}




