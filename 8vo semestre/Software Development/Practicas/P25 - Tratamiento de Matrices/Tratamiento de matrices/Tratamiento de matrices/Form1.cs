using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tratamiento_de_matrices
{
    public partial class Form1 : Form
    {
        int ma;
        int na;
        string[] fila;
        Matrices MatA;

        public Form1()
        {
            InitializeComponent();

        }

        private void button1_Click(object sender, EventArgs e)
        {
            ma = int.Parse(textBox2.Text);
            na = int.Parse(textBox3.Text);
            Leer_A();
        }

        public void Leer_A()
        {
            Matrices MatA = new Matrices(ma, na);
            for (int i = 0; i < ma; i++)
            {
                fila = textBox1.Lines.ElementAt(i).Split(' ');
                for (int j = 0; j < na; j++)
                    MatA.A[i, j] = double.Parse(fila[j]);
            }
        }

        public void Leer_B()
        {
            Matrices MatB = new Matrices(ma, na);
            for (int i = 0; i < ma; i++)
            {
                fila = textBox1.Lines.ElementAt(i).Split(' ');
                for (int j = 0; j < na; j++)
                    MatB.A[i, j] = double.Parse(fila[j]);
            }
        }
        string aux;
        public void Poner_A()
        {
            
            for (int i = 0; i < ma; i++)
            {
                aux = " ";
                for (int j = 0; j < na; j++)
                    aux = aux + MatA.A[i, j] + "";
            }
            listBox1.Items.Add(aux);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Poner_A();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start(@"Bonilla.exe");
        }
    }
}
