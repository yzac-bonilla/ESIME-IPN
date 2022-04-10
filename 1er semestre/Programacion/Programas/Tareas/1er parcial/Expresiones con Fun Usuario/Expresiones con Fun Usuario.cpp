/*
   Bonilla Silva Isaac
   1CM8
   PP13101211
   Tarea 2: calcula Z,G y W Con funciones de usuario
 */
    #include<stdio.h>
    #include<conio.h>
    #include<math.h>
    void calculaZ(void);
    void calculaG(void);
    void calculaW(void);
    float Z,G,W;
     main()
     {
          calculaZ(); 
          calculaG();
          calculaW();
          printf("\n\n\n\n\t\tRESULTADOS\n\n:\n\n\t\tZ= %f\n\n\t\tG= %f",Z,G);
          printf("\n\n\t\tW= %f",W);
          getch();
     }
     void calculaG(void)
     {
          float x,p,t,te;
          printf("\n\n\n\n\t\tDa los valores de X= P= Angulo t= ");
          scanf("%f%f%f",&x,&p,&t);
          te=t*3.1416/180;
          G=x*x+exp(x)-x*log(p*p)+cos(pow(te,3));
          printf("\n\n\t\tx= %f\n\n\t\tp= %f\n\n\t\tTetha = %f°\n\n",x,p,t);
     }
     void calculaW(void)
     {
          float a,d,r;
          printf("\n\n\t\tDa los valores de a= d= r= ");
          scanf("%f%f%f",&a,&d,&r);
          W=pow(a/(2*d),1/3.)-r;
          printf("\n\n\t\ta= %f\n\n\t\td= %f\n\n\t\tr= %f\n\n",a,d,r);
     }
     void calculaZ(void)
     {
          float a,b,y,fi,fir,z;
          printf("\n\n\t\tDa los valores de a= b= y= Angulo fi= ");
          scanf("%f%f%f%f",&a,&b,&y,&fi);
          fir=fi*3.1416/180;
          Z=(a*a+pow(b,5))/(3*4)+sin(fir)*sin(fir);
          printf("\n\n\t\ta= %f\n\n\t\tb= %f\n\n\t\ty= %ff\n\n\t\tFi= %f°\n\n",a,b,y,fi);
     }
          
          
          
