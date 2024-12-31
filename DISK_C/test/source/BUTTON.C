 #include"button.h"
#include"public.h"

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;

int inbutton(int x1,int y1,int x2,int y2)
{
 if(MouseX>x1&&MouseX<x2&&MouseY>y1&&MouseY<y2)
 {
  return(1);
 }
 else
 {
  return(0);
 }
}

int incircle(int x,int y,int r)
{
	if((MouseX-x)*(MouseX-x)+(MouseY-y)*(MouseY-y)<r*r)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int presscircle(int x,int y,int r)
{
	if((MouseX-x)*(MouseX-x)+(MouseY-y)*(MouseY-y)<r*r&&press==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
