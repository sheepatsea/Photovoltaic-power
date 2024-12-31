#include"public.h"
#include"main.h"

void draw_nonweek()
{
	setbkcolor(BLUE);
	setfillstyle(7,LIGHTBLUE);
	bar(0,0,640,480);
	setcolor(LIGHTGREEN);
	setlinestyle(0,0,1); 
	setfillstyle(1,CYAN);
	bar(560,430,630,460);
	rectangle(560,430,630,460);
	puthz(572,437,"返回",16,30,LIGHTCYAN);
	bar(45,12,135,52);
	rectangle(45,12,135,52);
	puthz(50,20,"近一周",24,28,LIGHTCYAN);
	setfillstyle(1,LIGHTBLUE);
	bar(491,12,609,52);
	rectangle(491,12,609,52);
	puthz(496,20,"日期定位",24,28,LIGHTCYAN);
	bar(275,12,365,52);
	rectangle(275,12,365,52);
	puthz(280,20,"近一月",24,28,LIGHTCYAN);
	bar(100,70,540,420);
	rectangle(100,70,540,420);
	puthz(140,221,"无历史数据",48,78,LIGHTCYAN);
} 

void draw_nonmonth()
{
	setbkcolor(BLUE);
	setfillstyle(7,LIGHTBLUE);
	bar(0,0,640,480);
	setcolor(LIGHTGREEN);
	setlinestyle(0,0,1); 
	setfillstyle(1,CYAN);
	bar(560,430,630,460);
	rectangle(560,430,630,460);
	puthz(572,437,"返回",16,30,LIGHTCYAN);
	bar(275,12,365,52);
	rectangle(275,12,365,52);
	puthz(280,20,"近一月",24,28,LIGHTCYAN);
	setfillstyle(1,LIGHTBLUE);
	bar(100,70,540,420);
	rectangle(100,70,540,420);
	bar(491,12,609,52);
	rectangle(491,12,609,52);
	puthz(496,20,"日期定位",24,28,LIGHTCYAN);
	bar(45,12,135,52);
	rectangle(45,12,135,52);
	puthz(50,20,"近一周",24,28,LIGHTCYAN);
	puthz(140,221,"无历史数据",48,78,LIGHTCYAN);
} 

void draw_week(int plant_mode,int weekday_num,struct DAYDATA *week_data)
{
	int i; 
	setbkcolor(BLUE);
	setfillstyle(7,LIGHTBLUE);
	bar(0,0,640,480);
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1); 
	setfillstyle(1,CYAN);
	bar(100,70,540,420);
	bar(560,430,630,460);
	rectangle(560,430,630,460);
	puthz(572,437,"返回",16,30,LIGHTCYAN);
	bar(45,12,135,52);
	rectangle(45,12,135,52);
	puthz(50,20,"近一周",24,28,LIGHTCYAN);
	setfillstyle(1,LIGHTBLUE);
	bar(491,12,609,52);
	rectangle(491,12,609,52);
	puthz(496,20,"日期定位",24,28,LIGHTCYAN);
	bar(275,12,365,52);
	rectangle(275,12,365,52);
	puthz(280,20,"近一月",24,28,LIGHTCYAN);
	for(i=0;i<weekday_num;i++)
	{
		input_date(plant_mode,week_data[i],i);
	}
	rectangle(100,70,540,420);
}

void draw_button1()
{
	int  v1[]={43,245,61,235,61,255};
	setfillstyle(1,CYAN);
	setcolor(DARKGRAY);
	fillellipse(55,245,15,15); 
	setfillstyle(1,DARKGRAY);
    fillpoly(3,v1);
}

void clr_button1()
{
	setfillstyle(1,BLUE);
	setcolor(BLUE);
	bar(40,230,70,260); 
	setfillstyle(7,LIGHTBLUE);
	setcolor(LIGHTBLUE);
	bar(40,230,70,260);  
}

void draw_button2()
{
	int v2[]={597,245,579,235,579,255}; 
	setfillstyle(1,CYAN);
	setcolor(DARKGRAY);
	fillellipse(585,245,15,15); 
	setfillstyle(1,DARKGRAY);
	fillpoly(3,v2);
}

void clr_button2()
{
	setfillstyle(1,BLUE);
	setcolor(BLUE);
	bar(570,230,600,260);
	setfillstyle(7,LIGHTBLUE);
	setcolor(LIGHTBLUE); 
	bar(570,230,600,260);
}

