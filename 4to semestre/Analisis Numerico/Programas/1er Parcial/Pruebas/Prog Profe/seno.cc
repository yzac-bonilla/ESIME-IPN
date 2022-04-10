**
   Javier Abellán. 11 Febrero 2004

   Programa de ejemplo de un gráfico de sin(x) en una ventana de X11.
   Cómo hacer un escalado para ajustar la gráfica del sin(x) a la ventana.
*/
#include <X11/Xlib.h>
#include <unistd.h>
#include <math.h>

#include <Escala.h>

// Ancho y alto de la ventana en pixels.
#define ANCHO 700
#define ALTO 500

/** Programa principal. Crea la ventana y dibuja en ella la función
   sin(x) ajustada a la ventana */
int main()
{
	/* Conexion con el servidor de X */
	Display *disp = NULL;

	/* Ventana que vamos a crear para dibujar */
	Window ventana;

	/* Color que vamos a utilizar para dibujar una linea */
	XColor color;

	/* Abrimos la conexion con el servidor de X */
	disp = XOpenDisplay(NULL);

	/* Creamos una ventana */
	ventana = XCreateSimpleWindow (
		disp,
		XDefaultRootWindow (disp),
		100, 100,
		ANCHO, ALTO,
		1, 1,
		WhitePixel (disp, DefaultScreen(disp)));

	/* Hacemos que la ventana sea visible */
	XMapWindow (disp, ventana);

	/* Obtenemos el color azul */
	color.flags = DoRed | DoGreen | DoBlue;
	color.red = 0;
	color.blue = 65535;
	color.green = 0;
	color.pad = 0;

	XAllocColor (
		disp,
		DefaultColormap (disp, DefaultScreen(disp)),
		&color);

	/* Indicamos que el color de dibujo a partir de ahora es el azul */
	XSetForeground (
		disp,
		XDefaultGC (disp, DefaultScreen(disp)),
		color.pixel);

   /* Instanciamos y preparamos la clase de conversión de escala.
      Para un ciclo completo de la función sin(x) hacemos variar x desde 0 
      hasta 2*PI .La y varía desde -1 hasta 1. */
   EscalaC escala;
   escala.tomaExtremos (0.0, 2*M_PI, -1.0, 1.0);
   escala.tomaAreaGrafica (ANCHO, ALTO);

   /* Cualquier cosa que dibujemos en la ventana antes de que esta esté
      realmente visible se pierde. Por ello esperamos un segundo antes
      de ponernos a dibujar */
   sleep(1);

   /* Calculamos la funcion seno y dibujamos los puntos */
   double x,y;
   int xPixel, yPixel;

   /* Bucle para x desde 0 hasta 2*PI en incrementos pequeños de 0.01 */
   for (x=0.0; x<2*M_PI; x+=0.01)
   {
      /* Calculamos x e y en pixels */
      xPixel = escala.dameX (x);
      yPixel = escala.dameY (sin(x));

      /* Dibujamos el punto */
      XDrawPoint (disp,
         ventana,
         XDefaultGC (disp, DefaultScreen(disp)),
         xPixel, yPixel);
   }
   
   XFlush(disp);
	/* Espera para que la ventana no se cierre inmediatamente */
	sleep (10);
}
