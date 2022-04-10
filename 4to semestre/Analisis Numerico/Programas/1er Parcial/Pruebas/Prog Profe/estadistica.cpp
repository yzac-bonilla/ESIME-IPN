#include<conio.h>
#include<math.h>
#include<iostream>
using namespace std;

class Estadistica
{
      private:
              double *xi,ds,X,sum;
              int N;
              
      public:
             Estadistica();
             ~Estadistica();
             void Lee_Datos();
             void Media();
             void Desviacion();
};
Estadistica::Estadistica()
{     
      
      cout<<"Digita el numero de elementos a calcular: "; cin>>N;
          xi=new double[N+1];
                             
}
Estadistica:: ~Estadistica()
{
           delete []xi; 
}
void Estadistica::Lee_Datos()
{
                 for(int i=1;i<=N;i++)
                 {
                     cout<<"\nDigita el dato ["<<i<<"] = ";
                     cin>>xi[i];
                 }
}
void Estadistica::Media()   
{
                  for(int i=1;i<=N;i++)
                  X=X+xi[i];
                  X=X/double(N);    
                  
                  cout<<"El valor de la Media es: "<<X<<endl;
}

void Estadistica::Desviacion()
{
     sum=0;
                    for(int i=1;i<=N;i++)
                    {
                        sum=(X-xi[i])*(X-xi[i]);
                        sum=sum+sum; 
                    }
                    
                    ds=sqrt(sum/double(N));
                    
                    cout<<"El valor de la Desviacion Estandar es: "<<ds;     
                         }

main()
{
          
      Estadistica obj;
      
      obj.Lee_Datos();
      obj.Media();
      obj.Desviacion();   
      
      
      
      getch();
      }                           
