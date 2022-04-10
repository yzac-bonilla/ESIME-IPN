using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Graficador_Figuras
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

            double xf, xi, x, yf, yi, y, cf, ci, cr, c, ff, fi, fr, f, t, h, amp1, amp2, w1, w2;

            amp1 = Double.Parse(textBox1.Text);
            amp2 = Double.Parse(textBox3.Text);
            w1 = Double.Parse(textBox2.Text);
            w2 = Double.Parse(textBox4.Text);
            xf = Double.Parse(textBox5.Text);
            xi = Double.Parse(textBox6.Text);
            yf = Double.Parse(textBox7.Text);
            yi = Double.Parse(textBox8.Text);
            ci = 0;
            fi = 0;
            cf = pictureBox1.Width;
            ff = pictureBox1.Height;
            h = (xf - xi) / (cf - ci);
            
            t= xi;
            x = amp1 * Math.Cos(w1 * t);
            y = amp2 * Math.Cos(w2 * t);
            cr = col(x, xf, xi, cf, ci);
            fr = fil(y, yf, yi, ff, fi);
            
            for (t = xi + h; t <= xf; t += h)
            {

                x = amp1 * Math.Cos(w1 * t);
                y = amp2 * Math.Cos(w2 * t);
                c = col(x, xf, xi, cf, ci);
                f = fil(y, yf, yi, ff, fi);

                q.DrawLine(Pens.PaleVioletRed, (float)cr, (float)fr, (float)c, (float)f);
                cr = c;
                fr = f;

            }
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
