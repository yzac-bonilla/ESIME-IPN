 /*
   Bonilla Silva Isaac
   1CM8
   PP13101211
   1.10 Para el siguiente programa indicar que valor entregaria
        la computadora si entregara:
 */
  
    #include<stdio.h>
    #include<conio.h>
    #include<math.h>
     main()
    {
         int x,y,z=2;
         float a,b=3.5;
         x=3/z+b;
         y=x+5/z*3/2-b;
         x=x+y;
         b=b/2;
         a=x+y+b;
         a=x+y+b/2-z;
         
         printf("\n\n\n\t x= %d y= %d a= %.3f b= %.3f",x,y,a,b);
         
         getch();
    return(0);
}
