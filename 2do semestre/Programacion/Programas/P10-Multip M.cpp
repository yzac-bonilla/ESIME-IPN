
    using namespace std;
    #include<iostream>
    #include<J:\include\Portada.h>
    
    struct Matriz
           {
                 int Ren;
                 int Col;
                 double **AptMat;
           };
    
    void Leer(Matriz *AptM);
    void Inicializar(Matriz *AptM);
    void LeerMat(Matriz *AptM);
    void Mult(const Matriz *AptM1,const Matriz *AptM2,Matriz *AptMR);
    void Imprimir(const Matriz *AptMat);
    
    int main(void)
        {
                  Caratula();
                  system("cls");
                  int i,j;
                  
                  Matriz *AptM1;
                  Matriz *AptM2;
                  Matriz *AptMR;
                  AptM1=new Matriz;
                  AptM2=new Matriz;
                  AptMR=new Matriz;
                  
                  Leer(AptM1);
                  AptM2->Ren=AptM1->Col;
                  AptM2->Col=AptM1->Col;
                  AptMR->Ren=AptM1->Ren;
                  AptMR->Col=AptM2->Col;
                  
                  Inicializar(AptM1);
                  Inicializar(AptM2);
                  Inicializar(AptMR);
                  
                  LeerMat(AptM1);
                  LeerMat(AptM2);
                  Mult(AptM1,AptM2,AptMR);
                  system("cls");
                  Imprimir(AptM1);
                  Imprimir(AptM2);
                  Imprimir(AptMR);
                  
                  for(int i=0;i<AptM1->Ren;i++)
                          delete []AptM1->AptMat[i];
                  for(int i=0;i<AptM2->Ren;i++)
                          delete []AptM2->AptMat[i];
                  for(int i=0;i<AptMR->Ren;i++)
                          delete []AptMR->AptMat[i];
                  delete []AptM1->AptMat;
                  delete []AptM2->AptMat;
                  delete []AptMR->AptMat;
                  delete AptM1;
                  delete AptM2;
                  delete AptMR;
                  
                  system("pause");
                  return(0);    
        }
                  
    void Leer(Matriz *AptM)
         {
                     cout<<"\n\n\t\tIngrese el Numero de Renglones de la Matriz: ";
                     cin>>AptM->Ren;
                     cout<<"\n\n\t\tIngrese el Numero de Columnas de la Matriz: ";
                     cin>>AptM->Col;
         }
    
    void Inicializar(Matriz *AptM)
         {
                            AptM->AptMat=new double *[AptM->Ren];
                            for(int i=0;i<AptM->Ren;i++)
                                    AptM->AptMat[i]=new double [AptM->Col];
         }
         
    void LeerMat(Matriz *AptM)
         {            cout<<"\n\n\t\tIngresa los Valores de la Matriz: \n\t\t";  
                      int i,j;
                      for(i=0;i<AptM->Ren;i++)
                           for(j=0;j<AptM->Col;j++)
                                cin>>AptM->AptMat[i][j];
         }
         
    void Mult(const Matriz *AptM1,const Matriz *AptM2,Matriz *AptMR)
         {
                     int i,j,k;
                     for(i=0;i<AptM1->Ren;i++)
                     for(j=0;j<AptM2->Ren;j++)
                        {
                                 AptMR->AptMat[i][j]=0;            
                                 for(k=0;k<AptM1->Col;k++)
                                     (AptMR->AptMat[i][j])+=AptM1->AptMat[i][k]*AptM2->AptMat[k][j];
                        }
         }
         
    void Imprimir(const Matriz *AptM)
         {
                      int i,j;
                      cout<<"\n\n\t\t "
                      <<"Matriz:";
                      for(i=0;i<AptM->Ren;i++)
                        {
                           cout<<"\n\n\t\t ";
                           for(j=0;j<AptM->Col;j++)
                             {
                                cout<<"  "
                                <<AptM->AptMat[i][j];
                             }
                        }
                      cout<<"\n\n\t\t ";
         }
                        
         
    
                     
                     
    
