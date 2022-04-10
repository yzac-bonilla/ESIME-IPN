
    using namespace std;
    #include<iostream>
    #include<J:\include\Portada.h>
    
    struct   Impuesto
             {
                     double Imp; 
             };
    
    void Leer(Impuesto *AptD);
    double Impuest(const Impuesto *AptD);
    void Imprimir(const Impuesto *AptD);
    
    struct Ingresos
           {
               double Sal;
               double Ext;
               Impuesto *AptD;
           };
    
    void Leer(Ingresos *AptI);
    double Impu(const Ingresos *AptI);
    void Imprimir(const Ingresos *AptI);
    double SubT(const Ingresos *AptI);
    
    struct Total
           {
                double Bono;
                Ingresos *AptI;
            }; 
            
    void Leer(Total *AptT);
    void Imprimir(const Total *AptT); 
    double Desc(const Total *AptT);
    double Tot(const Total *AptT);             
    
    int main(void)
        {
                  Caratula();
                  system("cls");
                  
                  Total *T;
                  T=new Total;
                  
                  system("color 2f");
                  Leer(T);
                  system("cls");
                  
                  system("color 1f");
                  Imprimir(T);
                  
                  delete T->AptI->AptD;
                  delete T->AptI;
                  delete T;
                  
                  system("pause");
                  return(0);
        }
                  
     //Impuesto
    
    void Leer(Impuesto *AptD)
         {
                       cout<<"\n\n\t\tPROGRAMA QUE CALCULA EL SALARIO DE UN EMPLEADO"
                       <<endl
                       <<"\n\n\t\tIngrese el Impuesto en %: ";
                       cin>>AptD->Imp;
                       cout<<endl;  
         } 
    double Impuest(const Impuesto *AptD)
           {
                            return(AptD->Imp);
           }
    void Imprimir(const Impuesto *AptD)
         {
                           cout<<endl
                           <<"\n\n\t\tImpuesto: "
                           <<AptD->Imp
                           <<"%"
                           <<endl;  
         }          
         
    //ingresos
    void Leer(Ingresos *AptI)
         {
                       AptI->AptD=new Impuesto;
                       Leer(AptI->AptD);
                       cout<<"\n\t\tIngrese el Salario Base en $: ";
                       cin>>AptI->Sal;
                       cout<<endl;
                       cout<<"\n\t\tIngrse el total de horas extras: ";
                       cin>>AptI->Ext;
                       cout<<endl;
         }
    double SubT(const Ingresos *AptI)
    {
            return(AptI->Ext*100+AptI->Sal);
    }
    double Impu(const Ingresos *AptI)
    {
           return(Impuest(AptI->AptD));
    }                 
    void Imprimir(const Ingresos *AptI)
         {
                        Imprimir(AptI->AptD);
                       cout<<"\n\t\tSalario Base: $"
                       <<AptI->Sal
                       <<endl
                       <<"\n\t\tHoras extras: "
                       <<AptI->Ext
                       <<endl
                       <<"\n\t\tPAGO POR HORAS EXTRAS = +$"
                       <<AptI->Ext*100
                       <<endl
                       <<"\n\t\tSUBTOTAL = $"
                       <<SubT(AptI)
                       <<endl;
         }
         
    //Total
    
    void Leer(Total *AptT)
         {
                    AptT->AptI=new Ingresos;
                    Leer(AptT->AptI);
                    cout<<"\n\t\tIngrese el Bono adquirido en $: ";
                    cin>>AptT->Bono;
         }
    double Desc(const Total *AptT)
           {
                      return(SubT(AptT->AptI)* Impu(AptT->AptI)/100);
           }
                      
    double Tot(const Total *AptT) 
           {
                     return((SubT(AptT->AptI)+AptT->Bono)-Desc(AptT));
           }          
    void Imprimir(const Total *AptT) 
         {
                        Imprimir(AptT->AptI);
                        cout<<"\n\n\t\tBono Adquirido: +$"
                        <<AptT->Bono
                        <<endl
                        <<"\n\t\tDEDUCCIONES = -$"
                        <<Desc(AptT)
                        <<endl
                        <<"\n\n\t\tTOTAL = $"
                        <<Tot(AptT)
                        <<endl;
         }
                        
                        
    
     
         
    
                            
     
    
    
    
                       
                       
                       
                           
         
    
    
            
      
