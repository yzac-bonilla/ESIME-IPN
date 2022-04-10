using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Figuras_Eventos
{
    public partial class Form1 : Form
    {
        bool punto, linea, rectangulo, circulo, click=true;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            punto = true;
            linea = rectangulo = circulo = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            linea = true;
            punto = rectangulo = circulo = false;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            rectangulo = true;
            punto = linea = circulo = false;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            circulo = true;
            punto = linea = rectangulo = false;
        }

        int x1, y1, x2, y2;
        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            Graphics obj_gra = pictureBox1.CreateGraphics();
            Rectangle obj_rect = new Rectangle();

            if (click)
            {
                x1 = e.X;
                y1 = e.Y;
                click=false;

                if (punto)
                {
                    obj_gra.DrawLine(Pens.Blue, x1, y1, x1 + 1, y1);
                    click=true;
                }
            }
            else
            {
                x2 = e.X;
                y2 = e.Y;
                click = true;

                
                if (x2 > x1)
                {
                    obj_rect.X = x1;
                    obj_rect.Width = x2 - x1;
                }
                else
                {
                    obj_rect.X = x2;
                    obj_rect.Width = x1 - x2;
                }

                if (y2 > y1)
                {
                    obj_rect.Y = y1;
                    obj_rect.Height = y2 - y1;
                }
                else
                {
                    obj_rect.Y = y2;
                    obj_rect.Height = y1 - y2;
                }

                if (linea)
                {
                    obj_gra.DrawLine(Pens.Red, x1, y1, x2 + 1, y2);
                }
                else if (rectangulo)
                {
                    obj_gra.DrawRectangle(Pens.Green, obj_rect);
                }
                else if (circulo)
                {
                    obj_gra.DrawEllipse(Pens.Fuchsia, obj_rect);
                }
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
