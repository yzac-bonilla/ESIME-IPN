
    #include <stdio.h>
    #include <conio.h>    
    #include <stdlib.h>
    #include <iostream>
    #include <math.h>
    
    using namespace std;
    
    class Matriz
          {
                private:
                        int R,C,NI;
                        double **AptMat,*X,*b,*X0,E;
                public:
                        Matriz(int r=2,int c=2,int ni=2,double Ep=0.001);
                        void Leer(void);
                        bool Dominante(void);
                        void Gauss_Seidel(void);
                        void Imprimir(void)const;
                        ~Matriz(void);
          };
          
    Matriz::Matriz(int r, int c,int ni,double Ep)
       {
             R=(r<1)?2:r;
             C=(c<1)?2:c;
             NI=ni;
             E=Ep;
             X=new double[C];
                  *X=0.0;
             X0=new double[R];
                  *X0=0.0;
             b=new double[R];
                  *b=0.0;
             AptMat=new double *[R];
             for(int i=0;i<R;i++)
                 AptMat[i]=new double [C];
             for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                   AptMat[i][j]=0.0;
       }
                      
     Matriz::~Matriz(void)
       {
             for(int i=0;i<R;i++)
                 delete []AptMat[i];
             delete []AptMat;
             delete []X;
             delete []b;
             delete []X0;
       }      
       
      void Matriz::Leer(void)
       {
              cout<<"\n\n\n\t\tIngresa los valores de la Matriz A:\n\t\t"; 
              for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                   {
                      cout<<"\n\t\ta "<<"["<<i<<"]"<<"["<<j<<"] = ";
                      cin>>AptMat[i][j];
                   }
              cout<<"\n\n\n\t\tIngresa los valores del Vector B:\n\t\t";
                 for(int i=0;i<R;i++)
                     {
                         cout<<"\n\t\tb "<<"["<<i<<"] = ";
                         cin>>b[i];
                     }
              cout<<"\n\n\n\t\tIngresa la aproximacion inicial:\n\t\t ";
              for(int i=0;i<R;i++)
                {
                     cout<<"\n\t\tX0 "<<"["<<i<<"] = ";
                     cin>>X0[i];
                }
              cout<<"\n\n\n\t\tIngresa el numero de iteraciones: ";
              cin>>NI;
              cout<<"\n\n\n\t\tIngresa el epsilon: ";
              cin>>E;
       } 
       
     void Matriz::Imprimir(void)const
       {
            system("cls");
            cout<<"\n\n\t\tMatriz A: ";
            for(int i=0;i<R;i++)
               {
                cout<<"\n\n\t\t ";
                for(int j=0;j<C;j++)
                    cout<<"  "<<AptMat[i][j];
               }
            cout<<endl;
            cout<<"\n\n\t\tVector B: ";
            for(int i=0;i<R;i++)
                cout<<"\n\n\t\t "<<b[i];
            cout<<endl;
       }
       
     bool Matriz::Dominante(void)
       {
            double s;
            for(int i=0;i<R;i++)
               {
                    s=0;
                    for(int j=0;j<C;j++)
                        if(i!=j)
                           s=s+AptMat[i][j];
                    if(AptMat[i][i] > s)
                       return 1;
                    else 
                       return 0;
               }         
       }  
       
     void Matriz::Gauss_Seidel(void)
          {      
                  bool Bandera;
                  char resp;
                  int k;
                  Bandera=Dominante();
                  if(Bandera==0)
                    {
                         cout<<"\n\n\t\tLa matriz no es dominante ¿Deseas intentarlo? (s/n): ";
                         cin>>resp;
                         if(resp=='N')
                            exit(1);
                    }
                  for(k=1;k<=NI;k++)
                    {
                          double s;
                          for(int i=0;i<R;i++)
                              {
                                   s=0;
                                   for(int j=0;j<C;j++)
                                      {
                                           if(i!=j)
                                             {
                                                if(i<j)
                                                  s=s+AptMat[i][j]*X0[j];
                                                else
                                                  s=s+AptMat[i][j]*X[j];
                                             }
                                      }
                                   X[i]=(b[i]-s)/AptMat[i][i];
                              }
                          bool B=0;
                          for(int i=0;i<R;i++)
                            {
                                  if(fabs(X[i]-X0[i]) > E)
                                     B=1;
                            }
                          if(B == 0)
                            {
                                  cout<<"\n\n\t\tDespues de "<<k<<"iteraciones, la solucion es :\n";
                                  for(int i=0;i<R;i++)
                                       cout<<"\n\n\t\tX["<<i<<"] = "<<X[i];
                                  cout<<endl<<endl;
                                  system("pause");
                                  exit(1);
                            }
                          for(int i=0;i<R;i++)  
                                  X0[i]=X[i];      
                    } 
                 cout<<"\n\n\t\tNo encontre solucion"<<endl<<endl;
                 system("pause");
                 exit(1);                          
          }
 
     void Leer(int &RefR,int &RefC);
     
     int main(void)
      {
            int Ren,Col;
            
            Matriz *AptM1;
            Leer(Ren,Col);
            AptM1=new Matriz(Ren,Col);
            
            AptM1->Leer();
            AptM1->Imprimir();
            AptM1->Gauss_Seidel();
            
            delete AptM1;
            system("pause");
            return(0);
      }
      
    void Leer(int &RefR,int &RefC)
       {
               cout<<"\n\n\n\t\tMETODO DE GAUSS-SEIDEL"
               <<"\n\n\n\t\tDatos de la matriz A:"
               <<"\n\n\t\tIngresa el Numero de Renglones = ";
               cin>>RefR;
               cout<<"\n\t\tIngresa el Numero de Columnas = ";
               cin>>RefC;
       }
