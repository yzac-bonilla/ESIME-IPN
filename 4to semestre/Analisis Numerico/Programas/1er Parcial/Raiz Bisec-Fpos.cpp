    
    #include <stdio.h>
    #include <conio.h>    
    #include <iostream>
    #include <math.h>
    #include <stdlib.h>
    #include <D:\include\M_Cerrado.h>

    using namespace std;

	int main(int argc, char *argv[])
		{
			M_Cerrado *Apt;
			Apt=new M_Cerrado;
			
			Apt->Leer();
			Apt->Biseccion();
			//Apt->F_Posicion();
			
			delete Apt;
    
            system("PAUSE");
            return EXIT_SUCCESS;
    }
