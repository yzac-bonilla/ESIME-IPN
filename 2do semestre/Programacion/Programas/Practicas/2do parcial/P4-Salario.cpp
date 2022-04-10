
    using namespace std;
    #include <iostream>
    #include <J:\include\Portada.h>
    
    class Empleado
      {
          private:
                 string Nombre;
                 double *Arreglo;
                 int Tam;
          public:
                 Empleado(string N=" ",int T=1);
                 void Leer(void);
                 int Empleado::Leer1(void)const;
                 bool Empleado::Validar1(const int x)const;
                 double Extra(void)const;
                 void Imprimir(void)const;
                 ~Empleado(void);
                 Empleado(const Empleado &RefE);
      };
      
      Empleado::Empleado(string N,int T)
         {                
                Nombre=N;
                Tam=(T<1)?1:T;
                Arreglo=new double[Tam];
                *Arreglo=0.0;
         }
      
       void Empleado::Leer(void)
         {
                     
                     cout<<"\n\n\t\tPROGRAMA PARA CALCULAR EL PAGO DE HORAS EXTRAS "
                     <<"\n\n\n\t\tIngresa el Nombre del Empleado: \n\n\t\t";
                     getline(cin,Nombre);
                     cout<<endl
                     <<"\n\t\tIngresa el Numero de Dias trabajados: \n\n\t\t";
                     Tam=Leer1();
                     cout<<"\n\n\t\tIngresa las horas extras por dia: \n\t\t";
                     Arreglo=new double[Tam];
                     for(int i=0;i<Tam;i++)
                             {
                                 cout<<"\n\t\tDia "
                                 <<i
                                 <<": ";
                                 cin>>Arreglo[i];
                             }
                     system("cls");
         }
    
    int Empleado::Leer1(void)const
         {
              int X;
              bool Bandera;
              do
                {
                       cin>>X;
                       Bandera=Validar1(X);
                }
                while(Bandera==false);
               return(X);                                                       
         }
    
    bool Empleado::Validar1(const int X)const
         {
               bool Bandera=true;
               if(X<=0)
                      Bandera=false;
               return(Bandera);
         }
         
    double Empleado::Extra(void)const
           {
                        double suma;
                        suma=0;
                        for(int i=0;i<Tam;i++)
                                    suma=suma+Arreglo[i];
                        return(suma*100);          
           }
           
    void Empleado::Imprimir(void)const
         {
                        cout<<"\n\n\t\t*NOMBRE DEL EMPLEADO: "
                        <<Nombre
                        <<endl
                        <<"\n\n\n\t\tSalario por hora extra: $100\n\t\t"
                        <<endl
                        <<"\n\t\tDias Trabajados: "
                        <<Tam
                        <<endl
                        <<"\n\t\tHoras Extras Trabajadas: "
                        <<endl;
                        for(int i=0;i<Tam;i++)
                             {
                                 cout<<"\n\t\tDia "
                                 <<i
                                 <<": "
                                 
                                 <<Arreglo[i]
                                 <<endl;   
                             }                                 
                                cout<<"\n\n\t\tPAGO TOTAL DE HORAS EXTRA = $"
                                <<Extra()
                                <<endl
                                <<"\n\n";                 
         }
      
      Empleado::~Empleado(void)
          {
             delete  []Arreglo;
             cout<<"Se esta eliminando memoria\n"
             <<endl;
          }
      
      Empleado::Empleado(const Empleado &RefE)
         {     
                Arreglo=new double[Tam];
                Arreglo[Tam]=*(RefE.Arreglo);
                Tam=RefE.Tam;
                Nombre=RefE.Nombre;
         }
      
      int main(void)
        {
                  Caratula();
                  system("cls");
                  
                  system("COLOR 07");
                  Empleado *AptE;
                  AptE=new Empleado;
                  
                  AptE->Leer();
                  system("cls");
                  system("COLOR f5");
                  AptE->Imprimir();
                  
                  delete  AptE;
                  system("pause");
                  return(0);
        }
       
