using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Windows.Forms;

namespace Graficador
{
    class Graficas
    {
        private double x, y, xi, yi, xf, yf;
        private int c, f, ci, fi, cf, ff, n;
        public Graficas() { }
        public void GraficadorXY(Graphics g, double xi,double xf)
        {
            int c1, f1;
            double h;
            ci = 1;
            cf = 300;
            fi = 1;
            ff = 300;
            this.xi = xi;
            this.xf = xf;
            n = cf - ci;
            h = (xf - xi) / n;
            yi = yf = 0;
            for(int k=1;k< n;k++)
            {
                x = xi + k * h;
                y = fu(x);
                if (y < yi) yi = y;
                if (y > yf) yf = y;
            }
            x = xi;
            c1 =(int) col(x);
            y = fu(x);
            f1 = (int)fil(y);
            for(int k=1;k< n;k++)
            {
                x = xi + k * h;
                y = fu(x);
                c =(int) col(x);
                f = (int) fil(y);

                g.DrawLine(Pens.Blue, c1, f1, c, f);
                c1 = c;
                f1 = f;
            }
        }
        public double fu(double x)
        {
            double ys;
            ys = Math.Cos(x);
            return ys;
        }
        public double col(double x)
        {
            double c = ((xf - x) * ci) / (xf - xi) + ((x - xi) * cf) / (xf - xi);
            return c;
        }

        public double fil(double y)
        {
            double f = ((yf - y) * ff) / (yf - yi) + ((y - yi) * fi) / (yf - yi);
            return f;
        }


    }
}
