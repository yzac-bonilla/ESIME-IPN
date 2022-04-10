

/**************************************/
/*    Programa de Metodos Numericos   */
/*      Aproximaciones Sucesivas o    */
/*             de punto fijo          */
/*         Para una funcion dada      */
/**************************************/

#include <stdio.h>
#include <math.h>

/************   Declaracion de Funciones  ***********/
/*   Ejemplo  Ecuacion Original --> X^2-0.5         */
/****************************************************/
void Lee_Datos(void);
double Funcion(double Xi);

double Xo;
float  Tolera;
int    Ciclos;

int main()

{
  double Fx;
  double Xn;
  float  Error = 1;
  int    Cont  = 0;

  Lee_Datos();

  printf("\n======================================================");
  printf("\n Ciclo    Xo       Fx        Xn       Error");
  printf("\n======================================================");

  while (Error > Tolera && Ciclos > Cont)
	 {
		Fx    = Funcion(Xo);
		Xn    = Fx;
		Error = fabs( (Xn - Xo)/Xn );
		Cont++;
		printf("\n%3d%10.4lf%10.4lf%10.4lf%10.4f",Cont,Xo,Fx,Xn,Error);
		Xo    = Xn;
	 }

  printf("\n======================================================");
  if (Ciclos > Cont)
	 printf("\n La raiz de la ecuacion es %.5lf ",Xn);
  else
	printf("\n\n No converge en %3d Ciclos !!!! Dar nuevos valores",Ciclos);
  //system("PAUSE");
}

void Lee_Datos(void)

{
	//system("CLS");
	printf("\n Dar el Valor inicial de X -> ");
	scanf("%lf",&Xo);
	printf("\n Cual es el error Permitido ->");
	scanf("%f",&Tolera);
	printf("\n Numero de ciclos maximos ->");
	scanf("%d",&Ciclos);
}

double Funcion(double Xo)
	{
	 return  Xo*Xo+Xo-0.5;
	}
