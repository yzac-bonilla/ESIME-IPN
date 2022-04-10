/*
   Bonilla Silva Isaac
   1CM8
   PP13101211

 */
	#include<stdio.h>
	#include<conio.h>
	#include<math.h>
	#include<J:\include\portada.H>
	int leer(void);
	float factorial(int);
	void imprimir(int,float);
	void main(void)
	{
		clrscr();
		caratula();
		clrscr();
		int n;
		float fac;
		clrscr();
		printf("\n\n\n\n\n\n\t\t\t\¨Que factorial deseas calcular? n=");
		n=leer();
		fac=factorial(n);
		imprimir(n,fac);
		getch();
	}
	float factorial(int n)
	 {
		int k;
		float f=1;
		for(k=1;k<=n;k++)
			f=f*k;
		return(f);
	 }
	int leer(void)
	 {
		int R;
		scanf("%d",&R);
		return(R);
	 }
	void imprimir(int n,float fac)
	{
		printf("\n\n\t\t	%d! = %.0f",n,fac);
	}