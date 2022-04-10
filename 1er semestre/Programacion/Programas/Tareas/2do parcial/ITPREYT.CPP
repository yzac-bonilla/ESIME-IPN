/*
   Bonilla Silva Isaac
   1CM8
   PP13101211
   Iterativa Precondicional y(t)
 */

    #include<stdio.h>
    #include<conio.h>
    #include<ctype.h>
    #include<stdlib.h>
    float calcuyt(float);
    void imprimir(float,float);
    void funyt(void);
    void main(void)
	{
		clrscr();
		funyt();
		getch();
	}
    void funyt(void)
	{
		float t,y;
		t=0.1;
		printf("\n\n\t\tT  y(t)");
		while(t<=1.1)
			{
				y=calcuyt(t);
				imprimir(t,y);
				t=t+0.1;
			}
    void imprimir(float t,float y)
	{
		printf("\n\n\t\t%f  %f",t,y);
	}
    float calcuyt(float t)
	{
		float yt;
		yt=(exp(-t)+exp(t))/2;
		return(yt);
	}