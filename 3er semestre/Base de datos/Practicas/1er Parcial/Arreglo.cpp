   
    #include <cstdlib>
    #include <iostream>
    
    using namespace std;
    class Enteros
              {
                     private:
                             int *Dato;
                             int N;
                     public:
                            Enteros(int n=1):N(n){};
                            void Leer(void);
                            int LeerN(void);
                            void Imprimir(void);
                            Enteros* Ordenar(void); 
                            void Imprimir2(void);
                            ~Enteros(void){delete []Dato;}
              };
              
    void Enteros::Leer(void)
         {
                         N=LeerN();
                         cout<<"\n\n\t\tIngresa los datos: \n";
                         Dato=new int[N];
                         for(int i=0;i<N;i++)
                                 {
                                     cout<<"\t\t";
                                     cin>>Dato[i];
                                 }
         }
         
    int Enteros::LeerN(void)
        {
                 int n;
                 cout<<"\n\n\t\tIngrese el tamaño del Arreglo: ";
                 cin>>n;
                 return n;
        }
        
    void Enteros::Imprimir(void)
         {
                            cout<<"\n\n\t\tDatos Insertados (Sin Ordenar):\n\n";
                            for(int i=0;i<N;i++)
                   {
                                     cout<<"\n\t\tDato "
                                     <<i
                                     <<": "
                                     <<Dato[i]
                                     <<endl;
                                       
                   }  
         }
                  
    Enteros* Enteros::Ordenar(void)
             {
                                   int temp;
                                   for (int i=1; i<N; i++)
                                   {
                                       for (int j=0 ; j<N-1; j++)
                                       {
                                           if (Dato[j] > Dato[j+1])
                                           {
                                                       temp = Dato[j];
                                                       Dato[j] = Dato[j+1];
                                                       Dato[j+1] = temp;
                                           }
                                       }
                                   }
             }  
             
    void Enteros::Imprimir2(void)
         {
                cout<<"\n\n\t\tDatos Ordenados: \n\n";
                for(int i=0;i<N;i++)
                                 {
                                     cout<<"\n\t\tDato "
                                     <<i
                                     <<": "
                                     <<Dato[i]
                                     <<endl;   
                                 } cout<<"\n"; 
         }
           
    int main(int argc, char *argv[])
    {
        Enteros *AptV;
        AptV=new Enteros;
        
        cout<<"\n\n\t\tARREGLO PARA GUARDAR ENTEROS\n";
        AptV->Leer();
        system("cls");
        AptV->Imprimir();
        AptV->Ordenar();
        AptV->Imprimir2();
        delete AptV;
        
        
        system("PAUSE");
        return EXIT_SUCCESS;
    }
    
    
        
