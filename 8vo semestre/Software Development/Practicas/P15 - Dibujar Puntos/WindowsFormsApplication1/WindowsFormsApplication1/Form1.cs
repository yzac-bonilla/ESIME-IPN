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
            for(int k=1;k<10000;k++)
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

        private void button2_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start(@"Bonilla.exe");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            PB1.Refresh();
        }
    }
}
