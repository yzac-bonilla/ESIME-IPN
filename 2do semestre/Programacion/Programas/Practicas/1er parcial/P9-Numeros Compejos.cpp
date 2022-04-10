
    using namespace std;
    #include<iostream>
    #include<stdlib.h>
    #include<string>
    #include<cctype>
    #include<cmath>
    #include<J:\include\Portada.h>
    
    struct Complejo
           {
                   double Real;
                   double Imag;
           };
    int Menu(void);
    bool ValidarOp(const int Opcion);
    Complejo LeerComp(void);
    bool ValidarDen(const Complejo *AptC2);
    Complejo Suma(const Complejo *AptC1,const Complejo *AptC2);
    Complejo Resta(const Complejo *AptC1,const Complejo *AptC2);
    Complejo Mult(const Complejo *AptC1,const Complejo *AptC2);
    Complejo Div(const Complejo *AptC1,const Complejo *AptC2);
    void Imprimir(const Complejo *AptC1,const Complejo *AptC2,const Complejo *AptC3, const char Simbolo);
    
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
                            Opcion=Menu();
                            if(Opcion != 5)
                                      {
                                           *AptC1=LeerComp();
                                           *AptC2=LeerComp();
                                      }
                            switch(Opcion)
                                          {
                                                  case 1:  *AptC3=Suma(AptC1,AptC2);
                                                              Simbolo='+';
                                                              Operacion="Suma";
                                                              break;
                                                  case 2:   *AptC3=Resta(AptC1,AptC2);
                                                              Simbolo='-';
                                                              Operacion="Resta";
                                                              break;
                                                  case 3:   *AptC3=Mult(AptC1,AptC2);
                                                              Simbolo='*';
                                                              Operacion="Multiplicacion";
                                                              break;
                                                  case 4:   *AptC3=Div(AptC1,AptC2);
                                                              Simbolo='/';
                                                              Operacion="Division";
                                                              break;
                                                  case 5:   break;
                                          }
                            if((AptC2->Real == 0  && AptC2->Imag == 0) && Opcion == 4 || Opcion == 5)
                                            {
                                            cout<<endl
                                            <<"\n\n\t\tEl Numero Complejo del Denominador debe de ser distinto a cero";
                                            }
                            else
                                {
                                            system("cls");
                                            cout<<"\n\n\t\tEl resultado de la "
                                            <<Operacion
                                            <<" es:"
                                            <<endl;
                                            Imprimir(AptC1,AptC2,AptC3,Simbolo);
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
                  
    int Menu(void)
        {
                  int Opcion;
                  bool Bandera=false;
                  while(Bandera == false)
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
                                         Bandera=ValidarOp(Opcion);
                                         if(Bandera==false)
                                                           {
                                                                   cout<<endl<<"\n\t\tOpcion equivocada, Intente nuevamente ";
                                                                   system("pause");
                                                           }
                                }
                  return(Opcion);
        }
    
    bool ValidarOp(const int Opcion)
         {
                         bool Bandera=true;
                         if(Opcion <1 || Opcion >5)
                                   Bandera=false;
                         return(Bandera);
         }
         
   Complejo LeerComp(void)
            {
                       Complejo R;
                       cout<<"\n\n\t\t\tIngrese la parte Real: ";
                       cin>>R.Real;
                       cout<<"\n\t\t\tIngrese la parte Imaginaria: ";
                       cin>>R.Imag;
                       return(R);
            }
            
   bool ValidarDen(const Complejo *AptC2)
        {
                         bool Bandera=true;
                         if(AptC2->Real == 0 && AptC2->Imag == 0)
                                        Bandera=false;
                         return(Bandera);
        }
        
   Complejo Suma(const Complejo *AptC1,const Complejo *AptC2)
            {
                       Complejo R;
                       R.Real=AptC1->Real+AptC2->Real;
                       R.Imag=AptC1->Imag+AptC2->Imag;   
                       return(R);
            }
            
   Complejo Resta(const Complejo *AptC1,const Complejo *AptC2)
            {
                       Complejo R;
                       R.Real=AptC1->Real-AptC2->Real;
                       R.Imag=AptC1->Imag-AptC2->Imag;   
                       return(R);
            }
            
   Complejo Mult(const Complejo *AptC1,const Complejo *AptC2)
            {
                       Complejo R;
                       R.Real=AptC1->Real*AptC2->Real-AptC1->Imag*AptC2->Imag;
                       R.Imag=AptC1->Real*AptC2->Imag+AptC1->Imag*AptC2->Real;
                       return(R);
            }
            
   Complejo Div(const Complejo *AptC1,const Complejo *AptC2)
            {
                       Complejo R;
                       bool Bandera=false;
                       Bandera=ValidarDen(AptC2);
                       if(Bandera=false)
                                        {
                                               cout<<"\n\n\t\tEl Numero Complejo del Denominador debe de ser distinto a cero";
                                               R=*AptC1;
                                        }
                       else
                           {
                                   R.Real=(AptC1->Real*AptC2->Real+AptC1->Imag*AptC2->Imag)/(pow(AptC2->Real,2)+pow(AptC2->Imag,2));
                                   R.Imag=(-AptC1->Real*AptC2->Imag+AptC2->Real*AptC1->Imag)/(pow(AptC2->Real,2)+pow(AptC2->Imag,2));
                           }
                       return(R);
            }
            
   void Imprimir(const Complejo *AptC1,const Complejo *AptC2,const Complejo *AptC3, const char Simbolo)
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
                       <<AptC3->Real
                       <<'+'
                       <<AptC3->Imag
                       <<'i'
                       <<"\n\n\t\t";
        }
