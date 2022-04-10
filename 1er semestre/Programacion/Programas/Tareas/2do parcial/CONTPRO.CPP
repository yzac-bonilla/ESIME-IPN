/*
   Bonilla Silva Isaac
   1CM8
   PP13101211
   Leer e imprimir m valores de X
 */
	#include<stdio.h>
	#include<conio.h>
	#include<math.h>
	#include<ctype.h>
	#include<stdlib.h>
	#include<J:\include\portada.H>
	int leer(void);
	float entrada(void);
	void imprimir(int,float);
	void main(void)
	{
		clrscr();
		caratula();
		clrscr();
		int i, m;
		float x;
		clrscr();
		printf("\n\n\n\n\n\n\t\t\t¨Cuantas X deseas leer? m=");
		m=leer();
		for(i=1;i<=m;i++);
		 {
			printf("\n\n\n\t\t\tDa X[%d]=",i);
			x=entrada();
			imprimir(i,x);
		 }
		getch();
		}
		int leer(void)
		 {
			int R;
			scanf("%d",&R);
			return(R);
		 }
		float entrada(void)
		 {
			float s;
			scanf("%f",&s);
			return(s);
		 }
		void imprimir(int i, float x)

		 {
			printf("\n\n\n\t\t\tX[%d]=%f",i,x);
		 }