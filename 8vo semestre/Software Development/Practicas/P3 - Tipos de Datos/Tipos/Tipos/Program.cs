using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tipos
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("\n\tTIPOS DE DATOS Y SUS TAMAÑOS");
            Console.WriteLine("\n\tTIPO: int | TAMAÑO: {0} Bytes | RANGO[{1},{2}]", sizeof(int), int.MinValue, int.MaxValue);
            Console.WriteLine("\n\tTIPO: double | TAMAÑO: {0} Bytes | RANGO[{1},{2}]", sizeof(double), double.MinValue, double.MaxValue);
            Console.WriteLine("\n\tTIPO: float | TAMAÑO: {0} Bytes | RANGO[{1},{2}]", sizeof(float), float.MinValue, float.MaxValue);
            Console.WriteLine("\n\tTIPO: uint | TAMAÑO: {0} Bytes | RANGO[{1},{2}]", sizeof(uint), uint.MinValue, uint.MaxValue);
            Console.WriteLine("\n\tTIPO: long | TAMAÑO: {0} Bytes | RANGO[{1},{2}]", sizeof(long), long.MinValue, long.MaxValue);
            Console.WriteLine("\n\tTIPO: short | TAMAÑO: {0} Bytes | RANGO[{1},{2}]", sizeof(short), short.MinValue, short.MaxValue);
            Console.WriteLine("\n\tTIPO: ushort | TAMAÑO: {0} Bytes | RANGO[{1},{2}]", sizeof(ushort), ushort.MinValue, ushort.MaxValue);
            Console.WriteLine("\n\tTIPO: char | TAMAÑO: {0} Bytes | RANGO[{1},{2}]", sizeof(char), char.MinValue, char.MaxValue);
            Console.WriteLine("\n\tTIPO: decimal | TAMAÑO: {0} Bytes | RANGO[{1},{2}]", sizeof(decimal), decimal.MinValue, decimal.MaxValue);
            Console.ReadKey();
        }
    }
}
