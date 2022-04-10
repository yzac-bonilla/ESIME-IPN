#include <stdio.h>
#include <iostream.h>
#include <graphics.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#include<dos.h>
using namespace std;
//detener
class detener{
      private:
      public:
	     detener();
	     ~detener();
	     void stop();
      };
detener::detener(){}
detener::~detener(){}
void detener::stop()
{
     typedef BOOL (*PlaySoundA_ptr) (char*, HMODULE, DWORD);
     PlaySoundA_ptr fn_PlaySound = 0;
     HMODULE Lib = LoadLibrary("winmm.dll");
     if (Lib)
     {
      fn_PlaySound =  (PlaySoundA_ptr)GetProcAddress(Lib, "PlaySoundA");
      if (fn_PlaySound)
    {
      fn_PlaySound("silencio.wav", NULL, SND_FILENAME | SND_ASYNC);
    }
    else
    {
      MessageBox(0, "Error", "No se encontro la función PlaySoundA", 0);
    }

    FreeLibrary(Lib);
  }
  else
  {
    MessageBox(0, "Error", "No se pudo cargar winmm.dll", 0);
  }                            initgraph
}
//clase para barras moviles
class barras
{
      private:
              
      public:
             barras();
             ~barras();
             void guia();
             };
barras::barras(){}
barras::~barras(){}
void barras::guia()
{
      int i=10,j=60;
      
      while(1){       
    setbkcolor(1);
    setfillstyle(0, 1);
    bar(i, 300, j, i);
    
    setbkcolor(14);
    setfillstyle(0, 14);
    bar(i*6, 300, (j+50), i);
    
    setbkcolor(2);
    setfillstyle(0, 2);
    bar(i*11, 300, (j+100),i);
    
    delay(150);
    
    setbkcolor(0);
    setfillstyle(0, 0);
    bar(10, 10, 250, 300);
    
    setbkcolor(1);
    setfillstyle(0, 1);
    bar(i, 150, j, i);
    
    setbkcolor(14);
    setfillstyle(0, 14);
    bar(i*6, 200, (j+50), i);
    
    setbkcolor(2);
    setfillstyle(0, 2);
    bar(i*11, i, (j+100), 100);
    
    delay(150);
    
    setbkcolor(0);
    setfillstyle(0, 0);
    bar(10, 10, 250, 300);
    setbkcolor(1);
    setfillstyle(0, 1);
    bar(i, 250, j, i);
    
    setbkcolor(14);
    setfillstyle(0, 14);
    bar(i*6, i, (j+50), 150);
    
    setbkcolor(2);
    setfillstyle(0, 2);
    bar(i*11, 300, (j+100), i);
    
    delay(150);
    
    setbkcolor(0);
    setfillstyle(0, 0);
    bar(10, 10, 250, 300);
    setbkcolor(1);
    setfillstyle(0, 1);
    bar(i, 50, j, i);
    
    setbkcolor(14);
    setfillstyle(0, 14);
    bar(i*6, 200, (j+50), i);
    
    setbkcolor(2);
    setfillstyle(0, 2);
    bar(i*11, 150, (j+100), i);
    
    }
     
     
     
     }
