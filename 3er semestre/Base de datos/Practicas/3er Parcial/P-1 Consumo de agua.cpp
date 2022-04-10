#include <cstdlib>
#include <iostream>
#include <fstream>

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
                       void ModificaApt(enlace *SIG);
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
    
    void enlace::ModificaApt(enlace *SIG)
    {
         sig=SIG;
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
         cout<<endl<<"Cantidad de agua ordenados: ";
         while(Aux!=NULL)
         {
                          cout<<Aux->RegresaDato()<<", ";
                          Aux=Aux->RegresaApt();
         }
         cout<<endl;
         
         Aux=Inicio;
         cout<<"\nLa menor cantidad de agua que se gasto fue: "<<MenorRecursivo(Aux)<<endl<<endl;
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
                 
    lista::~lista()
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
    lista L;
        
    int num;
    char var[50]="Consumo.csv";
    ifstream entrada;
    entrada.open(var);
    
    if(entrada.fail())
    {   
        cout<<"El archivo no se abrio"<<endl;
        system("PAUSE");
        exit(1);
    }
    cout<<"\nImpresion de los dias y cantidad de agua"<<endl<<endl;
    
    for(int i=0; i<7;i++)
    {   
        entrada.getline(var,50, ',');
        cout<<var;
        entrada>>var;
        num=atoi(var);
        cout<<' '<<var<<endl;
        L.Insertar(num);
    }
    entrada.close();
    L.Mostrar();
       
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
