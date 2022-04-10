    
    using namespace std;
    #include <iostream>
    #include <J:\include\Portada.h>
    
     //Impuesto
     class   Impuesto
             {
                     private:
                             double Imp; 
                     public:
                            Impuesto(double I=0.0);
                            void Leer1(void);
                            double LeerA(void)const;
                            bool Validar1(double x)const;
                            double Impuest(void)const;
                            void Imprimir1(void)const;
             };
    
    Impuesto::Impuesto(double I)
       {
               Imp=(I<1)?0.0:I;
       }
    
    void Impuesto::Leer1(void)
         {
                       cout<<"\n\n\t\tPROGRAMA QUE CALCULA EL SALARIO DE UN EMPLEADO"
                       <<endl
                       <<"\n\n\t\tIngrese el Impuesto en %: ";
                       Imp=LeerA();
                       cout<<endl;  
         } 
         
    double Impuesto::LeerA(void)const
         {
              double X;
              bool Bandera=false;
              while(Bandera==false)
                {
                       cin>>X;
                       Bandera=Validar1(X);
                }
               return(X);                                                       
         }
    
    bool Impuesto::Validar1(double x)const
         {
               bool Bandera=true;
               if(x<0)
                      Bandera=false;
               return(Bandera);
         }
         
    double Impuesto::Impuest(void)const
           {
                            return(Imp);
           }
    void Impuesto::Imprimir1(void)const
         {
                           cout<<endl
                           <<"\n\n\t\tImpuesto: "
                           <<Imp
                           <<"%"
                           <<endl;  
         }
    //Ingresos1     
    class IngresosI1:virtual public Impuesto
           {
                  private:
                       double Sal;
                  public:
                        IngresosI1(double I=0.0,double S1=0.0);
                        void LeerI1(void);
                        double Regresa1(void)const;
                        void ImprimirI1(void)const;
           };
    
    IngresosI1::IngresosI1(double I,double S1):Impuesto(I)
      {
            Sal=(S1<1)?0.0:S1;
      }
    
    void IngresosI1::LeerI1(void)
         {
                       Leer1();
                       cout<<"\n\t\tIngrese el Salario Base en $: ";
                       Sal=LeerA();
                       cout<<endl;
         } 
         
    double IngresosI1::Regresa1(void)const
        {
               return(Sal);
        
        }
                   
    void IngresosI1::ImprimirI1(void)const
         {
                       Imprimir1();
                       cout<<"\n\t\tSalario Base: $"
                       <<Sal
                       <<endl;
         }
     //IngresosI2
     class IngresosI2:virtual public Impuesto
           {
                  private:
                       double Sal;
                  public:
                        IngresosI2(double I=0.0,double S2=0.0);
                        void LeerI2(void);
                        double Regresa2(void)const;
                        void ImprimirI2(void)const;
           };
    
    IngresosI2::IngresosI2(double I,double S2):Impuesto(I)
      {
            Sal=(S2<1)?0.0:S2;
      }
    
    void IngresosI2::LeerI2(void)
         {
                       Leer1();
                       cout<<"\n\t\tIngrese el Salario Base en $: ";
                       Sal=LeerA();
                       cout<<endl;
         }
    
    double IngresosI2::Regresa2(void)const
        {
               return(Sal);
        
        }
                   
    void IngresosI2::ImprimirI2(void)const
         {
                       Imprimir1();
                       cout<<"\n\t\tSalario Base: $"
                       <<Sal
                       <<endl;
         }
         
    //Total
    class Total: public IngresosI1,public IngresosI2
           {
                   private:
                        double Bono;
                   public:
                        Total(double I=0.0,double S1=0.0,double E1=0.0,double S2=0.0,double E2=0.0,double B=0.0);
                        void Leer3(void);
                        void Imprimir3(void)const; 
                        double Desc(void)const;
                        double Tot(void)const; 
            }; 
     
     Total::Total(double I,double S1,double E1,double S2,double E2,double B):Impuesto(I),IngresosI1(S1,E1),IngresosI2(S2,E2)
           {
                  Bono=(B<1)?0.0:B;
           }
         
    void Total::Leer3(void)
         {
                    LeerI1();
                    cout<<"\n\t\tIngrese el Bono adquirido en $: ";
                    Bono=LeerA();
         }
                      
    double Total::Desc(void)const 
           {
                     return(((Regresa1()+Bono)*Impuest())/100);
           } 
           
    double Total::Tot(void)const 
           {
                     return(Regresa1()+Bono-Desc());
           }        
                    
    void Total::Imprimir3(void)const 
         {
                        ImprimirI1();
                        cout<<"\n\t\tBono Adquirido: +$"
                        <<Bono
                        <<endl
                        <<"\n\t\tDescuento: -$"
                        <<Desc()
                        <<endl
                        <<"\n\n\t\tTOTAL = $"
                        <<Tot()
                        <<"\n\n\t\t"
                        <<endl;
         }
    
    //Main     
    int main(void)
        {
                  Caratula();
                  system("cls");
                  
                  Total *AptT;
                  AptT=new Total;
                  
                  system("color 2f");
                  AptT->Leer3();
                  system("cls");
                  
                  system("color 1f");
                  AptT->Imprimir3();
                  
                  delete AptT;
                  
                  system("pause");
                  return(0);
        }
