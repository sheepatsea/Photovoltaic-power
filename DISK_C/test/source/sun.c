#include"public.h"
#include"sun.h"
#define PI 3.1415926
#define R 130


void sunny_new_sun(int x,int y)  //Ì«ÑôÍ¼Ïñ¸üÐÂ 
{
	setcolor(YELLOW);
	setlinestyle(0,0,NORM_WIDTH);
	setfillstyle(1,YELLOW);
	fillellipse(x,y,20,20);
}

void sunny_clear_sun(int x,int y)  //É¾³ý¾ÉÌ«ÑôÍ¼Ïñ
{
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,NORM_WIDTH);
	setfillstyle(1,LIGHTCYAN);
	fillellipse(x,y,20,20);
}

void cloudy_new_sun(int x,int y)  //Ì«ÑôÍ¼Ïñ¸üÐÂ 
{
	/*if(x>190&&x<385)
	{
		return ;
	}*/
	setcolor(YELLOW);
	setlinestyle(0,0,NORM_WIDTH);
	setfillstyle(1,YELLOW);
	fillellipse(x,y,10,10);
}

void cloudy_clear_sun(int x,int y)  //É¾³ý¾ÉÌ«ÑôÍ¼Ïñ
{
	setcolor(CYAN);
	setlinestyle(0,0,NORM_WIDTH);
	setfillstyle(1,CYAN);
	fillellipse(x,y,10,10);
}
void rainy_new_sun(int x,int y)  //Ì«ÑôÍ¼Ïñ¸üÐÂ 
{
	
}

void rainy_clear_sun(int x,int y)  //É¾³ý¾ÉÌ«ÑôÍ¼Ïñ
{
	
}
