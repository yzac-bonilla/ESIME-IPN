 
    #include <cstdlib>
    #include <iostream>
    #include <math.h>
    
    using namespace std;
    
    double dfx(double &X, double &Y);
    
    class Ec_Dif
          {
                private:
                        int n;
                        double *I,*X,h,*Y,*K;
                public:
                        Ec_Dif(int N=2, double H=0.1);
                        void Leer(void);
                        void Runge_Kutta(void);
                        void Imprimir(void)const;
                        ~Ec_Dif(void);
          };
          
              
    Ec_Dif::Ec_Dif(int N, double H)
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
       }    
       
    double dfx(double &X, double &Y)
       {
           return(2*X*Y);
       }       
        
    void Ec_Dif::Leer(void)
       {
           cout<<"\n\n\n\t\tMETODO DE RUNGE-KUTTA PARA CALCULAR ECUACIONES DIFERENCIALES\n"
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
       
        void Ec_Dif::Runge_Kutta(void)
       {   
           //Calculando h
           h=(I[n-1]-I[0])/(n-1);
           //Asignando los demas intervalos
           for(int i=0;i<n-1;i++)
             I[i+1]=I[i]+h;
           //Asignando los demas puntos X
           for(int i=0;i<n-1;i++)
             X[i+1]=X[i]+h;
           //Aplicando metodo
           K=new double[4];
           double x=0,y=0;
           for(int i=0;i<n-1;i++)
            {  
               K[0]=h*dfx(X[i],Y[i]);
               x=X[i]+h/2;
               y=Y[i]+K[0]/2;
               K[1]=h*dfx(x,y);
               y=Y[i]+K[1]/2;
               K[2]=h*dfx(x,y);
               x=X[i]+h;
               y=Y[i]+K[2];
               K[3]=h*dfx(x,y);
               Y[i+1]=Y[i]+(K[0]+2*K[1]+2*K[2]+K[3])/6;
            }
       }
           
    void Ec_Dif::Imprimir(void)const
       {
           system("cls");
           cout<<"\n\n\t\tECUACIONES DIFERENCIALES POR EL METODO DE RUNGE-KUTTA:\n"
           <<"\n\n\t\tf(x) = 2XY"
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
       
    Ec_Dif::~Ec_Dif(void)
       {
           delete []X;
           delete []Y;
           delete []K;
       }           

    int main(int argc, char *argv[])
    {
        Ec_Dif *AptI;
        AptI=new Ec_Dif;
        
        AptI->Leer();
        AptI->Runge_Kutta();
        AptI->Imprimir();
    
        delete AptI;
        
        system("pause");
        return EXIT_SUCCESS;
    }
    
