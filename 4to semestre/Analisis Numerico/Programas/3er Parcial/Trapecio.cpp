   
    #include <cstdlib>
    #include <iostream>
    #include <math.h>
    
    using namespace std;
    
    double fx(double &X);
    
    class Integral
          {
                private:
                        int n;
                        double *X,*Fx,h,I;
                public:
                        Integral(int N=2, double H=0.1);
                        void Leer(void);
                        void Trapecio(void);
                        void Imprimir(void)const;
                        ~Integral(void);
          };
          
    Integral::Integral(int N, double H)
       {
           n=N;
           h=H;
           
           X=new double[n];
           for(int i=0;i<n;i++)
              X[i]=0;
              
           Fx=new double[n];
           for(int i=0;i<n;i++)
              Fx[i]=0;
       }    
       
    double fx(double &X)
       {
           return(1/X);
       }       
        
    void Integral::Leer(void)
       {
           cout<<"\n\n\n\t\tMETODO DEL TRAPECIO PARA CALCULAR INTEGRALES DEFINIDAS\n"
           <<"\n\n\t\tIngresa el Numero Total de Puntos: ";
           cin>>n;
           X=new double[n];
           cout<<"\n\n\t\tIngresa el intervalo inicial a:\n\t\t"<<"\n\t\ta = ";
           cin>>X[0];
           cout<<"\n\n\t\tIngresa el intervalo final b:\n\t\t"<<"\n\t\tb = ";
           cin>>X[n-1];
           }
       
    void Integral::Trapecio(void)
       {
           //Calculando h
           h=(X[n-1]-X[0])/(n-1);
           //Asignando los demas puntos Xi con h
           for(int i=0;i<n-1;i++)
             X[i+1]=X[i]+h;
           //Evaluando la funcion en los puntos
           Fx=new double[n];
           for(int i=0;i<n;i++)
              Fx[i]=fx(X[i]);
           //Calculando Integral
           double s=0;
           for(int i=1;i<n-1;i++)
              s=s+Fx[i];
           I=h*(Fx[0]/2+s+Fx[n-1]/2);
       }
           
    void Integral::Imprimir(void)const
       {
           system("cls");
           cout<<"\n\n\t\tINTEGRACION POR EL METODO DEL TRAPECIO:\n"
           <<"\n\n\t\tf(x) = 1 / X"
           <<"\n\n\t\tIntervalo = [ "<<X[0]<<" , "<<X[n-1]<<" ]"
           <<"\n\n\t\th = "<<h<<endl
           <<"\n\n\t\tPuntos X:\n";
           for(int i=0;i<n;i++)
              cout<<"\n\t\tX"<<"["<<i<<"] = "<<X[i];
           cout<<endl
           <<"\n\n\t\tFuncion evaluada:\n";
           for(int i=0;i<n;i++)
              cout<<"\n\t\tF"<<"["<<i<<"] = "<<Fx[i];
           cout<<endl
           <<"\n\n\t\tIntegral = "<<I<<endl<<endl;
       }
       
    Integral::~Integral(void)
       {
           delete []X;
           delete []Fx;
       }           

int main(int argc, char *argv[])
{
    Integral *AptI;
    AptI=new Integral;
    
    AptI->Leer();
    AptI->Trapecio();
    AptI->Imprimir();

    delete AptI;
    
    system("pause");
    return EXIT_SUCCESS;
}
