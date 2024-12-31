#include"welcome.h"
#include"public.h"

void draw_sun()
{
	setcolor(RED);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setfillstyle(1,YELLOW);
	fillellipse(0,0,200,200);
	setcolor(YELLOW);
	moveto(0,258);
	lineto(92,291);
	lineto(119,223);
	lineto(183,256);
	lineto(187,187);
	lineto(268,178);
	lineto(224,121);
	lineto(289,57);
	lineto(226,25);
	lineto(260,0);
	setfillstyle(1,RED);
    floodfill(0,255,YELLOW);
}

void welcome_show()
{
   setbkcolor(LIGHTCYAN);
   draw_sun();
   puthz(350,50,"光伏发电",48,60,YELLOW);
   puthz(350,120,"模拟系统",48,60,YELLOW);
   setcolor(BROWN);
   setfillstyle(1,YELLOW);
   setlinestyle(0,0,NORM_WIDTH);
   bar(240,280,400,340);
   rectangle(240,280,400,340);
   puthz(270,300,"登入系统",24,24,BROWN);
   bar(240,370,400,430);
   rectangle(240,370,400,430);
   puthz(270,390,"退出系统",24,24,BROWN);
}
