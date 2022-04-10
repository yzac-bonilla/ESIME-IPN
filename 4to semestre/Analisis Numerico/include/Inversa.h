   
    #include <stdio.h>
    #include <conio.h>    
    #include <stdlib.h>
    #include <iostream>
    #include <math.h>
    
    using namespace std;
    
    class Metodo
          {
                private:
                        int R,C;
                        double **AptMat,*X,*b;
                public:
                        Metodo(int r=2,int c=4);
                        double Inversa(double **J);
          };
          
    Metodo::Metodo(int r, int c)
       {
             R=(r<1)?2:r;
             C=(c<1)?4:c;
       }
       
     double Metodo::Inversa(double **J)
          {    
                    //Triangularizacion
                    double c1,c2;
                    for(int i=0;i<1;i++)
                      {
                           for(int j=i+1;j<2;j++)
                              {    
                                   c1=-J[i][i]/J[j][i];
                                   if(J[j][i] != 0)
                                     {
                                          for(int k=0;k<4;k++)
                                              J[j][k]=J[i][k]+c1*J[j][k];
                                     }
                              }
                      }
                    //Triangularizacion recursiva
                    for(int i=1;i>0;i--)
                      {
                       for(int j=i-1;j>=0;j--)
                           {
                               c2=-J[j][i]/J[i][i];
                               if(J[i][i] != 0)
                                 {
                                     for(int k=0;k<4;k++)
                                     J[j][k]=J[j][k]+c2*J[i][k];
                                 }
                           }
                      }
                    //Gauss-jordan 
                    for(int i=0;i<2;i++)
                      {
                         for(int k=2;k<4;k++)
                              J[i][k]=J[i][k]/J[i][i];
                      }
                    //Mat inversa
                    cout<<"\n\n\t\tMatriz inversa: ";
                        for(int i=0;i<2;i++)
                           {
                                J[i][i]=J[i][i]/J[i][i];
                                cout<<"\n\n\t\t ";
                                for(int j=2;j<4;j++)
                                        cout<<"  "<<J[i][j];
                           } 
                    return(**J);  
          }
         
