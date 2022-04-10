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

        private void Firma_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start(@"Bonilla.exe");
        }

        private void exp_Click(object sender, EventArgs e)
        {
            lBsalida.Refresh();
            x = double.Parse(tBdato.Text);
            y = Math.Exp(x);
            lBsalida.Items.Add(y.ToString());
        }
    }
}
