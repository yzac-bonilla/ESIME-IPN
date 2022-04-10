     /*	Bonilla Silva Isaac
	PP13101211
	1CM8
	Guia 1.11
     */
	#include<stdio.h>
	#include<math.h>
	#include<conio.h>
	float leer1(void);
	double leer2(void);
	void imprimir(float,float,float);
	float calcuZ(double,float);
	void main(void)
	{
		double m;
		float a,b,c,d,Pi,z;clrscr();
		printf("Da el valor de Pi= ");
		Pi=leer1();
		printf("Da el valor de m= ");
		m=leer2();
		z=calcuZ(m,Pi);
		imprimir(z,Pi,m);
		getch();
       }
       float calcuZ(double x,float p)
       {
		float a,b,c,d,Z;
		a=sqrt(sin((p/3)*(p/3)));
		c=a*cos(p-3/2.);
		d=(c*exp(p/2))*(c*exp(p/2));
		b=pow(d,1/5);clrscr();
		Z=x*(a+b)/(c-d);
		return(Z);
       }
       float leer1(void)
       {
       float x;
       scanf("%f",&x);
       return(x);
       }
       double leer2(void)
       {
       double x;
       scanf("%e",&x);
       return(x);
       }
       void imprimir(float x,float y,double z)
       {
       printf("\n\n\t\tZ= %f\n\n\t\tPi= %f\n\n\t\tm= %f",x,y,z);
       }

