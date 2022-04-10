
    #include <stdio.h>
    #include <conio.h>    
    #include <stdlib.h>
    #include <iostream>
    #include <math.h>
    
    using namespace std;
    
    class Interpolacion
          {
                private:
                        int n;
                        double *X,*Y,*b,X0;
                public:
                        Interpolacion(int N=1);
                        void Leer(void);
                        void Lagrange(void);
                        void Imprimir(void)const;
                        ~Interpolacion(void);
          };
          
    Interpolacion::Interpolacion(int N)
       {
             n=(N<1)?1:N;
             X=new double[n];
                  *X=0.0;
             Y=new double[n];
                  *Y=0.0;
             b=new double[n];
                  *b=0.0;
       }
                      
     Interpolacion::~Interpolacion(void)
       {
             delete []X;
             delete []Y;
             delete []b;
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
              cout<<"\n\n\n\t\tIngresa el valor para Evaluar al Polinomio: ";
              cin>>X0;
       }            
      
     void Interpolacion::Imprimir(void)const
       {
            system("cls");
            cout<<"\n\n\t\tXi  Yi";
            for(int i=0;i<n;i++)
                cout<<"\n\n\t\t "<<X[i]<<"  "<<Y[i];
            cout<<endl;
       }
       
     void Interpolacion::Lagrange(void)
          {       
             double s=0;
             for(int i;i<n;i++)
               {
                     double P1;
                     for(int j;j<n;j++) 
                        {
                             if(i != j)
                               P1=P1*(X0-X[j]);
                        }
                     double P2;
                     for(int j;j<n;j++) 
                        {
                             if(i != j)
                               P2=P2*(X[i]-X[j]);
                        } 
                      s=s+f(X[i])*(P1/P2);  
               }
          }
     
     int main(void)
      {
            Interpolacion *Apt1;
            Apt1=new Interpolacion;
            
            Apt1->Leer();
            Apt1->Imprimir();
            Apt1->Lagrange();
            
            delete Apt1;
            system("pause");
            return(0);
      }
                 
