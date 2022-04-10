 /*
   Bonilla Silva Isaac
   1CM8
   PP13101211
   Programa para calcular K
 */
 
   #include<stdio.h>
   #include<math.h>
   #include<conio.h>
 
    main()
    {
       int b,c,d;
       float a,k;
       a=6;
       b=4;
       c=3;
       d=5;
   
     k=cos(sin(2.-d/2)*3/2+1)+c/6+pow(a,1/3)*d/c/a;
     
     printf("\n\n\n\t\tDatos: \n\n\tA = %.2f \n\n\tB = %d",a,b);
     printf("\n\n\tC = %d \n\n\tD = %d",c,d);
     printf("\n\n\t\tResultado: \n\n\tk = %f",k);
 
     getch();
     return(0);
     }  
 
