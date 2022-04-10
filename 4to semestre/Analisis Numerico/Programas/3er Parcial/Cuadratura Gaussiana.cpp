 
    #include <cstdlib>
    #include <iostream>
    #include <math.h>
    
    using namespace std;
    
    double fx(double &X);
    
    class Integral
          {
                private:
                        int n;
                        double *X,*Fx,*h,*I,In,a,b,*w,*z;
                public:
                        Integral(int N=2, int K=2);
                        void Leer(void);
                        void C_Gaussiana(void);
                        void Imprimir(void)const;
                        ~Integral(void);
          };
          
    Integral::Integral(int N, int K)
       {
           n=N;
           
           X=new double[n];
           for(int i=0;i<n;i++)
              X[i]=0;
           
           w=new double[n];
           for(int i=0;i<n;i++)
              w[i]=0;
              
           z=new double[n];
           for(int i=0;i<n;i++)
              z[i]=0;
              
           I=new double[n];
           for(int i=0;i<n;i++)
              I[i]=0;
              
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
           cout<<"\n\n\n\t\tCUADRATURA GAUSSIANA PARA CALCULAR INTEGRALES DEFINIDAS\n"
           <<"\n\n\t\tIngresa el intervalo inicial a:\n\t\t"<<"\n\t\ta = ";
           cin>>a;
           cout<<"\n\n\t\tIngresa el intervalo final b:\n\t\t"<<"\n\t\tb = ";
           cin>>b;
           cout<<"\n\n\t\tIngresa el Numero Total de Puntos: ";
           cin>>n;
       }
       
    void Integral::C_Gaussiana(void)
       {
           w=new double[n];
           z=new double[n];
           if(n==2)
            {
               w[0]=1;
               w[1]=1;
               z[0]=-0.5773502;
               z[1]=0.5773502;
            }
           if(n==3)
            {
               w[0]=0.55555;
               w[1]=0.88888;
               w[2]=0.55555;
               z[0]=-0.7745966;
               z[1]=0;
               z[2]=0.7745966;
            }
           if(n==4)
            {
               w[0]=0.3478548451;
               w[1]=0.6521451549;
               w[2]=0.6521451549;
               w[3]=0.3478548451;
               z[0]=-0.861136311;
               z[1]=-0.33998104;
               z[2]=0.33998104;
               z[3]=0.861136311;
            }
               
           X=new double[n];
           for(int i=0;i<n;i++)
              X[i]=((b-a)/2)*z[i]+a/2+b/2;
           Fx=new double[n];
           for(int i=0;i<n;i++)
              Fx[i]=fx(X[i]);
           I=new double[n];
           for(int i=0;i<n;i++)
              I[i]=Fx[i]*w[i];
           //Calculando integral
           double s=0;
           for(int i=0;i<n;i++)
              s=s+I[i];
           In=((b-a)/2)*s;
       }
           
    void Integral::Imprimir(void)const
       {
           system("cls");
           cout<<"\n\n\t\tINTEGRACION POR EL METODO DECUADRATURA GAUSSIANA:\n"
           <<"\n\n\t\tf(x) = 1 / X"
           <<"\n\n\t\tIntervalo = [ "<<X[0]<<" , "<<X[n-1]<<" ]"
           <<"\n\n\t\tFuncion evaluada en z:\n";
           for(int i=0;i<n;i++)
              cout<<"\n\t\tF"<<"["<<i<<"] = "<<X[i];
           cout<<endl
           <<"\n\n\t\tProducto de w *f(z) :\n";
           for(int i=0;i<n;i++)
              cout<<"\n\t\tw * f"<<"["<<i<<"] = "<<I[i];
           cout<<endl
           <<"\n\n\t\tIntegral = "<<In<<endl<<endl;
       }
       
    Integral::~Integral(void)
       {
           delete []X;
           delete []w;
           delete []z;
           delete []I;
           delete []Fx;
       }           

int main(int argc, char *argv[])
{
    Integral *AptI;
    AptI=new Integral;
    
    AptI->Leer();
    AptI->C_Gaussiana();
    AptI->Imprimir();
    
    delete AptI;
    
    system("pause");
    return EXIT_SUCCESS;
}
