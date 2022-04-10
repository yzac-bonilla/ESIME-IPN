using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// La plantilla de elemento Página en blanco está documentada en http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace Calculadora
{
    /// <summary>
    /// Página vacía que se puede usar de forma independiente o a la que se puede navegar dentro de un objeto Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        double x, y, z;

        private void button_Copy1_Click(object sender, RoutedEventArgs e)
        {
            x = double.Parse(textBox1.Text);
            y = double.Parse(textBox2.Text);
            z = x - y;
            listBox.Items.Add(z.ToString());
        }

        private void button_Copy_Click(object sender, RoutedEventArgs e)
        {
            x = double.Parse(textBox1.Text);
            y = double.Parse(textBox2.Text);
            z = x * y;
            listBox.Items.Add(z.ToString());
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            x = double.Parse(textBox1.Text);
            y = double.Parse(textBox2.Text);
            z = x / y;
            listBox.Items.Add(z.ToString());
        }

        private void textBlock1_SelectionChanged(object sender, RoutedEventArgs e)
        {

        }

        public MainPage()
        {
            this.InitializeComponent();
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            x = double.Parse(textBox1.Text);
            y = double.Parse(textBox2.Text);
            z = x + y;
            listBox.Items.Add(z.ToString());
        }
    }
}
