
    using namespace std;
    #include <iostream>
    #include <cmath>
    #include <J:\include\Portada.h>
    
    class Parabola
      {
          private:
              double *AptVel;
              double Ang;
              double Grav;
          public:
            Parabola(double a=1, double g=1);
            void Leer(void);
            double Leer1(void)const;
            double Leer2(void)const;
            bool Validar1(double x)const;
            bool Validar2(double x)const;
            double Grados(void)const;
            double Xmax(void)const;
            double Ymax(void)const;
            double Time(void)const;
            void Imprimir(void)const;
            ~Parabola(void);
            Parabola(const Parabola &RefT);
      };
      
    Parabola::Parabola(double a, double g)
        {
              AptVel=new double;
              *AptVel=1;
              Ang=(a<0 || a>180)?1:a;
              Grav=(g<0)?1:g;
        }
    
    
           
    void Parabola::Leer(void)
         {
                       cout<<"\n\n\n\t\tEscriba la velocidad inicial del proyectil Vo = ";
                       *AptVel=Leer1();
                       cout<<endl;
                       
                       cout<<"\n\n\t\tEscriba el angulo de inclinacion Teta = ";
                       Ang=Leer2();
                       cout<<endl;
                       
                       cout<<"\n\n\t\tEscriba el valor de la gravedad g = ";
                       Grav=Leer1();
                       cout<<endl;
         }
         
    double Parabola::Leer1(void)const
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
    
    bool Parabola::Validar1(double x)const
         {
               bool Bandera=true;
               if(x<=0)
                      Bandera=false;
               return(Bandera);
         }
         
    double Parabola::Leer2(void)const
         {
              double X;
              bool Bandera=false;
              while(Bandera==false)
                {
                       cin>>X;
                       Bandera=Validar2(X);
                }
               return(X);             
         }
         
    bool Parabola::Validar2(double x)const
         {
               bool Bandera=true;
               if(x<0 || x>180)
                      Bandera=false;
               return(Bandera);
         }
         
    double Parabola::Grados(void)const
           {
                         return( Ang*M_PI/180);
           }
         
    double Parabola::Xmax(void)const
         {
                       return( (pow(*AptVel,2)*sin(2*Grados()))/(Grav) );
         }
         
    double Parabola::Ymax(void)const
         {
                       return( (pow(*AptVel,2)*pow(sin(Grados()),2))/(2*Grav) );
         }
         
    double Parabola::Time(void)const
         {
                       return( (*AptVel*sin(Grados()))/(Grav) );
         }
         
    void Parabola::Imprimir(void)const
         {
                      cout<<"\n\n\t\tVelocidad inicial del proyectil:\n\t\tVo = "
                      <<*AptVel
                      <<" m/s"
                      <<endl
                      <<"\n\t\tAngulo de inclinacion:\n\t\tTeta = "
                      <<Ang
                      <<" Grados"
                      <<endl
                      <<"\n\t\tGravedad:\n\t\tg = "
                      <<Grav
                      <<" m/s2"
                      <<endl
                      <<"\n\t\tAlcance Maximo del Proyectil:\n\t\tx = "
                      <<Xmax()
                      <<" m"
                      <<endl
                      <<"\n\t\tAltura Maxima del Proyectil:\n\t\ty = "
                      <<Ymax()
                      <<" m"
                      <<endl
                      <<"\n\t\tTiempo en el punto mas Alto:\n\t\tT(ymax) = "
                      <<Time()
                      <<" seg"
                      <<endl
                      <<"\n\t\tTiempo total de la trayectoria:\n\t\tT = "
                      <<2*Time()
                      <<" seg"
                      <<endl;
         }
         
    Parabola::~Parabola(void)
      {
         cout<<"Se esta eliminando memoria\n"
         <<endl;
      }
      
    Parabola::Parabola(const Parabola &RefT)
        {
               AptVel=new double;
               *AptVel=*(RefT.AptVel);
               Ang=RefT.Ang;
               Grav=RefT.Grav;              
        }
                                      
    int main(void)
        {
             Caratula();
             system("cls");
             
             Parabola *AptT;
             AptT=new Parabola;
             
             AptT->Leer();
             system("cls");
             system("color e");
             AptT->Imprimir();
            
             system("pause");
             system("cls");
             Parabola *AptT2=new Parabola(*AptT2);
             AptT2->Imprimir();
             delete AptT2;
             delete AptT;
             
             system("pause");
             
             return(0);
        }
