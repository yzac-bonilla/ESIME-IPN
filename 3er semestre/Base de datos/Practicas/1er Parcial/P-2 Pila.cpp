    
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

    class Pila
          {
              private:
                      enlace *tope;
              public:
                     Pila(){tope=NULL;}
                     void Push(int v);
                     int Pop(void);
                     int Cima(void);
                     enlace* PilaVacia(){return tope=NULL;}
          };
          
    void Pila::Push(int v)
         {
                        tope=new enlace(v,tope);
         }
         
    int Pila::Cima(void)
        {
                        return(tope->RegresaDato());
        }
        
    int Pila::Pop(void)
        {
                       int v=-1;
                       if(!PilaVacia())
                           {
                               v=tope->RegresaDato();
                               enlace *Aux=tope;
                               tope=tope->RegresaApt();
                               delete Aux;
                           }
                       else
                           cout<<"\n\t\tLa Pila esta Vacia\n\t\t";
                       return v;
        }
                           
                             
    
    int main(int argc, char *argv[])
    {
        enlace *AptE;
        AptE=new enlace(0,NULL);
        Pila *AptP;
        AptP=new Pila();
        int N=0,v,I;
        
        cout<<"\n\n\t\tPROGRAMA PARA INSERTAR DATOS EN UNA PILA\n\t\t";
        while(N<=0)
            {
                cout<<"\n\n\t\tIngrese el tamaño de la Pila: \n\n\t\t";
                cin>>N;
                system("CLS");
            }
        
        for(int i=0;i<N;i++)
                {               
                    AptE->PideDato();
                    v=AptE->RegresaDato();
                    AptP->Push(v);
                }
        I=AptP->Cima();
        cout<<"\n\n\t\tPila(Cima): "<<I<<endl;
        
        delete AptE;
        delete AptP;
    
        system("PAUSE");
        return EXIT_SUCCESS;
    }
