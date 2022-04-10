#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char *argv[])
{
    queue<int>ICola;
    ICola.push(10);
    ICola.push(20);
    ICola.push(30);
    
    cout<<"Hay: "<<ICola.size()
        <<"Valores en la cola: "<<endl;
    
    while(!ICola.empty())
    {
        cout<<ICola.front()<<", ";
        ICola.pop();
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
