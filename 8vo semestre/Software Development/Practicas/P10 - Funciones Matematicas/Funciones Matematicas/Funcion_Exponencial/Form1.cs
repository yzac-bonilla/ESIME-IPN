using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Funcion_Exponencial
{
    public partial class Form1 : Form
    {
        public double x, y;

        public Form1()
        {
            InitializeComponent();
        }

        private void seno_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdato.Text);
            y = Math.Sin(x);
            lBsalida.Items.Add(y.ToString());
        }

        private void coseno_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdato.Text);
            y = Math.Cos(x);
            lBsalida.Items.Add(y.ToString());
        }

        private void button3_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdato.Text);
            y = Math.Sinh(x);
            lBsalida.Items.Add(y.ToString());
        }

        private void cos_h_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdato.Text);
            y = Math.Cosh(x);
            lBsalida.Items.Add(y.ToString());
        }

        private void aseno_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdato.Text);
            y = Math.Asin(x);
            lBsalida.Items.Add(y.ToString());
        }

        private void acoseno_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdato.Text);
            y = Math.Acos(x);
            lBsalida.Items.Add(y.ToString());
        }

        private void tan_h_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdato.Text);
            y = Math.Tanh(x);
            lBsalida.Items.Add(y.ToString());
        }

        private void log_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdato.Text);
            y = Math.Log10(x);
            lBsalida.Items.Add(y.ToString());
        }

        private void tan_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdato.Text);
            y = Math.Tan(x);
            lBsalida.Items.Add(y.ToString());
        }

        private void Firma_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start(@"Bonilla.exe");
        }

        private void exp_Click(object sender, EventArgs e)
        {
            lBsalida.Items.Clear();
            x = double.Parse(tBdato.Text);
            y = Math.Exp(x);
            lBsalida.Items.Add(y.ToString());
        }
    }
}
