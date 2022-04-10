
    using namespace std;
    #include <iostream>
    #include <cmath>
    #include <J:\include\Portada.h>
    
    class Raices
      {
          private:
              double A;
              double B;
              double C;
          public:
              Raices(double a=1, double b=1, double c=1);
              void Leer(void);
              double Leer1(void)const;
              bool Validar1(double x)const;
              double Caso_a(void)const;
              double Caso_b1(void)const;
              double Caso_b2(void)const;
              double Caso_c(void)const;
              double Caso_d(void)const;
              void Imprimir(void)const;
              ~Raices(void);
      };
    
    Raices::Raices(double a, double b, double c)
         {
                A=a;
                B=(b==0 && a==0)?1:b;
                C=c;
                cout<<"\n\n\t\tSe esta creando memoria\n"
                <<endl;
         }
         
    void Raices::Leer(void)
         {
                system("cls");
                cout<<"\n\n\t\tIngresa el valor de A = ";
                cin>>A;
                cout<<"\n\n\t\tIngresa el valor de B = ";
                B=Leer1();
                cout<<"\n\n\t\tIngresa el valor de C = ";
                cin>>C;
         }
         
    double Raices::Leer1(void)const
         {
              double X;
              bool Bandera;
              do
                {
                       cin>>X;
                       Bandera=Validar1(X);
                }
                while(Bandera==false);
               return(X);                                                       
         }
    
    bool Raices::Validar1(double x)const
         {
               bool Bandera=true;
               if(x==0 && A==0)
                      Bandera=false;
               return(Bandera);
         }
         
    double Raices::Caso_a(void)const
           {
                       return(-C/B);
           }
           
    double Raices::Caso_b1(void)const
           {
                   return((-B+sqrt(pow(B,2)-4*A*C))/(2*A));
           }
           
    double Raices::Caso_b2(void)const
           {
                   return((-B-sqrt(pow(B,2)-4*A*C))/(2*A));
           }
           
    double Raices::Caso_c(void)const
           {
                   return(-B/(2*A));
           }
                                  
    double Raices::Caso_d(void)const
           {
                   double D;
                   D=pow(B,2)-4*A*C;
                   D=sqrt(abs(D))/(2*A);
                   return(D);
           }         
           
    void Raices::Imprimir(void)const
         {
                cout<<"\n\n\t\tDatos:"
                <<endl
                <<"\n\t\tA = "
                <<A
                <<endl
                <<"\n\t\tB = "
                <<B
                <<endl
                <<"\n\t\tC = "
                <<C
                <<endl
                <<"\n\n\t\tRaices:";
                if(A==0)
                 {
                       cout<<"\n\n\t\tX = "
                       <<Caso_a()
                       <<endl;
                 }
                else
                 {
                    if(pow(B,2)-4*A*C>0)
                     {
                        cout<<"\n\n\t\tX1 = "
                        <<Caso_b1()
                        <<"\n\n\t\tX2 = "
                        <<Caso_b2()
                        <<endl;
                     }
                    else
                     {
                        if(pow(B,2)-4*A*C==0)
                         {
                             cout<<"\n\n\t\tX1 = "
                             <<Caso_c()
                             <<"\n\n\t\tX2 = "
                             <<Caso_c()
                             <<endl;
                         }
                        else
                        {
                            if(pow(B,2)-4*A*C<0)
                             {
                                 cout<<"Son Raices Imaginarias";
                                 if(A==0)
                                    cout<<"No se puede calcular la raiz Imaginaria con A=0";
                                 else
                                   {  
                                     cout<<"\n\n\t\tX1 = "
                                     <<Caso_c()
                                     <<" + "
                                     <<Caso_d()
                                     <<" i\n\n\t\tX2 = "
                                     <<Caso_c()
                                     <<" - "
                                     <<Caso_d()
                                     <<" i"
                                     <<endl;
                                   }
                             }
                        }
                     }
                 } 
         }            
                 
    Raices::~Raices(void)
      {
         cout<<"\n\n\t\tSe esta eliminando memoria\n"
         <<endl;
      }
      
    int Numero(void);
    
    int main(void)
        {
                  Caratula();
                  system("cls");
                  
                  int n;
                  n=Numero();
                  Raices *AptR;
                  AptR=new Raices[n];
                  
                  for(int i=0;i<n;i++)
                          AptR[i].Leer();
                  
                  system("cls");
                  
                  for(int i=0;i<n;i++)
                          AptR[i].Imprimir();
                  
                  delete []AptR;
                  system("pause");
                  return(0);
        }
        
    int Numero(void)
        {             int N;
                      cout<<"\n\n\t\tPROGRAMA PARA CALCULAR LAS RAICES DE ECUACIONES\n\t\t"
                      <<"\n\n\t\tIngrese el Numero de Ecuaciones: ";
                      cin>>N;
                      return(N);
        }
                
                   