//clase que da inicio a la musica
class yo
{
      private:
      public:
             yo();
             ~yo();
            void play(int num);             
};
yo::yo(){}
yo::~yo(){}
void yo::play(int song)
{
     //if()//generar clase
     
     if(song==1){
                 
     typedef BOOL (*PlaySoundA_ptr) (char*, HMODULE, DWORD); 
     PlaySoundA_ptr fn_PlaySound = 0;
     HMODULE Lib = LoadLibrary("winmm.dll");
     if (Lib)
     {
      fn_PlaySound =  (PlaySoundA_ptr)GetProcAddress(Lib, "PlaySoundA");
      if (fn_PlaySound)
    {
      fn_PlaySound("como una flor.wav", NULL, SND_FILENAME | SND_ASYNC);
    }
    else
    {
      MessageBox(0, "Error", "No se encontro la función PlaySoundA", 0);
    }
      
    FreeLibrary(Lib);
  }
  else
  {
    MessageBox(0, "Error", "No se pudo cargar winmm.dll", 0);
  }
}
if(song==2)
{   
     typedef BOOL (*PlaySoundA_ptr) (char*, HMODULE, DWORD); 
     PlaySoundA_ptr fn_PlaySound = 0;

     HMODULE Lib = LoadLibrary("winmm.dll");
     if (Lib)
     {
      fn_PlaySound =  (PlaySoundA_ptr)GetProcAddress(Lib, "PlaySoundA");
      if (fn_PlaySound)
    {
      fn_PlaySound("love.wav", NULL, SND_FILENAME | SND_ASYNC);
    }
    else
    {
      MessageBox(0, "Error", "No se encontro la función PlaySoundA", 0);
    }
        
    FreeLibrary(Lib);
  }
  else
  {
    MessageBox(0, "Error", "No se pudo cargar winmm.dll", 0);
  }
           }
if(song==3)
{   
     typedef BOOL (*PlaySoundA_ptr) (char*, HMODULE, DWORD); 
     PlaySoundA_ptr fn_PlaySound = 0;


     HMODULE Lib = LoadLibrary("winmm.dll");
     if (Lib)
     {
      fn_PlaySound =  (PlaySoundA_ptr)GetProcAddress(Lib, "PlaySoundA");
      if (fn_PlaySound)
    {
      fn_PlaySound("romeo.wav", NULL, SND_FILENAME | SND_ASYNC);
    }
    else
    {
      MessageBox(0, "Error", "No se encontro la función PlaySoundA", 0);
    }
    
    
    FreeLibrary(Lib);
  }
  else
  {
    MessageBox(0, "Error", "No se pudo cargar winmm.dll", 0);
  }
           }
if(song==4)
{ 
           
           typedef BOOL (*PlaySoundA_ptr) (char*, HMODULE, DWORD); 
     PlaySoundA_ptr fn_PlaySound = 0;


     HMODULE Lib = LoadLibrary("winmm.dll");
     if (Lib)
     {
      fn_PlaySound =  (PlaySoundA_ptr)GetProcAddress(Lib, "PlaySoundA");
      if (fn_PlaySound)
    {
      fn_PlaySound("Slave To The Rhythm.wav", NULL, SND_FILENAME | SND_ASYNC);
    }
    else
    {
      MessageBox(0, "Error", "No se encontro la función PlaySoundA", 0);
    }
    
    
    FreeLibrary(Lib);
  }
  else
  {
    MessageBox(0, "Error", "No se pudo cargar winmm.dll", 0);
  }
           }
          
}
//clase reproduccion de lista
class lista
{
      private:
              yo obj5;
              detener obj12;
              int x,y,i;
      public:
             lista();
             ~lista();
             void seleccion();
      };
lista::lista(){ 
                x=y=0;i=1;
                }
lista::~lista(){}
void lista::seleccion()
{
      clearmouseclick(WM_LBUTTONDOWN);
      const int DELAY=50; // Milliseconds of delay between checks
      while (!ismouseclick(WM_LBUTTONDOWN)){
      delay(DELAY);
      getmouseclick(WM_LBUTTONDOWN, x, y);
   
  if(x>=510 && x<=830){
     if(y>=140 && y<=160){
          
          setbkcolor(3);
	      setfillstyle(0,8);
	      bar(160, 135, 460, 230);
          settextstyle(GOTHIC_FONT,HORIZ_DIR,3);setbkcolor(3);   
          outtextxy(170,170," como la flor.wav");
          obj5.play(1);
         
          
          delay(200);}
  }
      
  if(x>=510 && x<=830){
     if(y>=160 && y<=180){
            
           setbkcolor(3);
	      setfillstyle(0,8);
	      bar(160, 135, 460, 230);
          settextstyle(GOTHIC_FONT,HORIZ_DIR,3);setbkcolor(3);   
          outtextxy(170,170,"bob marley.wav");
          obj5.play(2);
          
          
          delay(200);}
  }
     
  if(x>=510 && x<=830){
     if(y>=180 && y<=200){
               
            
           setbkcolor(3);
	      setfillstyle(0,8);
	      bar(160, 135, 460, 230);
          settextstyle(GOTHIC_FONT,HORIZ_DIR,3);setbkcolor(3);   
          outtextxy(170,170,"romeo.wav");
          obj5.play(3);
                
          delay(200);}
  }
          
  if(x>=510 && x<=830){
     if(y>=200 && y<=220){
               
           setbkcolor(3);
	      setfillstyle(0,8);
	      bar(160, 135, 460, 230);
          settextstyle(GOTHIC_FONT,HORIZ_DIR,1);setbkcolor(3);   
          outtextxy(170,170,"esclava del ritmo.wav");
          obj5.play(4);
          
          
          delay(200);}
  }
          
  if(x>=218 && x<=256){
     if(y>=252 && y<=290){ 
         
               obj12.stop();
                
          
          }
          
          delay(200);}
  }
       
     
     }
