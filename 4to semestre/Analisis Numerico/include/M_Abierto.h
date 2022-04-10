
    #include <stdio.h>
    #include <conio.h>    
    #include <iostream>
    #include <math.h>
    #include <stdlib.h>
 
    using namespace std;
        
    double fx(double x);  
    double dfx(double x);
    double gx(double x);
    double dgx(double x);
    
    class M_Abierto
		{
			private: 
					double X0,Xr,E;
					int NI;
					char Resp;
			public:
                    M_Abierto(double x0=0,double xr=0,double e=0.0001,int ni=1,char r=' ');
                    void Leer(void);
                    void Newton_R(void);
                    void P_Fijo(void);
        };
      
    M_Abierto::M_Abierto(double x0,double xr,double e,int ni,char r)    
        {
            X0=x0;
            Xr=xr;
            E=e;
            NI=ni;
            Resp=r;
        }
        
    void M_Abierto::Leer(void)
		{
			cout<<"\n\n\n\t\tIngrese el punto X0: ";
            cin>>X0;
            cout<<"\n\n\n\t\tIngrese el Epsilon: ";
            cin>>E;
            cout<<"\n\n\n\t\tIngrese el numero de Iteraciones: ";
            cin>>NI;
		}
		
    double fx(double x)
        {
            return(-sin(4*x)-0.4);
        }
        
    double dfx(double x)
        {
            return(-4*cos(4*x));
        }
        
    double gx(double x)
        {
            return((-asin(0.4))/4);
        }
        
    double dgx(double x)
        {
            return(5/(2*sqrt(5*x-3)));
        }
        
    void M_Abierto::P_Fijo(void)
         {
             //system("cls");                   
             if(fabs(dgx(X0)) > 1)
               {
                cout<<"\n\n\t\tNo tiene solucion"<<endl;
                system("pause");
                exit(1);
               }
             //cout<<"  i  "<<"  X0  "<<"  g(X0)  "<<"  |X-X0|  "<<endl;
             for(int i=1;1<=NI;i++)
                {
                   Xr=gx(X0);
                   if(fabs(Xr-X0) < E)
                      {
                          cout<<"\n\n\t\tDespues de "<<i<<" iteraciones LA RAIZ ES = "<<Xr<<endl<<endl;
                          system("pause");
                          exit(1);
                      }
                   else
                          X0=Xr;
                   //cout<<"  "<<i<<"  "<<X0<<"  "<<gx(X0)<<"  "<<fabs(Xr-X0)<<"  "<<endl;                       
                }
             system("cls");
             cout<<"\n\n\t\tDespues de "<<NI<<" iteraciones, NO se encontro la raiz."
             <<endl;
         }
         
    void M_Abierto::Newton_R(void)
         {
             cout<<endl<<"  i  "<<"  X0  "<<"  f(X0)  "<<"  f'(X0)  "<<"  X  "<<endl;
             for(int i=1;1<=NI;i++)
                {cout<<"  "<<i<<"  "<<X0<<"  "<<fx(X0)<<" "<<dfx(X0)<<" "<<Xr<<"  "<<endl;   
                  Xr=X0-fx(X0)/dfx(X0);
                  if(fx(Xr)==0 || fabs(Xr-X0) < E)
                     {
                          cout<<"\n\n\t\tDespues de "<<i<<" iteraciones LA RAIZ ES = "<<Xr<<endl<<endl;
                          system("pause");
                          exit(1);
                     }
                  else
                         X0=Xr;
                  
                }
             system("cls");
             cout<<"\n\n\t\tDespues de "<<NI<<" iteraciones, NO se encontro la raiz."
             <<endl;
         }

    
