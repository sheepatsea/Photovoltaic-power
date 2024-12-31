#include"public.h"
#include"main.h"
#include"chart.h"

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;

void past_data(int plant_mode,struct DAYDATA *pdate_data)
{
	int meaningless_plant=1,meaningless_menu=1;
	int i;
	int code=0,flag;
	float coord[49];
	linechart(plant_mode,coord,pdate_data);
	while(1)
	{
		func(2,&meaningless_plant,&meaningless_menu);
		newmouse(&MouseX,&MouseY,&press);
		flag=0;
		for(i=0;i<49;i++)
		{
			if(inbutton(26+12*i,coord[i]-4,34+12*i,coord[i]+4)==1&&code==0)
			{
				code=i+1;
				flag=1;
				break;
			}
		}
		if(code>0&&inbutton(26+12*(code-1),coord[code-1]-4,34+12*(code-1),coord[code-1]+4)==1)
		{
			if(flag==1)
			{
				clrmous(MouseX,MouseY);
				chart_sign(plant_mode,coord,code,pdate_data);
			}
		}
		else if(inbutton(560,10,630,40)==1)
		{
			MouseS=1;
			if(mouse_press(560,10,630,40)==1)
			{
				delay(400);
				newmouse(&MouseX,&MouseY,&press);
				clrmous(MouseX,MouseY);
				cleardevice();
				return;
			}
		}
		else
		{
			MouseS=0;
			if(code>0)
			{
				clrmous(MouseX,MouseY);
				clr_sign(coord,code);
				chart_graph(plant_mode);
				chart_line(plant_mode,coord,pdate_data);
				code=0;
			}
		}
	}
} 
                

void linechart(int plant_mode,float *coord,struct DAYDATA *pdate_data)
{
	int i;
	setbkcolor(BLUE);
    setcolor(LIGHTCYAN);
	setlinestyle(0,0,1);
    wri_date(plant_mode,pdate_data);
    setfillstyle(1,CYAN);
    bar(560,10,630,40);
    rectangle(560,10,630,40);
    puthz(572,17,"返回",16,30,LIGHTCYAN);
    chart_graph(plant_mode);
    chart_line(plant_mode,coord,pdate_data);
    chart_energy(plant_mode,pdate_data);
} 

void wri_date(int plant_mode,struct DAYDATA *pdate_data)
{
	char s1[5],s2[3],s3[3];
	itoa(pdate_data->year,s1,10);
	itoa(pdate_data->month,s2,10);
	itoa(pdate_data->day,s3,10);
	settextstyle(2,0,8);
	setcolor(LIGHTCYAN);
	outtextxy(10,0,s1);
	puthz(70,3,"年",24,24,LIGHTCYAN);
	outtextxy(100,0,s2);
	puthz(130,3,"月",24,24,LIGHTCYAN);
	outtextxy(160,0,s3); 
	puthz(190,3,"日",24,24,LIGHTCYAN);
	puthz(240,3,"星期",24,24,LIGHTCYAN);
	switch(pdate_data->weekday)
	{
		case 1:
			puthz(288,3,"一",24,24,LIGHTCYAN);
			break;
		case 2:
			puthz(288,3,"二",24,24,LIGHTCYAN);
			break;
		case 3:
			puthz(288,3,"三",24,24,LIGHTCYAN);
			break;
		case 4:
			puthz(288,3,"四",24,24,LIGHTCYAN);
			break;
		case 5:
			puthz(288,3,"五",24,24,LIGHTCYAN);
			break;
		case 6:
			puthz(288,3,"六",24,24,LIGHTCYAN);
			break;
		case 7:
			puthz(288,3,"日",24,24,LIGHTCYAN);
			break;
	}
	switch(pdate_data->weather_mode[plant_mode]) 
	{
		case 0:
			puthz(340,3,"晴",24,24,LIGHTCYAN);
			break;
		case 1:
			puthz(340,3,"多云",24,24,LIGHTCYAN);
			break;
		case 2:
			puthz(340,3,"小雨",24,24,LIGHTCYAN);
			break;
	}
}

