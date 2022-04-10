
    #include <iostream>
    #include <math.h>
    
    using namespace std;
    
    class Biseccion
		{
			private: 
					double a,b,Fa,Fb,E,Xr,m;
					int NI;
					char Resp;
			public:
					Biseccion(int N=1, double A=0, double B=0, double fa=0, double fb=0,double Ep=0.0001, double X=0,double M=0,char R=' ');
                    void Leer(void);
                    void Raiz(void);
                    void Imprimir(void);
		};
		
	Biseccion::Biseccion(int N, double A, double B, double fa, double fb, double Ep, double X, double M, char R)
		{
			NI=N;
			a=A;
			b=B;
			Fa=fa;
			Fb=fb;
			E=Ep;
			Xr=X;
			Resp=R;
		}
		
	void Biseccion::Leer(void)
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
		
	void Biseccion::Raiz(void)
		{
            Fa=cos(a);
			if(Fa == 0)
				{
					cout<<"La raiz es: "<<a;
					system("pause");
					exit(1);
				}
			Fb=cos(b);
			if(Fb == 0)
				{
					cout<<"La raiz es: "<<b;
					system("pause");
					exit(1);
				}
				
			if(Fa * Fb > 0)
				{
					cout<<"Es posible que no tenga una raiz"
					<<"¿Desea Continuar?(s/n)";
					cin>>Resp;
					if(Resp == 'n')
						{
							cout<<"Adios";
							exit(1);
						}
					else
						{
							for(int i=0;i<NI;i++)
								{
									m=(a+b)/2;
								double Fm=cos(m);
									if(Fm == 0 || fabs(b-a) < E)
										{
										cout<<"La raiz es m: "<<m;
										exit(1);
										if(Fb * Fm < 0)
											a=m;
										else
											b=m;
										}
								}
							Xr=m;
						}
				}								
			else
					{
						system("cls");
                        cout<<"\n\n\t\tDespues de "
							<<NI
							<<" iteraciones, NO se encontro la raiz."
                            <<endl;
						system("pause");
						exit(1);
					}
		}
		
	void Biseccion::Imprimir(void)
		{
            system("cls");
			cout<<"La raiz es: "
				<<Xr;
		}
		
	int main(int argc, char *argv[])
		{
			Biseccion *Apt;
			Apt=new Biseccion;
			
			Apt->Leer();
			Apt->Raiz();
			Apt->Imprimir();
			
			delete Apt;
    
            system("PAUSE");
            return (0);
    }
			
			
							
					 
