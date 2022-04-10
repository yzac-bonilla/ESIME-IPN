 
    #include <cstdlib>
    #include <iostream>
    #include <math.h>
    #include <F:\include\Euler.h>
    
    using namespace std;
    
    double dfx(double &X, double &Y);
    
    class Ec_Dif
          {
                private:
                        int n;
                        double *X,h,*Y,*I,*R;
                public:
                        Ec_Dif(int N=2, double H=0.1);
                        void Leer(void);
                        void Heun(void);
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
              
           R=new double[n];
           for(int i=0;i<n;i++)
              R[i]=0;
       }    
       
    double dfx(double &X, double &Y)
       {
           return(4*exp(0.8*X)-0.5*Y);
       }       
        
    void Ec_Dif::Leer(void)
       {
           cout<<"\n\n\n\t\tMETODO DE HEUN PARA CALCULAR ECUACIONES DIFERENCIALES\n"
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
       
        void Ec_Dif::Heun(void)
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
           for(int i=0;i<n-1;i++)
              Y[i+1]=Y[i]+dfx(X[i],Y[i])*h;
           R=new double[n];
           R[0]=Y[0];
           for(int i=0;i<n-1;i++){
              cout<<" R "<<i+1<<" = "<<Y[i]<<" + "<<h<<" / 2 "<<" * "<<dfx(X[i],Y[i])<<" + "<<dfx(X[i+1],Y[i+1]);
              R[i+1]=Y[i]+(h/2)*(dfx(X[i],Y[i])+dfx(X[i+1],Y[i+1]));
              cout<<" = "<<R[i+1]<<endl;
              }
       }
           
    void Ec_Dif::Imprimir(void)const
       {
           system("cls");
           cout<<"\n\n\t\tECUACIONES DIFERENCIALES POR EL METODO DE HEUN:\n"
           <<"\n\n\t\tf(x) = 4exp(0.8X) - 0.5Y"
           <<"\n\n\t\tIntervalo = [ "<<I[0]<<" , "<<I[n-1]<<" ]"
           <<"\n\n\t\th = "<<h<<endl;
           for(int i=0;i<n;i++)
              cout<<"\n\t\tx"<<"["<<i<<"] = "<<X[i];
           cout<<endl<<endl;
           for(int i=0;i<n;i++)
              cout<<"\n\t\ty"<<"["<<i<<"] = "<<Y[i];
           cout<<endl<<endl;
           cout<<"\n\n\t\tSOLUCION:\n";
           for(int i=0;i<n;i++)
              cout<<"\n\t\tY'"<<"["<<i<<"] = "<<R[i];
           cout<<endl<<endl;
       }
       
    Ec_Dif::~Ec_Dif(void)
       {
           delete []X;
           delete []Y;
       }           

    int main(int argc, char *argv[])
    {
        Ec_Dif *AptI;
        AptI=new Ec_Dif;
        
        AptI->Leer();
        AptI->Heun();
        AptI->Imprimir();
    
        delete AptI;
        
        system("pause");
        return EXIT_SUCCESS;
    }
    
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
          /* Metodo *Apt;
           Apt=new Metodo;
           Y=Apt->Euler(n,h,X[0],Y[0],I[0],I[n-1]);*/
