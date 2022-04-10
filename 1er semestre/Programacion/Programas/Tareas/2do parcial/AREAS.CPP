/*
   Bonilla Silva Isaac
   1CM8
   PP13101211
   Areas de figuras geometricas
 */
  
    #include<stdio.h>
    #include<conio.h>
    #include<ctype.h>
    #include<stdlib.h>
    #define pi 3.1416
    float leer(void);
    void areas(void);
    void rectangulo(void);
    void cuadrado(void);
    void circulo(void);
    void triangulo(void);
    void trapecio(void);
    void main(void)
	{
		clrscr();
		areas();
		getch();
	}
    void areas(void)
	{
		char op; clrscr();
		while(1)
		{
		printf("\n\n\t\tPROGRAMA PARA CALCULAR AREAS");
		printf("\n\n\t\tMENU");
		printf("\n\n\t\tA) Rectangulo");
		printf("\n\n\t\tB) Cuadrado");
		printf("\n\n\t\tC) Circulo");
		printf("\n\n\t\tD) Triangulo");
		printf("\n\n\t\tE) Trapecio");
        printf("\n\n\t\tF) Salir");
		op=toupper(getch());
		switch(op)
			{
				case 'A':
					rectangulo();
					break;
				case 'B':
					cuadrado();
					break;
				case 'C':
					circulo();
					break;
				case 'D':
					triangulo();
					break;
				case 'E':
					trapecio();
					break;
				case 'F': clrscr();
					printf("\n\n\t\tFIN DEl PROGRAMA =)");
					getch();
					exit(0);
				default:
					printf("\n\n\t\tOPCION NO VALIDA");
			}
		}
	}
	float leer(void)
		{
			float m;
			scanf("%f",&m);
			return(m);
		}
	void rectangulo(void)
		{
			float b,h,a;clrscr();
			printf("\n\n\t\tDa el Lado= ");
			b=leer();
			printf("\n\n\t\tDa la Altura= ");
			h=leer();
			a=h*b;
			printf("\n\n\t\tArea = %f",a); getch();clrscr();
		}
	void cuadrado(void)
		{
			float l,a; clrscr();
			printf("\n\n\t\tDa el Lado= ");
			l=leer();
			a=l*l;
			printf("\n\n\t\tArea = %f",a);getch(); clrscr();
		}
	void circulo(void)
		{
			float r,a; clrscr();
			printf("\n\n\t\tDa el Radio= ");
			r=leer();
			a=pi*(r*r);
			printf("\n\n\t\tArea = %f",a); getch(); clrscr();
		}
	void triangulo(void)
		{
			float b,h,a; clrscr();
			printf("\n\n\t\tDa la Base = ");
			b=leer();
			printf("\n\n\t\tDa la Altura = ");
			h=leer();
			a=(b*h)/2;
			printf("\n\n\t\tArea = %f",a); getch(); clrscr();
		}
	void trapecio(void)
		{
			float b,h,a,ar; clrscr();
			printf("\n\n\t\tDa el Lado a = ");
			a=leer();
			printf("\n\n\t\tDa el Lado b = ");
			b=leer();
			printf("\n\n\t\tDa la Altura = ");
			h=leer();
			ar=(a+b)/2*h;
			printf("\n\n\t\tArea = %f",ar); getch(); clrscr();
		}
