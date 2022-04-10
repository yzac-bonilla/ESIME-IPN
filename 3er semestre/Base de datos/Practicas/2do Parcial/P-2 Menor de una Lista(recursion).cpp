    
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
                       void ModificaApt(enlace *WTF);
                       enlace* RegresaApt(void);
                       int RegresaDato(void);
                       
                       
    };
    
    void enlace::PideDato(void)
    {
         cout<<"\n\n\t\tIngresa un entero: ";
         cin>>dato;
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
                  int MenorRecursivo(enlace* Aux);
                  
          public:
                 lista(){Inicio=Fin=NULL;}
                 void Insertar(int v);
                 int ListaVacia(void){return (Inicio==NULL);}
                 void Mostrar(void);
                 void Menor(void);
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
         
         Aux=Inicio;
         cout<<"\n\n\t\tEl menor de la Lista con recursion es: "<<MenorRecursivo(Aux)<<"\n\n\t\t";
    }
    
    void lista::Menor(void)
    {
         enlace *Aux=Inicio;
         int v=Aux->RegresaDato();
         cout<<endl<<"\n\t\tMenor de la Lista: ";
         while(Aux!=NULL)
         {
              if(v>=Aux->RegresaDato())
                    v=Aux->RegresaDato();                          
              Aux=Aux->RegresaApt();
         }
         cout<<v<<endl;
    }
    
    int lista::MenorRecursivo(enlace* Aux)
    {
         static int V=Aux->RegresaDato();
         if(Aux!=NULL)
            {
                 if(V >= Aux->RegresaDato())
                       V=Aux->RegresaDato();
                 Aux=Aux->RegresaApt();
                 MenorRecursivo(Aux);
            }           
         return V;
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
            system("cls");
            AptL->Mostrar();
            
            delete AptE;
            delete AptL;
        
        system("PAUSE");
        return EXIT_SUCCESS;
    }