void draw_month(int plant_mode,int num,struct DAYDATA *month_data)
{
	int i; 
	setbkcolor(BLUE);
	setfillstyle(7,LIGHTBLUE);
	bar(0,0,640,480);
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1); 
	setfillstyle(1,CYAN);
	bar(100,70,540,420);
	rectangle(100,70,540,420);
	bar(560,430,630,460);
	rectangle(560,430,630,460);
	puthz(572,437,"返回",16,30,LIGHTCYAN);
	bar(275,12,365,52);
	rectangle(275,12,365,52);
	puthz(280,20,"近一月",24,28,LIGHTCYAN);
	setfillstyle(1,LIGHTBLUE);
	bar(491,12,609,52);
	rectangle(491,12,609,52);
	puthz(496,20,"日期定位",24,28,LIGHTCYAN);
	bar(45,12,135,52);
	rectangle(45,12,135,52);
	puthz(50,20,"近一周",24,28,LIGHTCYAN);
	if(num<=7)
	{
		for(i=0;i<num;i++)
		{
			input_date(plant_mode,month_data[i],i);
		}
	}
	else
	{
		for(i=0;i<7;i++)
		{
			input_date(plant_mode,month_data[i],i);
		}
	    draw_button2();
	}
} 

void input_date(int plant_mode,struct DAYDATA date_data,int i)
{
	char s1[5],s2[3],s3[3];
	itoa(date_data.year,s1,10);
	itoa(date_data.month,s2,10);
	itoa(date_data.day,s3,10);
	settextstyle(2,0,8);
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1);
	setfillstyle(1,LIGHTBLUE);
	bar(100,70+50*i,540,120+50*i);
	rectangle(100,70+50*i,540,120+50*i);
	outtextxy(110,80+50*i,s1);
	puthz(170,83+50*i,"年",24,24,LIGHTCYAN);
	outtextxy(200,80+50*i,s2);
	puthz(230,83+50*i,"月",24,24,LIGHTCYAN);
	outtextxy(260,80+50*i,s3); 
	puthz(290,83+50*i,"日",24,24,LIGHTCYAN);
	puthz(340,83+50*i,"星期",24,24,LIGHTCYAN);
	switch(date_data.weekday)
	{
		case 1:
			puthz(388,83+50*i,"一",24,24,LIGHTCYAN);
			break;
		case 2:
			puthz(388,83+50*i,"二",24,24,LIGHTCYAN);
			break;
		case 3:
			puthz(388,83+50*i,"三",24,24,LIGHTCYAN);
			break;
		case 4:
			puthz(388,83+50*i,"四",24,24,LIGHTCYAN);
			break;
		case 5:
			puthz(388,83+50*i,"五",24,24,LIGHTCYAN);
			break;
		case 6:
			puthz(388,83+50*i,"六",24,24,LIGHTCYAN);
			break;
		case 7:
			puthz(388,83+50*i,"日",24,24,LIGHTCYAN);
			break;
	}
	switch(date_data.weather_mode[plant_mode]) 
	{
		case 0:
			puthz(440,83+50*i,"晴",24,24,LIGHTCYAN);
			break;
		case 1:
			puthz(440,83+50*i,"多云",24,24,LIGHTCYAN);
			break;
		case 2:
			puthz(440,83+50*i,"小雨",24,24,LIGHTCYAN);
			break;
	}
}

void draw_search(struct DAYDATA *pinitial,struct DAYDATA *pyesterday)
{
	setbkcolor(BLUE);
	setfillstyle(7,LIGHTBLUE);
	bar(0,0,640,480);
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1); 
	setfillstyle(1,CYAN); 
	bar(560,430,630,460);
	rectangle(560,430,630,460);
	puthz(572,437,"返回",16,30,LIGHTCYAN);
	bar(491,12,609,52);
	rectangle(491,12,609,52);
	puthz(496,20,"日期定位",24,28,LIGHTCYAN);
	setfillstyle(1,LIGHTBLUE);
	bar(100,70,540,450);
	rectangle(100,70,540,450);
	bar(45,12,135,52);
	rectangle(45,12,135,52);
	puthz(50,20,"近一周",24,28,LIGHTCYAN);
	bar(275,12,365,52);
	rectangle(275,12,365,52);
	puthz(280,20,"近一月",24,28,LIGHTCYAN);
	bar(130,80,230,100);
	bar(270,80,370,100);
	bar(410,80,510,100);
	puthz(148,82,"年：",16,16,LIGHTCYAN);
	puthz(294,82,"月：",16,16,LIGHTCYAN);
	puthz(434,82,"日：",16,16,LIGHTCYAN);
	input_year(pinitial,pyesterday);
	rectangle(130,80,230,100);
	rectangle(270,80,370,100);
	rectangle(410,80,510,100);
}

