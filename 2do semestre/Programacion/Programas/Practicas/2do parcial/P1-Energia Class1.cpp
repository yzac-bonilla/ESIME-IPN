
    using namespace std;
    #include <iostream>
    #include <cmath>
    #include <J:\include\Portada.h>
    
    class Energia
      {
         private: 
            double A;
            double X;
            double M;
            double T;
            
         public:
            Energia(double a=0,double x=0,double m=0,double t=1);
            void Leer(void);
            double Res_K(void)const;
            double Res_PE(void)const;
            double Res_KE(void)const;
            double Res_TE(void)const;
            void Imprimir(void)const;
            ~Energia(void);
      };
   
   Energia::Energia(double a,double x,double m,double t)
      {
            A=a;
            X=x;
            M=m;
            if(t<=0)
               T=1;
            else
               T=t;
            cout<<"Se esta creando memoria\n"
            <<endl;
      }
   
   void Energia::Leer(void)
      {
         double t;
         cout<<"\n\n\t\tIngresa la Amplitud del Movimiento, A= ";
         cin>>A;
         cout<<"\n\t\tIngresa el Desplazamiento inicial, X= ";
         cin>>X;
         cout<<"\n\t\tIngresa la Masa del Objeto, M= ";
         cin>>M;
         cout<<"\n\t\tIngresa el Tiempo del Periodo para un Ciclo de Movimiento, T= ";
         cin>>t;
         if(t<=0)
               T=1;
         else
               T=t;
      }
         
   double Energia::Res_K(void)const
      {
         return((4*pow(M_PI,2)*M)/pow(T,2));
      }
   
   double Energia::Res_PE(void)const
      {
         return((Energia::Res_K()*pow(X,2))/2);
      }
      
   double Energia::Res_KE(void)const
      {
         return(Res_TE() - Res_PE());
      }
      
   double Energia::Res_TE(void)const
      {
         return((Res_K()*pow(A,2))/2.0);
      }
      
   void Energia::Imprimir(void)const
      {
         cout<<"\n\n\t\tAmplitud del Movimiento, A= "
         <<A
         <<endl
         <<"\n\t\tDesplazamiento inicial, X= "
         <<X
         <<endl
         <<"\n\t\tMasa del Objeto, M= "
         <<M
         <<endl
         <<"\n\t\tTiempo del Periodo para un Ciclo de Movimiento, T= "
         <<T
         <<endl
         <<"\n\n\t\tConstante del Resorte = "
         <<Res_K()
         <<endl
         <<"\n\t\tEnergia Potencial = "
         <<Res_PE()
         <<endl
         <<"\n\t\tEnergia Cinetica = "
         <<Res_KE()
         <<endl
         <<"\n\t\tEnergia Total = "
         <<Res_TE()
         <<endl
         <<"\n";
      }
   
   Energia::~Energia(void)
      {
         cout<<"Se esta eliminando memoria\n"
         <<endl;
      }
         
            
   int main(void)
      {
         Caratula();
         system("cls");
         
         Energia *AptE;
         AptE=new Energia;
         
         AptE->Leer();
         system("cls");
         AptE->Imprimir();
         
         delete AptE;
         system("pause");
         return(0);
         
       //  PRUEBAS
      /*    Energia *AptE;
         AptE=new Energia;
         AptE->Imprimir();
         system("pause");
         delete AptE;*/
         
       //
        /* Energia *AptE;
         AptE=new Energia(5,3,4,8);
         AptE->Imprimir();
         system("pause");
         delete AptE;*/
        //
         /*Energia *AptE;
         AptE=new Energia(5,3,4,-4);
         AptE->Imprimir();
         system("pause");
         delete AptE;*/
      }
      
   
                                
         
         
      
   
      
      
            
    
    
