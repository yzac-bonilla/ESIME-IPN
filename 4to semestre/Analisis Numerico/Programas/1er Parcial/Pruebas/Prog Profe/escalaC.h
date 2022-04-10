/**
   Javier Abellán. 10 Febrero 2004

   Clase de transformación de escala gráfica a pixels de pantalla.
*/

#ifndef _ESCALA_H
#define _ESCALA_H

/**
   Convierte coordenadas de una escala gráfica cualquiera a pixels de
   pantalla.
*/
class EscalaC
{
   public:
      /** Constructor.
         Inicializa los atributos con valores por defecto */
      EscalaC();

      /** Se le pasan los extremos de nuestro gráfico, es decir, 
      x e y mínimas y máximas. */
      void tomaExtremos (double nuevaXMin, double nuevaXMax,
         double nuevaYMin, double nuevaYMax);

      /** Se le pasa el ancho y alto de nuestra zona de dibujo */
      void tomaAreaGrafica (int nuevoAncho,
         int nuevoAlto);
         
      /** Devuelve el pixel x correspondiente al valor x que se le
      pasa. */
      int dameX (double x);

      /** Devuelve el pixel y correspondiente al valor y que se le 
      pasa */
      int dameY (double y);

      /** Se le pasa un array de valores x y el número de valores en
      dicho array. Devuelve en xPixel los pixels correspondientes a
      dichos valores de x.
      x es el array de valores x.
      numeroPuntos es el numero de valores x en el array anterior.
      xPixel es un array con hueco suficiente. En el devuelve este método
      los pixels x */
      void dameX (double *x, int *xPixel, int numeroPuntos);
      
      /** Se le pasa un array de valores y y el número de valores en
      dicho array. Devuelve en yPixel los pixels correspondientes a
      dichos valores de y.
      y es el array de valores y.
      numeroPuntos es el numero de valores y en el array anterior.
      yPixel es un array con hueco suficiente. En el devuelve este método
      los pixels y */
      void dameY (double *y, int *yPixel, int numeroPuntos);
      

   private:
      /** X minima de nuestro gráfico */
      double xMin;

      /** X máxima de nuestro gráfico */
      double xMax;

      /** Y mínima de nuestro gráfico */
      double yMin;

      /** Y máxima de nuestro gráfico */
      double yMax;

      /** ancho en pixels de nuestra área de dibujo */
      int ancho;

      /** alto en pixels de nuestra área de dibujo */
      int alto;
};

#endif

