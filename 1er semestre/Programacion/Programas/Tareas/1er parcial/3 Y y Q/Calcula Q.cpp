/*
   Bonilla Silva Isaac
   1CM8
   PP13101211
   Tarea 2: Calcula Q Sin funciones de usuario
 */
  
    #include<stdio.h>
    #include<conio.h>
    #include<math.h>
     main()
     {
           float x,y,z,a,b,c,d,pi,Q;
           printf("Da el valor de pi = ");
           scanf("%f",&pi);
           c=3/pi;
           d=c-360*3.1416/180;
           b=d+c;
           a=c+b;
           x=exp(a);
           y=tan(b);
           z=exp(cos(b));
           printf("\n\n\t\tDatos: \n\n\t\tA = %f \n\n\t\tB = %f",a,b);
           printf("\n\n\t\tC = %f \n\n\t\tD = %f \n\n\t\tPI = %f",c,d,pi);
           printf("\n\n\t\tX = %f \n\n\t\tY = %f \n\n\t\tZ = %f",x,y,z);
           Q=(sin(x)+cos(x+y)/(y+z))/(y-x);
           printf("\n\n\t\tResultado: \n\n\t\tq= %f",Q);
           getch();
           return(0);
           }
           
           
