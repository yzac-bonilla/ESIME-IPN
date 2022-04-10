#include <cstdlib>
#include <iostream>

using namespace std;

class enlace
{
      private:
              enlace *izq;
              int dato;
              enlace *der;
      public:
              enlace (int v, enlace *i=NULL, enlace *d=NULL):dato(v),izq(i),der(d){}
              enlace *&RegresaDer(void){return der;}
              enlace *&RegresaIzq(void){return izq;}
              void PideDato(void);
              int RegresaDato(void);
              void MostrarDato(void);
              void ModificaDato(int D);
              void ModificaApt(enlace *WTF);
              void ModificaAnt(enlace *ANTE);
              
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
         der=WTF;
    }
    
    void enlace::ModificaAnt(enlace *ANTE)
    {
         izq=ANTE;
    }

class AB
{
      private:
              enlace *raiz, *actual;
              void Insertar(int, enlace*&);
              void Podar(enlace *&);
              void Entre(enlace *);
              void Pre(enlace *);
              void Post(enlace *);
      public:
              AB(){raiz=actual=NULL;}
              //~AB(){Podar(raiz);}
              void Inserta(int d){Insertar(d,raiz);}
              void Raiz(){actual=raiz;}
              void Entreorden(){Raiz();Entre(actual);};
              void Preorden(){Raiz();Pre(actual);};
              void Postorden(){Raiz();Post(actual);};
              void BorrarPodar(){Raiz();Podar(actual);};
};

void AB::Insertar(int v, enlace *&raiz)
{
     enlace *a=raiz;
     
     if(a==NULL)
        raiz=new enlace(v);
     
     else
         if(v<=a->RegresaDato())
         Insertar(v,a->RegresaIzq());
         
         else
         Insertar(v,a->RegresaDer());
}

void AB::Entre(enlace *a)
{
     if(a!=NULL)
     {   
         Entre(a->RegresaIzq());
         cout<<a->RegresaDato()<<',';
         Entre(a->RegresaDer());
     }
}

void AB::Pre(enlace *a)
{
     if(a!=NULL)
     {   
         cout<<a->RegresaDato()<<',';
         Pre(a->RegresaIzq());
         Pre(a->RegresaDer());
     }
}

void AB::Post(enlace *a)
{
     if(a!=NULL)
     {   
         Post(a->RegresaIzq());
         Post(a->RegresaDer());
         cout<<a->RegresaDato()<<',';
     }
}

void AB::Podar(enlace *&a)
{
     if(a!=NULL)
     {   
         Podar(a->RegresaIzq());
         Podar(a->RegresaDer());
         cout<<"Dato borrado: "<<a->RegresaDato()<<endl;
         delete a;
     }
}
     

int main(int argc, char *argv[])
{
    enlace *AptW;
    AptW=new enlace(0,NULL);
    
    AB obj;
    int V,N=0;
    
    cout<<"Ingresa el numero de datos: ";
    cin>>N;
    for(int i=0;i<N;i++)
      {
      AptW->PideDato();
      V=AptW->RegresaDato();
      obj.Inserta(V);
      }
    
    
    cout<<"\nEntreorden: ";obj.Entreorden();cout<<endl;
    cout<<"Preorden: ";obj.Preorden();cout<<endl;
    cout<<"Postorden: ";obj.Postorden();cout<<endl;
    cout<<endl;
    cout<<"Borrar datos del arbol"<<endl;
    obj.BorrarPodar();
    cout<<endl;
             
    system("PAUSE");
    return EXIT_SUCCESS;
}