void input_year(struct DAYDATA *pinitial,struct DAYDATA *pyesterday)
{
	int i;
	char s[5];
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1);
	setfillstyle(1,LIGHTBLUE);
	settextstyle(2,0,7);
	for(i=0;pinitial->year+i<=pyesterday->year;i++)	
    {
		itoa(pinitial->year+i,s,10);
		bar(130,100+20*i,230,120+20*i);
		rectangle(130,100+20*i,230,120+20*i);
		outtextxy(160,98+20*i,s);
	}
}

void line_year(int year_j)
{
	char s[5];
	itoa(year_j,s,10); 
	setfillstyle(1,BLUE);
	setcolor(LIGHTCYAN);
	bar(130,100+20*(year_j-2022),230,120+20*(year_j-2022));
	rectangle(130,100+20*(year_j-2022),230,120+20*(year_j-2022));						
	settextstyle(2,0,7);
	outtextxy(180,78,s);
	outtextxy(160,98+20*(year_j-2022),s);
}

void clr_year(struct DAYDATA *pinitial,struct DAYDATA *pyesterday)
{
	int i;
	setcolor(LIGHTBLUE);
	setfillstyle(1,LIGHTBLUE);
	setlinestyle(0,0,1);
	for(i=0;pinitial->year+i<=pyesterday->year;i++)	
    {
		bar(130,100+20*i,230,120+20*i);
	}
	bar(186,81,229,99); 
} 

void input_month(int monthnum)
{
	int i;
	char s[3];
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1);
	setfillstyle(1,LIGHTBLUE);
	settextstyle(2,0,7);
    for(i=0;i<monthnum;i++)
    {
    	itoa(i+1,s,10);
    	bar(270,100+20*i,370,120+20*i);
    	rectangle(270,100+20*i,370,120+20*i);
    	outtextxy(310,98+20*i,s);
	}
}

void line_month(int month_j)
{
	char s[3];
	setfillstyle(1,BLUE);
	setcolor(LIGHTCYAN);
	bar(270,100+(month_j-1)*20,370,100+month_j*20);
	rectangle(270,100+(month_j-1)*20,370,100+month_j*20);
	settextstyle(2,0,7);
	itoa(month_j,s,10);
	outtextxy(326,78,s);
	outtextxy(310,98+20*(month_j-1),s);
} 

void clr_month(int monthnum)
{
	int i;
	setcolor(LIGHTBLUE);
	setfillstyle(1,LIGHTBLUE);
	setlinestyle(0,0,1);
	for(i=0;i<monthnum;i++)
    {
    	bar(270,100+20*i,370,120+20*i);
	}
	bar(326,81,369,99);
	setcolor(LIGHTCYAN);
	line(270,100,370,100);
}

void input_day(int daynum)
{
	int i,v[]={515,85,515,95,525,90};
	char s[3];
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1);
	setfillstyle(1,LIGHTBLUE);
	settextstyle(2,0,7);
	if(daynum<=16)
	{
		for(i=0;i<daynum;i++)
	    {
		    itoa(i+1,s,10);
		    bar(410,100+20*i,510,120+20*i);
		    rectangle(410,100+20*i,510,120+20*i);
		    outtextxy(450,98+20*i,s);
	    }
	}
	else if(daynum>16)
	{
		for(i=0;i<16;i++)
	    {
		    itoa(i+1,s,10);
		    bar(410,100+20*i,510,120+20*i);
		    rectangle(410,100+20*i,510,120+20*i);
		    outtextxy(450,98+20*i,s);
	    }
	    setfillstyle(1,MAGENTA);
	    fillpoly(3,v);
	}
}

void input_daypage2(int daynum)
{
	int i,v[]={405,85,405,95,395,90};
	char s[3];
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1);
	setfillstyle(1,LIGHTBLUE);
	settextstyle(2,0,7);
	for(i=0;i<daynum-16;i++)
	{
		itoa(i+17,s,10);
		bar(410,100+20*i,510,120+20*i);
		rectangle(410,100+20*i,510,120+20*i);
		outtextxy(450,98+20*i,s);
	}
	setfillstyle(1,MAGENTA);
	fillpoly(3,v);
}

void clr_day()
{
	int i;
	setcolor(LIGHTBLUE);
	setfillstyle(1,LIGHTBLUE);
	setlinestyle(0,0,1);
	for(i=0;i<16;i++)
	{
		bar(410,100+20*i,510,120+20*i);
	}
	bar(395,85,405,95);
	bar(515,85,525,95);
	setcolor(LIGHTCYAN);
	line(410,100,510,100);
}
