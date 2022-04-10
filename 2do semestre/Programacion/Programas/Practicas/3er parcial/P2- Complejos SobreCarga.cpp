
    using namespace std;
    #include<iostream>
    #include<stdlib.h>
    #include<string>
    #include<cctype>
    #include<cmath>
    #include<J:\include\Portada.h>
    
     class Complejo
           {
                   private:
                       double Real;
                       double Imag;
                   
                   public:
                        Complejo(double R=1,double I=1);
                        int Menu(void);
                        bool ValidarOp(const int Opcion);
                        void LeerComp(void);
                        Complejo operator+(const Complejo *AptC2)const;
                        Complejo operator-(const Complejo *AptC2)const;
                        Complejo operator*(const Complejo *AptC2)const;
                        Complejo operator/(const Complejo *AptC2)const;
                        void Imprimir(const Complejo *AptC1,const Complejo *AptC2, const char Simbolo)const;
                        double RegresaR(void)const;
                        double RegresaI(void)const;   
           };
           
     Complejo::Complejo(double R,double I)
        {
             Real=R;
             Imag=I;
        }
        
     int Complejo::Menu(void)
        {
                  int Opcion;
                  do
                                {
                                         system("cls");
                                         cout<<"\n\n\t\t\tCALCULADORA DE NUMEROS COMPLEJOS"
                                         <<"\n\n\t\t\tSelecciona una Opcion"
                                         <<"\n\n\t\t\t1.- Suma"
                                         <<"\n\t\t\t2.- Resta"
                                         <<"\n\t\t\t3.- Multiplicacion"
                                         <<"\n\t\t\t4.- Division"
                                         <<"\n\t\t\t5.- Salir"
                                         <<endl
                                         <<"\n\t\t\tDame tu Opcion: ";
                                         cin>>Opcion;
                                }while(Opcion<1 || Opcion>5);
                  return(Opcion);
        }
    
    bool Complejo::ValidarOp(const int Opcion)
         {
                         bool Bandera=true;
                         if(Opcion <1 || Opcion >5)
                                   Bandera=false;
                         return(Bandera);
         }
         
   void Complejo::LeerComp(void)
            {
                       cout<<"\n\n\t\t\tIngrese la parte Real: ";
                       cin>>Real;
                       cout<<"\n\t\t\tIngrese la parte Imaginaria: ";
                       cin>>Imag;
            }
        
   Complejo Complejo::operator+(const Complejo *AptC2)const
            {
                       Complejo R;
                       R.Real=Real+AptC2->Real;
                       R.Imag=Imag+AptC2->Imag;   
                       return(R);
            }
            
   Complejo Complejo::operator-(const Complejo *AptC2)const
            {
                       Complejo R;
                       R.Real=Real-AptC2->Real;
                       R.Imag=Imag-AptC2->Imag;   
                       return(R);
            }
            
   Complejo Complejo::operator*(const Complejo *AptC2)const
            {
                       Complejo R;
                       R.Real=Real*AptC2->Real-Imag*AptC2->Imag;
                       R.Imag=Real*AptC2->Imag+Imag*AptC2->Real;
                       return(R);
            }
            
   Complejo Complejo::operator/(const Complejo *AptC2)const
            {
                       Complejo R;
                       double Denom;
                       if(AptC2->Real==0 && AptC2->Imag==0)
                                               cout<<"\n\n\t\tOperacion Invalida";
                       else
                           {
                                   R.Real=(Real*AptC2->Real+Imag*AptC2->Imag)/(pow(AptC2->Real,2)+pow(AptC2->Imag,2));
                                   R.Imag=(-Real*AptC2->Imag+AptC2->Real*Imag)/(pow(AptC2->Real,2)+pow(AptC2->Imag,2));
                           }
                       return(R);
            }
            
   void Complejo::Imprimir(const Complejo *AptC1,const Complejo *AptC2, const char Simbolo)const
        {
                       cout<<"\n\n\t\t"
                       <<AptC1->Real
                       <<'+'
                       <<AptC1->Imag
                       <<'i'
                       <<" "
                       <<Simbolo
                       <<" "
                       <<AptC2->Real
                       <<'+'
                       <<AptC2->Imag
                       <<'i'
                       <<" "
                       <<'='
                       <<" "
                       <<Real
                       <<'+'
                       <<Imag
                       <<'i'
                       <<"\n\n\t\t";
        }
        
   double Complejo::RegresaR(void)const
      {
            return(Real);
      }
      
   double Complejo::RegresaI(void)const
      {
            return(Imag);
      }   
        
   int main(void)
        {
                  Caratula();
                  system("cls");
                  Complejo *AptC1,*AptC2,*AptC3;
                  int Opcion;
                  char Respuesta,Simbolo;
                  string Operacion;
                  AptC1=new Complejo;
                  AptC2=new Complejo;
                  AptC3=new Complejo;
                  do
                    {
                            Opcion=AptC3->Menu();
                            if(Opcion != 5)
                                      {
                                           AptC1->LeerComp();
                                           AptC2->LeerComp();
                                      }
                            switch(Opcion)
                                          {
                                                  case 1:  *AptC3=*AptC1+AptC2;
                                                              Simbolo='+';
                                                              Operacion="Suma";
                                                              break;
                                                  case 2:   *AptC3=*AptC1-AptC2;
                                                              Simbolo='-';
                                                              Operacion="Resta";
                                                              break;
                                                  case 3:   *AptC3=(*AptC1)*AptC2;
                                                              Simbolo='*';
                                                              Operacion="Multiplicacion";
                                                              break;
                                                  case 4:   *AptC3=*AptC1/AptC2;
                                                              Simbolo='/';
                                                              Operacion="Division";
                                                              break;
                                                  case 5:   break;
                                          }
                            if(Opcion == 4 && (AptC2->RegresaR()==0 && AptC2->RegresaI()==0) || Opcion == 5)
                                            {
                                            cout<<endl;
                                            }
                            else
                                {
                                            system("cls");
                                            cout<<"\n\n\t\tEl resultado de la "
                                            <<Operacion
                                            <<" es:"
                                            <<endl;
                                            AptC3->Imprimir(AptC1,AptC2,Simbolo);
                                }
                            
                            cout<<"\n\n\t\tDesea Continuar S/N";
                            cin>>Respuesta;
                    }while(Respuesta=toupper(Respuesta)=='S');
                            delete AptC1;
                            delete AptC2;
                            delete AptC3;
                  system("pause");
                  return(0);
        }
    
