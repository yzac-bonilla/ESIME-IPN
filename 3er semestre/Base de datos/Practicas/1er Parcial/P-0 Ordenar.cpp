   
    #include <cstdlib>
    #include <iostream>
    
    using namespace std;
    class Enteros
              {
                     private:
                             int Dato;
                     public:
                            Enteros(int D=0):Dato(D){};
                            void Leer(void);
                            int RegresaDatos(void);
                            void Imprimir(void);
              };
              
    void Enteros::Leer(void)
         {
                         cout<<"\n\n\t\tIngresa un dato: \n";
                         cin>>Dato;
         }
    
    int Enteros::RegresaDatos(void)
       {
              return Dato;
       } 
          
    void Enteros::Imprimir(void)
       {
            cout<<"\n\t\tDato: "<<Dato;
       } 
           
    int main(int argc, char *argv[])
      {
        cout<<"\n\n\t\tPROGRAMA PARA ORDENAR DATOS DE UN ARREGLO\n";
        //TAMAÑO ARREGLO
        int n=0;
        while(n<=0)
           {
                cout<<"\n\n\t\tIngrese el tamaño del Arreglo: ";
                cin>>n;  
           }
        //DECLARACION VARIABLES   
        Enteros Arreglo[n];
        Enteros *Direc[n];
        Enteros *Ordenar;
        
        //ARREGLOS
        for(int i=0;i<n;i++)
          {
             Direc[i]=&Arreglo[i];
          }
      
        for(int i=0;i<n;i++)
          {
            Arreglo[i].Leer();
          }
        
        system("cls");
        //BURBUJA
        for(int i =0; i <n; i++)
          {
            for(int j = 0; j<n-1 ; j++)
            {
                if( Direc[j+1]->RegresaDatos() < Direc[j]->RegresaDatos())
                   {
                        Ordenar = Direc[j];
                        Direc[j] = Direc[j+1];
                        Direc[j+1] = Ordenar;
                   }
            }
          }      
        //IMPRIMIR
        cout  << "\n\n\t\tDATOS INGRESADOS(SIN ORDENAR):\n\t\t"<<endl;
        for(int i=0;i<n;i++)
           {
                Arreglo[i].Imprimir();
                cout<< " Direccion: "<<&Arreglo[i]
                <<endl;
           }
      
        cout  << "\n\n\t\tDATOS ORDENADOS:\n\t\t"<<endl;
        for(int i=0;i<n;i++)
           {
                Direc[i]->Imprimir();
                cout<< " Direccion: "<<Direc[i]
                <<endl;
           }
             
        system("PAUSE");
        return EXIT_SUCCESS;
      }

    
    
        
