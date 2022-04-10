    
    #include <cstdlib>
    #include <iostream>
    
    using namespace std;
    
    class enlace
    {
                private:
                        int dato, cont;
                        enlace *sig;
                
                public:
                       enlace (int v,int c,enlace *s=NULL):dato(v),cont(c),sig(s){};
                       void PideDato(void);
                       void MostrarDato(void);
                       void ModificaDato(int D);
                       void ModificaApt(enlace *WTF);
                       enlace* RegresaApt(void);
                       int RegresaDato(void);
                       int RegresaCont(void);
                       
                       
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
    
    int enlace::RegresaCont(void)
    {
        return cont;
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
                 void Insertar(int v, int c);
                 int ListaVacia(void){return (Inicio==NULL);}
                 void Borrar(int v);
                 void Mostrar(void);
                 int Moda(void);
                 ~lista();
    };
    
    void lista::Mostrar(void)
    {
         enlace *Aux=Inicio;
         while(Aux!=NULL)
         {
                          cout<<"\n\t\tEl valor: "<<Aux->RegresaDato()<<"\tAparece: "<<Aux->RegresaCont()<<endl;
                          Aux=Aux->RegresaApt();
         }
         cout<<endl;
    }
    
    int lista::Moda(void)
    {
        enlace *Aux, *Aux2;
        Aux=Inicio;
        Aux2=Inicio->RegresaApt();
        while(Aux2!=NULL)
        {
                         if(Aux->RegresaCont()<Aux2->RegresaCont())
                               Aux=Aux2;
                         Aux2=Aux2->RegresaApt();
        }
        return Aux->RegresaDato();
    }
    
    void lista::Insertar(int v, int c)
    {
         if(ListaVacia())
         {
                         Inicio=Fin=new enlace(v,c);
         }
         else
         {
             if(v<Inicio->RegresaDato())
             {
                                        Inicio=new enlace(v,c,Inicio);
             }
             else
             {
                 if(v>Fin->RegresaDato())
                 {
                                         Fin->ModificaApt(new enlace(v,c));
                                         Fin=Fin->RegresaApt();
                 }
                 else
                 {
                     enlace *Aux=Inicio;
                     while(v>Aux->RegresaApt()->RegresaDato())
                     Aux=Aux->RegresaApt();
                     Aux->ModificaApt(new enlace(v,c,Aux->RegresaApt()));
                 }
             }
         }
    }
    
    void lista::Borrar(int v)
    {
         if(v==Inicio->RegresaDato())
         {
                                     enlace *Aux;
                                     Aux=Inicio;
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
                                       cout<<"\n\t\t\tEl valor "<<v<<" no existe en la lista.\n\t\t";
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
        //lista *obj;
        //obj = new lista();
        lista obj;
        int Moda;
        
        cout<<"\n\n\t\tPROGRAMA PARA CALCULAR LA MODA\n\n\t\t";
        
        obj.Insertar(9,8);
        obj.Insertar(3,2);
        obj.Insertar(6,4);
        obj.Mostrar();
        
        Moda=obj.Moda(); 
        cout<<"\n\n\t\tMODA: "<<Moda<<"\n\n";
        
        //delete obj;
                
        system("PAUSE");
        return EXIT_SUCCESS;
    }
