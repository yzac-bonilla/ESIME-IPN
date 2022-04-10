
    using namespace std;
    #include<iostream>
    #include<F:\include\Portada.h>
    
    struct Matriz
           {
                 int m;
                 int n;
                 int k;
                 double **AptMat;
           };
    
    void Leer_ijk(Matriz *AptM);
    void Inicializar(Matriz *AptM1,Matriz *AptM2,Matriz *AptMR,Matriz *AptM);
    void LeerMat(Matriz *AptM1,Matriz *AptM2,Matriz *AptM);
    void Mult(const Matriz *AptM1,const Matriz *AptM2,Matriz *AptMR,Matriz *AptM);
    void Imprimir(const Matriz *AptM1,const Matriz *AptM2,const Matriz *AptMR,const Matriz *AptM);
    
    int main(void)
        {
                  Caratula();
                  system("cls");
                  int i;
                  
                  Matriz *AptM;
                  Matriz *AptM1;
                  Matriz *AptM2;
                  Matriz *AptMR;
                  
                  AptM=new Matriz;
                  AptM1=new Matriz;
                  AptM2=new Matriz;
                  AptMR=new Matriz;
                  
                  Leer_ijk(AptM);
                  Inicializar(AptM1,AptM2,AptMR,AptM);
                  LeerMat(AptM1,AptM2,AptM);
                  Mult(AptM1,AptM2,AptMR,AptM);
                  
                  system("cls");
                  Imprimir(AptM1,AptM2,AptMR,AptM);
                  
                  for(int i=0;i<AptM->m;i++)
                          delete []AptM1->AptMat[i];
                  for(int i=0;i<AptM->k;i++)
                          delete []AptM2->AptMat[i];
                  for(int i=0;i<AptM->m;i++)
                          delete []AptMR->AptMat[i];
                  delete []AptM1->AptMat;
                  delete []AptM2->AptMat;
                  delete []AptMR->AptMat;
                  delete AptM;
                  delete AptM1;
                  delete AptM2;
                  delete AptMR;
                  
                  system("pause");
                  return(0);    
        }
                  
    void Leer_ijk(Matriz *AptM)
         {
                     cout<<"\n\n\t\tPRODUCTO DE 2 MATRICES"
                     <<"\n\n\t\tDa el Numero de Filas de la Matriz 1, m= ";
                     cin>>AptM->m;
                     cout<<"\n\n\t\tDa el Numero de Columnas de la Matriz 2, n= ";
                     cin>>AptM->n;
                     cout<<"\n\n\t\tDa el Numero de Columnas de la Matriz 1 y" 
                     <<"\n\t\tel numero de Filas de la Matriz 2, k= ";
                     cin>>AptM->k;
         }
    
    void Inicializar(Matriz *AptM1,Matriz *AptM2,Matriz *AptMR,Matriz *AptM)
         {
                            AptM1->AptMat=new double *[AptM->m];
                            for(int i=0;i<AptM->m;i++)
                                    AptM1->AptMat[i]=new double [AptM->k];
                                    
                            AptM2->AptMat=new double *[AptM->k];
                            for(int l=0;l<AptM->k;l++)
                                    AptM2->AptMat[l]=new double [AptM->n];
                                    
                            AptMR->AptMat=new double *[AptM->m];
                            for(int i=0;i<AptM->m;i++)
                                    AptMR->AptMat[i]=new double [AptM->n];                  
         }
         
    void LeerMat(Matriz *AptM1,Matriz *AptM2,Matriz *AptM)
         {            
                      int i,j,l;
         
                      cout<<"\n\n\t\tIngresa los Valores de la Matriz 1: \n\t\t"; 
                      for(i=0;i<AptM->m;i++)
                           for(l=0;l<AptM->k;l++)
                                cin>>AptM1->AptMat[i][l];
                                
                      cout<<"\n\n\t\tIngresa los Valores de la Matriz 2: \n\t\t"; 
                      for(l=0;l<AptM->k;l++)
                           for(j=0;j<AptM->n;j++)
                                cin>>AptM2->AptMat[l][j];             
         }
         
    void Mult(const Matriz *AptM1,const Matriz *AptM2,Matriz *AptMR,Matriz *AptM)
         {
                     int i,j,l;
                     for(i=0;i<AptM->m;i++)              
                          for(j=0;j<AptM->n;j++)
                              {
                                 AptMR->AptMat[i][j]=0;
                                 for(l=0;l<AptM->k;l++)
                                    (AptMR->AptMat[i][j])+=AptM1->AptMat[i][l]*AptM2->AptMat[l][j];
                              }
         }
         
    void Imprimir(const Matriz *AptM1,const Matriz *AptM2,const Matriz *AptMR,const Matriz *AptM)
         {
                      int i,j,l;
                      
                      cout<<"\n\n\t\t "
                      <<"Matriz 1:";
                      for(i=0;i<AptM->m;i++)
                        {
                           cout<<"\n\n\t\t ";
                           for(l=0;l<AptM->k;l++)
                             {
                                cout<<"  "
                                <<AptM1->AptMat[i][l];
                             }
                        }
                      cout<<"\n\n\t\t ";
                      
                      cout<<"Matriz 2:";
                      for(l=0;l<AptM->k;l++)
                        {
                           cout<<"\n\n\t\t ";
                           for(j=0;j<AptM->n;j++)
                             {
                                cout<<"  "
                                <<AptM2->AptMat[l][j];
                             }
                        }
                      cout<<"\n\n\t\t ";
                      
                      cout<<"Producto Matricial:";
                      for(i=0;i<AptM->m;i++)
                        {
                           cout<<"\n\n\t\t ";
                           for(j=0;j<AptM->n;j++)
                             {
                                cout<<"  "
                                <<AptMR->AptMat[i][j];
                             }
                        }
                      cout<<"\n\n\t\t ";      
         }
                        
         
    
                     
                     
    
