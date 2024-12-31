#include"public.h"
#include"main.h"
#include"battery.h"

void battery(int plant_mode,float *b,float *c,float *e)
{
	char s1[10],s2[10],s3[10];
	setlinestyle(0,0,1); 
	setfillstyle(1,BLUE);
	setcolor(BLUE);
	bar(555,70,634,90);
	bar(555,110,634,130);
	bar(555,150,634,170);
	setfillstyle(7,LIGHTBLUE);
	setcolor(LIGHTBLUE);
	bar(555,70,634,90);
	bar(555,110,634,130);
	bar(555,150,634,170);
	settextstyle(0,0,1);
	setcolor(LIGHTCYAN);
	sprintf(s1,"%.2f",b[plant_mode]);
	sprintf(s2,"%.2f",c[plant_mode]);
	sprintf(s3,"%.2f",e[plant_mode]);
	outtextxy(560,78,s1);
	outtextxy(560+strlen(s1)*9,78,"kw");
	outtextxy(560,118,s2);
	outtextxy(560+strlen(s2)*9,118,"kw");
	outtextxy(560,158,s3);
} 

void battery_init()
{
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1);
	rectangle(485,40,635,180);
	puthz(490,42,"用电情况",16,27,LIGHTCYAN);
	puthz(490,72,"直流负载",16,16,LIGHTCYAN);
	puthz(490,112,"交流负载",16,16,LIGHTCYAN);
	puthz(490,152,"电池储能",16,16,LIGHTCYAN);
	settextstyle(0,0,1);
	outtextxy(589,47,"(kw*h)");
	line(485,60,635,60);
}
