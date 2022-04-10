   
    #include <cstdlib>
    #include <iostream>
    #include <math.h>
    
    using namespace std;
    
    double fx(double &X);
    
    class Derivada
          {
                private:
                        int n;
                        double *X,*Fx,h,dfx;
                public:
                        Derivada(int N=2, double H=0.1);
                        int Menu(void);
                        void Leer(void);
                        void Adelante(void);
                        void Atras(void);
                        void Central(void);
                        void Central_X(void);
                        void Imprimir(void)const;
                        ~Derivada(void);
          };
          
    Derivada::Derivada(int N, double H)
       {
           n=N;
           h=H;
           
           X=new double[n];
           for(int i=0;i<n;i++)
              X[i]=0;
              
           Fx=new double[n+2];
           for(int i=0;i<n+2;i++)
              Fx[i]=0;
       }
       
    Derivada::~Derivada(void)
       {
           delete []X;
           delete []Fx;
       }
       
    int Derivada::Menu(void)
        {
                  int Opcion;
                  system("cls");
                  cout<<"\n\n\t\t\tMETODOS PARA DERIVAR"
                  <<"\n\n\t\t\tSelecciona una Opcion:"
                  <<"\n\n\t\t\t1.- Hacia Adelante (2 puntos)"
                  <<"\n\t\t\t2.- Hacia Atras (2 puntos)"
                  <<"\n\t\t\t3.- Central (3 puntos)"
                  <<"\n\t\t\t4.- Central (5 puntos)"
                  <<"\n\t\t\t5.- Salir"
                  <<endl
                  <<"\n\t\t\tDame tu Opcion: ";
                  cin>>Opcion;
                  while(Opcion <1 || Opcion >5)
                    {
                      cout<<endl<<"\n\t\tOpcion Invalida!!! Intente nuevamente. \n\n";
                      cout<<"\n\t\t\tDame tu Opcion: ";
                      cin>>Opcion;
                    }
                  return(Opcion);
        }
       
    void Derivada::Leer(void)
       {
           cout<<"\n\n\n\t\tDATOS"
           <<"\n\n\t\tIngresa el Numero Total de Puntos: ";
           cin>>n;
           X=new double[n];
           cout<<"\n\n\t\tIngresa el Punto Inicial X0:\n\t\t"
           <<"\n\t\tX[0] = ";
           cin>>X[0];
           cout<<"\n\n\t\tIngresa h: ";
           cin>>h;
       }
       
    void Derivada::Imprimir(void)const
       {
           system("cls");
           cout<<"\n\n\t\tDERIVADA"
           <<"\n\n\t\tf(x) = (X^2 * Cos(2*X)) / 3 "
           <<"\n\n\t\th = "<<h
           <<"\n\t\tX = "<<X[0]<<endl;
       }
       
    double fx(double &X)
       {
           return((X*X*cos(2*X))/3);
       }
       
    void Derivada::Adelante(void)
       {
           //Asignando los demas puntos Xi con h
           for(int i=0;i<n-1;i++)
             X[i+1]=X[i]+h;
           cout<<"\n\n\t\tPuntos:\n";
           for(int i=0;i<n;i++)
              cout<<"\n\t\tX"<<"["<<i<<"] = "<<X[i];
           cout<<endl;
           //Evaluando la funcion con los Xi
           for(int i=0;i<n;i++)
              Fx[i]=fx(X[i]);
           cout<<"\n\n\t\tFuncion evaluada:\n";
           for(int i=0;i<n;i++)
              cout<<"\n\t\tF"<<"["<<i<<"] = "<<Fx[i];
           cout<<endl;
           //Calculando derivada
           double s=0;
           for(int i=0;i<n;i++)
             s=Fx[i]-s;
           dfx=s/h;
           cout<<"\n\n\t\tDerivada hacia adelante:"
           <<"\n\n\t\tf'(x) = "<<dfx
           <<endl<<endl;
       }
       
        void Derivada::Atras(void)
       {
           //Asignando los demas puntos Xi con h
           for(int i=0;i<n-1;i++)
             X[i+1]=X[i]-h;
           cout<<"\n\n\t\tPuntos:\n";
           for(int i=0;i<n;i++)
              cout<<"\n\t\tX"<<"["<<i<<"] = "<<X[i];
           cout<<endl;
           //Evaluando la funcion con los Xi
           for(int i=0;i<n;i++)
              Fx[i]=fx(X[i]);
           cout<<"\n\n\t\tFuncion evaluada:\n";
           for(int i=0;i<n;i++)
              cout<<"\n\t\tF"<<"["<<i<<"] = "<<Fx[i];
           cout<<endl;
           //Calculando derivada
           double s=0;
           for(int i=n-1;i>=0;i--)
             s=Fx[i]-s;
           dfx=s/h;
           cout<<"\n\n\t\tDerivada hacia atras:"
           <<"\n\n\t\tf'(x) = "<<dfx
           <<endl<<endl;
       }
       
       void Derivada::Central(void)
       {
           //Asignando los demas puntos Xi con h
           X[1]=X[0]+h;
           X[2]=X[0]-h;
           cout<<"\n\n\t\tPuntos:\n";
           for(int i=1;i<n;i++)
              cout<<"\n\t\tX"<<"["<<i<<"] = "<<X[i];
           cout<<endl;
           //Evaluando la funcion con los Xi
           for(int i=0;i<n-1;i++)
              Fx[i]=fx(X[i+1]);
           cout<<"\n\n\t\tFuncion evaluada:\n";
           for(int i=0;i<n-1;i++)
              cout<<"\n\t\tF"<<"["<<i<<"] = "<<Fx[i];
           cout<<endl;
           //Calculando derivada
           double s=0;
           for(int i=n-2;i>=0;i--)
             s=Fx[i]-s;
           dfx=s/(2*h);
           cout<<"\n\n\t\tDerivada central:"
           <<"\n\n\t\tf'(x) = "<<dfx
           <<endl<<endl;
       }
       
    void Derivada::Central_X(void)
       {
           //Asignando los demas puntos Xi con h
           X[1]=X[0]+h;
           X[2]=X[1]+h;
           X[3]=X[0]-h;
           X[4]=X[3]-h;
           cout<<"\n\n\t\tPuntos:\n";
           for(int i=1;i<n;i++)
              cout<<"\n\t\tX"<<"["<<i<<"] = "<<X[i];
           cout<<endl;
           //Evaluando la funcion con los Xi
           for(int i=0;i<n-1;i++)
              Fx[i]=fx(X[i+1]);
           cout<<"\n\n\t\tFuncion evaluada:\n";
           for(int i=0;i<n-1;i++)
              cout<<"\n\t\tF"<<"["<<i+1<<"] = "<<Fx[i];
           cout<<endl;
           //Calculando derivada
           dfx=(-Fx[1]+8*Fx[0]-8*Fx[2]+Fx[3])/(12*h);
           cout<<"\n\n\t\tDerivada central (mas exacta):"
           <<"\n\n\t\tf'(x) = "<<dfx
           <<endl<<endl;
       }

int main(int argc, char *argv[])
{
    Derivada *AptD;
    AptD=new Derivada;
    int Opcion;
    char resp;
            
     do
      {
        Opcion=AptD->Menu();
        if(Opcion != 5)
         {
           system("cls");
           AptD->Leer();
         }
        switch(Opcion)
         {
           case 1:   AptD->Imprimir();
                     AptD->Adelante();
                     break;
           
           case 2:   AptD->Imprimir();
                     AptD->Atras();
                     break;
          
           case 3:   AptD->Imprimir();
                     AptD->Central();
                     break;
          
           case 4:   AptD->Imprimir();
                     AptD->Central_X();
                     break;
          
           case 5:   break;
         }
         cout<<"\n\n\t\tDESEA CONTINUAR? (S/N)"<<endl;
         cin>>resp;
      }while(resp=toupper(resp)!='N');
    
    delete AptD;
    return EXIT_SUCCESS;
}
