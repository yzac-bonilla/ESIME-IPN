
    #include <stdio.h>
    #include <conio.h>    
    #include <stdlib.h>
    #include <iostream>
    #include <math.h>
    #include <E:\include\Inversa.h>
    
    using namespace std;
    
    double fxy(double &x,double &y);
    double gxy(double &x,double &y);
    
    class Matriz
          {
                private:
                        int NI;
                        double **F,**J,*X,*Y,*X0,E;
                public:
                        Matriz(void);
                        void Leer(void);
                        void dfxy(double &x,double &y);
                        void dgxy(double &x,double &y);
                        void Newton(void);
                        void Imprimir(void)const;
                        ~Matriz(void);
          };
          
    Matriz::Matriz(void)
       {
             X=new double[2];
                  *X=0.0;
             Y=new double[2];
                  *Y=0.0;
             X0=new double[2];
                  *X0=0.0;
                       
             F=new double *[2];
             for(int i=0;i<2;i++)
                 F[i]=new double [2];
             for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                   F[i][j]=0.0;
                   
             J=new double *[2];
             for(int i=0;i<2;i++)
                 J[i]=new double [2+2];
             for(int i=0;i<2;i++)
                for(int j=0;j<2+2;j++)
                   J[i][j]=0.0;
       }
                      
     Matriz::~Matriz(void)
       {
             for(int i=0;i<2;i++)
                 delete []F[i];
             delete []F;
             for(int i=0;i<2;i++)
                 delete []J[i];
             delete []J;
             delete []X;
             delete []Y;
             delete []X0;
       }      
       
      void Matriz::Leer(void)
       {
              cout<<"\n\n\n\t\tMETODO DE NEWTON"<<endl
              <<"\n\n\t\tIngresa el Punto Inicial X0 (x,y):\n\t\t";
              for(int i=0;i<2;i++)
               {
                  cout<<"\n\t\tX0 "<<"["<<i<<"] = ";
                  cin>>X0[i];
               }   
              cout<<"\n\n\n\t\tIngresa el numero de Iteraciones: "; 
              cin>>NI;
              cout<<"\n\n\n\t\tIngresa el Epsilon: ";
              cin>>E;
       }            
      
     void Matriz::Imprimir(void)const
       {
            system("cls");
            cout<<"\n\n\n  ECUACIONES (Matriz F): "
            <<"\n\n\t\t2x + Cos(y) = 0 "
            <<"\n\n\t\t2y - Sen(x) = 0 "
            <<endl<<endl;
       }
       
     double fxy(double &x,double &y)
       {
            return(2*x+cos(y));
       }
       
     double gxy(double &x,double &y)
       {
            return(2*y-sin(x));
       }
       
     void Matriz::dfxy(double &x,double &y)
       {
            J[0][0]=2;
            J[0][1]=-sin(y);
            J[0][2]=1.0;
            J[0][3]=0.0;
       }
       
     void Matriz::dgxy(double &x,double &y)
       {
            J[1][0]=-cos(x);
            J[1][1]=2;
            J[1][2]=0.0;
            J[1][3]=1.0;
       }
     
     void Matriz::Newton(void)
       {
            int z;
            Metodo *Apt;
            Apt=new Metodo;
            
            for(z=1;z<=NI;z++)
              {
                    cout<<"  Iteracion # "<<z<<"\n\n\t\tX0 = "<<X0[0]<<" , "<<X0[1];
                    //Mat J
                    dfxy(X0[0],X0[1]);
                    dgxy(X0[0],X0[1]);
                    cout<<"\n\n\t\tMatriz ampliada (J|I): ";
                    for(int i=0;i<2;i++)
                       {
                        cout<<"\n\n\t\t ";
                        for(int j=0;j<4;j++)
                            cout<<"  "<<J[i][j];
                       }
                    //mat J inversa
                    **J=Apt->Inversa(J);
                    //Mat F[X0]       
                    F[0][0]=fxy(X0[0],X0[1]);
                    F[1][0]=gxy(X0[0],X0[1]);
                    cout<<"\n\n\t\tMatriz F[X0]: ";
                    for(int i=0;i<2;i++)
                       {
                        cout<<"\n\n\t\t ";
                        for(int j=0;j<1;j++)
                            cout<<"  "<<F[i][j];
                       }
                    //Producto 
                    cout<<endl<<"\n\n\t\tProducto de J^-1 * F[X0]:";
                    for(int i=0;i<2;i++)
                       {    
                            double s=0;
                            for(int j=2;j<4;j++)
                                      s=s+J[i][j]*F[j-2][0];
                            Y[i]=s;
                            cout<<"\n\n\t\tY"<<i<<" = "<<Y[i];
                        }
                     cout<<endl<<endl;
                     //Calculando sol
                     for(int i=0;i<2;i++)
                       X[i]=X0[i]-Y[i];
                     //Verificando sol
                     bool b=1;
                     for(int i=0;i<2;i++)
                        {
                             if(fabs(X[i]-X0[i]) > E)
                                 b=0;
                        }
                     //Asignando nuevos valores a X0
                     for(int i=0;i<2;i++)
                       X0[i]=X[i];
                     //Imprimiendo sol
                     if(b == 1)
                        {
                             cout<<"\n\n  LA SOLUCION ES:\n\n";
                             for(int i=0;i<2;i++)
                                 cout<<"\t\tX["<<i<<"] = "<<X[i]<<endl<<endl;
                                 system("pause");
                                 exit(1);
                        } 
              }
            cout<<"\n\n  Despues de "<<z-1<<" iteraciones NO encontre solucion"<<endl<<endl;                    
       }
     
     int main(void)
      {
            Matriz *AptM;
            AptM=new Matriz;
            
            AptM->Leer();
            AptM->Imprimir();
            AptM->Newton();
            
            delete AptM;
            system("pause");
            return(0);
      }
                 
