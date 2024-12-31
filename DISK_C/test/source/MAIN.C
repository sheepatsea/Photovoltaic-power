#include"public.h"
#include"main.h"

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;

void main()
{
   int meaningless_plant=5,meaningless_menu=5;
   int gd=VGA,gm=VGAHI;
   initgraph(&gd,&gm,"C:\\BORLANDC\\BGI");
   welcome_show();
   mouseinit();
   while(1)
   {
   	  func(0,&meaningless_plant,&meaningless_menu);
	  newmouse(&MouseX,&MouseY,&press);
	  if(inbutton(240,280,400,340)==1)
	  {
		  MouseS=1;
		  if(mouse_press(240,280,400,340)==1)
		  {
			main_system();
			clrmous(MouseX,MouseY);
            cleardevice();
			welcome_show();
		  }
	  }
	  else if(inbutton(240,370,400,430)==1)
	  {
		  MouseS=1;
		  if(mouse_press(240,370,400,430)==1)
		  {
			closegraph();
			exit(1);
		  }
	  }
	  else MouseS=0;
   }
}
