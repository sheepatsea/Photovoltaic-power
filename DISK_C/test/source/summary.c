#include"public.h"
#include"main.h"
#include"summary.h"

void summary_init()
{
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1);
	rectangle(485,340,635,480);  //右三 （发电总结） 
    line(485,360,595,360);
    line(595,360,635,340);
    puthz(490,342,"发电总结",16,32,LIGHTCYAN);
}

void summary_chart(int plant_mode)
{
	FILE *fp;
	int medium;
	struct DAYDATA yesterday;
	fp=fopen("C:\\test\\DATA\\last.txt","rt");
	fscanf(fp,"%d%d%d",&medium,&yesterday.month,&yesterday.day);
	fclose(fp);
	setfillstyle(1,BLUE);
	setcolor(BLUE);
	bar(486,361,634,479);
	setfillstyle(7,LIGHTBLUE);
	setcolor(LIGHTBLUE);
	bar(486,361,634,479);
	if(medium==0||(medium==22&&yesterday.month==1&&yesterday.day<3))
	{
		puthz(490,408,"无发电总结",24,29,LIGHTCYAN);
	}
	else
	{
		yesterday.year=medium+2000;
		search_data(&yesterday);
		summary_graph(plant_mode);
		summary_bar(&yesterday,plant_mode);
	}
}

void summary_graph(int plant_mode)
{
	int i;
	char s[10];
	setcolor(WHITE);
	setlinestyle(0,0,1);
	line(512,380,512,470);
	line(512,470,632,470);
	for(i=0;i<4;i++)
	{
		line(512,390+20*i,520,390+20*i);
		line(512,400+20*i,515,400+20*i);
	}
	line(512,380,507,385);
	line(512,380,517,385);
	line(632,470,627,475);
	line(632,470,627,465);//箭头 
	settextstyle(0,0,1);
	outtextxy(497,370,"kw*h");
	outtextxy(502,465,"0");
	settextstyle(2,0,4);
	switch(plant_mode)
	{
		case 0:
			for(i=0;i<4;i++)
	        {
	        	itoa(4000-1000*i,s,10);
		        outtextxy(512-6*strlen(s),385+20*i,s);
	        }
	        break;
	    case 1:
	    	for(i=0;i<4;i++)
	    	{
	    		itoa(200-50*i,s,10);
	    		outtextxy(512-6*strlen(s),385+20*i,s);
			}
			break;
		case 2:
			for(i=0;i<4;i++)
	    	{
	    		itoa(300-75*i,s,10);
	    		outtextxy(512-6*strlen(s),385+20*i,s);
			}
			break;
		case 3:
			for(i=0;i<4;i++)
	    	{
	    		itoa(2000-500*i,s,10);
	    		outtextxy(512-6*strlen(s),385+20*i,s);
			}
			break;
	}
}

void summary_bar(struct DAYDATA *pyesterday,int plant_mode)
{
	struct DAYDATA day1,day2;
	float coord[3],ratio=0;
	char s[10];
	threedayago_search(pyesterday,&day1);
	nextday(&day1,&day2);
	switch(plant_mode)
	{
		case 0:
			ratio=0.02;
			break;
		case 1:
			ratio=0.4;
			break;
		case 2:
			ratio=0.267;
			break;
		case 3:
	        ratio=0.04;
			break; 
	}
	coord[0]=470-(day1.energy[plant_mode]*ratio);
	coord[1]=470-(day2.energy[plant_mode]*ratio);
	coord[2]=470-(pyesterday->energy[plant_mode]*ratio);
	setfillstyle(1,LIGHTGREEN);
	setcolor(LIGHTGREEN);
	setlinestyle(0,0,1);
	settextstyle(0,0,1);
	bar(532,coord[0],552,469);
	bar(567,coord[1],587,469);
	bar(602,coord[2],622,469);
	sprintf(s,"%.f",day1.energy[plant_mode]);
	outtextxy(543-4*strlen(s),coord[0]-10,s);
	sprintf(s,"%.f",day2.energy[plant_mode]);
	outtextxy(578-4*strlen(s),coord[1]-10,s);
	sprintf(s,"%.f",pyesterday->energy[plant_mode]);
	outtextxy(613-4*strlen(s),coord[2]-10,s);
}
