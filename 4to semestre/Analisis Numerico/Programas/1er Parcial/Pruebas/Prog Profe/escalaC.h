/**
   Javier Abell�n. 10 Febrero 2004

   Clase de transformaci�n de escala gr�fica a pixels de pantalla.
*/

#ifndef _ESCALA_H
#define _ESCALA_H

/**
   Convierte coordenadas de una escala gr�fica cualquiera a pixels de
   pantalla.
*/
class EscalaC
{
   public:
      /** Constructor.
         Inicializa los atributos con valores por defecto */
      EscalaC();

      /** Se le pasan los extremos de nuestro gr�fico, es decir, 
      x e y m�nimas y m�ximas. */
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

      /** Se le pasa un array de valores x y el n�mero de valores en
      dicho array. Devuelve en xPixel los pixels correspondientes a
      dichos valores de x.
      x es el array de valores x.
      numeroPuntos es el numero de valores x en el array anterior.
      xPixel es un array con hueco suficiente. En el devuelve este m�todo
      los pixels x */
      void dameX (double *x, int *xPixel, int numeroPuntos);
      
      /** Se le pasa un array de valores y y el n�mero de valores en
      dicho array. Devuelve en yPixel los pixels correspondientes a
      dichos valores de y.
      y es el array de valores y.
      numeroPuntos es el numero de valores y en el array anterior.
      yPixel es un array con hueco suficiente. En el devuelve este m�todo
      los pixels y */
      void dameY (double *y, int *yPixel, int numeroPuntos);
      

   private:
      /** X minima de nuestro gr�fico */
      double xMin;

      /** X m�xima de nuestro gr�fico */
      double xMax;

      /** Y m�nima de nuestro gr�fico */
      double yMin;

      /** Y m�xima de nuestro gr�fico */
      double yMax;

      /** ancho en pixels de nuestra �rea de dibujo */
      int ancho;

      /** alto en pixels de nuestra �rea de dibujo */
      int alto;
};

#endif

