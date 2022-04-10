   
    #include <cstdlib>
    #include <iostream>
    #include <math.h>
    
    using namespace std;
    
    class Calculo
          {
                  private:
                          int n;
                          float Rx,Rds,*X;
                  public:
                         Calculo(int N=1, float R1=0,float R2=0);
                         void Leer(void);
                         void Operacion_X(void);
                         void Operacion_DS(void);
                         void Imprimir(void);
                         ~Calculo(void);
          };
           
    Calculo::Calculo(int N, float R1, float R2)
         {
                  n=N;
                  Rx=R1;
                  Rds=R2;
                  X=new float[n];
                  *X=0.0;
         }
          
    void Calculo::Leer(void)
         {
                   cout<<"\n\n\n\t\tIngrese n: ";
                   cin>>n;
                   cout<<endl;
                   X=new float[n];
                   for(int i=0;i<n;i++)
                       {
                        cout<<"\n\n\t\tIngrese un dato X: ";
                        cin>>X[i];
                       }
         }
                   
    void Calculo::Operacion_X(void)
        {
                  Rx=0;
                  for(int i=0;i<n;i++)
                        Rx= X[i]+Rx;
                  Rx=Rx/n;
        }
                 
    void Calculo::Operacion_DS(void)
        {
                  Rds=0;
                  for(int i=0;i<n;i++)
                      Rds=pow(Rx-X[i],2)+Rds;
                  Rds=sqrt(Rds/n);
        }
        
    void Calculo::Imprimir(void)
         {
                  cout<<"\n\n\n\t\tEl Arreglo de las X es: ";
                  for(int i=0;i<n;i++)
                        cout<<X[i]<<", ";
                  cout<<"\n\n\t\tLa Media es = "<<Rx
                      <<"\n\n\t\tLa Desviacion estandar = "<<Rds
                      <<endl;
         }
    
    Calculo::~Calculo(void)
         {
                  delete []X;
		 }
    
    int main(int argc, char *argv[])
    {
                  Calculo *Obj;
                  Obj=new Calculo;
                  
                  Obj->Leer();
                  Obj->Operacion_X();
                  Obj->Operacion_DS();
                  system("cls");
                  Obj->Imprimir();
                  
                  delete Obj;
    
                  system("PAUSE");
                  return EXIT_SUCCESS;
    }
