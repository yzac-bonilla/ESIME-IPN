
  #include<stdlib.h>
  #include<stdio.h>
  #include<conio.h>
  #include<graphics.h>

  int main(void)
    {
	int driver=DETECT, mode,error;
	int x=15,y=15,radio=5;

	initgraph(&driver,&mode,"D:\TC\BGI");
	if (error != grOk)
	 {
	 printf("Error de graficas: %s\n", grapherrormsg(error));
	 printf("Presione cualquier tecla para salir:");
	 getch();
	 exit(1);
	  }

	circle(x,y,radio);

	closegraph();
	system("pause");
	return(0);
    }