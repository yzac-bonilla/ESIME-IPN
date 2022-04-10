using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Pelota
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Graphics gra = pictureBox1.CreateGraphics();
            int x = 0, y = 0, dx = 1, dy = 1;

            for (int i = 0; i < 10000; i++)
            {
                if (x < 0 || x > pictureBox1.Width - 10)
                {
                    dx = -dx;
                }
                if (y < 0 || y > pictureBox1.Height - 10)
                {
                    dy = -dy;
                }
                x = x + dx;
                y = y + dy;
                for (int j = 0; j < 15; j++)
                {
                    gra.FillEllipse(Brushes.White, x, y, 10, 10);
                }
                gra.FillEllipse(Brushes.Black, x, y, 10, 10);
            } 
        }

        private void button2_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start(@"Bonilla.exe");
        }
    }
}
