 /*
   Bonilla Silva Isaac
   1CM8
   PP13101211
   Estructura Ramificada Simple 1
 */
	 #include<stdio.h>
	 #include<math.h>
	 #include<conio.h>
	 float calcuy(float);
	 float leer(void);
	 void funy(float);
	 void imprimir(float,float);
	 void main(void)
	 {
		float x;
		clrscr();
		printf("\n\n\t\tDa x = ");
		x=leer();
		funy(x);
		getch();
	 }
	 float leer(void)
	 {
		float M;
		scanf("%f",&M);
		return(M);
	 }
	 void funy(float x)
	 {
		float y;
		clrscr();
		if(x!=3)
		{
			y=calcuy(x);
			imprimir(x,y);
		}
		else
			printf("\n\n\t\tCon x= %f no se puede calcular y",x);
		}

	 void imprimir(float x,float y)
	 {
			printf("\n\n\t\tCon x= %f se obtuvo y= %f",x,y);
	 }
	 float calcuy(float x)
	 {
		float y;
		y=exp(x)/(x-3);
		return(y);
	 }