using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Mi_Album_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void tabla1BindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.tabla1BindingSource.EndEdit();
            this.tableAdapterManager.UpdateAll(this.album_2DataSet);

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: esta línea de código carga datos en la tabla 'album_2DataSet.Tabla1' Puede moverla o quitarla según sea necesario.
            this.tabla1TableAdapter.Fill(this.album_2DataSet.Tabla1);

        }

        private void nombreLabel_Click(object sender, EventArgs e)
        {

        }

        private void nombreTextBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void imagenPictureBox_Click(object sender, EventArgs e)
        {

            OpenFileDialog ar = new OpenFileDialog();
            ar.Title = "Open Picture";
            ar.FileName = ".jpg";
            ar.Filter = "All Files |*.*";
            ar.ShowDialog();
            imagenPictureBox.Image = System.Drawing.Image.FromFile(ar.FileName);

        }

        private void imagenLabel_Click(object sender, EventArgs e)
        {

        }
    }
}
