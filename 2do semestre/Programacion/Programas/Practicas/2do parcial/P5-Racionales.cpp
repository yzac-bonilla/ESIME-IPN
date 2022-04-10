
    using namespace std;
    #include <iostream>
    #include<string>
    #include<cctype>
    #include<cmath>
    #include <J:\include\Portada.h>
    
    class Racional
      {
          private:
                 int Num;
                 int Den;
          public:
                 Racional(int N=0,int D=1);
                 int Menu(void);
                 void Leer_R(void);
                 Racional Suma(const Racional *AptR2);
                 Racional Resta(const Racional *AptR2);
                 Racional Mult(const Racional *AptR2);
                 Racional Div(const Racional *AptR2);
                 bool Val_Op(const int Opcion);
                 bool Val_Den(const int Den);
                 int RegresarR(void);
                 void Imprimir(const Racional *AptR1,const Racional *AptR2,const char Simbolo);
                  ~Racional(void);
                 Racional(const Racional &RefR);
      };

      Racional::Racional(int N, int D)
         {
               Num=N;
               Den=(D==0)?1:D;
         }
      
      int Racional::Menu(void)
        {
                  int Opcion;
                  bool Bandera=false;
                  while(Bandera == false)
                                {
                                         system("cls");
                                         cout<<"\n\n\t\t\tCALCULADORA DE NUMEROS RACIONALES"
                                         <<"\n\n\t\t\tSelecciona una Opcion"
                                         <<"\n\n\t\t\t1.- Suma"
                                         <<"\n\t\t\t2.- Resta"
                                         <<"\n\t\t\t3.- Multiplicacion"
                                         <<"\n\t\t\t4.- Division"
                                         <<"\n\t\t\t5.- Salir"
                                         <<endl
                                         <<"\n\t\t\tDame tu Opcion: ";
                                         cin>>Opcion;
                                         Bandera=Val_Op(Opcion);
                                         if(Bandera==false)
                                                           {
                                                                   cout<<endl<<"\n\t\tOpcion Invalida, Intente nuevamente ";
                                                                   system("pause");
                                                           }
                                }
                  return(Opcion);
        }
        
      bool Racional::Val_Op(const int Opcion)
         {
                         bool Bandera=true;
                         if(Opcion <1 || Opcion >5)
                                   Bandera=false;
                         return(Bandera);
         }
      
      void Racional::Leer_R(void)
          {
               bool Bandera=false;
               int D;
               cout<<"\n\n\t\tEscribe el Numerador = ";
               cin>>Num;
               while(Bandera==false)
                 {
                     cout<<"\n\n\t\tEscribe el Denominador = ";
                     cin>>D;
                     Bandera=Val_Den(D);
                     if(Bandera==false)
                       {
                          cout<<endl
                          <<"\n\n\t\tEL DENOMINADOR DEBE DE SER DISTINTO A CERO"
                          <<endl
                          <<"\t\tINTENTE "
                          <<endl;
                       }
                 }
               Den=D;
          }
               
            
      bool Racional::Val_Den(const int D)
        {
                         bool Bandera=true;
                         if(D==0)
                                        Bandera=false;
                         return(Bandera);
        }
        
      Racional Racional::Suma(const Racional *AptR2)
          {
               Racional Z;
               Z.Den=Den*AptR2->Den;
               Z.Num=(AptR2->Den*Num)+(Den*AptR2->Num);
               return Z;
          }
          
      Racional Racional::Resta(const Racional *AptR2)
          {
               Racional Z;
               Z.Den=Den*AptR2->Den;
               Z.Num=(AptR2->Den*Num)-(Den*AptR2->Num);
               return Z;
          }
          
      Racional Racional::Mult(const Racional *AptR2)
          {
               Racional Z;
               Z.Den=Den*AptR2->Den;
               Z.Num=Num*AptR2->Num;
               return Z;
          }
          
      Racional Racional::Div(const Racional *AptR2)
          {
               Racional Z;
               bool Bandera=false;
               Bandera=Val_Den(AptR2->Num);
               if(Bandera==false)
                 {
                      cout<<"\n\n\t\tEL NUMERADOR DEBE DE SER DISTINTO A CERO\n";
                 }
               else
                 {
                       Z.Den=Den*AptR2->Num;
                       Z.Num=Num*AptR2->Den;
                 }
               return Z;
          }
          
      void Racional::Imprimir(const Racional *AptR1,const Racional *AptR2,const char Simbolo)
           {
                cout<<endl
                <<"\t\t"
                <<AptR1->Num
                <<'/'
                <<AptR1->Den
                <<" "
                <<Simbolo
                <<" "
                <<AptR2->Num
                <<'/'
                <<AptR2->Den
                <<" "
                <<'='
                <<" "
                <<Num
                <<'/'
                <<Den;
           }      
      
      int Racional::RegresarR(void)
          {
                return(Num);
          }
      
      Racional::~Racional(void)
        {
             cout<<"\n\t\tSe esta eliminando memoria\n"
             <<endl;
        }
        
      Racional::Racional(const Racional &RefR)
         {     
                Num=RefR.Num;
                Den=RefR.Den;
                
         }
      
      int main(void)
          {
                    Racional *AptR1,*AptR2,*AptR3;
                    int Opcion;
                    char Respuesta,Simbolo;
                    string Operacion;
                    AptR1=new Racional;
                    AptR2=new Racional;
                    AptR3=new Racional;
                    do
                       {
                              Opcion=AptR3->Menu();
                              if(Opcion != 5)
                                      {
                                           system("cls");
                                           AptR1->Leer_R();
                                           AptR2->Leer_R();
                                      }
                            switch(Opcion)
                                          {
                                                  case 1:  *AptR3=AptR1->Suma(AptR2);
                                                              Simbolo='+';
                                                              Operacion="Suma";
                                                              break;
                                                  case 2:   *AptR3=AptR1->Resta(AptR2);
                                                              Simbolo='-';
                                                              Operacion="Resta";
                                                              break;
                                                  case 3:   *AptR3=AptR1->Mult(AptR2);
                                                              Simbolo='*';
                                                              Operacion="Multiplicacion";
                                                              break;
                                                  case 4:   *AptR3=AptR1->Div(AptR2);
                                                              Simbolo='/';
                                                              Operacion="Division";
                                                              break;
                                                  case 5:   break;
                                          }
                            if((AptR2->RegresarR() == 0 && Opcion == 4) || Opcion == 5)
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
                                            system("cls");
                                            AptR3->Imprimir(AptR1,AptR2,Simbolo);
                                }
                            
                            cout<<"\n\n\t\tDesea Continuar S/N";
                            cin>>Respuesta;
                    }while(Respuesta=toupper(Respuesta)=='S');
                            delete AptR1;
                            delete AptR2;
                            delete AptR3;
                  system("pause");
                  return(0);
        }
