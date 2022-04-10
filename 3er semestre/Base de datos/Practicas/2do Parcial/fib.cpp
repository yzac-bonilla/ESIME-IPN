    
    #include <cstdlib>
    #include <iostream>
    
    using namespace std;    

    int fib(int x);
    int Leer(void);
            
    int main(int argc, char *argv[])
    {
        int F,X;
        
        X=Leer();
        F=fib(X);
        cout<<"\n\n\t\t"<<F<<endl;
        
        system("PAUSE");
        return EXIT_SUCCESS;
    }

    int fib(int x)
    {
           if(x==0 || x==1)
               return 1;
           return fib(x-1)+fib(x-2);
    }

    int Leer(void)
    {
         int x;
         cout<<"\n\n\t\tIngrese un Numero Entero: ";
         cin>>x;
         return x;
    }
