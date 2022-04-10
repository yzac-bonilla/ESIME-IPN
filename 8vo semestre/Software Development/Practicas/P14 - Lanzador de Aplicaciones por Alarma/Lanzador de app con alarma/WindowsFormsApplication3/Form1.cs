using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            label1.Text = DateTime.Now.ToString("dd/MM/yyyy-hh:mm:ss:f");
            if (checkBox1.Checked)
            {
                if (label1.Text==textBox1.Text)
                {
                    System.Diagnostics.Process.Start(@"C:\Program Files (x86)\Internet Explorer\iexplore.exe");
                }
            }
            
            if (checkBox2.Checked)
            {
                if (label1.Text == textBox2.Text)
                {
                    System.Diagnostics.Process.Start(@"C:\Windows\notepad.exe");
                }
            }

            if (checkBox3.Checked)
            {
                if (label1.Text == textBox3.Text)
                {
                    System.Diagnostics.Process.Start(@"C:\Windows\system32\calc.exe");
                }
            }

            if (checkBox4.Checked)
            {
                if (label1.Text == textBox4.Text)
                {
                    System.Diagnostics.Process.Start(@"C:\Windows\explorer.exe");
                }
            }

            if (checkBox5.Checked)
            {
                if (label1.Text == textBox5.Text)
                {
                    System.Diagnostics.Process.Start(@"C:\Program Files (x86)\Adobe\Acrobat Reader DC\Reader\AcroRd32.exe");
                }
            }

            if (checkBox6.Checked)
            {
                if (label1.Text == textBox6.Text)
                {
                    System.Diagnostics.Process.Start(@"C:\Program Files (x86)\Google\Chrome\Application\chrome.exe");
                }
            }

            if (checkBox7.Checked)
            {
                if (label1.Text == textBox7.Text)
                {
                    System.Diagnostics.Process.Start(@"C:\Program Files\Windows Media Player\wmplayer.exe");
                }
            }

            if (checkBox8.Checked)
            {
                if (label1.Text == textBox8.Text)
                {
                    System.Diagnostics.Process.Start(@"C:\Program Files\Windows Defender\MSASCui.exe");
                }
            }

            if (checkBox9.Checked)
            {
                if (label1.Text == textBox9.Text)
                {
                    System.Diagnostics.Process.Start(@"C:\Program Files\Windows Journal\Journal.exe");
                }
            }

            if (checkBox10.Checked)
            {
                if (label1.Text == textBox10.Text)
                {
                    System.Diagnostics.Process.Start(@"C:\Program Files (x86)\Windows Photo Viewer\ImagingDevices.exe");
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start(@"Bonilla.exe");
        }
    }
}
