using System;
using System.Drawing;
using System.Windows.Forms;
using info.lundin.math;

namespace Graficador_Polares
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Graphics q = pictureBox1.CreateGraphics();
            string funcion = textBox1.Text;

            double xf, xi, x, yf, yi, y, cf, ci,cr, c, ff, fi, fr, f,r,angulo,h;

            xf = Double.Parse(textBox2.Text);
            xi = Double.Parse(textBox3.Text);
            yf = Double.Parse(textBox4.Text);
            yi = Double.Parse(textBox5.Text);
            ci = 0;
            fi = 0;
            cf = pictureBox1.Width;
            ff = pictureBox1.Height;
            h = (xf - xi) / (cf - ci);
            
            angulo = xi;
            r = evaluar(angulo, funcion);
            x = r * Math.Cos(angulo);
            y = r * Math.Sin(angulo);
            cr = col(x, xf, xi, cf, ci);
            fr = fil(y, yf, yi, ff, fi);
            
            for (angulo = xi + h; angulo <= xf; angulo += h)
            {
                r = evaluar(angulo, funcion);
                x = r * Math.Cos(angulo);
                y = r * Math.Sin(angulo);
                c = col(x, xf, xi, cf, ci);
                f = fil(y, yf, yi, ff, fi);

                q.DrawLine(Pens.Fuchsia, (float)cr, (float)fr, (float)c, (float)f);
                cr = c;
                fr = f;

            }

        }

        double evaluar(double angulo, string funcion)
        {
            ExpressionParser ecu = new ExpressionParser();
            ecu.Values.Add("t", angulo);
            return (ecu.Parse(funcion));
        }


        double col(double x,double xf,double xi,double cf, double ci)
        {
            return (cf * (x - xi) + ci * (xf - x)) / (xf - xi);
        }

        double fil(double y, double yf, double yi, double ff, double fi)
        {
            return (ff * (yf - y) + fi * (y - yi)) / (yf - yi);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            pictureBox1.Refresh();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start(@"Bonilla.exe");
        }
    }
}
