
    #include <stdio.h>
    #include <conio.h>    
    #include <stdlib.h>
    #include <iostream>
    #include <math.h>
    
    using namespace std;
    
    class Matriz
          {
                private:
                        int R,C;
                        double **AptMat,**L,**U,*X,*Y,*b;
                public:
                        Matriz(int r=2,int c=2);
                        void Leer(void);
                        void Desc_LU(void);
                        void Imprimir(void)const;
                        ~Matriz(void);
          };
          
    Matriz::Matriz(int r, int c)
       {
             R=(r<1)?2:r;
             C=(c<1)?2:c;
             X=new double[C];
                  *X=0.0;
             Y=new double[C];
                  *Y=0.0;
             b=new double[R];
                  *b=0.0;
             AptMat=new double *[R];
             for(int i=0;i<R;i++)
                 AptMat[i]=new double [C];
             for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                   AptMat[i][j]=0.0;
                   
             L=new double *[R];
             for(int i=0;i<R;i++)
                 L[i]=new double [C];
             for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                   L[i][j]=0.0;
                   
             U=new double *[R];
             for(int i=0;i<R;i++)
                 U[i]=new double [C];
             for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                   U[i][j]=0.0;
       }
                      
     Matriz::~Matriz(void)
       {
             for(int i=0;i<R;i++)
                 delete []AptMat[i];
             delete []AptMat;
             for(int i=0;i<R;i++)
                 delete []L[i];
             for(int i=0;i<R;i++)
                 delete []U[i];
             delete []U;
             delete []L;
             delete []X;
             delete []Y;
             delete []b;
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
       
     void Matriz::Desc_LU(void)
          {       //inicializar mat L como mat identidad
                  for(int i=0;i<R;i++)
                     {
                       for(int j=0;j<R;j++)
                          {
                               if(i!=j)
                                 L[i][j]=0;
                               else
                                 L[i][j]=1;
                          }
                     }
                    //mat L inicial 
                    cout<<endl<<"\n\n\t\tMatriz L inicial: ";
                    for(int i=0;i<R;i++)
                       {
                        cout<<"\n\n\t\t ";
                        for(int j=0;j<C;j++)
                            cout<<"  "<<L[i][j];
                       }
                 //Hacer mat U = mat A    
                 for(int i=0;i<R;i++)
                  for(int j=0;j<C;j++)
                      U[i][j]=AptMat[i][j];
                  
                    cout<<endl;   
                  //mat U inicial
                    cout<<endl<<"\n\n\t\tMatriz U inicial: ";
                    for(int i=0;i<R;i++)
                       {
                        cout<<"\n\n\t\t ";
                        for(int j=0;j<C;j++)
                            cout<<"  "<<U[i][j];
                       }
                    cout<<endl;     
                  //Triangularizacion para U
                  double cte;
                  cout<<"\n\n\t\tTriangularizacion de U:\n\n";
                  for(int i=0;i<R-1;i++)
                     {
                       for(int j=i+1;j<R;j++)
                          {    
                               cte=-U[j][i]/U[i][i];
                               cout<<"\n\t\ti= "<<i<<endl
                               <<"\t\tC = -"<<U[j][i]<<" / "<<U[i][i]<<" = "<<cte<<endl
                               <<"\t\tL["<<j<<"]["<<i<<"] = "<<-cte<<endl;
                               L[j][i]=-cte;       //asignando valores a L
                               for(int k=0;k<C;k++)
                                {
                                  U[j][k]=U[j][k]+cte*U[i][k];
                                  cout<<"\t\tU"<<"["<<j<<"]"<<"["<<k<<"]"<<" = "
                                  <<U[j][k]<<" + "<<cte<<" * "<<U[i][k]<<" = " 
                                  <<U[j][k]<<endl; 
                                }
                          }
                     } 
                   //mat U Triangularizada
                    cout<<endl<<"\n\n\t\tMatriz U (Triangularizada): ";
                    for(int i=0;i<R;i++)
                       {
                        cout<<"\n\n\t\t ";
                        for(int j=0;j<C;j++)
                            cout<<"  "<<U[i][j];
                       }
                    cout<<endl;               
                  //mat L 
                    cout<<endl<<"\n\n\t\tMatriz L (construida con -C): ";
                    for(int i=0;i<R;i++)
                       {
                        cout<<"\n\n\t\t ";
                        for(int j=0;j<C;j++)
                            cout<<"  "<<L[i][j];
                       }
                    cout<<endl;   
                  //Solucion Ly=b
                  double s=0;
                  cout<<"\n\n\t\tLy=b:\n\n";
                  Y[0]=b[0];
                  cout<<"\n\t\tY0 = "<<b[0]<<endl<<endl; 
                  for(int i=1;i<R;i++)
                      {
                           s=0;
                           for(int j=0;j<C-1;j++)
                             {
                               if(i != j)
                               {
                                cout<<"\t\tS = "<<s<<" + "<<L[j][j]<<" * "<<L[i][j]<<" = ";
                                s=s+Y[j]*L[i][j];
                                cout<<s<<endl; 
                               }
                             }
                           Y[i]=b[i]-s;
                           cout<<"\n\t\tY"<<i<<" = "<<b[i]<<" - "<<s<<" = "<<Y[i]<<endl<<endl;    
                      }
                  cout<<endl;
                  //Solucion Ux=y por gauss
                  cout<<"\n\t\tUx=y: \n\n\t\tSOLUCION\n\n";
                  for(int j=R-1;j>=0;j--)
                      {
                           s=0;
                           for(int i=j+1;i<R;i++)
                                s=s+U[j][i]*X[i];
                           X[j]=(Y[j]-s)/U[j][j];
                           cout<<"\t\tX"<<j<<" = "<<X[j]<<endl<<endl;    
                      }
                  cout<<endl;
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
            AptM1->Desc_LU();
            
            delete AptM1;
            system("pause");
            return(0);
      }
      
    void Leer(int &RefR,int &RefC)
       {
               cout<<"\n\n\n\t\tDESCOMPOSICION LU"
               <<"\n\n\n\t\tDatos de la matriz A:"
               <<"\n\n\t\tIngresa el Numero de Renglones = ";
               cin>>RefR;
               cout<<"\n\t\tIngresa el Numero de Columnas = ";
               cin>>RefC;
       }
                 
