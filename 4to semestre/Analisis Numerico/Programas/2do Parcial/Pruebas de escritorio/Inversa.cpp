   
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
                        double **AptMat,*X,*b;
                public:
                        Matriz(int r=2,int c=2);
                        void Leer(void);
                        void Inversa(void);
                        void Imprimir(void)const;
                        ~Matriz(void);
          };
          
    Matriz::Matriz(int r, int c)
       {
             R=(r<1)?2:r;
             C=(c<1)?2:c;
             X=new double[C];
                *X=0.0;
             b=new double[R];
                *b=0.0;
             
             AptMat=new double *[R];
             for(int i=0;i<R;i++)
                 AptMat[i]=new double [C+R];
             for(int i=0;i<R;i++)
                for(int j=0;j<C+R;j++)
                   AptMat[i][j]=0.0;
             //inicializar matriz ampliada (A|I)
                 AptMat[R-3][c]=1.0;
                 AptMat[R-2][c+1]=1.0;
                 AptMat[R-1][c+2]=1.0;
       }
                      
     Matriz::~Matriz(void)
       {
             for(int i=0;i<R;i++)
                 delete []AptMat[i];
             delete []AptMat;
             delete []X;
             delete []b;
       }      
       
      void Matriz::Leer(void)
       {
              cout<<"\n\n\n\t\tIngresa los valores de la Matriz A:\n\t\t"; 
              for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                   {
                      cout<<"\n\t\ta "<<"["<<i<<"]["<<j<<"] = ";
                      cin>>AptMat[i][j];
                   }
              cout<<"\n\n\n\t\tIngresa los valores del Vector B:\n\t\t";
              for(int i=0;i<R;i++)
                 {
                      cout<<"\n\t\tb ["<<i<<"] = ";
                      cin>>b[i];
                 }
       }          
      
     void Matriz::Imprimir(void)const
       {
            system("cls");
            cout<<"\n\n\t\tMatriz (A|I): ";
            for(int i=0;i<R;i++)
               {
                cout<<"\n\n\t\t ";
                for(int j=0;j<C+R;j++)
                    cout<<"  "<<AptMat[i][j];
               }
            cout<<endl;
            cout<<"\n\n\t\tVector B: ";
            for(int i=0;i<R;i++)
                cout<<"\n\n\t\t "<<b[i];
            cout<<endl;
       }
       
     void Matriz::Inversa(void)
          {    
               //Triangularizacion
                double c1,c2;
                  for(int i=0;i<R-1;i++)
                     {
                       for(int j=i+1;j<R;j++)
                          {    
                               c1=-AptMat[i][i]/AptMat[j][i];
                               if(AptMat[j][i] != 0)
                                 {
                                      for(int k=0;k<C+R;k++)
                                          AptMat[j][k]=AptMat[i][k]+c1*AptMat[j][k];
                                 }
                          }
                     }
                for(int i=R-1;i>0;i--)
                  {
                   for(int j=i-1;j>=0;j--)
                       {
                           c2=-AptMat[j][i]/AptMat[i][i];
                           for(int k=0;k<C+R;k++)
                               AptMat[j][k]=AptMat[j][k]+c2*AptMat[i][k];
                       }
                  }
                  cout<<"\n\n\t\tMatriz triangularizada: ";
                    for(int i=0;i<R;i++)
                       {
                            cout<<"\n\n\t\t ";
                            for(int j=0;j<C+R;j++)
                                    cout<<"  "<<AptMat[i][j];
                       } 
                 cout<<endl; 
                //Gauss-jordan 
                for(int i=0;i<R;i++)
                  {
                     for(int k=C;k<C+R;k++)
                          AptMat[i][k]=AptMat[i][k]/AptMat[i][i];
                  }
                //Mat identidad
                cout<<"\n\n\t\tMatriz identidad: ";
                    for(int i=0;i<R;i++)
                       {
                            AptMat[i][i]=AptMat[i][i]/AptMat[i][i];
                            cout<<"\n\n\t\t ";
                            for(int j=0;j<C+R;j++)
                                    cout<<"  "<<AptMat[i][j];
                                    }
                //Mat inversa
                cout<<"\n\n\t\tMatriz inversa: ";
                    for(int i=0;i<R;i++)
                       {
                            AptMat[i][i]=AptMat[i][i]/AptMat[i][i];
                            cout<<"\n\n\t\t ";
                            for(int j=C;j<C+R;j++)
                                    cout<<"  "<<AptMat[i][j];
                                    }
                //Producto 
                cout<<endl<<"\n\n\t\tRESULTADOS:";
                for(int i=0;i<R;i++)
                   {    
                        double s=0;
                        for(int j=C;j<C+R;j++)
                                  s=s+AptMat[i][j]*b[j-C];
                        X[i]=s;
                        cout<<"\n\n\t\tX"<<i<<" = "<<X[i];
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
            AptM1->Inversa(); //AptM1->Imprimir();
            
            delete AptM1;
            system("pause");
            return(0);
      }
      
    void Leer(int &RefR,int &RefC)
       {
               cout<<"\n\n\n\t\tDatos de la matriz A:"
               <<"\n\n\t\tIngresa el Numero de Renglones = ";
               cin>>RefR;
               cout<<"\n\t\tIngresa el Numero de Columnas = ";
               cin>>RefC;
       }
                 
