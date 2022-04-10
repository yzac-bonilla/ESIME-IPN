#include<iostream.h>
#include<conio.h>

struct tipo
	{
	   float f;
	   int i[2];
	   char c[4];
	};

int main()
	{
	   tipo x;
	   clrscr();
	   x.c[0]=x.c[1]=x.c[2]=x.c[3]=0;
	   x.f=1025;
	   cout<<"x.c[0]="<<x.c[0]<<"x.c[1]<<="<<x.c[1]<<"x.c[2]="<<x.c[2]<<"x.c[3]="<<x.c[3];
	   cout<<"x.i[0]="<<x.i[0]<<"x.i[1]="<<x.i[1];
	   cout<<"x.f="<<x.f;
	   cin.get();
	   cout<<sizeof(x);
	   return 0;
	}