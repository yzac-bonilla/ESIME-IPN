    #include <cstdlib>
    #include <iostream>
    #include <stack>
    #include <queue>

    using namespace std;

    int Operacion(char Simbolo,int Op1,int Op2);

    int main()
    {
        char Simbolo,Simbolo2,R;
        int Op1,Op2,V,N;
        stack <char>IPila;
        queue <char>ICola;
        
        system("color F1");

        cout<<"\n\t\t Evaluacion de un Posfijo (AB+) \n\n";
		cout<<"\n Ingresa el numero de caracteres: ";
		cin>>N;
		
        
		for(int i=0;i<N;i++)
            {
                        cout<<"\n Ingresa el dato: ";
                        cin>>Simbolo ;
                        cin.ignore();
						ICola.push(Simbolo);
            }
        system("cls");
        
        while(!ICola.empty())
           {
                system("color F2");
                Simbolo2=ICola.front();
                if((Simbolo2 == '+') || (Simbolo2 =='-' )|| (Simbolo2 == '*') || (Simbolo2 == '/'))
                  {

						 Op2=int(IPila.top()-'0');
                         IPila.pop();
                         Op1=int(IPila.top()-'0');
                         IPila.pop();
                         V=Operacion(Simbolo2,Op1,Op2);
                         IPila.push(char('0'+V));
                         
                         cout <<"Operacion: " <<Op2<<Simbolo2<<Op1<<"="<<V<<endl;
                         cout <<"Top de la Pila: "<<IPila.top()<<endl;
                         cout<<endl;
					}
                else
                    {
                         IPila.push(Simbolo2);
                         cout <<"Top de la Pila: "<<IPila.top()<<endl;
                         cout<<endl;
                    }
                ICola.pop();
           }

        R=IPila.top();
        IPila.pop();
        cout<<"RESULTADO="<<R<<endl<<endl;

        system("PAUSE");
        return EXIT_SUCCESS;
    }

    int Operacion(char Simbolo,int Op1,int Op2)
       {
              int V;
              if(Simbolo=='+')
                  V=Op2+Op1;
              else
                  {
                      if(Simbolo=='-')
                          V=Op2-Op1;
                      else
                          {
                              if(Simbolo=='*')
                                  V=Op2*Op1;
                              else
                                  {
                                      if(Simbolo=='/')
                                           V=Op2/Op1;
                                  }
                          }

                  }
              return V;
       }

