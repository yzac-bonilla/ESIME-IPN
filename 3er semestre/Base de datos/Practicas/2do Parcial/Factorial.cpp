    
    #include <cstdlib>
    #include <iostream>
    
    using namespace std;
    
    class Factorial
          {
                   private: 
                            double Num,Fac;
                   public:
                            void Leer(void);
                            void Imprimir(void);
                            double Fact(void);
          };
          
    void Factorial::Leer(void)
    {
         cout<<"\n\n\t\tIngrese un Numero Entero: ";
         cin>>Num;
    }
     
    void Factorial::Imprimir(void)
    {
         cout<<"\n\t\tEl Factorial de "<<Num<<" es: "<<Fac<<endl;
    }
     
    double Factorial::Fact(void)
    {
        Fac=1;
        for(int i=1;i<=Num;i++)
            Fac=Fac*i;
        return(Fac);
    }
       
    int main(int argc, char *argv[])
    {
        Factorial *AptF;
        AptF=new Factorial;
        double n;
        
        AptF->Leer();
        AptF->Fact();
        system("cls");
        AptF->Imprimir();
        
        delete AptF;
        system("PAUSE");
        return EXIT_SUCCESS;
    }
