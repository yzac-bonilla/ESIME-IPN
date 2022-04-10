/*
   Bonilla Silva Isaac
   1CM8
   2013300995
   Libreria que Lee e Imprime un Vector
 */
	#include<stdio.h>
	#include<conio.h>

	int  leer(void);
	void leevec(int,int [ne]);
	void impvec(int,int [ne]);
	void leevec(int m,int x[ne])
	 {
		int i;
		for(i=1;i<=m;i++)
		scanf("%d",&x[i]);
	 }
	void impvec(int m, int y[ne])
	 {
     	int i;
		for(i=1;i<=m;i++)
		printf("[%d]=%.02d\n\n\t\t",i,y[i]);
	 }
	int leer(void)
	 {
		int R;
		scanf("%d",&R);
		return(R);
	 }

