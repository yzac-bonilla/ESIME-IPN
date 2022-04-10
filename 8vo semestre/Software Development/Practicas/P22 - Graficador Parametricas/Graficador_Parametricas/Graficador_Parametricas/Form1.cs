using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using info.lundin.math;

namespace Graficador_Parametricas
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
            string funcionF = textBox1.Text;
            string funcionG = textBox2.Text;

            double xf, xi, x, yf, yi, y, cf, ci, cr, c, ff, fi, fr, f, t, h;

            xf = Double.Parse(textBox3.Text);
            xi = Double.Parse(textBox4.Text);
            yf = Double.Parse(textBox5.Text);
            yi = Double.Parse(textBox6.Text);
            ci = 0;
            fi = 0;
            cf = pictureBox1.Width;
            ff = pictureBox1.Height;
            h = (xf - xi) / (cf - ci);

            t = xi;
            x = evaluar(t, funcionF);
            y = evaluar(t, funcionG);
            cr = col(x, xf, xi, cf, ci);
            fr = fil(y, yf, yi, ff, fi);



            for (t = xi + h; t <= xf; t += h)
            {
                
                x = evaluar(t,funcionF);
                y = evaluar(t, funcionG);
                c = col(x, xf, xi, cf, ci);
                f = fil(y, yf, yi, ff, fi);

                q.DrawLine(Pens.OrangeRed, (float)cr, (float)fr, (float)c, (float)f);
                cr = c;
                fr = f;

            }
        }

        double evaluar(double t, string funcion)
        {
            ExpressionParser ecu = new ExpressionParser();
            ecu.Values.Add("t", t);
            return (ecu.Parse(funcion));
        }


        double col(double x, double xf, double xi, double cf, double ci)
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
