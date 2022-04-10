/*
   Bonilla Silva Isaac
   1CM8
   PP13101211
   Tarea 2: Calcula Y Sin funciones de usuario
 */
  
    #include<stdio.h>
    #include<conio.h>
    #include<math.h>
     main()
     {
           float a,f,c,b,d,y,pi;
           printf("\n\n\t\tDa el valor de pi = ");
           scanf("%f",&pi);
           b=4/3.*pi;
           f=sin(b);
           c=cos(b);
           d=c/f;
           a=sqrt(d-f);
           printf("\n\n\t\tDatos: \n\n\t\tA = %f \n\n\t\tB = %f",a,b);
           printf("\n\n\t\tC = %f \n\n\t\tD = %f \n\n\t\tPi = %f",c,d,pi);
           printf("\n\n\t\tF= %f",f);
           y=(a+b-c)/(d+f);
           printf("\n\n\t\tResultado: \n\n\t\ty= %f",y);
           getch();
           return(0);
           }
