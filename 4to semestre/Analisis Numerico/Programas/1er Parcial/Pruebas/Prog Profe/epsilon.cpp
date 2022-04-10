#include<stdio.h>
#include<conio.h>
int main(void)
{
	double x=1.0;
	int n=0;
	while(1.0+(x*0.5)>1.0)
	{
		++n; x*=0.5;
	}
	
	printf("epsilon en binario=2^(-%)\n",n);
	printf("epsilon en decimal=%G\n",x);

getch();
return 0;
}
