#include"main.h"
#include"public.h"
#include"weather.h"

extern int MouseX;
extern int MouseY;

int weather_change(void)  //产生天气参数 
{
	int flag,cnt ;
	srand((unsigned)time(NULL));
	for(cnt=0;cnt<10;cnt++)
	{
	   flag=rand()%3;	
	}
	return flag;
 } 
 
void weather_show(int weather_mode)
{
    if(inbutton(158,40,483,328))
	{
		clrmous(MouseX,MouseY);
	}
	setcolor(LIGHTCYAN);
    setlinestyle(0,0,NORM_WIDTH);
	switch(weather_mode)
	{
		case 0:
        	setfillstyle(1,LIGHTCYAN);
        	bar(158,40,483,328); 
        	rectangle(158,40,483,328);
            break;
        case 1: 
          	setfillstyle(1,CYAN);
        	bar(158,40,483,328); 
        	rectangle(158,40,483,328); 
         	draw_cloud();
        	break;
        case 2:
        	setfillstyle(1,LIGHTBLUE);
           	bar(158,40,483,328); 
          	rectangle(158,40,483,328);
      //	draw_rain(); 
          	draw_darkclouds();
        	break;
	}
	realtime_show();
}

void draw_cloud(void)  //画多云天气云 
{
	setcolor(WHITE);
	setlinestyle(0,0,NORM_WIDTH); 
	setfillstyle(1,WHITE);
	sector(250,80,0,180,15,10);
	sector(280,80,0,180,15,10);
	sector(295,90,0,90,10,10);
	sector(295,90,270,360,10,10);
	sector(295,110,0,90,10,10);
	sector(295,110,270,360,10,10);
	sector(235,90,90,270,10,10);
	sector(235,110,90,270,10,10);
	sector(250,120,180,360,15,10);
	sector(280,120,180,360,15,10);
	bar(235,80,295,120);
	
	sector(360,80,0,180,15,10);
	sector(390,80,0,180,15,10);
	sector(405,90,0,90,10,10);
	sector(405,90,270,360,10,10);
	sector(405,110,0,90,10,10);
	sector(405,110,270,360,10,10);
	sector(345,90,90,270,10,10);
	sector(345,110,90,270,10,10);
	sector(360,120,180,360,15,10);
	sector(390,120,180,360,15,10);
	bar(345,80,405,120);

}

void draw_darkclouds()//画雨天乌云 
{   
    int i;
	setcolor(LIGHTGRAY);
	setlinestyle(0,0,NORM_WIDTH);
	setfillstyle(1,LIGHTGRAY);
	for(i=178;i<=458;i+=40)
	{
	   sector(i,60,180,360,20,15);	
	}
	sector(483,60,180,270,5,15);
	bar(158,40,483,60);
} 

