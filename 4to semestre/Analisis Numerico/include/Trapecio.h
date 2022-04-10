   
    #include <cstdlib>
    #include <iostream>
    #include <math.h>
    
    using namespace std;
    
    double f(double &X);
    
    class Metodo
          {
                private:
                        int n;
                        double *X,*Fx,I;
                public:
                       Metodo(int N=2);
                       double Trapecio(double *X, double &h, int k, double a, double b);
          };
          
    Metodo::Metodo(int N)
       {
           n=N;
           
           X=new double[n];
           for(int i=0;i<n;i++)
              X[i]=0;
              
           Fx=new double[n];
           for(int i=0;i<n;i++)
              Fx[i]=0;
       }    
       
    double f(double &X)
       {
           return(1/X);
       }  
       
    double Metodo::Trapecio(double *X, double &h, int k, double a, double b)
       {
               //Calculando el numero de puntos
               n=(b-a)/h+1;
               X=new double[n];
               X[0]=a;
               X[n-1]=b;
               cout<<"\n\n\t\tIntervalo = [ "<<X[0]<<" , "<<X[n-1]<<" ]";
               //Asignando los demas puntos Xi con h
               for(int i=0;i<n-1;i++)
                 X[i+1]=X[i]+h;
               cout<<"\n\n\t\tPuntos X:\n";
               for(int i=0;i<n;i++)
                  cout<<"\n\t\tX"<<"["<<i<<"] = "<<X[i];
               cout<<endl;
               //Evaluando la funcion en los puntos
               Fx=new double[n];
               for(int i=0;i<n;i++)
                  Fx[i]=f(X[i]);
               cout<<"\n\n\t\tFuncion evaluada:\n";
               for(int i=0;i<n;i++)
               cout<<"\n\t\tF"<<"["<<i<<"] = "<<Fx[i];
               cout<<endl;
               //Calculando Estimacion
               double s=0;
               for(int i=1;i<n-1;i++)
                  s=s+Fx[i];
               I=h*(Fx[0]/2+s+Fx[n-1]/2);
               return (I);
       }

