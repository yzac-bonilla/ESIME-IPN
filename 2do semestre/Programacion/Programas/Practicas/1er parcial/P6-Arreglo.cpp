    
    using namespace std;
    #include<iostream>
    #include<F:\include\Portada.H>
    
    struct Obrero
           {
                 string *Nom;
                 double *AptC;
                 int *AptDias;     
           };
    
    void Leer(Obrero *AptDatos);
    double Extra(const Obrero *AptDatos);
    void Imprimir(const Obrero *AptDatos);
    int Numero(void);
    
    int main(void)
        {
                  Caratula();
                  Obrero *Datos;
                  Datos=new Obrero;
                  system("cls");
                  system("color 1f");
                  
                  int n;
                  n=Numero();
                  system("cls");
                  
                  for(int i=0;i<n;i++)
                          Leer(&Datos[i]);
                          
                  system("color 2f");
                  for(int i=0;i<n;i++)
                          Imprimir(&Datos[i]);
                  
                  for(int i=0;i>n;i++)
                      {
                          delete []Datos[i].AptC;
                          delete Datos[i].Nom;
                          delete Datos[i].AptDias;
                      }
                  delete  []Datos;
                  system("pause");
                  return(0);
        }
                  
    void Leer(Obrero *AptDatos)
         {
                     cin.ignore();
                     AptDatos->Nom=new string;
                     cout<<"\n\t\tIngresa el Nombre del Empleado: \n\n\t\t";
                     getline(cin,*(AptDatos->Nom));
                     cout<<endl
                     
                     <<"\n\t\tIngresa el Numero de Dias trabajados: \n\n\t\t";
                     AptDatos->AptDias=new int;
                     cin>>*(AptDatos->AptDias);
                     AptDatos->AptC=new double[*(AptDatos->AptDias)];
                     for(int i=0;i<*(AptDatos->AptDias);i++)
                             {
                                 cout<<"\n\t\tIngresa las horas extras por dia: \n\n\t\t";
                                 cin>>AptDatos->AptC[i];
                             }
                     system("cls");
         }
         
    double Extra(const Obrero *AptDatos)
           {
                        double suma;
                        suma=0;
                        for(int i=0;i<*(AptDatos->AptDias);i++)
                                    suma=suma+AptDatos->AptC[i];
                        return(suma*100);          
           }
           
    void Imprimir(const Obrero *AptDatos)
         {
                        cout<<"\n\n\t\t*NOMBRE DEL EMPLEADO: "
                        <<*(AptDatos->Nom)
                        <<endl
                        <<"\n\n\t\tSalario por hora extra: $100"
                        <<endl
                        <<"\n\t\tDias Trabajados: "
                        <<*(AptDatos->AptDias)
                        <<endl;
                        for(int i=0;i<*(AptDatos->AptDias);i++)
                             {
                                 cout<<"\n\t\tHoras extras por dia: "
                                 <<AptDatos->AptC[i]
                                 <<endl;   
                             }                                 
                                cout<<"\n\t\tPAGO TOTAL DE HORAS EXTRA = $"
                                <<Extra(AptDatos)
                                <<endl;                 
         }
         
    int Numero(void)
        {             int N;
                      cout<<"\n\n\t\tPROGRAMA PARA CALCULAR EL PAGO TOTAL DE HORAS EXTRA\n\t\t"
                      <<"\n\n\t\tIngrese el Numero de Empleados: ";
                      cin>>N;
                      return(N);
        }
    
    
