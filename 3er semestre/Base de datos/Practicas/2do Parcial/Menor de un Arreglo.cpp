#include <cstdlib>
#include <iostream>

using namespace std;

void imprime(int a[], int i, int j);
void Menor (int a[], int i, int j);

    int main(int argc, char *argv[])
    {
        int N,i=0;
        
        cout<<"\n\n\t\tEjercicio Recursion\n";
        
        cout<<"\n\n\t\tIngrese el tamaño del Arreglo: ";
        cin>>N;
        
        int a[N];
        cout<<"\n\n\t\tIngresa los datos: \n";
        for(int k=0;k<N;k++)
            {
                cout<<"\t\t";
                cin>>a[k];
            }
            
        system("cls");
        
        cout<<"\n\n\t\tArreglo: ";
        imprime(a,i,N); 
        Menor(a,i,N);
        
        system("PAUSE");
        return EXIT_SUCCESS;
    }

void imprime(int a[], int i, int j)
    {       
         if(i<j)
         {
                cout<<a[i]<<", ";
                imprime(a,i+1,j);
         }
    }

void Menor (int a[], int i, int j)
    {
         int v=a[i];
         while(i<j)
            {
                 if(v>=a[i+1])
                    v=a[i+1];                        
                 i=i+1;
            }
         cout<<"\n\n\n\t\tMenor del Arreglo: "<<v<<endl;
    }