//clase que muestra al reproductor
class jam
{
      private:
              lista obj8;
             
              int x,y;
      public:
             jam();
             ~jam();
             void visual();
             };
jam::jam(){ x=y=0;}
jam::~jam(){}
void jam::visual()
{
      setbkcolor(9);
	setfillstyle(0,9);
	bar(152,117,499,299);//relleno marco musicjam
	bar(501, 117, 849, 299);//relleno marco playlist
	bar(152, 301, 849, 480);//relleno marco abajo
	setbkcolor(3);
	setfillstyle(0,8);
	bar(506, 135, 830, 275);//relleno display playlist
	outtextxy(510,140,"cancion 1");
	outtextxy(510,160,"cancion 2");
	outtextxy(510,180,"cancion 3");
	outtextxy(510,200,"cancion 4");
	bar(160, 135, 460, 230);//relleno display musicjam
	
	

	setbkcolor(4);
	setcolor(1);


	//division
	line(500,100,500,300);//enmedio, vertical
	line(150,300,850,300);//marcos de arriba, horizontal
	line(150,115,850,115);//para titulos arriba, horizontal
	line(150,480,850,480);//para titulos abajo,horizontal
	rectangle(506, 135, 830, 275);//marco display playlist
	rectangle(160, 135, 460, 230);//marco display musicjam
    settextstyle(GOTHIC_FONT,HORIZ_DIR,3);      
     	

	
	
	
	//titulos arriba
	setcolor(14);
	settextstyle(2,0,4);
	outtextxy( 295 , 105 , "MUSICJAM" );
	outtextxy( 650 , 105 , "PLAYLIST" );
	line(158,108,290,108);
	line(345,108,645,108);
	line(700,108,840,108);
	
	
	 //titulos abajo
	setcolor(14);
	settextstyle(2,0,4);
	outtextxy(220,485, "DESIGNED BY:            RAMIREZ PATIÑO ANA ITZEL     /      REYES HERNANDEZ ROSA DEL CARMEN");
	 



      //Marco reproductor
      setbkcolor(4);
	  setcolor(1);
      //setlinestyle(0,0,3);
	  
	  line(150,120,150,480);
	  line(175,100,825,100);
	  line(850,120,850,480);
	  line(175,500,825,500);
	  ellipse(179,120,92,180,28,21);
	  ellipse(822,120,0,88,28,21);
	  ellipse(179,480,180,270,29,21);
	  ellipse(827,480,270,0,24,21);    
    //Botones
	 setlinestyle(0,0,3);
	 setcolor(8);
	 setbkcolor(7);
	 setfillstyle(0,7);
	 //circle(200,260,15);
	 //fillellipse(175,280,14,14);//anterior
	 fillellipse(189,270,21,21);//play
	 //fillellipse(247,280,16,16);//pausa
	 fillellipse(237,271,19,19);//detener
	// fillellipse(316,280,14,14);//siguiente
	 
	 setcolor(0);
	 //settextstyle(4,0,0);
	 //outtextxy(169,275, "<<"); 
    
	   obj8.seleccion();
    
	  
	 
     }
//clase audio de portada
class audio
{
      private:
              
              detener obj10;
              jam obj11;
              int x,y,i;
      public:
             audio();
             ~audio();
             void sonido();
             void segcaratula();
             
}; 
audio::audio()
{x=y=0;i=1;
              }
audio::~audio()
{
               }
