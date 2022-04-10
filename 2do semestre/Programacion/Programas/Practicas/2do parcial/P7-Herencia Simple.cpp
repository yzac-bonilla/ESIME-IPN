
    using namespace std;
    #include <iostream>
    #include <J:\include\Portada.h>
    
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
    
    class Ingresos:public Impuesto
           {
                  private:
                       double Sal;
                       double Ext;
                  public:
                        Ingresos(double I=0.0,double S=0.0,double E=0.0);
                        void Leer2(void);
                        double Impu(void)const;
                        void Imprimir2(void)const;
                        double SubT(void)const; 
           };
    
    Ingresos::Ingresos(double I,double S,double E):Impuesto(I)
      {
            Sal=(S<1)?0.0:S;
            Ext=(E<1)?0.0:E;
      }
    
    void Ingresos::Leer2(void)
         {
                       Leer1();
                       cout<<"\n\t\tIngrese el Salario Base en $: ";
                       Sal=LeerA();
                       cout<<endl;
                       cout<<"\n\t\tIngrse el total de horas extras: ";
                       Ext=LeerA();
                       cout<<endl;
         }
    double Ingresos::SubT(void)const
    {
            return(Ext*100+Sal);
    }
    double Ingresos::Impu(void)const
    {
           return(Impuest());
    }                 
    void Ingresos::Imprimir2(void)const
         {
                       Imprimir1();
                       cout<<"\n\t\tSalario Base: $"
                       <<Sal
                       <<endl
                       <<"\n\t\tHoras extras: "
                       <<Ext
                       <<endl
                       <<"\n\t\tPAGO POR HORAS EXTRAS = +$"
                       <<Ext*100
                       <<endl
                       <<"\n\t\tSUBTOTAL = $"
                       <<SubT()
                       <<endl;
         }
    
    class Total:public Ingresos
           {
                   private:
                        double Bono;
                   public:
                        Total(double I=0.0,double S=0.0,double E=0.0,double B=0.0);
                        void Leer3(void);
                        void Imprimir3(void)const; 
                        double Desc(void)const;
                        double Tot(void)const; 
            }; 
     
     Total::Total(double I,double S,double E,double B):Ingresos(I,S,E)
           {
                  Bono=(B<1)?0.0:B;
           }
         
    void Total::Leer3(void)
         {
                    Leer2();
                    cout<<"\n\t\tIngrese el Bono adquirido en $: ";
                    Bono=LeerA();
         }
    double Total::Desc(void)const
           {
                      return(SubT()* Impu()/100);
           }
                      
    double Total::Tot(void)const 
           {
                     return((SubT()+Bono)-Desc());
           }          
    void Total::Imprimir3(void)const 
         {
                        Imprimir2();
                        cout<<"\n\n\t\tBono Adquirido: +$"
                        <<Bono
                        <<endl
                        <<"\n\t\tDEDUCCIONES = -$"
                        <<Desc()
                        <<endl
                        <<"\n\n\t\tTOTAL = $"
                        <<Tot()
                        <<"\n\n\t\t"
                        <<endl;
         }
         
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
         
