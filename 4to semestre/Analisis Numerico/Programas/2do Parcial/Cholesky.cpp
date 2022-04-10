
    #include <stdio.h>
    #include <conio.h>    
    #include <stdlib.h>
    #include <iostream>
    #include <math.h>
    
    using namespace std;
    
    class Matriz
          {
                private:
                        int R,C;
                        double **AptMat,**L,**U,*X,*Y,*b;
                public:
                        Matriz(int r=2,int c=2);
                        void Leer(void);
                        void Cholesky(void);
                        void Imprimir(void)const;
                        ~Matriz(void);
          };
          
    Matriz::Matriz(int r, int c)
       {
             R=(r<1)?2:r;
             C=(c<1)?2:c;
             X=new double[C];
                  *X=0.0;
             Y=new double[C];
                  *Y=0.0;
             b=new double[R];
                  *b=0.0;
             AptMat=new double *[R];
             for(int i=0;i<R;i++)
                 AptMat[i]=new double [C];
             for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                   AptMat[i][j]=0.0;
                   
             L=new double *[R];
             for(int i=0;i<R;i++)
                 L[i]=new double [C];
             for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                   L[i][j]=0.0;
                   
             U=new double *[R];
             for(int i=0;i<R;i++)
                 U[i]=new double [C];
             for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                   U[i][j]=0.0;
       }
                      
     Matriz::~Matriz(void)
       {
             for(int i=0;i<R;i++)
                 delete []AptMat[i];
             delete []AptMat;
             for(int i=0;i<R;i++)
                 delete []L[i];
             for(int i=0;i<R;i++)
                 delete []U[i];
             delete []U;
             delete []L;
             delete []X;
             delete []Y;
             delete []b;
       }      
       
      void Matriz::Leer(void)
       {
              cout<<"\n\n\n\t\tIngresa los valores de la Matriz A (SIMETRICA):\n\t\t"; 
              for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                   {
                      cout<<"\n\t\ta "<<"["<<i<<"]"<<"["<<j<<"] = ";
                      cin>>AptMat[i][j];
                   }
              cout<<"\n\n\n\t\tIngresa los valores del Vector B:\n\t\t";
                 for(int i=0;i<R;i++)
                     {
                         cout<<"\n\t\tb "<<"["<<i<<"] = ";
                         cin>>b[i];
                     }
       }            
      
     void Matriz::Imprimir(void)const
       {
            system("cls");
            cout<<"\n\n\t\tMatriz A: ";
            for(int i=0;i<R;i++)
               {
                cout<<"\n\n\t\t ";
                for(int j=0;j<C;j++)
                    cout<<"  "<<AptMat[i][j];
               }
            cout<<endl;
            cout<<"\n\n\t\tVector B: ";
            for(int i=0;i<R;i++)
                cout<<"\n\n\t\t "<<b[i];
            cout<<endl;
       }
       
     void Matriz::Cholesky(void)
          {      
                 //Comprobando si es simetrica
                 for(int i=0; i<R; i++)
                    {
			              for(int j=0; j<C; j++)
                             {
					               if(AptMat[i][j] != AptMat[j][i])
					                 {
            							system("cls");
                                        cout<<"\n\n\t\t La Matriz Ingresada no es Simetrica"
                                        <<"\n\n\t\t No se puede realizar el Metodo de Cholesky."<<endl<<endl;
            							system("pause");
            							exit(0);
          							 }
					         }
                      }
                 //Definiendo mat L
                 double s;
     	         for(int j=0; j<R; j++)
            	   {
            			s=0;
            			for(int k=0; k<j; k++)
            			   s=s+pow(L[j][k],2);
            			L[j][j]=sqrt(AptMat[j][j]-s);
            			for(int i=j+1; i<R; i++)
            			   {
            					s=0;
            					for(int m=0; m<j; m++)
            					   s=s+L[i][m]*L[j][m];
         					    L[i][j]=(AptMat[i][j]-s)/L[j][j];
          					}
          			}
                  cout<<endl<<"\n\n\t\tMatriz L : ";
                  for(int i=0;i<R;i++)
                    {
                       cout<<"\n\n\t\t ";
                       for(int j=0;j<C;j++)
                          cout<<"  "<<L[i][j];
                    }
                 //Igualar mat U a la transp de L    
                    for(int i=0;i<R;i++)
                      {
                            for(int j=0;j<C;j++)
                              U[i][j]=L[j][i];
                      }
                    cout<<endl<<"\n\n\t\tMatriz U (Transpuesta de L): ";
                    for(int i=0;i<R;i++)
                       {
                        cout<<"\n\n\t\t ";
                        for(int j=0;j<C;j++)
                            cout<<"  "<<U[i][j];
                       }    
                  //Resolver Ly=b
            	for(int i=0; i<R; i++)
            	   {
                        s=0;
            	        for(int j=i-1; j>=0; j--)
            			    s=s+(L[i][j]*Y[j]);
            	          Y[i]=(b[i]-s)/L[i][i];
       			   }

	             //Solucion Ux=y por gauss
                  cout<<"\n\n\t\tSOLUCION:\n\n";
                  for(int j=R-1;j>=0;j--)
                      {
                           s=0;
                           for(int i=j+1;i<R;i++)
                             s=s+U[j][i]*X[i];
                           X[j]=(Y[j]-s)/U[j][j];
                           cout<<"\t\tX"<<j<<" = "<<X[j]<<endl<<endl;  
                      }
                  cout<<endl;
          }
                       
     void Leer(int &RefR,int &RefC);
     
     int main(void)
      {
            int Ren,Col;
            
            Matriz *AptM1;
            Leer(Ren,Col);
            AptM1=new Matriz(Ren,Col);
            
            AptM1->Leer();
            AptM1->Imprimir();
            AptM1->Cholesky();
            
            delete AptM1;
            system("pause");
            return(0);
      }
      
    void Leer(int &RefR,int &RefC)
       {
               cout<<"\n\n\n\t\tMETODO DE CHOLESKY"
               <<"\n\n\n\t\tDatos de la Matriz A (SIMETRICA):"
               <<"\n\n\t\tIngresa el Numero de Renglones = ";
               cin>>RefR;
               cout<<"\n\t\tIngresa el Numero de Columnas = ";
               cin>>RefC;
       }