void audio::sonido()
{
     typedef BOOL (*PlaySoundA_ptr) (char*, HMODULE, DWORD); 
     PlaySoundA_ptr fn_PlaySound = 0;


     HMODULE Lib = LoadLibrary("winmm.dll");
     if (Lib)
     {
      fn_PlaySound =  (PlaySoundA_ptr)GetProcAddress(Lib, "PlaySoundA");
      if (fn_PlaySound)
    {
      fn_PlaySound("jam.wav", NULL, SND_FILENAME | SND_ASYNC);
    }
    else
    {
      MessageBox(0, "Error", "No se encontro la función PlaySoundA", 0);
    }
    
    
    FreeLibrary(Lib);
  }
  else
  {
    MessageBox(0, "Error", "No se pudo cargar winmm.dll", 0);
  }
}
void audio::segcaratula()
{
     cleardevice();
     setbkcolor(0);
     clearviewport();
     setcolor(14);
     settextstyle(GOTHIC_FONT,HORIZ_DIR,3);      
     outtextxy(275,220,"BIENVENIDO A");
     settextstyle(GOTHIC_FONT,HORIZ_DIR,5);      
     outtextxy(275,240,"MUSICJAM");
     setbkcolor(14);setfillstyle(0, 14);
     bar(500,400,580,430);
     setbkcolor(14);setfillstyle(0, 14);
     bar(490,390,600,430);
    setcolor(0); settextstyle(GOTHIC_FONT,HORIZ_DIR,1); 
    outtextxy(500,400,"INICIO");
     setbkcolor(0);
    
     clearmouseclick(WM_LBUTTONDOWN);
      const int DELAY=50; // Milliseconds of delay between checks
      while (!ismouseclick(WM_LBUTTONDOWN)){
      delay(DELAY);
      getmouseclick(WM_LBUTTONDOWN, x, y);
   
  if(x>=490 && x<=600){
     if(y>=390 && y<=430){ 
          setcolor(i++);
               obj10.stop();
          cleardevice();//LIMPIA pantalla en modo grafico    
     //aqui va la caratula del reproductor
    obj11.visual();

          
          
          }
          
          delay(200);}
  }
     
     getch();
   
    
}
//clase que visualiza la portada
class Portada
{
      private:
              audio obj;
              int i,j;
              char Clave[9],Letra;
      public:
             Portada();
             ~Portada();
             void inicio();
             void clave();      
};
Portada::Portada()
{
                i=j=0;  
                  }
Portada::~Portada()
{
                  
                  }
void Portada::inicio()
{
     
   cleardevice();//LIMPIA pantalla en modo grafico
   obj.sonido();
   setbkcolor(0);
   clearviewport();
   setcolor(9);
   for(i=100;i<1000;i++)
      for(j=200;i<1000;i++)
         rectangle(0,0,i,j);
   setcolor(0);
   settextstyle(GOTHIC_FONT,HORIZ_DIR,4);setbkcolor(9);      
   outtextxy(105,10,"INSTITUTO POLITECNICO NACIONAL");
   settextstyle(GOTHIC_FONT,HORIZ_DIR,2); 
   outtextxy(220,45,"UNIDAD PROFESIONAL LOPEZ MATEOS");
   settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
   outtextxy(105,70,"ESCUELA SUPERIOR DE INGENIERIA MECANICA Y ELECTRICA");setcolor(7);
   outtextxy(340,100,"UNIDAD ZACATENCO");
   outtextxy(130,120,"INGENIERIA EN COMUNICACIONES Y ELECTRONICA");
   setcolor(7);
   settextstyle(GOTHIC_FONT,HORIZ_DIR,3);   setcolor(5);
   outtextxy(170,160,"PROGRAMACION ORIENTADA A OBJETOS");
   settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
   setcolor(7);
    setcolor(13);setbkcolor(13); 
   for(i=100;i<1000;i++)
      for(j=600;i<1000;i++)
         rectangle(0,200,i,j);setcolor(1);
   outtextxy(450,240,"2CM8");
   outtextxy(150,280,"RAMIREZ PATIÑO ANA ITZEL");
   outtextxy(150,300,"REYES HERNANDEZ ROSA DEL CARMEN");
}
void Portada::clave()
{
     //clave de acceso:
        
         i=0;
       outtextxy(150,350,"Clave de Acceso:");
       cout<<"clave de acceso:";
      do{ 
            Letra=getch();
            Clave[i]=Letra;
            Clave[i+1]='\0';
            settextstyle(GOTHIC_FONT,HORIZ_DIR,3);setcolor(4);
            outtextxy(400+(i*15),350,"*");
            i++;
        }while(i<9);
  
         if( strcmp(Clave,"musicjam"))
             {
                 cout<<"valido";
                 settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
                 outtextxy(150,370,"clave valida");
                 obj.segcaratula();
             }
         else
             {  
                 cout<<"invalido";
                 outtextxy(150,370,"clave invalida");
                 outtextxy(150,380,"imposible continuar");
             }
  getch();
  closegraph();//cerramos el modo grafico
     }  

int main( )
{   
    Portada obj1;
    initwindow( 1000 , 600 , "WinBGIm" );
    obj1.inicio();
    obj1.clave();
    closegraph( );
    getch();   
	return( 0 );
}


