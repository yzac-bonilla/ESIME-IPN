/*
   Bonilla Silva Isaac
   1CM8
   PP13101211
   Tabular Y, Iterativa Poscondicional Anidada 1
 */
	#include<stdio.h>
	#include<conio.h>
	#include<math.h>
	#include<J:\include\portada.H>
	void funy(void);
	float calcuy(float);
	void imprimir(float,float);
	void main(void)
	{
		clrscr();
		caratula();
		clrscr();
		funy();
		getch();
	}
	void funy(void)
	{
		float x,y;
		x=-10;
		printf("\n\n\t\t	x	y");
		do
		{
			if(x!=1 && x!=0)
			{
				y=calcuy(x);
				imprimir(x,y);
			}
			else
			{
			printf("\n\n\n\t\t\tNo se puede calcular Y con X=%.0f",x);
			}
			x=x+1;
		}while(x<=10);
	}
	void imprimir(float x,float y)
	{
		printf("\n\n\t\t	%.0f	%f",x,y);
	}
	float calcuy(float x)
	{
		float yx;
		yx=exp(sin(x)/x)/(x-1);
		return(yx);
	}



