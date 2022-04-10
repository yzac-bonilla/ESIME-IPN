#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    //Escribir en un archivo
    ofstream asalida("prueba.txt");
    asalida<<"Hola Mundo"<<endl;
    asalida.close();
    
    //Imprimir una palabra de un archivo
    ifstream aentrada("prueba.txt");
    char var[20];
    aentrada>>var;
    cout<<var<<endl;
    aentrada.close();
    
    //Imprimir todo un archivo
    ifstream aentrada2("prueba.txt");
    aentrada2.getline(var,20);
    cout<<var<<endl;
    aentrada2.close();
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
