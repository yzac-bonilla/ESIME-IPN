    
    using namespace std;
    #include<iostream>
    #include<cmath>
    #include<J:\include\Portada.H>
    
    struct Circuito
           {
                   double Volt;
                   double Resis;
                   double Induc;
                   double Capa;
                   double Frec;
           };
       
    void Leer(Circuito *AptInt);
    void Imprimir(const Circuito *AptInt);
    double Calcular(const Circuito *AptInt);
    double Validar(void);
    
    int main(void)
         {         system("color 4f");
                   Caratula();
                   system("pause");
                   
                   Circuito *Formula;
                   system("cls");
                   system("color e");
                   
                   Formula=new Circuito;
                   Leer(Formula);
                   system("cls");
                   
                   Imprimir(Formula);
                   system("color e");
                   delete Formula;
                   system("pause");
                   return(0);
         }
        
     double Validar(void)
         {
                          double Variable;
                          do
                            {
                                 cin>>Variable;
                            }while(Variable <= 0);
                          return(Variable);
         }
         
    void Leer(Circuito *AptInt)
         {
                       cout<<"\n\n\t\tEscribe el Voltaje = ";
                       AptInt->Volt=Validar();
                       cout<<"\n\n\t\tEscribe la Resistencia = ";
                       AptInt->Resis=Validar();
                       cout<<"\n\n\t\tEscribe la Inductancia = ";
                       cin>>AptInt->Induc;
                       cout<<"\n\n\t\tEscribe la Capacitancia = ";
                       cin>>AptInt->Capa;
                       cout<<"\n\n\t\tEscribe la Frecuencia = ";
                       AptInt->Frec=Validar();
         }
        
    double Calcular(const Circuito *AptInt)
           {
                          double Corriente;
                          Corriente=1.0/(2*M_PI*(AptInt->Frec)*(AptInt->Capa));
                          Corriente=(2*M_PI*(AptInt->Frec)*(AptInt->Induc))-Corriente;
                          Corriente=pow(AptInt->Resis,2)+pow(Corriente,2);
                          Corriente=sqrt(Corriente);
                          Corriente=AptInt->Volt/Corriente;
                          return(Corriente);
           }                        
         
    void Imprimir(const Circuito *AptInt)
         {
                        cout<<"\n\n\t\tVoltaje: "
                        <<AptInt->Volt
                        <<" V"
                        <<endl
                        <<"\n\t\tResistencia: "
                        <<AptInt->Resis
                        <<" Ohms"
                        <<endl
                        <<"\n\t\tInductancia: "
                        <<AptInt->Induc
                        <<" H"
                        <<endl
                        <<"\n\t\tCapacitancia: "
                        <<AptInt->Capa
                        <<" f"
                        <<endl
                        <<"\n\t\tFrecuencia: "
                        <<AptInt->Frec
                        <<" cps"
                        <<endl
                        <<"\n\n\t\tINTENSIDAD DE CORRIENTE = "
                        <<Calcular(AptInt)
                        <<" A"
                        <<endl;
         }               