void draw_rain()  //画雨天雨滴运动 
{
	static int x_rain=0;
	static int flag_rain=0;
	static unsigned int bkcolor[13][30];
	int i;
	int x,y;
	switch(flag_rain)
	{
		case 0:
			flag_rain=1;
			break;
		
		case 1:
	for(i=0,x=40-x_rain,y=160+3*x_rain;i<30;i++,x--,y+=3)
    {
        putpixel(x,y,bkcolor[0][i]);
	}
	for(i=0,x=121-x_rain,y=159+3*x_rain;i<30;i++,x--,y+=3)
    {
         putpixel(x,y,bkcolor[1][i]);
	}
	for(i=0,x=194-x_rain,y=159+3*x_rain;i<30;i++,x--,y+=3)
    {
         putpixel(x,y,bkcolor[2][i]);
	}
	for(i=0,x=128-x_rain,y=318+3*x_rain;i<30;i++,x--,y+=3)
    {
       putpixel(x,y,bkcolor[3][i]);
	}
		for(i=0,x=264-x_rain,y=155+3*x_rain;i<30;i++,x--,y+=3)
    {
       putpixel(x,y,bkcolor[4][i]);
	}
		for(i=0,x=220-x_rain,y=281+3*x_rain;i<30;i++,x--,y+=3)
    {
       putpixel(x,y,bkcolor[5][i]);
	}
		for(i=0,x=154-x_rain,y=387+3*x_rain;i<30;i++,x--,y+=3)
    {
       putpixel(x,y,bkcolor[6][i]);
	}
		for(i=0,x=356-x_rain,y=156+3*x_rain;i<30;i++,x--,y+=3)
    {
      putpixel(x,y,bkcolor[7][i]);
	}
		for(i=0,x=325-x_rain,y=305+3*x_rain;i<30;i++,x--,y+=3)
    {
      putpixel(x,y,bkcolor[8][i]);
	}
		for(i=0,x=432-x_rain,y=143+3*x_rain;i<30;i++,x--,y+=3)
    {
     putpixel(x,y,bkcolor[9][i]);
	}
	for(i=0,x=502-x_rain,y=150+3*x_rain;i<30;i++,x--,y+=3)
    {
      putpixel(x,y,bkcolor[10][i]);
	}
	for(i=0,x=587-x_rain,y=149+3*x_rain;i<30;i++,x--,y+=3)
    {
      putpixel(x,y,bkcolor[11][i]);
	}
	for(i=0,x=628-x_rain,y=238+3*x_rain;i<30;i++,x--,y+=3)
    {
       putpixel(x,y,bkcolor[12][i]);
	}
		 
	}
	
	
  
//***************************************//	
	x_rain+=2;
	if(3*x_rain>200)
	{
		x_rain=0;
	}
	
//***************************************//	
	 for(i=0,x=40-x_rain,y=160+3*x_rain;i<30;i++,x--,y+=3)
    {
       bkcolor[0][i]=getpixel(x,y);
    	putpixel(x,y,WHITE);
	}
	for(i=0,x=121-x_rain,y=159+3*x_rain;i<30;i++,x--,y+=3)
    {
       bkcolor[1][i]=getpixel(x,y);
    	putpixel(x,y,WHITE);
	}
	for(i=0,x=194-x_rain,y=159+3*x_rain;i<30;i++,x--,y+=3)
    {
       bkcolor[2][i]=getpixel(x,y);
    	putpixel(x,y,WHITE);
	}
	for(i=0,x=128-x_rain,y=318+3*x_rain;i<30;i++,x--,y+=3)
    {
      bkcolor[3][i]=getpixel(x,y);
    	putpixel(x,y,WHITE);
	}
		for(i=0,x=264-x_rain,y=155+3*x_rain;i<30;i++,x--,y+=3)
    {
     bkcolor[4][i]=getpixel(x,y);
    	putpixel(x,y,WHITE);
	}
		for(i=0,x=220-x_rain,y=281+3*x_rain;i<30;i++,x--,y+=3)
    {
      bkcolor[5][i]=getpixel(x,y);
    	putpixel(x,y,WHITE);
	}
		for(i=0,x=154-x_rain,y=387+3*x_rain;i<30;i++,x--,y+=3)
    {
      bkcolor[6][i]=getpixel(x,y);
    	putpixel(x,y,WHITE);
	}
		for(i=0,x=356-x_rain,y=156+3*x_rain;i<30;i++,x--,y+=3)
    {
     bkcolor[7][i]=getpixel(x,y);
    	putpixel(x,y,WHITE);
	}
		for(i=0,x=325-x_rain,y=305+3*x_rain;i<30;i++,x--,y+=3)
    {
      bkcolor[8][i]=getpixel(x,y);
    	putpixel(x,y,WHITE);
	}
		for(i=0,x=432-x_rain,y=143+3*x_rain;i<30;i++,x--,y+=3)
    {
     bkcolor[9][i]=getpixel(x,y);
    	putpixel(x,y,WHITE);
	}
	for(i=0,x=502-x_rain,y=150+3*x_rain;i<30;i++,x--,y+=3)
    {
     bkcolor[10][i]=getpixel(x,y);
    	putpixel(x,y,WHITE);
	}
	for(i=0,x=587-x_rain,y=149+3*x_rain;i<30;i++,x--,y+=3)
    {
     bkcolor[11][i]=getpixel(x,y);
    	putpixel(x,y,WHITE);
	}
	for(i=0,x=628-x_rain,y=238+3*x_rain;i<30;i++,x--,y+=3)
    {
      bkcolor[12][i]=getpixel(x,y);
    	putpixel(x,y,WHITE);
	}

}
