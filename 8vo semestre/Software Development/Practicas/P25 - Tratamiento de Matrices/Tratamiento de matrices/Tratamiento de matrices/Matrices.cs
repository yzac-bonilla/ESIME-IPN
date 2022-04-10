using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tratamiento_de_matrices
{
    class Matrices
    {
        private int m, n;
        private double[,] a;

        public int M
        {
            set { m = value; }
            get { return (m); }
        }
        public int N
        {
            set { n = value; }
            get { return (n); }
        }
        public double[,] A
        {
            set { a = value; }
            get { return (a); }
        }

        public Matrices(int m, int n)
        {
            M = m;
            N = n;
            A = new double[m, n];
        }

        public double SumaElem()
        {
            double s = 0;
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                    s += A[i, j];
            }
            return (s);
        }
    }
}
