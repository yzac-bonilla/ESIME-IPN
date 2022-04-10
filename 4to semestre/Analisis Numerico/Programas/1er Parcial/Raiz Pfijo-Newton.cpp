    
    #include <stdio.h>
    #include <conio.h>    
    #include <iostream>
    #include <math.h>
    #include <stdlib.h>
    #include <D:\include\M_Abierto.h>

    using namespace std;

    int main(int argc, char *argv[])
		{
			M_Abierto *Apt;
			Apt=new M_Abierto;
			
			Apt->Leer();
			Apt->Newton_R();
			
			delete Apt;
    
            system("PAUSE");
            return EXIT_SUCCESS;
        }
