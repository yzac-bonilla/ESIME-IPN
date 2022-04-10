
    #include<iostream>
    using namespace std;
    
    struct Empleado
           {
                   string RFC;
                   string Nombre;
                   string AP;
                   string AM;
                   float T_I;
                   float Salario;
           };
    
    void Leer(Empleado &RefDatos);
    double Impuesto(const Empleado &RefDatos);
    double S_Neto(const Empleado &RefDatos);
    void Imprimir(const Empleado &RefDatos);
    
    int main(void)
        {
                  Empleado Trabajo;
                  Leer(Trabajo);
                  system("cls");
                  Imprimir(Trabajo);
                  
                  cout<<endl
                  <<endl;
                  system("pause");
                  Leer(Trabajo);
                  system("cls");
                  Imprimir(Trabajo);
                  
                  Empleado Datos;
                  Leer(Datos);
                  system("cls");
                  Imprimir(Datos);
                  system("pause");
                  return(0);
        }
    
    void Leer(Empleado &RefDatos)
         {
                       cout<<"Escribe tu RFC: ";
                       getline(cin,RefDatos.RFC);
                       cout<<"Escribe tu Nombre: ";
                       getline(cin,RefDatos.Nombre);
                       cout<<"Escribe tu Apellido Paterno: ";
                       getline(cin,RefDatos.AP);
                       cout<<"Escribe tu Apellido Materno: ";
                       getline(cin,RefDatos.AM);
                       cout<<"Escribe la Tasa Impuesta: ";
                       cin>>RefDatos.T_I;
                       cout<<"Escribe el Salario: ";
                       cin>>RefDatos.Salario;
                       cin.ignore();
         }
         
   double Impuesto(const Empleado &RefDatos)
          {
                         return(RefDatos.T_I*RefDatos.Salario);
          } 
   
   double S_Neto(const Empleado &RefDatos)
          {
                       return(RefDatos.Salario-Impuesto(RefDatos));
          }
          
   void Imprimir(const Empleado &RefDatos)
        {
                       cout<<"RFC:"
                       <<endl
                       <<RefDatos.RFC
                       <<endl
                       <<"Nombre:"
                       <<endl
                       <<RefDatos.Nombre
                       <<endl
                       <<"Apellido Paterno:"
                       <<endl
                       <<RefDatos.AP
                       <<endl
                       <<"Apellido Materno:"
                       <<endl
                       <<RefDatos.AM
                       <<endl
                       <<"Impuesto:"
                       <<endl
                       <<Impuesto(RefDatos)
                       <<endl
                       <<"Salario Neto:"
                       <<endl
                       <<S_Neto(RefDatos);
        }             
