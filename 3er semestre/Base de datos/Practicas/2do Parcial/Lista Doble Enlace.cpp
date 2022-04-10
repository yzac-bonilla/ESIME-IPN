
    #include <cstdlib>
    #include <iostream>
    
    using namespace std;
    
    class enlace
    {
                private:
                        int dato;
                        enlace *sig,*ant;
                
                public:
                       enlace (int v,enlace *s=NULL,enlace *a=NULL):dato(v),sig(s),ant(a){};
                       void PideDato(void);
                       int RegresaDato(void);
                       void MostrarDato(void);
                       void ModificaDato(int D);
                       void ModificaApt(enlace *WTF);
                       enlace* RegresaApt(void);
                       void ModificaAnt(enlace *ANTE);
                       enlace* RegresaAnt(void);
    };
    
    void enlace::PideDato(void)
    {
         cout<<"\n\n\t\tIngresa un entero: ";
         cin>>dato;
    }
    
    void enlace::ModificaDato(int D)
    {
         dato=D;
    }
    
    int enlace::RegresaDato(void)
    {
        return dato;
    }
    
    void enlace::MostrarDato(void)
    {
         cout<<"\n\t\tDato Ingresado: "<<dato;
    }
    
    void enlace::ModificaApt(enlace *WTF)
    {
         sig=WTF;
    }
    
    enlace* enlace::RegresaApt(void)
    {
           return sig;
    }
    
    void enlace::ModificaAnt(enlace *ANTE)
    {
         ant=ANTE;
    }
    
    enlace* enlace::RegresaAnt(void)
    {
           return ant;
    }
    
    class listaD
    {
          private:
                  enlace *Primero;
                  enlace *Ultimo;
                  
          public:
                 listaD(){Primero=Ultimo=NULL;}
                 void Insertar(int v);
                 int ListaVacia(void){return (Primero==NULL);}
                 void Borrar(int v);
                 void Mostrar(void);
                 ~listaD();
    };
    
    void listaD::Mostrar(void)
    {
         if(Primero != NULL)
            {
                cout<<"\n\n\n\t\tLista de *Primero a *Ultimo: ";
                enlace *aux=Primero;
                while(aux != NULL)
                   {
                        cout<<aux->RegresaDato()<<", ";
                        aux=aux->RegresaApt();
                   }
                cout<<"\n\n\t\tLista de *Ultimo a *Primero: ";
                aux=Ultimo;
                while(aux != NULL)
                   {
                        cout<<aux->RegresaDato()<<", ";
                        aux=aux->RegresaAnt(); 
                   }
                cout<<endl;
            }
         else
             cout<<"La lista esta vacia";
    }
    
    void listaD::Insertar(int v)
    {
         if(!Primero)
             Primero=Ultimo=new enlace(v);
         else
            {
                 if(v<Primero->RegresaDato())
                    {
                        Primero=new enlace(v,Primero,NULL);
                        Primero->RegresaApt()->ModificaAnt(Primero);
                    }
                 else
                    {
                        if(v>Ultimo->RegresaDato())
                           {
                               Ultimo=new enlace(v,NULL,Ultimo);
                               Ultimo->RegresaAnt()->ModificaApt(Ultimo);
                           }
                        else
                           {
                               enlace *aux;
                               aux=Primero;
                               while(v>aux->RegresaApt()->RegresaDato())
                                   aux=aux->RegresaApt();
                               aux=new enlace(v,aux->RegresaApt(),aux);
                               aux->RegresaAnt()->ModificaApt(aux);
                               aux->RegresaApt()->ModificaAnt(aux);
                           }
                    }
            }
    }
    
    void listaD::Borrar(int v)
    {
         if(Primero)
            {
                enlace *aux;
                if(v<Primero->RegresaDato())
                   cout<<"El dato"<<v<<"no esta en la lista";
                else
                   {
                       if(v==Primero->RegresaDato())
                          {
                             aux=Primero;
                             Primero=Primero->RegresaApt();
                             delete aux;
                             Primero->ModificaAnt(NULL);
                          }
                       else
                           {
                              if(v>Ultimo->RegresaDato())
                                 cout<<"El dato"<<v<<"no esta en la lista";
                              else
                                {
                                    if(v==Ultimo->RegresaDato())
                                       {
                                           aux=Ultimo;
                                           Primero=Ultimo->RegresaAnt();
                                           delete aux;
                                           Primero->ModificaApt(NULL);
                                       }
                                    else
                                       {
                                           aux=Primero->RegresaApt();
                                           while(aux->RegresaDato()<v)
                                               aux=aux->RegresaApt();
                                           if(v!=aux->RegresaDato())
                                              cout<<"El dato"<<v<<"no esta en la lista";
                                           else
                                              {
                                                 aux->RegresaAnt()->ModificaApt(aux->RegresaApt());
                                                 aux->RegresaApt()->ModificaApt(aux->RegresaAnt());//?
                                                 delete aux;
                                              }
                                       }
                                }
                           }
                   }
            }
    }
    
    listaD::~listaD()//DESTRUCTOR
    {
        while(Primero != NULL)
          {
             enlace *Aux=Primero;
             Primero=Primero->RegresaApt();
             delete Aux;
          }     
        delete Primero;
    }       
                       
     int main(int argc, char *argv[])
    {
        enlace *AptE;
        AptE=new enlace(0,NULL,NULL);
        listaD *AptL;
        AptL=new listaD();
        int N=0,v;
        
        cout<<"\n\n\t\tPROGRAMA PARA INSERTAR DATOS EN UNA LISTA\n\t\t";
        while(N<=0)
            {
                cout<<"\n\n\t\tIngrese el tamaño de la Lista: \n\n\t\t";
                cin>>N;
                system("CLS");
            }
        
        for(int i=0;i<N;i++)
                {               
                    AptE->PideDato();
                    v=AptE->RegresaDato();
                    AptL->Insertar(v);
                }
        AptL->Mostrar();        
        
        delete AptE;
        delete AptL;
                
        system("PAUSE");
        return EXIT_SUCCESS;
    }
                                  
                
    
