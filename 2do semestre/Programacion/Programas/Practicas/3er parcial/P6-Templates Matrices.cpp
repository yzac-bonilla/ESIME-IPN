
    using namespace std;
    #include <iostream>
    #include <J:\include\Portada.h>
    
    template<class M>
    class Matriz
      {
          private:
                 int NRen;
                 int NCol;
                 M **AptMat;
          public:
                 Matriz(int R=2, int C=2);
                 ~Matriz(void);
                 Matriz(Matriz &RefMat);
                 bool Val_Dim(const Matriz *AptM2);
                 void Leer(void);
                 M Mult(const Matriz *AptM1,const Matriz *AptM2);
                 void Imprimir(void)const;
                 void Imprimir2(const Matriz *AptM1,const Matriz *AptM2)const;
      };
    
    template<class M>  
    Matriz<M>::Matriz(int R, int C)
       {
             NRen=(R<1)?2:R;
             NCol=(C<1)?2:C;
             AptMat=new M *[R];
             for(int i=0;i<R;i++)
                 AptMat[i]=new double [C];
             for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                   AptMat[i][j]=0.0;
       }
    
    template<class M>   
    Matriz<M>::Matriz(Matriz &RefMat)
      {
           NRen=RefMat.NRen;
           NCol=RefMat.NCol;
           AptMat=new M *[NRen];
           for(int i=0;i<NRen;i++)
                 AptMat[i]=new double [NCol];
           for(int i=0;i<NRen;i++)
                for(int j=0;j<NCol;j++)
                   AptMat[i][j]=RefMat.AptMat[i][j];
      }
    
    template<class M>  
    Matriz<M>::~Matriz(void)
       {
             for(int i=0;i<NRen;i++)
                 delete []AptMat[i];
             delete []AptMat;
       }
    
    template<class M>   
    bool Matriz<M>::Val_Dim(const Matriz *AptM2)
      {
             return(NCol==AptM2->NRen);
      }
    
    template<class M>  
    void Matriz<M>::Leer(void)
       {
              cout<<"\n\n\n\t\tIngresa los valores de la Matriz:\n\n\t\t"; 
              for(int i=0;i<NRen;i++)
                for(int j=0;j<NCol;j++)
                   cin>>AptMat[i][j];
       }   
    
    template<class M>   
    M Matriz<M>::Mult(const Matriz *AptM1,const Matriz *AptM2)
       {
                M Producto=0;
                for(int i=0;i<NRen;i++)
                   {
                        for(int j=0;j<NCol;j++)
                          {
                             for(int k=0;k<AptM2->NRen;k++)
                                 { 
                                      (AptMat[i][j])+=AptM1->AptMat[i][k]*AptM2->AptMat[k][j];
                                      Producto=AptMat[i][j];
                                 }  
                          }
                    }
                return(Producto);
       }
    
    template<class M>   
    void Matriz<M>::Imprimir(void)const
       {
            cout<<"\n\n\t\tMatriz: ";
            for(int i=0;i<NRen;i++)
               {
                cout<<"\n\n\t\t ";
                for(int j=0;j<NCol;j++)
                  {
                    cout<<"  "
                    <<AptMat[i][j];
                  }
               }
            cout<<"\n\n\t\t ";
       }
    
    template<class M>   
    void Matriz<M>::Imprimir2(const Matriz *AptM1,const Matriz *AptM2)const
       {
            cout<<"\n\n\t\tProducto: ";
            for(int i=0;i<AptM1->NRen;i++)
               {
                cout<<"\n\n\t\t ";
                for(int j=0;j<AptM2->NCol;j++)
                  {
                    cout<<"  "
                    <<AptMat[i][j];
                  }
               }
            cout<<"\n\n\t\t ";
       }
       
    void Leer(int &RefR,int &RefC);
    
    int main(void)
      {
            Caratula();
            system("cls");
            
            int NR1,NR2,NC1,NC2;
            
            Matriz<double> *AptM1;
            Matriz<double> *AptM2;
            Matriz<double> *AptM3;
            
            Leer(NR1,NC1);
            Leer(NR2,NC2);
            
            AptM1=new Matriz<double>(NR1,NC1);
            AptM2=new Matriz<double>(NR2,NC2);
            AptM3=new Matriz<double>(NR1,NC2);
            
            bool Bandera;
            Bandera=AptM1->Val_Dim(AptM2);
            if(Bandera==false)
               cout<<"\n\n\t\tNO SE PUEDE CALCULAR\n\n\t\t";
            else
              {
                  AptM1->Leer();
                  AptM2->Leer();
                  
                  AptM3->Mult(AptM1,AptM2);
                  
                  system("cls");
                  
                  AptM1->Imprimir();
                  AptM2->Imprimir();
                  AptM3->Imprimir2(AptM1,AptM2);   
             }
            delete AptM1;
            delete AptM2;
            delete AptM3;
            system("pause");
            return(0);
      }
      
    void Leer(int &RefR,int &RefC)
       {
               cout<<"\n\n\n\t\tIngresa el Numero de Filas = ";
               cin>>RefR;
               cout<<"\n\n\n\t\tIngresa el Numero de Columnas = ";
               cin>>RefC;
       }
