 /*
   Bonilla Silva Isaac
   1CM8
   PP13101211
   1.8 Si se procesara el siguiente programa, indicar que valores
       entregaria la computadora.
 */
  
    #include<stdio.h>
    #include<conio.h>
     main()
    {
           int x=3, y=1, z=2;
           float a,b,c;
           
           a=x/z+1/2;
           b=5/x*z/2;
           c=(x/(2+x)-x/z)/2;
           a=a+b;
           b=b*c;
           x=a-1.0/2;
           y=y+x;
           z=z-x;
           
           printf("\n\n\tx = %d\n\n\ty = %d",x,y);
           printf("\n\n\tz = %d\n\n\ta = %d",z,a);
           printf("\n\n\tb = %d\n\n\tc = %d",b,c);
           
           getch();
           return(0);
           }
           
