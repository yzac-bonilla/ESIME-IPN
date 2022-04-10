#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    char Archivo[21]="prueba3.dat";
    ofstream archsal;
    archsal.open(Archivo);
    if(archsal.fail())
    {   
        cout<<"El archivo no se abrio";
        exit(1);
    }
    //Escribir en el archivo
    archsal<<"uno "<<4.93<<endl
           <<"dos "<<8.21<<endl
           <<"tres "<<15.09<<endl;
    archsal.close();
    
    //Imprimir lo q se escribio en el archivo
    ifstream aentrada("prueba3.dat");
    char var[20];
    aentrada.getline(var,20);
    cout<<var<<endl;
    aentrada.getline(var,20);
    cout<<var<<endl;
    aentrada.getline(var,20);
    cout<<var<<endl;
    aentrada.close();
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