void chart_graph(int plant_mode)
{
	int i;
	char s[10];
	setcolor(WHITE);
	setlinestyle(0,0,1);
    moveto(30,50);
    lineto(30,460);
    lineto(615,460);
    for(i=0;i<24;i++)
    {
 	   line(54+24*i,460,54+24*i,452);
 	   line(42+24*i,460,42+24*i,457);
    }
    for(i=0;i<10;i++)
    {
 	   line(30,420-40*i,38,420-40*i);
 	   line(30,440-40*i,33,440-40*i);
    }
    line(30,50,35,55);
    line(30,50,25,55);
    line(615,460,610,455);
    line(615,460,610,465);
    settextstyle(2,0,6);
    outtextxy(15,30,"P/kW");
    settextstyle(2,0,5);
    outtextxy(617,450,"t/h");
    if(plant_mode==0)
    {
    	for(i=1;i<=10;i++)
    	{
    		itoa(60*i,s,10);
    		outtextxy(5,453-40*i,s);
		}
	}
	else if(plant_mode==1||plant_mode==2)
	{
		for(i=1;i<=10;i++)
		{
			itoa(4*i,s,10);
			outtextxy(5,453-40*i,s);
		}
	}
	else if(plant_mode==3)
	{
		for(i=1;i<=10;i++)
		{
			itoa(40*i,s,10);
			outtextxy(5,453-40*i,s);
		}
	}
    outtextxy(23,460,"0");
    for(i=1;i<10;i++)
    {
 	   itoa(i,s,10);
 	   outtextxy(27+24*i,460,s);
    }
    for(i=10;i<25;i++)
    {
 	   itoa(i,s,10);
 	   outtextxy(24+24*i,460,s);
    }
}

void chart_line(int plant_mode,float *coord,struct DAYDATA *pdate_data)
{
	int i;
	setcolor(WHITE);
	setlinestyle(0,0,1);
	moveto(30,460);
    if(plant_mode==0)
    {
    	for(i=0;i<49;i++)
    	{
    		coord[i]=pdate_data->plant[0][i]*0.666;
    		coord[i]=460-coord[i];
    		lineto(30+12*i,coord[i]);
		}
	}
	else if(plant_mode==1)
	{
		for(i=0;i<49;i++)
    	{
    		coord[i]=pdate_data->plant[1][i]*10;
    		coord[i]=460-coord[i];
    		lineto(30+12*i,coord[i]);
		}
	}
	else if(plant_mode==2)
	{
		for(i=0;i<49;i++)
    	{
    		coord[i]=pdate_data->plant[2][i]*10;
    		coord[i]=460-coord[i];
    		lineto(30+12*i,coord[i]);
		}
	}
	else if(plant_mode==3)
	{
		for(i=0;i<49;i++)
    	{
    		coord[i]=pdate_data->plant[3][i];
    		coord[i]=460-coord[i];
    		lineto(30+12*i,coord[i]);
		}
	}
}

void chart_energy(int plant_mode,struct DAYDATA *pdate_data)
{
	char s[10];
    sprintf(s,"%.2f",pdate_data->energy[plant_mode]);
    setcolor(LIGHTCYAN);
	settextstyle(2,0,7);
	puthz(100,40,"总发电量：",16,16,LIGHTCYAN);
	outtextxy(180,38,s);
	outtextxy(180+12*strlen(s),38,"kw*h");
} 

void chart_sign(int plant_mode,float *coord,int code,struct DAYDATA *pdate_data)
{
	char s[10],s0[10],s1[3],s2[2]=":",s3[3];
	int i;
	setcolor(WHITE);
	setlinestyle(0,0,3);
	moveto(30,460);
	for(i=0;i<49;i++)
	{
		lineto(30+12*i,coord[i]);
	}
	setlinestyle(1,0,1);
	line(30+12*(code-1),coord[code-1],30+12*(code-1),460);
	line(30+12*(code-1),coord[code-1],30,coord[code-1]);
	setfillstyle(1,GREEN);
	setcolor(GREEN);
	fillellipse(30+12*(code-1),coord[code-1],2,2);
	sprintf(s,"%.2f",pdate_data->plant[plant_mode][code-1]);
	puthz(414,30,"时间：",16,16,LIGHTCYAN);
	puthz(414,50,"功率：",16,16,LIGHTCYAN);
	settextstyle(2,0,7);
	setcolor(LIGHTCYAN);
	itoa((code-1)/2,s1,10);
	if((code-1)%2==0)
	{
	   	strcpy(s3,"00");
	}
	else
	{
		strcpy(s3,"30");
	}
	strcpy(s0,s1);
	strcat(s0,s2);
	strcat(s0,s3);
	outtextxy(462,28,s0);
	outtextxy(462,48,s);
	outtextxy(462+12*strlen(s),48,"kw");
}

void clr_sign(float *coord,int code)
{
	int i;
	setfillstyle(1,BLUE);
	setcolor(BLUE);
	bar(413,29,550,70);
	bar(550,41,570,70);
	setlinestyle(0,0,3);
	for(i=0;i<49;i++)
	{
		lineto(30+12*i,coord[i]);
	}
	fillellipse(30+12*(code-1),coord[code-1],2,2);
	setlinestyle(0,0,1);
	line(30+12*(code-1),coord[code-1],30+12*(code-1),460);
	line(30+12*(code-1),coord[code-1],30,coord[code-1]);
}
