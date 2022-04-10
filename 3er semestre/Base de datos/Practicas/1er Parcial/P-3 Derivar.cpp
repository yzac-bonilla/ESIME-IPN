
    #include <cstdlib>
    #include <iostream>
    
    using namespace std;

      class enlace
      {
            private:
                    float coef;
                    float expo;
                    enlace *sig;
            
            public:
                    enlace (float c,float e,enlace *s=NULL):coef(c),expo(e),sig(s){};
                    void PideDato(void);
                    void MostrarDato(void);
                    void ModificaApt(enlace *WTF);
                    enlace* RegresaApt(void);
                    float RegresaCoef(void);
                    float RegresaExpo(void);                    
                       
    };
    
    void enlace::PideDato(void)
    {
         cout<<"\n\n\t\tIngresa el coeficiente de X: ";
         cin>>coef;
         cout<<"\n\t\tIngresa el exponente de X: ";
         cin>>expo;
    }
    
    float enlace::RegresaCoef(void)
    {
        return coef;
    }
    
    float enlace::RegresaExpo(void)
    {
        return expo;
    }
    
    void enlace::MostrarDato(void)
    {
         cout<<"\n\t\tTermino Ingresado: "<<coef<<"x^"<<expo<<"\n\n";
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
                 void Insertar(float c, float e);
                 int ListaVacia(void){return (Inicio==NULL);}
                 void Borrar(int v);
                 void Mostrar(void);
                 void Derivar(void);
                 ~lista();
    };
    
    void lista::Mostrar(void)
    {
         enlace *Aux=Inicio;
         cout<<endl<<"\n\t\tECUACION: \n\n\t\t";
         while(Aux!=NULL)
         {
                          cout<<Aux->RegresaCoef()<<"X^"<<Aux->RegresaExpo()<<" + ";
                          Aux=Aux->RegresaApt();
         }
         cout<<endl;
    }
    
    void lista::Derivar(void)
    {
         enlace *Aux=Inicio;
         cout<<endl<<"\n\t\tDERIVADA: \n\n\t\t";
         while(Aux!=NULL)
         {
                          if(Aux->RegresaExpo() == 1)
                              {
                                     cout<<Aux->RegresaCoef()<<" + ";
                                     Aux=Aux->RegresaApt();
                              }
                          else
                              {
                                      if(Aux->RegresaExpo() == 0)
                                         {
                                              cout<<"0"<<" + ";
                                              Aux=Aux->RegresaApt();
                                         }
                                      else
                                          {
                                              cout<<Aux->RegresaCoef()*Aux->RegresaExpo()<<"x^"<<Aux->RegresaExpo()-1<<" + ";
                                              Aux=Aux->RegresaApt();
                                          }
                              }
         }
         cout<<endl;
    }
         
    void lista::Insertar(float c, float e)
    {
         if(ListaVacia())
         {
                         Inicio=Fin=new enlace(c,e);
         }
         
         else
         {
             if(e>Inicio->RegresaExpo())
             {
                                        Inicio=new enlace(c,e,Inicio);
             }
             else
             {
                 if(e<Fin->RegresaExpo())
                 {
                                         
                                         Fin->ModificaApt(new enlace(c,e));
                                         Fin=Fin->RegresaApt();
                 }
                 else
                 {
                     enlace *Aux=Inicio;
                     if(e == Aux->RegresaExpo())
                        {
                              Fin->ModificaApt(new enlace(c,e));
                              Fin=Fin->RegresaApt();
                        }
                     else
                         {
                             
                             while(e<Aux->RegresaApt()->RegresaExpo())
                                   Aux=Aux->RegresaApt();
                             Aux->ModificaApt(new enlace(c,e,Aux->RegresaApt()));
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
            AptE=new enlace(0,0,NULL);
            lista *AptL;
            AptL=new lista();
            float c,e;
            int N=0;
            
            cout<<"\n\n\tPROGRAMA PARA CALCULAR LA DERIVADA DE X^n (EJ: 5X^3 + 2X^10 - 6X^2)\n";  
            while(N<=0)
                {
                    cout<<"\n\n\t\tIngrese el numero total de terminos con X: ";
                    cin>>N;
                    system("CLS");
                }
            
            for(int i=0;i<N;i++)
                    {
                        AptE->PideDato();
                        c=AptE->RegresaCoef();
                        e=AptE->RegresaExpo();
                        AptL->Insertar(c,e);
                        AptE->MostrarDato();
                    }
            AptL->Mostrar();
            AptL->Derivar();
            
            delete AptE;
            delete AptL;
        
        
        system("PAUSE");
        return EXIT_SUCCESS;
    }
