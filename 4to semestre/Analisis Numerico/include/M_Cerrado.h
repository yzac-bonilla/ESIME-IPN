
    #include <stdio.h>
    #include <conio.h>  
    #include <iostream>
    #include <stdlib.h>
    #include <math.h>
    
    using namespace std;
    
    double fx(double x);
    
    class M_Cerrado
		{
			private: 
					double a,b,E,Xr,m;
					int NI;
					char Resp;
			public:
					M_Cerrado(int N=1, double A=0, double B=0, double Ep=0.0001, double X=0,double M=0,char R=' ');
                    void Leer(void);
                    void Biseccion(void);
                    void F_Posicion(void);
		};
		
	M_Cerrado::M_Cerrado(int N, double A, double B, double Ep, double X, double M, char R)
		{
			NI=N;
			a=A;
			b=B;
			E=Ep;
			Xr=X;
			Resp=R;
		}
		
	void M_Cerrado::Leer(void)
		{
			cout<<"\n\n\n\t\tIngrese el intervalo a: ";
            cin>>a;
            cout<<"\n\n\n\t\tIngrese el intervalo b: ";
            cin>>b;
            cout<<"\n\n\n\t\tIngrese el Epsilon: ";
            cin>>E;
            cout<<"\n\n\n\t\tIngrese el numero de Iteraciones: ";
            cin>>NI;
		}
		
	double fx(double x)
	      {
              return(sin(2*x)+cos(x)-1.4); //
          }
		
	void M_Cerrado::Biseccion(void)
		{
			if(fx(a) == 0)
				{
					cout<<"\n\n\t\tLA RAIZ ES = "<<a<<endl<<endl;
					system("pause");
					exit(1);
				}
			if(fx(b) == 0)
				{
					cout<<"\n\n\t\tLA RAIZ ES = "<<b<<endl<<endl;
					system("pause");
					exit(1);
				}
				
			if(fx(a)*fx(b) > 0)
				{
					cout<<"\n\n\t\tEs posible que no tenga una raiz."
					<<"\n\n\t\t¿Desea Continuar?(s/n)";
					cin>>Resp;
					if(Resp == 'n')
						{
                            system("cls");
							cout<<"\n\n\t\t=) Bye...  "<<endl<<endl;
							system("pause");
							exit(1);
						}
                }
			for(int i=1;i<=NI;i++)
			    {
			         m=(a+b)/2;
			         if(fx(m) == 0 || fabs(b-a) < E)
							{
				                cout<<"\n\n\t\tDespues de "<<i<<" iteraciones LA RAIZ ES = "<<m<<endl<<endl;
				                system("pause");
                                exit(1);
                            }
			         if(fx(b) * fx(m) < 0)
			               a=m;
	                 else
	                       b=m;
			    }
			system("cls");
            cout<<"\n\n\t\tDespues de "<<NI<<" iteraciones, NO se encontro la raiz."<<endl;
		}
		
	void M_Cerrado::F_Posicion(void)
	     {
			if(fx(a) == 0)
				{
					cout<<"\n\n\t\tLA RAIZ ES = "<<a<<endl<<endl;
					system("pause");
					exit(1);
				}
			if(fx(b) == 0)
				{
					cout<<"\n\n\t\tLA RAIZ ES = "<<b<<endl<<endl;
					system("pause");
					exit(1);
				}
			for(int i=1;i<=NI;i++)
                {
                    Xr=a-(fx(a)*(b-a))/(fx(b)-fx(a));
                    if(fx(Xr)  == 0 || fabs(b-a) < E)
                       {
                            cout<<"\n\n\t\tDespues de "<<i<<" iteraciones LA RAIZ ES = "<<Xr<<endl<<endl;
                            system("pause");
                            exit(1);
                       }
                    if(fx(Xr)*fx(b) < 0)
                            a=Xr;
                    else
                            b=Xr;
                }
            system("cls");
            cout<<"\n\n\t\tDespues de "<<NI<<" iteraciones, NO se encontro la raiz."<<endl;
        }

