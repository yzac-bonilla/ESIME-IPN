    
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
                        double **AptMat;
                public:
                        Matriz(int r=2,int c=2);
                        void Leer(void);
                        void Gauss_Jordan(void);
                        void Imprimir(void)const;
                        ~Matriz(void);
          };
          
    Matriz::Matriz(int r, int c)
       {
             R=(r<1)?2:r;
             C=(c<1)?2:c;
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
       
     void Matriz::Gauss_Jordan(void)
          {      
                //Triangularizacion
                double c1,c2;
                cout<<"\n\n\t\tTriangularizacion Superior:\n\n";
                  for(int i=0;i<R-1;i++)
                     {
                       for(int j=i+1;j<R;j++)
                          {    
                               c1=-AptMat[i][i]/AptMat[j][i];
                               cout<<"\n\t\tC = -"<<AptMat[i][i]<<" / "<<AptMat[j][i]<<" = "<<c1
                               <<", i= "<<i<<endl;
                               if(AptMat[j][i] != 0)
                                 {
                                      for(int k=0;k<C;k++)
                                        {
                                          AptMat[j][k]=AptMat[i][k]+c1*AptMat[j][k];
                                          cout<<"\t\ta"<<"["<<j<<"]"<<"["<<k<<"]"<<" = "
                                          <<AptMat[i][k]<<" + "<<c1<<"*"<<AptMat[j][k]<<" = "
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
                   cout<<"\n\n\t\tMatriz Triangular Superior: ";
                    for(int i=0;i<R;i++)
                       {
                            cout<<"\n\n\t\t ";
                            for(int j=0;j<C;j++)
                                    cout<<"  "<<AptMat[i][j];
                       }
                  cout<<endl;
                cout<<"\n\n\t\tTriangularizacion:\n\n";     
                for(int i=R-1;i>0;i--)
                  {
                   for(int j=i-1;j>=0;j--)
                       {
                           c2=-AptMat[j][i]/AptMat[i][i];
                           cout<<"\n\t\tC = -"<<AptMat[j][i]<<" / "<<AptMat[i][i]<<" = "<<c2
                           <<", i= "<<i<<", j= "<<j<<endl;
                           for(int k=0;k<C;k++)
                             {
                               AptMat[j][k]=AptMat[j][k]+c2*AptMat[i][k];
                               cout<<"\t\ta"<<"["<<j<<"]"<<"["<<k<<"]"<<" = "
                                   <<AptMat[j][k]<<" + "<<c2<<"*"<<AptMat[i][k]<<" = "
                                   <<AptMat[j][k]<<endl;
                             }
                       }
                  }
                cout<<"\n\n\t\tMatriz triangularizada: ";
                    for(int i=0;i<R;i++)
                       {
                            cout<<"\n\n\t\t ";
                            for(int j=0;j<C;j++)
                                    cout<<"  "<<AptMat[i][j];
                       }
                //Solucion    
                cout<<endl<<endl<<"\n\n\t\tRESULTADOS:\n\t\t"<<endl;
                for(int i=0;i<C-1;i++)
                    {
                        cout<<"\t\ta"<<"["<<i<<"]"<<"["<<C-1<<"]"<<" = "
                            <<AptMat[i][C-1]<<" / "<<AptMat[i][i]<<" = ";
                        AptMat[i][C-1]=AptMat[i][C-1]/AptMat[i][i];
                        cout<<AptMat[i][C-1]<<"\n\t\tX"<<i<<" = "<<AptMat[i][C-1]<<endl<<endl;
                    }
                cout<<"\n\t\tMatriz identidad: ";
                    for(int i=0;i<R;i++)
                       {
                            AptMat[i][i]=AptMat[i][i]/AptMat[i][i];
                            cout<<"\n\n\t\t ";
                            for(int j=0;j<C;j++)
                                    cout<<"  "<<AptMat[i][j];
                       }
                cout<<endl<<endl;
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
            AptM1->Gauss_Jordan();
            
            delete AptM1;
            system("pause");
            return(0);
      }
      
    void Leer(int &RefR,int &RefC)
       {
               cout<<"\n\n\n\t\tMETODO DE GAUSS-JORDAN"
               <<"\n\n\n\t\tDatos de la matriz Ampliada (A|B):"
               <<"\n\n\t\tIngresa el Numero de Renglones = ";
               cin>>RefR;
               cout<<"\n\t\tIngresa el Numero de Columnas = ";
               cin>>RefC;
       }
                 
