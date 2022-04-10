
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
                        double **AptMat,*X;
                public:
                        Matriz(int r=2,int c=2);
                        void Leer(void);
                        void Gauss(void);
                        void Imprimir(void)const;
                        ~Matriz(void);
          };
          
    Matriz::Matriz(int r, int c)
       {
             R=(r<1)?2:r;
             C=(c<1)?2:c;
             X=new double[C];
                  *X=0.0;
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
       }      
       
      void Matriz::Leer(void)
       {
              cout<<"\n\n\n\t\tIngresa los valores de la Matriz Ampliada (A|B):\n\t\t"; 
              for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                   {
                      cout<<"\n\t\tValor "<<"["<<i<<"]"<<"["<<j<<"]"<<" = ";
                      cin>>AptMat[i][j];
                   }
       }            
      
     void Matriz::Imprimir(void)const
       {
            system("cls");
            cout<<"\n\n\t\tMatriz (A|B): ";
            for(int i=0;i<R;i++)
               {
                cout<<"\n\n\t\t ";
                for(int j=0;j<C;j++)
                    cout<<"  "<<AptMat[i][j];
               }
            cout<<endl;
       }
       
     void Matriz::Gauss(void)
          {       //Triangularizacion
                 double cte;
                 cout<<"\n\n\t\tTriangularizacion:\n\n";
                  for(int i=0;i<R-1;i++)
                     {
                       for(int j=i+1;j<R;j++)
                          {    
                               cte=-AptMat[i][i]/AptMat[j][i];
                               cout<<"\n\t\tC = -"<<AptMat[i][i]<<" / "<<AptMat[j][i]<<" = "<<cte
                               <<", i= "<<i<<endl;
                               if(AptMat[j][i] != 0)
                                 {
                                      for(int k=0;k<C;k++)
                                        {
                                          AptMat[j][k]=AptMat[i][k]+cte*AptMat[j][k];
                                          cout<<"\t\ta"<<"["<<j<<"]"<<"["<<k<<"]"<<" = "
                                          <<AptMat[i][k]<<" + "<<cte<<"*"<<AptMat[j][k]<<" = "
                                          <<AptMat[j][k]<<endl;
                                        }
                                 }
                               else
                                 {
                                       cout<<"El SEL no tiene solucion"<<endl<<endl;
                                       system("pause");
                                       exit(1);
                                 }
                          }
                     }
                   //Imprimir mat triangular
                   cout<<"\n\n\t\tMatriz Triangularizada: ";
                    for(int i=0;i<R;i++)
                       {
                            cout<<"\n\n\t\t ";
                            for(int j=0;j<C;j++)
                                    cout<<"  "<<AptMat[i][j];
                       }
                  cout<<endl;
                  //Condiciones   
                  if(AptMat[R-1][R-1] == 0 && AptMat[C-1][C-1] != 0)
                      {
                           cout<<"El SEL no tiene solucion"<<endl<<endl;
                           system("pause");
                           exit(1);
                      }
                  if(AptMat[R-1][R-1] == 0 && AptMat[C-1][C-1] == 0)
                      {
                           cout<<"El SEL tiene infinidad de soluciones"<<endl<<endl;
                           system("pause");
                           exit(1);
                      }
                   //Solucion       
                  X=new double[C];
                  double s;
                  cout<<"\n\n\t\tRESULTADOS:\n\n";
                  for(int j=R-1;j>=0;j--)
                      {
                           s=0;
                           for(int i=j+1;i<R;i++)
                                s=s+AptMat[j][i]*X[i];
                           X[j]=(AptMat[j][R]-s)/AptMat[j][j];
                           cout<<"\t\tX"<<j<<" = "<<X[j]<<endl<<endl;    
                      }
                  cout<<endl;
          }
                       
     void Leer(int &RefR,int &RefC);
     
     int main(void)
      {
            int NR1,NC1;
            
            Matriz *AptM1;
            Leer(NR1,NC1);
            AptM1=new Matriz(NR1,NC1);
            
            AptM1->Leer();
            AptM1->Imprimir();
            AptM1->Gauss();
            
            delete AptM1;
            system("pause");
            return(0);
      }
      
    void Leer(int &RefR,int &RefC)
       {
               cout<<"\n\n\n\t\tMETODO DE GAUSS"
               <<"\n\n\n\t\tDatos de la matriz Ampliada (A|B):"
               <<"\n\n\t\tIngresa el Numero de Renglones = ";
               cin>>RefR;
               cout<<"\n\t\tIngresa el Numero de Columnas = ";
               cin>>RefC;
       }
                 
