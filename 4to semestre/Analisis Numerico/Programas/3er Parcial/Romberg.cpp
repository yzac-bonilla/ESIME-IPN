  
    #include <cstdlib>
    #include <iostream>
    #include <math.h>
    #include <F:\include\Trapecio.h>
    
    using namespace std;
    
    double fx(double &X);
    
    class Integral
          {
                private:
                        int n,k;
                        double *X,*Fx,*h,*I,*T,In,a,b;
                public:
                        Integral(int N=2, int K=2);
                        void Leer(void);
                        void Romberg(void);
                        void Imprimir(void)const;
                        ~Integral(void);
          };
          
    Integral::Integral(int N, int K)
       {
           n=N;
           k=K;
           
           X=new double[n];
           for(int i=0;i<n;i++)
              X[i]=0;
              
           h=new double[k];
           for(int i=0;i<k;i++)
              h[i]=0;
              
           T=new double[k];
           for(int i=0;i<k;i++)
              T[i]=0;
           
           I=new double[k+k];
           for(int i=0;i<k;i++)
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
           cout<<"\n\n\n\t\tMETODO DE ROMBERG PARA CALCULAR INTEGRALES DEFINIDAS\n"
           <<"\n\n\t\tIngresa el intervalo inicial a:\n\t\t"<<"\n\t\ta = ";
           cin>>a;
           cout<<"\n\n\t\tIngresa el intervalo final b:\n\t\t"<<"\n\t\tb = ";
           cin>>b;
           cout<<"\n\n\t\tIngresa el numero de niveles k:\n\t\t"<<"\n\t\tk = ";
           cin>>k;
           h=new double[k];
           cout<<"\n\n\t\tIngresa los valores de h: \n";
           for(int i=0;i<k;i++)
             {
                cout<<"\n\t\th "<<"["<<i<<"] = ";
                cin>>h[i];
             }
           
           }
       
    void Integral::Romberg(void)
       {
           //Trapecio
           Metodo *Apt;
           Apt=new Metodo;
           I=new double[k+k];
           for(int z=0;z<k;z++)
             {
                cout<<"\n\n Nivel: "<<z
                <<"\n\n\t\th "<<"["<<z<<"] = "<<h[z];
                I[z]=Apt->Trapecio(X,h[z],k,a,b);
                cout<<"\n\n\t\tEstimacion "<<z<<" = "<<T[z]<<endl<<endl;
             }
           //Calculando Integral
           for(int z=2;z<k;z++)
             {
                for(int j=0;j<k;j++)
                 {  
                    cout<<"\n\n\t\tIntegral "<<j<<" = "<<pow(4,z-1)<<" * "<<I[j+1]<<" - "<<I[j]<<" / "<<pow(4,z-1)-1;   
                    I[z+1]=(pow(4,z-1)*I[j+1]-I[j])/(pow(4,z-1)-1);
                    cout<<" = "<<I[z+1]<<endl;
                 }
             }
       }
           
    void Integral::Imprimir(void)const
       {
           system("cls");
           cout<<"\n\n\t\tINTEGRACION POR EL METODO DE ROMBERG:\n"
           <<"\n\n\t\tf(x) = 1 / X"<<endl;
       }
       
    Integral::~Integral(void)
       {
           delete []X;
           delete []h;
           delete []I;
           delete []Fx;
       }           

int main(int argc, char *argv[])
{
    Integral *AptI;
    AptI=new Integral;
    
    AptI->Leer();
    AptI->Imprimir();
    AptI->Romberg();

    delete AptI;
    
    system("pause");
    return EXIT_SUCCESS;
}










/*for(int z=0; z<k-1; z++)
	                         for(int j=0; j<k-1; j++){
                                       cout<<"\n\n\t\tIntegral "<<j<<" = "<<pow(4,z+1)<<" * "<<I[j+1]<<" - "<<I[j]<<" / "<<pow(4,z+1)-1;
		                               I[j]=(pow(4,z+1)*I[j+1]-I[j])/(pow(4,z+1)-1);
                                 }*/
