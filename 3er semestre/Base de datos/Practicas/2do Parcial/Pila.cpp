#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char *argv[])
{
    stack<int>IPila;
    IPila.push(10);
    IPila.push(20);
    IPila.push(30);
    
    cout<<"Hay: "
        <<IPila.size()<<endl
        <<"Valores en la pila: "<<endl
        <<"El valor de la Cima es: "
        <<IPila.top()<<endl;
        
    while(!IPila.empty())
    {
        cout<<IPila.top()
            <<", ";
        IPila.pop();
    }
    cin.get();
        
    system("PAUSE");
    return EXIT_SUCCESS;
}
