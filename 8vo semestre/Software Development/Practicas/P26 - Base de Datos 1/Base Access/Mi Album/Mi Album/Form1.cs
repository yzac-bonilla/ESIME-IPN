using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Mi_Album
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void alumnoBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.alumnoBindingSource.EndEdit();
            this.tableAdapterManager.UpdateAll(this.albumDataSet);

        }

        private void alumnoBindingNavigatorSaveItem_Click_1(object sender, EventArgs e)
        {
            this.Validate();
            this.alumnoBindingSource.EndEdit();
            this.tableAdapterManager.UpdateAll(this.albumDataSet);

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: esta línea de código carga datos en la tabla 'albumDataSet.Alumno' Puede moverla o quitarla según sea necesario.
            this.alumnoTableAdapter.Fill(this.albumDataSet.Alumno);

        }
    }
}
