    
    #include <cstdlib>
    #include <iostream>
    
    using namespace std;
    
    class enlace
    {
                private:
                        int dato;
                        enlace *sig;
                
                public:
                       enlace (int v,enlace *s=NULL):dato(v),sig(s){};
                       void PideDato(void);
                       void MostrarDato(void);
                       void ModificaDato(int D);
                       void ModificaApt(enlace *WTF);
                       enlace* RegresaApt(void);
                       int RegresaDato(void);
                       
                       
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
    
    class lista
    {
          private:
                  enlace *Inicio;
                  enlace *Fin;
                  
          public:
                 lista(){Inicio=Fin=NULL;}
                 void Insertar(int v);
                 int ListaVacia(void){return (Inicio==NULL);}
                 void Borrar(int v);
                 void Mostrar(void);
                 ~lista();
    };
    
    void lista::Mostrar(void)
    {
         enlace *Aux=Inicio;
         cout<<endl<<"\n\t\tLista: ";
         while(Aux!=NULL)
         {
                          cout<<Aux->RegresaDato()<<", ";
                          Aux=Aux->RegresaApt();
         }
         cout<<endl;
    }
    
    void lista::Insertar(int v)
    {
         if(ListaVacia())
         {
                         Inicio=Fin=new enlace(v);
         }
         else
         {
             if(v<Inicio->RegresaDato())
             {
                                        Inicio=new enlace(v,Inicio);
             }
             else
             {
                 if(v>Fin->RegresaDato())
                 {
                                         Fin->ModificaApt(new enlace(v));
                                         Fin=Fin->RegresaApt();
                 }
                 else
                 {
                     enlace *Aux=Inicio;
                     while(v>Aux->RegresaApt()->RegresaDato())
                          Aux=Aux->RegresaApt();
                     Aux->ModificaApt(new enlace(v,Aux->RegresaApt()));
                 }
             }
         }
    }
    
    void lista::Borrar(int v)
    {
         if(v==Inicio->RegresaDato())
         {
                                     enlace *Aux=Inicio;
                                     Inicio=Inicio->RegresaApt();
                                     delete Aux;
         }
         else
         {
             enlace *Aux=Inicio;
             while(Aux->RegresaApt()!=NULL && v>Aux->RegresaApt()->RegresaDato())
                       Aux=Aux->RegresaApt();
         
             if(v==Fin->RegresaDato())
             {
                                      delete Fin;
                                      Aux->ModificaApt(NULL);
                                      Fin=Aux;
             }
             
             else
             {
                 if(!Aux->RegresaApt())
                 {
                                       cout<<"\n\t\tEl valor "<<v<<" no existe en la lista.\n\t\t";
                 }
                 else
                 {
                     enlace *Aux2=Aux->RegresaApt();
                     if(Aux2->RegresaDato()==v)
                     {
                                                Aux->ModificaApt(Aux->RegresaApt()->RegresaApt());
                                                delete Aux2;
                     }
                     else
                     {
                         cout<<"\n\t\tEl valor no existe en la lista.\n\t\t";
                     }
                 }
             }
         }
    }
             
    lista::~lista()//DESTRUCTOR
         {
                   while(Inicio != NULL)
                        {
                             enlace *Aux=Inicio;
                             Inicio=Inicio->RegresaApt();
                             delete Aux;
                        }     
                   delete Inicio;
         }                  
    
    int main(int argc, char *argv[])
    {
        enlace *AptE;
        AptE=new enlace(0,NULL);
        lista *AptL;
        AptL=new lista();
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
    
    
    
    
    
    
    
    
    
    
