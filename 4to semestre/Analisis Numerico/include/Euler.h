 
    #include <cstdlib>
    #include <iostream>
    #include <math.h>
    
    using namespace std;
    
    double fx(double &X, double &Y);
    
    class Metodo
          {
                private:
                        int n;
                        double *I,*X,h,*Y;
                public:
                        Metodo(int N=2, double H=0.1);
                         double * Euler(int n, double h, double &X, double &Y,double I1,double I2);
          };
          
              
    Metodo::Metodo(int N, double H)
       {
           n=N;
           h=H;
           
           I=new double[n];
           for(int i=0;i<n;i++)
              I[i]=0;
           
           X=new double[n];
           for(int i=0;i<n;i++)
              X[i]=0;
              
           Y=new double[n];
           for(int i=0;i<n;i++)
              Y[i]=0;
       }    
       
    double fx(double &X, double &Y)
       {
           return(4*exp(0.8*X)-0.5*Y);
       }       

         double * Metodo::Euler(int n, double h, double &x0, double &y0,double I1,double I2)
       {
           I=new double[n];
           X=new double[n];
           Y=new double[n];
           X[0]=x0;
           Y[0]=y0;
           I[0]=I1;
           I[n-1]=I2;
           //Calculando h
           h=(I[n-1]-I[0])/(n-1);
           //Asignando los demas intervalos
           for(int i=0;i<n-1;i++)
             I[i+1]=I[i]+h;
           //Asignando los demas puntos X
           for(int i=0;i<n-1;i++)
             X[i+1]=X[i]+h;
           //Aplicando metodo
           for(int i=0;i<n-1;i++)
              Y[i+1]=Y[i]+fx(X[i],Y[i])*h;
              
           system("cls");
           cout<<"\n\n\t\tECUACIONES DIFERENCIALES POR EL METODO DE HEUN:\n"
           <<"\n\n\t\tf(x) = 4exp(0.8X) - 0.5Y"
           <<"\n\n\t\tIntervalo = [ "<<I[0]<<" , "<<I[n-1]<<" ]"
           <<"\n\n\t\th = "<<h<<endl;
           for(int i=0;i<n;i++)
              cout<<"\n\t\tX"<<"["<<i<<"] = "<<X[i];
           cout<<endl<<endl;
           for(int i=0;i<n;i++)
              cout<<"\n\t\tY'"<<"["<<i<<"] = "<<Y[i];
           cout<<endl<<endl;
           return (Y);
       }
       

