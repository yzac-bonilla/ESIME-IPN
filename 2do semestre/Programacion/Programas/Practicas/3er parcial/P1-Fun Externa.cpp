
    using namespace std;
    #include <iostream>
    
    class   Tienda
             {
                   friend double Restante(const Tienda *AptT, int Vend);
                   friend double Total(const Tienda *AptT, int Vend);
                   friend double Costo2(const Tienda *AptT, int Vend);
                   private:
                           int Proto;
                           double Precio;
                           
                   public:
                          Tienda(int Pt=0,double Pr=0.0);
                          void Leer(void);
                          double Costo(void);
                          void Imprimir(void);
                          
             };
    
    Tienda::Tienda(int Pt,double Pr)
       {
             Proto=Pt;
             Precio=Pr;
       }
    
    void Tienda::Leer(void)
       {     cout<<"\n\n\t\t\t\t    .:TIENDA:."
             <<"\n\n\tIngrese el numero de Prortoboards existentes en el almacen = ";
             cin>>Proto;
             cout<<"\n\n\tIngrese el Precio Unitario = ";
             cin>>Precio;
       }
       
    double Tienda::Costo(void)
      {
           return(Proto*Precio);
      }
      
    void Tienda::Imprimir(void)
       {
             cout<<"\n\n\t\tNumero de Prortoboards: "
             <<Proto
             <<"\n\n\t\tPrecio Unitario: "
             <<Precio
             <<"\n\n\t\tCosto del Inventario en Protoboards: "
             <<Costo();
       }
                          
    int Lee_Vendidos(void);
    void Mostrar(const Tienda *AptT, int Vend);
    
    int main(void)
       {
            int Vend;
            Tienda *AptT;
            AptT=new Tienda;
            
            AptT->Leer();
            Vend=Lee_Vendidos();
            system("cls");
            
            AptT->Imprimir();
            Mostrar(AptT,Vend);
            
            delete AptT;
            system("pause");
            return(0);
       }
                  
    int Lee_Vendidos(void)
       {
             int Vendidos;
             cout<<"\n\n\t\tIngrese el numero de Protoboards Vendidos = ";
             cin>>Vendidos;
             return(Vendidos);
       }
       
    double Restante(const Tienda *AptT, int Vend)
       {
            return(AptT->Proto-Vend);
       }
       
    double Total(const Tienda *AptT, int Vend)
        {
             return(AptT->Precio*Vend);
        }
    
    double Costo2(const Tienda *AptT, int Vend)
        {
             return(Restante(AptT,Vend)*AptT->Precio);
        }
    
    void Mostrar(const Tienda *AptT, int Vend)
        {
             cout<<"\n\n\t\tProtoboards Vendidos: "
             <<Vend
             <<endl
             <<"\n\n\t\tNumero de Protoboards que quedaron en el almacen: "
             <<Restante(AptT,Vend)
             <<"\n\n\t\tTotal recaudado de la venta del dia: "
             <<Total(AptT,Vend)
             <<"\n\n\t\tNuevo Costo del inventario en Protoboards: "
             <<Costo2(AptT,Vend)
             <<"\n\n\t\t";
        }    
           
                           
