
    #include<iostream>
    #include<cmath>
    using namespace std;
    
    struct Viga
           {
               float L;
               float I;
               float E;
               float P;
               float a;
               float x;
           };
    
    void Leer(Viga &RefDatos);
    double CalcuRa(const Viga &RefDatos);
    double CalcuRb(const Viga &RefDatos);
    double Valor_b(const Viga &RefDatos);
    double Fuerza(const Viga &RefDatos);
    double Moment(const Viga &RefDatos);
    double Deflec(const Viga &RefDatos);
    void Imprimir(const Viga &RefDatos);
   
    int main(void)
        {
                  Viga Datos;
                  system("COLOR 2");
                  system("cls");
                  Leer(Datos);
                  system("cls");
                  Imprimir(Datos);
                  system("COLOR f5");
                  system("pause");                          
        }
    
    double Valor_b(const Viga &RefDatos)
           {
                    return(RefDatos.L-RefDatos.a);              
           }                        
           
    void Leer(Viga &RefDatos)
         {         
                   cout<<"\n\n\t\tEscribe la longitud de la viga L =  ";
                   cin>>RefDatos.L; 
                   while(RefDatos.L <= 0)
                       {
                           cout<<"\n\n\t\tL debe de ser mayor y distinta de 0 =  ";
                           cin>>RefDatos.L;                
                       }; 
                  
                   cout<<"\n\n\t\tEscribe el momento de inercia I =  ";
                   cin>>RefDatos.I;
                   while(RefDatos.I == 0)
                       {
                           cout<<"\n\n\t\tI debe de ser distinta de 0 =  ";
                           cin>>RefDatos.I;               
                       };
                       
                   cout<<"\n\n\t\tEscribe el modulo de elasticidad del material E =  ";
                   cin>>RefDatos.E;
                   while(RefDatos.E == 0)
                       {
                           cout<<"\n\n\t\tE debe de ser distinta de 0 =  ";
                           cin>>RefDatos.E;               
                       };
                       
                   cout<<"\n\n\t\tEscribe la magnitud de la carga concentrada P =  ";
                   cin>>RefDatos.P;
                   while(RefDatos.P < 0)
                       {
                           cout<<"\n\n\t\tP debe de ser mayor a 0, P =  ";
                           cin>>RefDatos.a;                
                       };
                   cout<<"\n\n\t\tEscribe la distancia de la carga al soporte a =  ";
                   cin>>RefDatos.a;
                   while(RefDatos.a > RefDatos.L || RefDatos.a < 0)
                       {
                           cout<<"\n\n\t\ta debe de ser menor a L y mayor que 0, a =  ";
                           cin>>RefDatos.a;                
                       };
                   cout<<"\n\n\t\tEscribe la distancia donde se desea calcular V, M y Y, x = ";
                   cin>>RefDatos.x;
                   while(RefDatos.x > RefDatos.L || RefDatos.x < 0)
                       {
                           cout<<"\n\n\t\tx debe de ser menor a L y mayor que 0, x =  ";
                           cin>>RefDatos.x;                
                       };
         }
         
    double CalcuRa(const Viga &RefDatos)
           {
                        return((RefDatos.P*Valor_b(RefDatos))/RefDatos.L);
           }
           
    double CalcuRb(const Viga &RefDatos)
           {
                        return((RefDatos.P*RefDatos.a)/RefDatos.L);
           } 
    
    double Fuerza(const Viga &RefDatos)
           {
                       double F;
                       if(RefDatos.x < RefDatos.a)
                                     F=CalcuRa(RefDatos);
                       else
                                     F=-CalcuRb(RefDatos);
                       return(F);                    
           }
           
    double Moment(const Viga &RefDatos)
           {
                       double M;
                       if(RefDatos.x < RefDatos.a)                                       
                                     M=(RefDatos.P*Valor_b(RefDatos)*RefDatos.x)/RefDatos.L; 
                       else
                                     M=(RefDatos.P*((Valor_b(RefDatos)*RefDatos.x)/RefDatos.L-RefDatos.x+RefDatos.a));
                       return(M);
           }
    double Deflec(const Viga &RefDatos)
           {
                       double y;
                       if(RefDatos.x < RefDatos.a)
                                     y= (-RefDatos.P*Valor_b(RefDatos)*RefDatos.x*(pow(RefDatos.L,2)-pow(Valor_b(RefDatos),2)
                                     -pow(RefDatos.x,2)))/(6*RefDatos.E*RefDatos.I*RefDatos.L) ;
                       else
                                     y= (-RefDatos.P*RefDatos.a*(RefDatos.L-RefDatos.x)*(2*RefDatos.L*Valor_b(RefDatos)
                                     -pow(Valor_b(RefDatos),2)-pow((RefDatos.L-RefDatos.x),2)))/(6*RefDatos.E*RefDatos.I*RefDatos.L ) ;
                       return(y);
           }       
    
    void Imprimir(const Viga &RefDatos)
         {
                       cout<<"Longitud de la Viga(L):"
                       <<endl
                       <<RefDatos.L
                       <<endl
                       <<"Momento de inercia de la seccion (I):"
                       <<endl
                       <<RefDatos.I
                       <<endl
                       <<"Modulo de elasticidad del material (E):"
                       <<endl
                       <<RefDatos.E
                       <<endl
                       <<"Magnitu de la carga concentrada(P):"
                       <<endl
                       <<RefDatos.P
                       <<endl
                       <<"Distancia de la carga al soporte (a):"
                       <<endl
                       <<RefDatos.a
                       <<endl
                       <<"Distancia de la carga al extremo libre (b):"
                       <<endl
                       <<Valor_b(RefDatos)
                       <<endl
                       <<"Distancia donde se desea calcular V, M y Y, (x):"
                       <<endl
                       <<RefDatos.x
                       <<endl
                       <<"Reaccion izquierda (Ra):"
                       <<endl
                       <<CalcuRa(RefDatos)
                       <<endl
                       <<"Reaccion derecha (Rb):"
                       <<endl
                       <<CalcuRb(RefDatos)
                       <<endl
                       <<"Fuerza Cortante (Vx):"
                       <<endl
                       <<Fuerza(RefDatos)
                       <<endl
                       <<"Momento (Mx):"
                       <<endl
                       <<Moment(RefDatos)
                       <<endl
                       <<"Defleccion (yx):"
                       <<endl
                       <<Deflec(RefDatos)
                       <<endl;             
        }
                                     
    
