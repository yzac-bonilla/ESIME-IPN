using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Graphics q = PB1.CreateGraphics();
            Random rnd = new Random();
            int x, y, r, g, b;
            Pen lapiz = new Pen(Color.White);
            for(int k=1;k<1000;k++)
            {
                x = rnd.Next(PB1.Width);
                y = rnd.Next(PB1.Height);
                r = rnd.Next(255);
                g = rnd.Next(255);
                b = rnd.Next(255);
                lapiz = new Pen(Color.FromArgb(100,r,g,b));
                q.DrawLine(lapiz, x, y, x + 1, y);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Graphics q = PB1.CreateGraphics();
            Random rnd = new Random();
            int x, y, r, g, b;
            Pen lapiz = new Pen(Color.White);
            for (int k = 1; k < 10; k++)
            {
                x = rnd.Next(PB1.Width);
                y = rnd.Next(PB1.Height);
                r = rnd.Next(255);
                g = rnd.Next(255);
                b = rnd.Next(255);
                lapiz = new Pen(Color.FromArgb(100, r, g, b));
                Point[] points =
                {
                    new Point(x,  y),
                    new Point(10, 100),
                    new Point(200,  50),
                    new Point(250, 300)
                 };
                q.DrawLines(lapiz, points);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Graphics q = PB1.CreateGraphics();
            Random rnd = new Random();
            int x, y, r, g, b;
            Pen lapiz = new Pen(Color.White);
            for (int k = 1; k < 10; k++)
            {
                x = rnd.Next(PB1.Width);
                y = rnd.Next(PB1.Height);
                r = rnd.Next(255);
                g = rnd.Next(255);
                b = rnd.Next(255);
                lapiz = new Pen(Color.FromArgb(100, r, g, b));
                RectangleF[] rects =
                {
                     new RectangleF( x, y, x, y),
                     new RectangleF(100.0F, 200.0F, 250.0F,  50.0F),
                     new RectangleF(300.0F,   0.0F,  50.0F, 100.0F)
                };
                q.DrawRectangles(lapiz,rects);
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Graphics q = PB1.CreateGraphics();
            Random rnd = new Random();
            int x, y, r, g, b;
            Pen lapiz = new Pen(Color.White);
            for (int k = 1; k < 10; k++)
            {
                x = rnd.Next(PB1.Width);
                y = rnd.Next(PB1.Height);
                r = rnd.Next(255);
                g = rnd.Next(255);
                b = rnd.Next(255);
                lapiz = new Pen(Color.FromArgb(100, r, g, b));
                q.DrawEllipse(lapiz, x, y, x,y);
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start(@"Bonilla.exe");
        }

        private void button6_Click(object sender, EventArgs e)
        {
            PB1.Refresh();
        }
    }
}
