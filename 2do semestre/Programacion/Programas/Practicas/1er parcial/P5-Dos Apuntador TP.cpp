    
    using namespace std;
    #include<iostream>
    #include<cmath>
    #include<J:\include\Portada.H>
    
    struct Parabola
           {
                double Vel;
                double Ang;
                double *AptGrav;
           };
           
    struct Result
           {
                 double Grados;
                 double Xmax;
                 double Ymax;
                 double Time;      
           };
    double Validar(void);
    double ValAng(void);
    void Leer(Parabola *AptDatos);
    void Grados(const Parabola *AptDatos, Result *AptRes);
    void Xmax(const Parabola *AptDatos, Result *AptRes);
    void Ymax(const Parabola *AptDatos, Result *AptRes);
    void Time(const Parabola *AptDatos, Result *AptRes);
    void Llenar(const Parabola *AptDatos, Result *AptRes);
    void Imprimir(const Parabola *AptDatos,const Result *AptRes);
    
    int main(void)
        {
                  Caratula(); 
                  system("COLOR f2");
                  system("cls");
                  
                  Parabola *Datos;
                  Datos=new Parabola;
                  Result *Res;
                  Res=new Result;
                  
                  Leer(Datos);
                  system("cls");
                  Llenar(Datos,Res);
                  
                  Imprimir(Datos,Res);
                  system("COLOR e");
                  delete Datos->AptGrav;
                  delete Datos;
                  delete Res;
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
                       cout<<"\n\n\n\t\tTiro Parabolico:\n\n\n\t\t"
                       <<"\n\n\n\t\tEscriba la velocidad inicial del proyectil Vo = ";
                       AptDatos->Vel=Validar();
                       cout<<endl;
                       
                       cout<<"\n\n\t\tEscriba el angulo de inclinacion Teta = ";
                       AptDatos->Ang=ValAng();
                       cout<<endl;
                       
                       cout<<"\n\n\t\tEscriba el valor de la gravedad g = ";
                       AptDatos->AptGrav=new double;
                       cin>>*(AptDatos->AptGrav);
                       cout<<endl;
         }
         
    void Grados(const Parabola *AptDatos, Result *AptRes)
         {
                      AptRes->Grados=(AptDatos->Ang)*M_PI/180;
         }
         
    void Xmax(const Parabola *AptDatos,Result *AptRes)
         {
                      AptRes->Xmax=(pow(AptDatos->Vel,2)*sin(2*AptRes->Grados))/(*(AptDatos->AptGrav));
         }
         
    void Ymax(const Parabola *AptDatos, Result *AptRes)
         {
                       AptRes->Ymax=(pow(AptDatos->Vel,2)*pow(sin(AptRes->Grados),2))/(2*(*(AptDatos->AptGrav)));
         }
         
    void Time(const Parabola *AptDatos, Result *AptRes)
         {
                       AptRes->Time=(AptDatos->Vel*sin(AptRes->Grados))/(*(AptDatos->AptGrav));
         }
    
    void Llenar(const Parabola *AptDatos, Result *AptRes)
         {
                      Grados(AptDatos,AptRes);
                      Xmax(AptDatos,AptRes);
                      Ymax(AptDatos,AptRes);
                      Time(AptDatos,AptRes);
         }
                  
    void Imprimir(const Parabola *AptDatos,const Result *AptRes)
         {
                      cout<<"\n\n\t\tVelocidad inicial del proyectil:\n\t\tVo = "
                      <<AptDatos->Vel
                      <<" m/s"
                      <<endl
                      <<"\n\t\tAngulo de inclinacion:\n\t\tTeta = "
                      <<AptDatos->Ang
                      <<" Grados"
                      <<endl
                      <<"\n\t\tGravedad:\n\t\tg = "
                      <<*(AptDatos->AptGrav)
                      <<" m/s2"
                      <<endl
                      <<"\n\t\tAlcance Maximo del Proyectil:\n\t\tx = "
                      <<AptRes->Xmax
                      <<" m"
                      <<endl
                      <<"\n\t\tAltura Maxima del Proyectil:\n\t\ty = "
                      <<AptRes->Ymax
                      <<" m"
                      <<endl
                      <<"\n\t\tTiempo en el punto mas Alto:\n\t\tT(ymax) = "
                      <<AptRes->Time
                      <<" seg"
                      <<endl
                      <<"\n\t\tTiempo total de la trayectoria:\n\t\tT = "
                      <<2*AptRes->Time
                      <<" seg"
                      <<endl;
         }      
    
