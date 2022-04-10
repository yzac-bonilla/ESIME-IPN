#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream entrada;
    ofstream salida;
    
    char buffer[2048];
    int bytesleidos;
    
    if(argc != 3)
    {
            cout<<"Utilizar: copia <archivo_origen> <archivo_destino>";
            return 1;
    }
    
    entrada.open(argv[1]);
    if(!entrada.good())
    {       
            cout<<"El archivo no se pudo abrir";
            return 1;
    }
    
    salida.open(argv[2]);
    if(!salida.good())
    {
            cout<<"El archivo no se pudo abrir";
            return 1;
    }
    
    do
    {
            entrada.read(buffer,2048);
            bytesleidos=entrada.gcount();
            salida.write(buffer,bytesleidos);
    }while(bytesleidos>0);
    entrada.close();
    salida.close();
    return 0;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
