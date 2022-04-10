
    #include <cstdlib>
    #include <iostream>
    
    using namespace std;

    class Arreglo
      {
          private:
                  int N, *Dato,I;
                  int MenorRecursivo (int a[], int i, int j);
                  void imprime(int a[], int i, int j);
          public:
                 Arreglo(int n=1,int *D=NULL,int In=0):N(n),Dato(D),I(In){};
                 int Leer(void);
                 void Mostrar(void);
                 //void Menor (int a[], int i, int j);
      };
      
    int Arreglo::Leer(void)
      {
            cout<<"\n\n\t\tIngrese el tamaño del Arreglo: ";
            cin>>N;
            
            Dato=new int[N];
            cout<<"\n\n\t\tIngresa los datos: \n";
            for(int i=0;i<N;i++)
               {
                   cout<<"\t\t";
                   cin>>Dato[i];
               }
      }
     
     void Arreglo::imprime(int a[], int i, int j)
    {       
         if(i<j)
         {
                cout<<a[i]<<", ";
                imprime(a,i+1,j);
         }
    }
        
    /*void Arreglo::Menor (int a[], int i, int j)
    {
         int v=a[i];
         while(i<j)
            {
                 if(v>=a[i+1])
                    v=a[i+1];                        
                 i=i+1;
            }
         cout<<"\n\n\n\t\tMenor del Arreglo: "<<v<<endl;
    }*/
    
    int Arreglo::MenorRecursivo (int a[], int i, int j)
    {
         static int v=a[i];
         if(i<j)
            {
                 if(v>=a[i+1])
                   v=a[i+1];
                 MenorRecursivo(a,i+1,j);
            }
          return v;                 
    }
                        
    void Arreglo::Mostrar(void)
    {
         cout<<"\n\n\t\tArreglo: ";
         imprime(Dato,I,N);
         cout<<endl
         <<"\n\n\t\tEl menor del arreglo con recursion es: "<<MenorRecursivo(Dato,I,N)<<endl;
    }
         
    int main(int argc, char *argv[])
    {
        Arreglo *Apt1;
        Apt1=new Arreglo();
        
        cout<<"\n\n\t\tEjercicio Recursion\n";
        Apt1->Leer();
        system("cls");
        
        Apt1->Mostrar();
        
        delete Apt1;
        
        system("PAUSE");
        return EXIT_SUCCESS;
    }
 
