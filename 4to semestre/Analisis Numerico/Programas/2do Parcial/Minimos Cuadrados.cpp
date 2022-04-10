
    #include <stdio.h>
    #include <conio.h>    
    #include <stdlib.h>
    #include <iostream>
    #include <math.h>
    
    using namespace std;
    
    class Interpolacion
          {
                private:
                        int n,grado;
                        double **AptMat,*X,*Y,*b;
                public:
                        Interpolacion(int N=1,int G=1);
                        void Leer(void);
                        void Min_Cuadrados(void);
                        void Imprimir(void)const;
                        ~Interpolacion(void);
          };
          
    Interpolacion::Interpolacion(int N,int G)
       {
             n=(N<1)?1:N;
             grado=(G<1)?1:G;
             X=new double[n];
                  *X=0.0;
             Y=new double[n];
                  *Y=0.0;
             b=new double[n];
                  *b=0.0;
             AptMat=new double *[grado+2];
             for(int i=0;i<grado+2;i++)
                 AptMat[i]=new double [grado+3];
             for(int i=0;i<grado+2;i++)
                for(int j=0;j<grado+3;j++)
                   AptMat[i][j]=0.0;
       }
                      
     Interpolacion::~Interpolacion(void)
       {
             delete []X;
             delete []Y;
             delete []b;
             for(int i=0;i<grado+1;i++)
                 delete []AptMat[i];
             delete []AptMat;
       }      
       
      void Interpolacion::Leer(void)
       {
              cout<<"\n\n\n\t\tIngresa el Numero total de Puntos: ";
              cin>>n;
              cout<<"\n\n\n\t\tIngresa los Puntos Xi:\n\t\t";
              for(int i=0;i<n;i++)
               {
                   cout<<"\n\t\tX "<<"["<<i<<"] = ";
                   cin>>X[i];
               }
              cout<<"\n\n\n\t\tIngresa los Puntos Yi:\n\t\t";
              for(int i=0;i<n;i++)
               {
                   cout<<"\n\t\tY "<<"["<<i<<"] = ";
                   cin>>Y[i];
               }
              cout<<"\n\n\n\t\tIngresa el Grado de la funcion a Proponer: ";
              cin>>grado;
       }            
      
     void Interpolacion::Imprimir(void)const
       {
            system("cls");
            cout<<"\n\n\t\tXi  Yi";
            for(int i=0;i<n;i++)
                cout<<"\n\n\t\t "<<X[i]<<"  "<<Y[i];
            cout<<endl;
            cout<<"\n\n\t\tMatriz: ";
            for(int i=0;i<grado+1;i++)
               {
                cout<<"\n\n\t\t ";
                for(int j=0;j<grado+2;j++)
                    cout<<"  "<<AptMat[i][j];
               }
            cout<<endl;
       }
       
     void Interpolacion::Min_Cuadrados(void)
          {       
             
                  //Solucion por Gauss
                  double cte;
                  for(int i=0;i<grado;i++)
                     {
                       for(int j=i+1;j<grado+1;j++)
                          {    
                               cte=-AptMat[i][i]/AptMat[j][i];
                               if(AptMat[j][i] != 0)
                                 {
                                      for(int k=0;k<grado+2;k++)
                                          AptMat[j][k]=AptMat[i][k]+cte*AptMat[j][k];
                                 }
                          }
                     }
                  double s;
                  cout<<"\n\n\t\tRESULTADOS:\n\n";
                  for(int j=grado;j>=0;j--)
                      {
                           s=0;
                           for(int i=j+1;i<grado+1;i++)
                                s=s+AptMat[j][i]*X[i];
                           X[j]=(AptMat[j][grado+1]-s)/AptMat[j][j];
                           cout<<"\t\tX"<<j<<" = "<<X[j]<<endl<<endl;    
                      }
                  cout<<endl;
          }
     
     int main(void)
      {
            Interpolacion *Apt1;
            Apt1=new Interpolacion;
            
            Apt1->Leer();
            Apt1->Imprimir();
            //Apt1->Min_Cuadrados();
            
            delete Apt1;
            system("pause");
            return(0);
      }
                 
