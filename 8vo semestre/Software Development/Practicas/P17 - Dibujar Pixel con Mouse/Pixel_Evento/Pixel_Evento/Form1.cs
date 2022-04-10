using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Pixel_Evento
{
    public partial class Form1 : Form
    {
        bool click;
        public Form1()
        {
            InitializeComponent();
        }

        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            click = true;
            Graphics q = pictureBox1.CreateGraphics();
            q.DrawLine(Pens.Black, e.X, e.Y, e.X + 1, e.Y);
        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
        {
            click = false;
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            Graphics q = pictureBox1.CreateGraphics();
            if (click) q.DrawLine(Pens.Black, e.X, e.Y, e.X + 1, e.Y);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Graphics q = pictureBox1.CreateGraphics();
            Pen lapiz = new Pen(Color.White);
            Random aleatorio = new Random();
            int x, y;
            for (int n = 1000, k = 0; k < n; k++)
            {
                x = aleatorio.Next(pictureBox1.Width - 1);
                y = aleatorio.Next(pictureBox1.Height);
                Color col_aletorio = Color.FromArgb(100, aleatorio.Next(255), aleatorio.Next(255), aleatorio.Next(255));
                lapiz.Color = col_aletorio;
                q.DrawLine(lapiz, x, y, x + 1, y);
            } 
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Graphics q = pictureBox1.CreateGraphics();
            Pen lapiz = new Pen(Color.White);
            Random aleatorio = new Random();
            int x, y;
            for (int n = 1, k = 0; k < n; k++)
            {
                x = aleatorio.Next(pictureBox1.Width);
                y = aleatorio.Next(pictureBox1.Height);
                Color col_aletorio = Color.FromArgb(100, aleatorio.Next(255), aleatorio.Next(255), aleatorio.Next(255));
                lapiz.Color = col_aletorio;
                q.DrawLine(lapiz, x, y, aleatorio.Next(pictureBox1.Width - x), aleatorio.Next(pictureBox1.Height - y));
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Graphics q = pictureBox1.CreateGraphics();
            Pen lapiz = new Pen(Color.White);
            Random aleatorio = new Random();
            Rectangle rect = new Rectangle();
            for (int n = 1, k = 0; k < n; k++)
            {
                rect.X = aleatorio.Next(pictureBox1.Width);
                rect.Y = aleatorio.Next(pictureBox1.Height);
                rect.Width = aleatorio.Next(pictureBox1.Width - rect.X);
                rect.Height = aleatorio.Next(pictureBox1.Height - rect.Y);
                Color col_aletorio = Color.FromArgb(100, aleatorio.Next(255), aleatorio.Next(255), aleatorio.Next(255));
                lapiz.Color = col_aletorio;
                q.DrawRectangle(lapiz, rect);
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Graphics q = pictureBox1.CreateGraphics();
            Pen lapiz = new Pen(Color.White);
            Random aleatorio = new Random();
            Rectangle rect = new Rectangle();
            for (int n = 1, k = 0; k < n; k++)
            {
                rect.X = aleatorio.Next(pictureBox1.Width);
                rect.Y = aleatorio.Next(pictureBox1.Height);
                if ((pictureBox1.Height - rect.Y) > (pictureBox1.Width - rect.X))
                {
                    rect.Width = rect.Height = aleatorio.Next(pictureBox1.Width - rect.X);
                }
                else
                {
                    rect.Width = rect.Height = aleatorio.Next(pictureBox1.Height - rect.Y);
                }
                Color col_aletorio = Color.FromArgb(100, aleatorio.Next(255), aleatorio.Next(255), aleatorio.Next(255));
                lapiz.Color = col_aletorio;
                q.DrawEllipse(lapiz, rect);
            }       
        }

        private void button5_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start(@"Bonilla.exe");
        }

        private void button6_Click(object sender, EventArgs e)
        {
            pictureBox1.Refresh();
        }
    }
}
