/*
   Bonilla Silva Isaac
   1CM8
   PP13101211
   Tarea 2: calcula Y Con funciones de usuario
 */
  
    #include<stdio.h>
    #include<conio.h>
    #include<math.h>
    void calculaA(void);
    void calculaF(void);
    float a,f,b,d;
     main()
     {
           float c,y,Pi;
           printf("\n\n\t\tDa el valor de Pi= ");
           scanf("%f",&Pi);
           b=4/3.*Pi;
           calculaF();
           c=cos(b);
           d=c/f;
           calculaA();
           printf("\n\n\t\tDatos:");
           printf("\n\n\t\tB= %f \n\n\t\tC= %f \n\n\t\tD= %f ",b,c,d);
           y=(a+b-c)/(d+f);
           printf("\n\n\t\tPI= %f ",Pi);
           printf("\n\n\t\tF= %f",f);
           printf("\n\n\t\tA= %f",a);
           printf("\n\n\t\tResultado: \n\n\t\ty= %f",y);
           getch();
           return(0);
     }
     void calculaF(void)
     {
               f=sin(b);         
     }
     void calculaA(void) 
     {
              a=sqrt(d-f);             
     }
