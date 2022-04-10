 /*
   Bonilla Silva Isaac
   1CM8
   PP13101211
   1.7 Para el siguiente programa indica el valor que entregaria 
       la computadora si:
 */
  
    #include<stdio.h>
    #include<conio.h>
     main()
    {
         int x,y,z=2;
         float a,b=3.5;
         x=3/z+b;
         y=x+5/z*3/2-b;
         x=x+y;
         z=b/3;
         b=y/2;
         a=x+y+b/2-z;
         
         printf("\n x= %d y= %d z= %d a= %f b= %f",x,y,z,a,b);
         
         getch();
         return(0);
         }
         
         
