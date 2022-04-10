#include <iostream.h>
#include <conio.h>

struct tipo
//union tipo

{
float f;
int i[];
char c[];
};
int main()
{
tipo x;
clrscr();
x.c[0]=x.c[1]=x.c[2]=x.c[3]=0;
x.i[0]=x.i[1]=0;
x.f=10.25;
cout<<"x.c[0] = "<<x.c[0]<<" x.c[1] = "<<x.c[1]<<" x.c[2] = "<<x.c[2]<<" x.c[3] = "<<x.c[3]<<endl;
cout<<"x.i[0] = "<<x.i[0]<<" x.i[1] = "<<x.i[1]<<endl;
cout<<"x.f= "<<x.f<<endl;
cout<<sizeof(x);
cin.get();
return 0;
}