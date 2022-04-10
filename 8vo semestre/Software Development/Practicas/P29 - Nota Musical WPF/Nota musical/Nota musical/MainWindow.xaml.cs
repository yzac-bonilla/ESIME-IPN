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
            textBox.Text = frecuencia(4, 8).ToString();

        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            System.Diagnostics.Process.Start(@"Firma con WPF.exe");
        }
    }
}
