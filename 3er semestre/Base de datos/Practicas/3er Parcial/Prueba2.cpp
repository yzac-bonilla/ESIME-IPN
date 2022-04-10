#include <cstdlib>
#include <iostream>
#include <fstream>

//Programa q invierte el texto del archivo prueba 3
using namespace std;

int main(int argc, char *argv[])
{
    char Archivo[21]="prueba3.dat";
    char car;
    
    int long des,ultimo;
    ifstream archent;
    archent.open(Archivo);
    if(archent.fail())
    {   
        cout<<"El archivo no se abrio";
        exit(1);
    }
    archent.seekg(0L, ios::end);
    ultimo=archent.tellg();
    for(des=1L; des<=ultimo; des++)
    {   
        archent.seekg(-des,ios::end);
        car=archent.get();
        cout<<car;
    }
    archent.close();
    cout<<endl<<endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
