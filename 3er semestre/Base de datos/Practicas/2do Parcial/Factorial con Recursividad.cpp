    
    #include <cstdlib>
    #include <iostream>
    
    using namespace std;

    int Leer(void);      
    void Imprimir(int Num,int Fac);
    int FactRecursivo(int Num);
             
    int main(int argc, char *argv[])
    {   
        int n,f;
        
        n=Leer();
        f=FactRecursivo(n);
        Imprimir(n,f);
        
        system("PAUSE");
        return EXIT_SUCCESS;
    }

    int Leer(void)
    {
         int Num;
         cout<<"\n\n\t\tIngrese un Numero Entero: ";
         cin>>Num;
         return Num;
    }
     
    void Imprimir(int Num,int Fac)
    {
         cout<<"\n\t\tEl Factorial de "<<Num<<" es: "<<Fac<<endl;
    }
    
    int FactRecursivo(int Num)
    {
           if(Num==0 || Num==1)
               return 1;
           return Num*FactRecursivo(Num-1);
    }
