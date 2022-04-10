 
    #include <cstdlib>
    #include <iostream>
    #include <math.h>
    #include <F:\include\Ec Dif R-K.h>
    
    using namespace std;
    
    class Ec_Dif
          {
                public:
                        void Solucion(void);
          }; 
       
    void Ec_Dif::Solucion(void)
       {   
           system("cls");
           Metodo *Apt;
           Apt=new Metodo;
           
           Apt->Leer();
           Apt->RK();
           Apt->Imprimir();
       }         

    int main(int argc, char *argv[])
    {
        Ec_Dif *AptI;
        AptI=new Ec_Dif;
        
        AptI->Solucion();
    
        delete AptI;    
        system("pause");
        return EXIT_SUCCESS;
    }
    
