/*
   Bonilla Silva Isaac
   1CM8
   PP13101211

 */
	#include<stdio.h>
	#include<conio.h>
	#include<math.h>
	#include<ctype.h>
	#include<stdlib.h>
    // #include<J:\include\portada.H>
	#include<C:\PORTADA.H>
	void funR(void);
    float calcuR(float);
	void imprimir(float,float);
	void main(void)
	{
		clrscr();
		caratula();
		clrscr();
		funR();
		getch();
	}
	void funR(void)
	 {
	 	float R,m=-10;
		printf("\n\n\t\tm\t R");
		do
		 {
			if(m!=1/m && m!=0 &&m!=3/(m-1/m))
			 {
				R=calcuR(m);
				imprimir(m,R);
			 }
			else
             {
				printf("\n\n\t\tNo se puede calcular R con m=%f",m);
			 }
			m++;
		 }while(m<=10);
	 }
	float calcuR(float m)
	 {
		float RT;
		RT=1/((1/3*m)-(1/(m-1/m)));
		return(RT);
	 }
	void imprimir(float m,float R)
	 {
		printf("\n\n\t\t%.0f\t %f",m,R);
	 }