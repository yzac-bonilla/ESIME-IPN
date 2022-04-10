﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using info.lundin.math;

namespace Funcion_Exponencial
{
    public partial class Form1 : Form
    {
        public double x, y, z;

        public Form1()
        {
            InitializeComponent();
        }

        private void seno_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdatoX.Text);
            y = Math.Sin(x);
            lBsalida.Items.Add(y.ToString());
        }

        private void coseno_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdatoX.Text);
            y = Math.Cos(x);
            lBsalida.Items.Add(y.ToString());
        }

        private void button3_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdatoX.Text);
            y = Math.Sinh(x);
            lBsalida.Items.Add(y.ToString());
        }

        private void cos_h_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdatoX.Text);
            y = Math.Cosh(x);
            lBsalida.Items.Add(y.ToString());
        }

        private void aseno_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdatoX.Text);
            y = Math.Asin(x);
            lBsalida.Items.Add(y.ToString());
        }

        private void acoseno_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdatoX.Text);
            y = Math.Acos(x);
            lBsalida.Items.Add(y.ToString());
        }

        private void tan_h_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdatoX.Text);
            y = Math.Tanh(x);
            lBsalida.Items.Add(y.ToString());
        }

        private void log_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdatoX.Text);
            y = Math.Log10(x);
            lBsalida.Items.Add(y.ToString());
        }

        private void resta_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdatoX.Text);
            y = double.Parse(tBdatoY.Text);
            z = x - y;
            lBsalida.Items.Add(z.ToString());
        }

        private void multiplicacion_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdatoX.Text);
            y = double.Parse(tBdatoY.Text);
            z = x * y;
            lBsalida.Items.Add(z.ToString());
        }

        private void division_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdatoX.Text);
            y = double.Parse(tBdatoY.Text);
            if(y==0)
                lBsalida.Items.Add("Indeterminación");
            else
            {
                z = x / y;
                lBsalida.Items.Add(z.ToString());
            }
        }

        private void Firma_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start(@"Bonilla.exe");
        }

        private void tan_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdatoX.Text);
            y = Math.Tan(x);
            lBsalida.Items.Add(y.ToString());
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string fx = textBox1.Text;
            y = fu(x, fx);
            lBsalida.Items.Add(y);
        }

        double fu(double x,string fx)
        {
            ExpressionParser ec = new ExpressionParser();
            ec.Values.Add("x", x);
            return (ec.Parse(fx));
        }

        private void button2_Click(object sender, EventArgs e)
        {
            lBsalida.Items.Clear();
        }

        private void suma_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdatoX.Text);
            y = double.Parse(tBdatoY.Text);
            z = x + y;
            lBsalida.Items.Add(z.ToString());
        }

        private void exp_Click(object sender, EventArgs e)
        {
            x = double.Parse(tBdatoX.Text);
            y = Math.Exp(x);
            lBsalida.Items.Add(y.ToString());
        }
    }
}
