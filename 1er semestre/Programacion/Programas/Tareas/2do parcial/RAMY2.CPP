 /*
   Bonilla Silva Isaac
   1CM8
   PP13101211
   Estructura Ramificada Simple 2
 */
	 #include<stdio.h>
	 #include<math.h>
	 #include<conio.h>
	 float leer(void);
	float calcugt(float);
	 void imprimir(float,float);
	 void main(void)
	 {
		float t,g; clrscr();
		printf("\n\n\t\tDa t= ");
		t=leer();
		g=calcugt(t);
		imprimir(t,g);
		getch();
	}
	float calcugt(float t)
	{
		float gt; clrscr();
		if(t<=-5)
			gt=t*t-t-1;
		else
			if(t<0)
				gt=exp(2*t);
		else
			gt=cos(t*t);
		return(gt);
	}
	void imprimir(float t,float g)
	 {
			printf("\n\n\t\tCon t=%f se obtuvo g=%f",t,g);
	 }
	 float leer(void)
	 {
		float M;
		scanf("%f",&M);
		return(M);
	 }