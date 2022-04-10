
    using namespace std;
    #include <iostream>
    #include <cmath>
    #include <J:\include\Portada.h>
    
    //Resistencia
     class   Resist
             {
                   private:
                           double *AptX;
                           int N;
                   public:
                          Resist(int R=1);
                          ~Resist(void);
                          Resist(const Resist &RefE);
                          void Leer1(void);
                          double R_Total(void)const;
                          void Imprimir1(void)const;
             };
             
     Resist::Resist(int R)
         {
                 N=(R<1)?1:R;
                 AptX=new double[N];
                 
                 for(int i=0;i<N;i++)
                      AptX[i]=0.0;
         }
         
     Resist::~Resist(void)
         {
                delete []AptX;
                cout<<"\n\n\t\tSe esta eliminando memoria\n\n\t\t"
                <<endl;
         }
         
     Resist::Resist(const Resist &RefE)
         {      
                N=RefE.N;
                AptX=new double[N];
                for(int i;i<N;i++)
                   AptX[i]=RefE.AptX[i]; 
         }
             
     void Resist::Leer1(void)
        {
               cout<<"\n\n\t\tIngresa el numero de Resistencias = ";
               cin>>N;
               cout<<"\n\n\t\tIngresa los Valores de las Resistencias = ";
               AptX=new double [N];
               for(int i=0;i<N;i++)
                  cin>>AptX[i];
        }
         
     double Resist::R_Total(void)const
        {
            double RT;
            RT=0;
            for(int i=0;i<N;i++)
              RT=RT+(AptX[i]);
            return(RT);
        }
        
     void Resist::Imprimir1(void)const
        {
              cout<<"\n\n\t\tValor de Resistencias: ";
              for(int i=0;i<N;i++)
                   cout<<AptX[i]
                   <<", ";
              cout<<"\n\n\t\tResistencia Total = ";
              cout<<R_Total();
        }
        
     //Voltaje
     class   Volt
             {
                   private:
                           double V;
                   public:
                          Volt(double E=0.0);
                          void Leer2(void);
                          double Regresa(void)const;
                          void Imprimir2(void)const;
             };
     
     Volt::Volt(double E)
           {
                  V=(E<0)?0:E;
           }
             
     void Volt::Leer2(void)
        {
               cout<<"\n\n\t\tIngresa el Voltaje  = ";
               cin>>V;
        }
        
     double Volt::Regresa(void)const
         {
              return(V);
         }
        
     void Volt::Imprimir2(void)const
         {
               cout<<"\n\n\t\tVoltaje: "
               <<V;
         }
         
     //Corriente
     class   Corriente:public Resist, public Volt
             {
                   public:
                          Corriente(int R=0,double E=0.0);
                          void Leer3(void);
                          double Intensidad(void)const;
                          void Imprimir3(void)const;
             };
     
     Corriente::Corriente(int R,double E):Resist(R),Volt(E)
         {
         }
     
     double Corriente::Intensidad(void)const
        {
              return(Regresa()/R_Total());
        }
        
     void Corriente::Leer3(void)
         {
              Leer1();
              Leer2();
         }
         
     void Corriente::Imprimir3(void)const
         {
                 Imprimir1();
                 Imprimir2();
                 cout<<"\n\n\n\t\tIntensidad de Corriente = "
                 <<Intensidad();
         }
         
     //Potencia
     class   Potencia:public Corriente
             {
                   public:
                          Potencia(int R=0,double E=0.0);
                          void Leer4(void);
                          double Poten(void)const;
                          void Imprimir4(void)const;
             };
      
      Potencia::Potencia(int R,double E):Corriente(R,E)
      {
      }
      
      void Potencia::Leer4(void)
          {
                 Leer3();
          }
      double Potencia::Poten(void)const
          {
                  return(pow(Intensidad(),2)*R_Total());
          }
              
      void Potencia::Imprimir4(void)const
          {
                 Imprimir3();
                 cout<<endl
                 <<"\n\t\tPotencia = "
                 <<Poten()
                 <<"\n\n\t\t";
          }   
          
     //Main
     int main(void)
        {
                Caratula();
                system("cls");
                              
                Potencia *AptP;
                AptP=new Potencia;
                
                AptP->Leer4();
                
                system("cls");
                AptP->Imprimir4();
                
                delete AptP;
                system("pause");
                return(0);
        }
                
     
     
     
               
