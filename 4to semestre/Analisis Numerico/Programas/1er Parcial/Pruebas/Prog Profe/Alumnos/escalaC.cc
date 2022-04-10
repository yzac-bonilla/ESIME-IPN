/**
   Javier Abellán. 11 Febrero 2004

   Clase para la conversión de escala de un gráfico a un área de pantalla
   en pixels.
*/ 
#include <Escala.h>

/* Necesario para NULL de punteros */
#include <stdio.h>

/**
   Constructor.
   Rellena los atributos con valores por defecto.
*/
EscalaC::EscalaC()
{
   xMin = -10.0;
   xMax = 10.0;
   yMin = -10.0;
   yMax = 10.0;
   ancho = 100;
   alto = 100;
}

/** Se le pasan los extremos de nuestro gráfico, es decir, x e y mínimas y 
máximas. */
void EscalaC::tomaExtremos (double nuevaXMin, double nuevaXMax,
         double nuevaYMin, double nuevaYMax)
{
   // Se rechazan valores iguales de máximo y mínimo.
   if (nuevaXMin == nuevaXMax) return;
   if (nuevaYMin == nuevaYMax) return;
   
   // Si los valores de x minimo y máximo están al revés, se guardan dándoles
   // la vuelta.
   if (nuevaXMin > nuevaXMax)
   {
      xMin = nuevaXMax;
      xMax = nuevaXMin;
   }
   else
   {
      xMin = nuevaXMin;
      xMax = nuevaXMax;
   }

   // Si los valores de y minimo y máximo están al revés, se guardan dándoles
   // la vuelta.
   if (nuevaYMin > nuevaYMax)
   {
      yMin = nuevaYMax;
      yMax = nuevaYMin;
   }
   else
   {
      yMin = nuevaYMin;
      yMax = nuevaYMax;
   }
}

/** Se le pasa el ancho y alto de nuestra zona de dibujo */
void EscalaC::tomaAreaGrafica (int nuevoAncho, int nuevoAlto)
{
   // Se rechazan valores de 0 o negativos
   if (nuevoAncho < 1) return;
   if (nuevoAlto < 1) return;

   ancho = nuevoAncho;
   alto = nuevoAlto;
}

/** Devuelve el pixel x correspondiente al valor x que se le pasa. */
int EscalaC::dameX (double x)
{
   int xPixel;

   xPixel = (int)((x - xMin)/(xMax - xMin)*ancho);

   return xPixel;
}

/** Devuelve el pixel y correspondiente al valor y que se le pasa.
Tiene en cuenta que la y en pantalla crece hacia abajo, mientras que un
gráfico suele crecer hacia arriba. */
int EscalaC::dameY (double y)
{
   int yPixel;

   yPixel = (int)(alto - (y - yMin)/(yMax - yMin)*alto);

   return yPixel;
}

/** Se le pasa un array de valores x y el número de valores en
dicho array. Devuelve en xPixel los pixels correspondientes a
dichos valores de x.
- x es el array de valores x.
- numeroPuntos es el numero de valores x en el array anterior.
- xPixel es un array con hueco suficiente. En el devuelve este método
los pixels x */
void EscalaC::dameX (double *x, int *xPixel, int numeroPuntos)
{
   int i;
   double factorConversion;
   
   // Se comprueban los parámetros que nos pasan
   if (x==NULL) return;
   if (xPixel == NULL) return;
   if (numeroPuntos < 1) return;

   // El siguiente factor se utiliza en todos los puntos, asi que por
   // eficiencia, en vez de calcularlo cada vez dentro del bucle,
   // se guarda en una variable aparte.
   factorConversion = ancho/(xMax - xMin);

   for (i=0; i<numeroPuntos; i++)
   {
      xPixel[i] = (int)((x[i]-xMin)*factorConversion);
   }
}

/** Se le pasa un array de valores y y el número de valores en
dicho array. Devuelve en yPixel los pixels correspondientes a
dichos valores de y.
y es el array de valores y.
numeroPuntos es el numero de valores y en el array anterior.
yPixel es un array con hueco suficiente. En el devuelve este método
los pixels y */
void EscalaC::dameY (double *y, int *yPixel, int numeroPuntos)
{
   int i;
   double factorConversion;
   
   // Se comprueban los parámetros que nos pasan
   if (y==NULL) return;
   if (yPixel == NULL) return;
   if (numeroPuntos < 1) return;

   // El siguiente factor se utiliza en todos los puntos, asi que por
   // eficiencia se guarda en una variable aparte.
   factorConversion = alto/(yMax - yMin);

   for (i=0; i<numeroPuntos; i++)
   {
      yPixel[i] = (int)(alto - (y[i]-yMin)*factorConversion);
   }
}

