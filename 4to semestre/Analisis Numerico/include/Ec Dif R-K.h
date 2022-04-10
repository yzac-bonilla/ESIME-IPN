
    #include <cstdlib>
    #include <iostream>
    #include <math.h>
    
    using namespace std;
    
    double df(double &X, double &Y);
    double dg(double &X, double &Y);
    
    class Metodo
          {
                private:
                        int n;
                        double *I,*X,h,*Y,*K,*M;
                public:
                        Metodo(int N=2, double H=0.1);
                        void Leer(void);
                        void RK(void);
                        void Imprimir(void)const;
                        ~Metodo(void);
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
              
           K=new double[4];
           for(int i=0;i<4;i++)
              K[i]=0;
              
           M=new double[4];
           for(int i=0;i<4;i++)
              M[i]=0;
       }    
       
    double df(double &X, double &Y)
       {
           return(2*X+4*Y);
       }       
       
    double dg(double &X, double &Y)
       {
           return(-X+6*Y);
       }
       
    void Metodo::Leer(void)
       {
           cout<<"\n\n\n\t\tSISTEMAS DE ECUACIONES DIFERENCIALES\n"
           <<"\n\n\t\tIngresa el Numero Total de Puntos: ";
           cin>>n;
           I=new double[n];
           cout<<"\n\n\t\tIngresa el intervalo inicial a:\n\t\t"<<"\n\t\ta = ";
           cin>>I[0];
           cout<<"\n\n\t\tIngresa el intervalo final b:\n\t\t"<<"\n\t\tb = ";
           cin>>I[n-1];
           X=new double[n];
           cout<<"\n\n\t\tIngresa el punto X inicial:\n\t\t"<<"\n\t\tX0 = ";
           cin>>X[0];
           Y=new double[n];
           cout<<"\n\n\t\tIngresa el punto Y inicial:\n\t\t"<<"\n\t\tY0 = ";
           cin>>Y[0];
       }
       
    void Metodo::RK(void)
       {   
           //Calculando h
           h=(I[n-1]-I[0])/(n-1);
           //Asignando los demas intervalos
           for(int i=0;i<n-1;i++)
             I[i+1]=I[i]+h;
           //Aplicando metodo
           K=new double[4];
           M=new double[4];
           double x=0,y=0;
           for(int i=0;i<n-1;i++)
            {  
               M[0]=h*df(X[i],Y[i]);
               K[0]=h*dg(X[i],Y[i]);
               x=X[i]+M[0]/2;
               y=Y[i]+K[0]/2;
               M[1]=h*df(x,y);
               K[1]=h*dg(x,y);
               x=X[i]+M[1]/2;
               y=Y[i]+K[1]/2;
               M[2]=h*df(x,y);
               K[2]=h*dg(x,y);
               x=X[i]+M[2];
               y=Y[i]+K[2];
               M[3]=h*df(x,y);
               M[3]=h*dg(x,y);
               X[i+1]=X[i]+(M[0]+2*M[1]+2*M[2]+M[3])/6;
               Y[i+1]=Y[i]+(K[0]+2*K[1]+2*K[2]+K[3])/6;
            }
       }

    void Metodo::Imprimir(void)const
       {
           system("CLS");                         
           cout<<"\n\n\t\tSISTEMA DE ECUACIONES DIFERENCIALES:\n"
           <<"\n\n\t\tx' = 2X+4Y"
           <<"\n\n\t\ty' = -X+6Y"
           <<"\n\n\t\tIntervalo = [ "<<I[0]<<" , "<<I[n-1]<<" ]"
           <<"\n\n\t\th = "<<h<<endl
           <<"\n\n\t\tSOLUCION:\n";
           for(int i=0;i<n;i++)
              cout<<"\n\t\tX"<<"["<<i<<"] = "<<X[i];
           cout<<endl<<endl;
           for(int i=0;i<n;i++)
              cout<<"\n\t\tY'"<<"["<<i<<"] = "<<Y[i];
           cout<<endl<<endl;
       }
       
    Metodo::~Metodo(void)
       {
           delete []X;
           delete []Y;
           delete []K;
       }  
    
