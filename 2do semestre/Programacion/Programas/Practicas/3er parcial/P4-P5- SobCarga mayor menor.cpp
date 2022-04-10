
    using namespace std;
    #include <iostream>
    #include<string>
    #include<cctype>
    #include<cmath>
    #include <J:\include\Portada.h>
    
    class Racional
      {
          friend istream &operator>>(istream &Entrada, Racional *AptR);
          friend ostream &operator<<(ostream &Salida, Racional *AptR);
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
                 void Imprimir(Racional *AptR1,Racional *AptR2,const char Simbolo);
                  ~Racional(void);
                 Racional(const Racional &RefR);
                 void Comparar(Racional *AptR2);
                 bool operator>(const Racional *AptR2)const;
                 bool operator<(const Racional *AptR2)const;
                 bool operator>=(const Racional *AptR2)const;
                 bool operator<=(const Racional *AptR2)const;
                 bool operator==(const Racional *AptR2)const;
                 bool operator!=(const Racional *AptR2)const;
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
         
      bool Racional::Val_Den(const int D)
        {
                         bool Bandera=true;
                         if(D==0)
                                        Bandera=false;
                         return(Bandera);
        }
      
      void Racional::Leer_R(void)
          {
                Racional *AptR;
                AptR=this;
                cin>>AptR;
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
          
      void Racional::Imprimir(Racional *AptR1,Racional *AptR2,const char Simbolo)
           {
                Racional *AptR;
                AptR=this;
                
                cout<<endl
                <<"\t\t"
                <<AptR1
                <<" "
                <<Simbolo
                <<" "
                <<AptR2
                <<" "
                <<'='
                <<" "
                <<AptR
                <<endl;
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
      
      void Racional::Comparar(Racional *AptR2)
         {
                  Racional *AptR;
                  AptR=this;
                  
                  if(*AptR>AptR2)
                      cout<<"\n\n\t\t"<<AptR<<" > "<<AptR2;
                  if(*AptR<AptR2)
                      cout<<"\n\n\t\t"<<AptR<<" < "<<AptR2;
                  if(*AptR>=AptR2)
                      cout<<"\n\n\t\t"<<AptR<<" >= "<<AptR2;
                  if(*AptR<=AptR2)
                      cout<<"\n\n\t\t"<<AptR<<" <= "<<AptR2;
                  if(*AptR==AptR2)
                      cout<<"\n\n\t\t"<<AptR<<" == "<<AptR2;
                  if(*AptR!=AptR2)
                      cout<<"\n\n\t\t"<<AptR<<" != "<<AptR2;
         }
         
      bool Racional::operator>(const Racional *AptR2)const
         {
               return((Num*AptR2->Den)>(Den*AptR2->Num));
         }
         
      bool Racional::operator<(const Racional *AptR2)const
         {
               return((Num*AptR2->Den)<(Den*AptR2->Num));
         }
         
      bool Racional::operator>=(const Racional *AptR2)const
         {
               return((Num*AptR2->Den)>=(Den*AptR2->Num));
         }
         
      bool Racional::operator<=(const Racional *AptR2)const
         {
               return((Num*AptR2->Den)<=(Den*AptR2->Num));
         }
         
      bool Racional::operator==(const Racional *AptR2)const
         {
               return((Num*AptR2->Den)==(Den*AptR2->Num));
         }
         
      bool Racional::operator!=(const Racional *AptR2)const
         {
               return((Num*AptR2->Den)!=(Den*AptR2->Num));
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
                                            AptR3->Imprimir(AptR1,AptR2,Simbolo);
                                            AptR1->Comparar(AptR2);
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
        
    istream &operator>>(istream &Entrada, Racional *AptR)
         {
                int Denom;
                char Diagonal;
                
                cout<<"\n\n\t\tIngresa un Numero Racional(ejemplo: 1/2) = ";
                cin>>AptR->Num
                >>Diagonal
                >>Denom;
                
                while(Denom == 0)
                    cin>>Denom;
                AptR->Den=Denom;
                
                return(Entrada);
         }
         
    ostream &operator<<(ostream &Salida, Racional *AptR)
         {
                cout<<AptR->Num
                <<'/'
                <<AptR->Den;
                
                return(Salida);
         }
