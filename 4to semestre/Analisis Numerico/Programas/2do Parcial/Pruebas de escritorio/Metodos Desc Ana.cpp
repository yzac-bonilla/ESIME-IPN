#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
using namespace std;

class MD
{
	private:
		double **a,*b,*x,*y,**L,**U,c;
		int n,i,j;
	public:
		MD(int N);
		~MD(void);
		void Leer(void);
		void Imprimir(void);
		void LU(void);
		void Cholesky(void);
	};

MD::MD(int N)
{
	n=N; i=j=0;
	
	a=new double*[n];
	for(i=0; i<n; i++)
	   a[i]=new double[n];
	   
	L=new double*[n];
	for(i=0; i<n; i++)
	   L[i]=new double[n];
	   
	U=new double*[n];
	for(i=0; i<n; i++)
	   U[i]=new double[n];
	   
	b=new double[n];
	x=new double[n];
	y=new double[n];
	
	for(i=0; i<n; i++)
	   x[i]=0;

	for(i=0; i<n; i++)
	   b[i]=0;
	   
	for(i=0; i<n; i++)
	   y[i]=0.0;
	
	for(i=0; i<n; i++)
	   for(j=0; j<n; j++)
		  a[i][j]=0.0;
		  
	for(i=0; i<n; i++)
	   for(j=0; j<n; j++)
		  L[i][j]=0.0;
		  
	for(i=0; i<n; i++)
	   for(j=0; j<n; j++)
		  U[i][j]=0.0;
	}

MD::~MD(void)
{
	for(i=0; i<n; i++)
	   delete []a[i];
	delete []a;
	
	for(i=0; i<n; i++)
	   delete []L[i];
	delete []L;
	
	for(i=0; i<n; i++)
	   delete []U[i];
	delete []U;
	
	delete []b;
	delete []x;
	}
	
void MD::Leer(void)
{
    cout << "\n Ingresa la matriz ampliada \n";
     for(i=0; i<n; i++)
       {
			cout << "\n";
              for(j=0; j<n; j++)
                {
                       cout << "     a[" << i <<"][" << j << "]= ";
                       cin >> a[i][j];
                       }
              cout << "     b" << i << " = ";
              cin >> b[i];

              }
        }
	
void MD::Imprimir(void)
{
            cout<<"\n\n";
            for(i=0;i<n;i++)
               {
                cout<<"\n\n\t\t ";
                for(j=0;j<n;j++)
                  {
                    cout<<"  " << a[i][j];
                  }
                cout << "  " << b[i];
               }
            cout<<"\n\n\t\t ";
       }

void MD::LU(void)
{
	double s=0;
	for(i=0; i<n; i++)
	   for(j=0; j<n; j++)
		  U[i][j]=a[i][j];


	//Hacer Matriz Identidad a L
	for(i=0; i<n; i++)
	   {
			for(j=0; j<n; j++)
			   {
					if(i==j)
					   L[i][j]=1;
					else
					   L[i][j]=0;
					}
			}
			
	//Metodo Gauss, para hacer matriz U
	for(i=0; i<n-1; i++)
	   {
			for(j=i+1; j<n; j++)
			   {
					if(U[i][i]!=0)
					   c=-(U[j][i]/U[i][i]);
					L[j][i]=-c;
					for(int k=0; k<n; k++)
					   U[j][k]=c*U[i][k]+U[j][k];
					}
			}
     
	
			
	//Imprimir Matriz U
	cout << "\n\n    Matriz U : \n";
     for(i=0;i<n;i++)
               {
                cout<<"\n\n\t\t ";
                for(j=0;j<n;j++)
                  {
                    cout<<"  " << U[i][j];
                  }
               }
            cout<<"\n\n";
    //Imprimir Matriz L
	cout << "\n\n    Matriz L : \n";
	for(i=0;i<n;i++)
               {
                cout<<"\n\n\t\t ";
                for(j=0;j<n;j++)
                  {
                    cout<<"  " << L[i][j];
                  }
               }
           cout << "\n\n";
               
               
	 //Resolver Ly=b
	for(i=0; i<n; i++)
	   {
            s=0;
	        for(j=i-1; j>=0; j--)
		       {
			    s=s+(L[i][j]*y[j]);
			   }
	        y[i]=(b[i]-s)/L[i][i];
			}
			
	//Resolver Ux=y; resultado final
	cout << "\n\n Valores de incognitas \n\n";
	for(int j=n-1;j>=0;j--)
        {
			s=0;
            for(int i=j+1;i<n;i++)
                s=s+U[j][i]*x[i];
            x[j]=(y[j]-s)/U[j][j];
            cout<<"\n  X[" << j << "] es = "<<x[j]<<endl;
                      }
     cout << "\n\n";

	}
	
void MD::Cholesky(void)
{
	double s=0;
	
	for(i=0; i<n; i++)
	   {
			for(j=0; j<n; j++)
			   {
					if(a[i][j]!=a[j][i])
					   {
							cout << "\n La Matriz Ingresada no es Simetrica, No se puede realizar el Metodo de Cholesky" << endl;
							system("pause");
							exit(0);
							}
					}
			}
	
	for(j=0; j<n; j++)
	   {
			s=0;
			for(int k=0; k<j; k++)
			   s=s+pow(L[j][k],2);
			L[j][j]=sqrt(a[j][j]-s);
			for(i=j+1; i<n; i++)
			   {
					s=0;
					for(int m=0; m<j; m++)
					   s=s+L[i][m]*L[j][m];
					L[i][j]=(a[i][j]-s)/L[j][j];
					}
			}

	for(i=0; i<n; i++)
	   {
			for(j=0; j<n; j++)
			   {
					U[j][i]=L[i][j];
					}
			}
			
	//Imprimir Matriz L
	cout << "\n\n    Matriz L : \n";
	for(i=0;i<n;i++)
               {
                cout<<"\n\n\t\t ";
                for(j=0;j<n;j++)
                  {
                    cout<<"  " << L[i][j];
                  }
               }
           cout << "\n\n";

    //Imprimir Matriz U
	cout << "\n\n    Matriz U : \n";
     for(i=0;i<n;i++)
               {
                cout<<"\n\n\t\t ";
                for(j=0;j<n;j++)
                  {
                    cout<<"  " << U[i][j];
                  }
               }
            cout<<"\n\n";
            
      //Resolver Ly=b
	for(i=0; i<n; i++)
	   {
            s=0;
	        for(j=i-1; j>=0; j--)
		       {
			    s=s+(L[i][j]*y[j]);
			   }
	        y[i]=(b[i]-s)/L[i][i];
			}

	//Resolver Ux=y; resultado final
	cout << "\n\n Valores de incognitas \n\n";
	for(int j=n-1;j>=0;j--)
        {
			s=0;
            for(int i=j+1;i<n;i++)
                s=s+U[j][i]*x[i];
            x[j]=(y[j]-s)/U[j][j];
            cout<<"\n  X[" << j << "] es = "<<x[j]<<endl;
                      }
     cout << "\n\n";
		  
	}
       
int main(void)
{
	int N;
	cout << " \n\n Da el numero de incognitas del SEL:  ";
	cin >> N;
	MD obj(N);
	obj.Leer();
	system("cls");
	cout << " \n Matriz Ingresada:  ";
	obj.Imprimir();
	//obj.LU();
	obj.Cholesky();
	system("pause");
	}
