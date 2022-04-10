
    #include<iostream>
    #include<cmath>
    using namespace std;
    
    struct Parabola
           {
                double Vel;
                double Ang;
                double Grav;
           };
           
    void Leer(Parabola *AptDatos);
    double Validar(void);
    double ValAng(void);
    double Grados(const Parabola *AptDatos);
    double Xmax(const Parabola *AptDatos);
    double Ymax(const Parabola *AptDatos);
    double Time(const Parabola *AptDatos);
    void Imprimir(const Parabola *AptDatos);
    
    int main(void)
        {
                  Parabola *Datos;
                  Datos=new Parabola;
                  
                  system("COLOR 2");
                  system("cls");
                  
                  Leer(Datos);
                  system("cls");
                  Imprimir(Datos);
                  
                  delete Datos;
                  system("COLOR e");
                  system("pause");
        }
    
    double Grados(const Parabola *AptDatos)
           {
                         return( (*AptDatos).Ang*M_PI/180);
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
    
    double ValAng(void)
         {
                          double Variable;
                          do
                            {
                                 cin>>Variable;
                            }while(Variable < 0 || Variable > 180);
                          return(Variable);
         }
         
    void Leer(Parabola *AptDatos)
         {
                       cout<<"\n\n\n\t\tEscriba la velocidad inicial del proyectil Vo = ";
                       (*AptDatos).Vel=Validar();
                       cout<<endl;
                       
                       cout<<"\n\n\t\tEscriba el angulo de inclinacion Teta = ";
                       (*AptDatos).Ang=ValAng();
                       cout<<endl;
                       
                       cout<<"\n\n\t\tEscriba el valor de la gravedad g = ";
                       (*AptDatos).Grav=Validar();
                       cout<<endl;
         }
         
    double Xmax(const Parabola *AptDatos)
         {
                       return( (pow((*AptDatos).Vel,2)*sin(2*Grados(AptDatos)))/((*AptDatos).Grav) );
         }
         
    double Ymax(const Parabola *AptDatos)
         {
                       return( (pow((*AptDatos).Vel,2)*pow(sin(Grados(AptDatos)),2))/(2*(*AptDatos).Grav) );
         }
         
    double Time(const Parabola *AptDatos)
         {
                       return( ((*AptDatos).Vel*sin(Grados(AptDatos)))/((*AptDatos).Grav) );
         }
         
    void Imprimir(const Parabola *AptDatos)
         {
                      cout<<"\n\n\t\tVelocidad inicial del proyectil:\n\t\tVo = "
                      <<(*AptDatos).Vel
                      <<" m/s"
                      <<endl
                      <<"\n\t\tAngulo de inclinacion:\n\t\tTeta = "
                      <<(*AptDatos).Ang
                      <<" Grados"
                      <<endl
                      <<"\n\t\tGravedad:\n\t\tg = "
                      <<(*AptDatos).Grav
                      <<" m/s2"
                      <<endl
                      <<"\n\t\tAlcance Maximo del Proyectil:\n\t\tx = "
                      <<Xmax(AptDatos)
                      <<" m"
                      <<endl
                      <<"\n\t\tAltura Maxima del Proyectil:\n\t\ty = "
                      <<Ymax(AptDatos)
                      <<" m"
                      <<endl
                      <<"\n\t\tTiempo en el punto mas Alto:\n\t\tT(ymax) = "
                      <<Time(AptDatos)
                      <<" seg"
                      <<endl
                      <<"\n\t\tTiempo total de la trayectoria:\n\t\tT = "
                      <<2*Time(AptDatos)
                      <<" seg"
                      <<endl;
         }
                                
    
           
    
