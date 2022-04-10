 /*
   Bonilla Silva Isaac
   1CM8
   PP13101211
   tarea 1
 */
    #include<stdio.h>
    #include<conio.h>
    #include<math.h>
     main()
    {
           int c,d;
           float a,b,k1,k2,k3;
           a=3;
           b=8;
           c=3;
           d=2;
           k1=cos(sin(c/d-1.))/b*c/cos(d/c);
           k2=a/b*c/d*a/b;
           k3=exp(cos(sin(1.-c/d)/a)/b)/c;
           
         printf("\n\n\n\t\t\tDatos: \n\n\n\t\t\tA = %.2f \n\n\n\t\t\tB = %.2f",a,b);
         printf("\n\n\n\t\t\tC = %d \n\n\n\t\t\tD = %d ",c,d);
         printf("\n\n\n\t\t\tResultados: \n\n\n\t\t\tK1 = %f ",k1);
         printf(" \n\n\n\t\t\tK2 = %f ",k2);
         printf(" \n\n\n\t\t\tK3 = %f ",k3);
         
         getch();
         return(0);
         }
