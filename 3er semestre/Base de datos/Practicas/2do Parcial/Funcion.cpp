    
    #include <cstdlib>
    #include <iostream>
    
    using namespace std;    

    int Funcion(int a,int b);
    int LeerA(void);
    int LeerB(void);
            
    int main(int argc, char *argv[])
    {
        int F,A,B;
        
        A=LeerA();
        B=LeerB();
        F=Funcion(A,B);
        cout<<"\n\n\t\t"<<F<<endl;
        
        system("PAUSE");
        return EXIT_SUCCESS;
    }

    int Funcion(int a,int b)
    {
           if(b<=0)
               return 1;
           return a*Funcion(a,b-1);
    }

    int LeerA(void)
    {
         int x;
         cout<<"\n\n\t\tIngrese un Numero Entero: ";
         cin>>x;
         return x;
    }

    int LeerB(void)
    {
         int x;
         cout<<"\n\n\t\tIngrese un Numero Entero: ";
         cin>>x;
         return x;
    }
