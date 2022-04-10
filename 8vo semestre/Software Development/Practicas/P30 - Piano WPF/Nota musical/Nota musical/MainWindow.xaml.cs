using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Nota_musical
{
    /// <summary>
    /// Lógica de interacción para MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        double y;
        double frecuencia(double Nota, double Octava)
        {
            y = 440*(Math.Exp((Octava-4)+((Nota-10)/12)*Math.Log10(2)));
            return (y);
        }
        public MainWindow()
        {
            InitializeComponent();
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            System.Media.SoundPlayer Sonido = new System.Media.SoundPlayer();
            Sonido.SoundLocation=(@"piano-a.wav");
            Sonido.Load();
            Sonido.Play();
            textBox.Text = frecuencia(1, 8).ToString();
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            System.Media.SoundPlayer Sonido = new System.Media.SoundPlayer();
            Sonido.SoundLocation = (@"piano-b.wav");
            Sonido.Load();
            Sonido.Play();
            textBox.Text = frecuencia(2, 8).ToString();
        }

        private void button2_Click(object sender, RoutedEventArgs e)
        {
            System.Media.SoundPlayer Sonido = new System.Media.SoundPlayer();
            Sonido.SoundLocation = (@"piano-bb.wav");
            Sonido.Load();
            Sonido.Play();
            textBox.Text = frecuencia(3, 8).ToString();
        }

        private void button3_Click(object sender, RoutedEventArgs e)
        {
            System.Media.SoundPlayer Sonido = new System.Media.SoundPlayer();
            Sonido.SoundLocation = (@"piano-c#.wav");
            Sonido.Load();
            Sonido.Play();
            textBox.Text = frecuencia(4, 8).ToString();
        }

        private void button4_Click(object sender, RoutedEventArgs e)
        {
            System.Media.SoundPlayer Sonido = new System.Media.SoundPlayer();
            Sonido.SoundLocation = (@"piano-c.wav");
            Sonido.Load();
            Sonido.Play();
            textBox.Text = frecuencia(5, 8).ToString();
        }

        private void button5_Click(object sender, RoutedEventArgs e)
        {
            System.Media.SoundPlayer Sonido = new System.Media.SoundPlayer();
            Sonido.SoundLocation = (@"piano-d.wav");
            Sonido.Load();
            Sonido.Play();
            textBox.Text = frecuencia(6, 8).ToString();
        }

        private void button6_Click(object sender, RoutedEventArgs e)
        {
            System.Media.SoundPlayer Sonido = new System.Media.SoundPlayer();
            Sonido.SoundLocation = (@"piano-e.wav");
            Sonido.Load();
            Sonido.Play();
            textBox.Text = frecuencia(7, 8).ToString();
        }

        private void button7_Click(object sender, RoutedEventArgs e)
        {
            System.Media.SoundPlayer Sonido = new System.Media.SoundPlayer();
            Sonido.SoundLocation = (@"piano-eb.wav");
            Sonido.Load();
            Sonido.Play();
            textBox.Text = frecuencia(8, 8).ToString();
        }

        private void button8_Click(object sender, RoutedEventArgs e)
        {
            System.Media.SoundPlayer Sonido = new System.Media.SoundPlayer();
            Sonido.SoundLocation = (@"piano-f#.wav");
            Sonido.Load();
            Sonido.Play();
            textBox.Text = frecuencia(9, 8).ToString();
        }

        private void button9_Click(object sender, RoutedEventArgs e)
        {
            System.Media.SoundPlayer Sonido = new System.Media.SoundPlayer();
            Sonido.SoundLocation = (@"piano-f.wav");
            Sonido.Load();
            Sonido.Play();
            textBox.Text = frecuencia(10, 8).ToString();
        }

        private void button10_Click(object sender, RoutedEventArgs e)
        {
            System.Media.SoundPlayer Sonido = new System.Media.SoundPlayer();
            Sonido.SoundLocation = (@"piano-g#.wav");
            Sonido.Load();
            Sonido.Play();
            textBox.Text = frecuencia(11, 8).ToString();
        }

        private void button11_Click(object sender, RoutedEventArgs e)
        {
            System.Media.SoundPlayer Sonido = new System.Media.SoundPlayer();
            Sonido.SoundLocation = (@"piano-g.wav");
            Sonido.Load();
            Sonido.Play();
            textBox.Text = frecuencia(12, 8).ToString();
        }

        private void button12_Click(object sender, RoutedEventArgs e)
        {
            System.Diagnostics.Process.Start(@"Firma con WPF.exe");
        }
    }
}
