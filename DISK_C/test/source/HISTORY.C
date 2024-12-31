#include"public.h"
#include"main.h"

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;
int mouse_press(int x1, int y1, int x2, int y2);

void history(int plant_mode)
{
	int medium,j;
	int num=100;
    struct DAYDATA INITIAL,yesterday,weekago,monthago,week_data[7],month_data[32];//进入页面之前给周数据月数据赋信息 
    FILE *fp;
    fp=fopen("C:\\test\\DATA\\initial.txt","rt");
	fscanf(fp,"%d%d%d",&INITIAL.year,&INITIAL.month,&INITIAL.day);
	fclose(fp);
    fp=fopen("C:\\test\\DATA\\last.txt","rt");
    fscanf(fp,"%d%d%d",&medium,&yesterday.month,&yesterday.day);
    fclose(fp);
    if(medium==0)
    {
    	nondata(); 
    	clrmous(MouseX,MouseY);
    	cleardevice();
    	return;
	}
	else
	{
		yesterday.year=medium+2000;
		search_data(&INITIAL);
		search_data(&yesterday);
		weekago_search(&yesterday,&weekago);
		monthago_search(&yesterday,&monthago);
		if(orderjudge(&INITIAL,&weekago)==1)
		{
			search_data(&weekago);
			week_data[0]=weekago;
			for(j=0;j<6;j++)
			{
				nextday(&week_data[j],&week_data[j+1]);
			}
		}
		else
		{
			week_data[0]=INITIAL;
			for(j=0;orderjudge(&week_data[j],&yesterday)==1;j++)
			{
				nextday(&week_data[j],&week_data[j+1]);
			}
			num=j+1;//num是week_data[]数组中实际的结构数量
		}
		if(num<8)
		{
			for(j=0;j<num;j++)
			{
				month_data[j]=week_data[j];
			}
		}
		else
		{
			if(orderjudge(&INITIAL,&monthago)==1)
			{
				search_data(&monthago);
				month_data[0]=monthago;
			}  
			else
			{
				month_data[0]=INITIAL;
			}
			for(j=0;orderjudge(&month_data[j],&yesterday)==1;j++)
			{
				nextday(&month_data[j],&month_data[j+1]);
			}
			num=1+j;//num是月页面天数 
		}
		history_data(num,plant_mode,month_data,week_data,&INITIAL,&yesterday);
		clrmous(MouseX,MouseY);
		cleardevice();
		return;
	}
}

void nondata()
{
	int switch_code=1;
	while(1)
	{
		switch(switch_code)
		{
			case 1:
				switch_code=nonweek();
			    break;
			case 2:
				switch_code=nonmonth();
				break; 
			case 4:
				return; 
		}
	}
}

int nonweek()
{
	int meaningless_plant=1,meaningless_menu=1;
	clrmous(MouseX,MouseY);
	cleardevice();
	draw_nonweek();
	while(1)
	{
		func(2,&meaningless_plant,&meaningless_menu);
		newmouse(&MouseX,&MouseY,&press);
		if(inbutton(560,430,630,460)==1)
		{
			MouseS=1;
			if(mouse_press(560,430,630,460)==1)
			{
				return 4;
			}
		}
		else if(inbutton(275,12,365,52)==1) 
		{
			MouseS=1;
			if(mouse_press(275,12,365,52)==1)
			{
				return 2;
			}
		}
		else if(inbutton(491,12,609,52)==1)
		{
			MouseS=1;
			if(mouse_press(491,12,609,52)==1)
			{
				MouseS=0;
				puthz(272,53,"暂无历史数据",16,16,LIGHTCYAN);
				delay(200);
			    setcolor(LIGHTBLUE);
			    setfillstyle(7,LIGHTBLUE);
			    bar(272,53,368,69);
			}
		}
		else
		{
			MouseS=0;
		}
	}
} 

int nonmonth()
{
	int meaningless_plant=1,meaningless_menu=1;
	clrmous(MouseX,MouseY);
	cleardevice();
	draw_nonmonth();
	while(1)
	{
	    func(2,&meaningless_plant,&meaningless_menu);
		newmouse(&MouseX,&MouseY,&press);
		if(inbutton(560,430,630,460)==1)
		{
			MouseS=1;
			if(mouse_press(560,430,630,460)==1)
			{
				return 4;
			}
		}
		else if(inbutton(45,12,135,52)==1) 
		{
			MouseS=1;
			if(mouse_press(45,12,135,52)==1)
			{
				return 1;
			}
		}
		else if(inbutton(491,12,609,52)==1)
		{
			MouseS=1;
			if(mouse_press(491,12,609,52)==1)
			{
				MouseS=0;
				puthz(272,53,"暂无历史数据",16,16,LIGHTCYAN);
				delay(200);
			    setcolor(LIGHTBLUE);
			    setfillstyle(7,LIGHTBLUE);
			    bar(272,53,368,69);
			}
		}
		else
		{
			MouseS=0;
		}
	}
} 

void history_data(int num,int plant_mode,struct DAYDATA *month_data,struct DAYDATA *week_data,struct DAYDATA *pinitial,struct DAYDATA *pyesterday)
{
	int switch_code=1;
	while(1)
	{
		switch(switch_code)
		{
			case 1:
				switch_code=history_week(num,plant_mode,week_data);
				break;
			case 2:
				switch_code=history_month(num,plant_mode,month_data);
				break;
			case 3:
				switch_code=history_search(plant_mode,pinitial,pyesterday);
				break; 
			case 4:
				return;
		}
	}
} 

int history_week(int num,int plant_mode,struct DAYDATA *week_data)
{
	int num_j,weekday_num;//根据点击的日期返回选择日期结构体的下标 
	int meaningless_plant=1,meaningless_menu=1;
	clrmous(MouseX,MouseY);
	cleardevice();
	if(num>7)
	{
		weekday_num=7;
	}
	else
	{
		weekday_num=num;
	}
	draw_week(plant_mode,weekday_num,week_data);
	while(1)
	{
		func(2,&meaningless_plant,&meaningless_menu);
		newmouse(&MouseX,&MouseY,&press);
		if(inbutton(560,430,630,460)==1)
		{
			MouseS=1;
			if(mouse_press(560,430,630,460)==1)
			{
				return 4;
			}
		}
		else if(inbutton(275,12,365,52)==1) 
		{
			MouseS=1;
			if(mouse_press(275,12,365,52)==1)
			{
				return 2;
			}
		}
		else if(inbutton(491,12,609,52)==1)
		{
			MouseS=1;
			if(mouse_press(491,12,609,52)==1)
			{
				return 3;
			}
		}
		else if(inbutton(100,70,540,70+50*weekday_num)==1)
		{
			MouseS=1;
			num_j=find_date(weekday_num);
			if(num_j<7)
			{
				clrmous(MouseX,MouseY);
				cleardevice();
				past_data(plant_mode,&week_data[num_j]);
				draw_week(plant_mode,weekday_num,week_data);
				delay(200);
			}
		}
		else
		{
			MouseS=0;
		}
	}
} 

int history_month(int num,int plant_mode,struct DAYDATA *month_data)
{
	int i,page=1,pagenum,num_left;
	int meaningless_plant=1,meaningless_menu=1;
	clrmous(MouseX,MouseY);
	cleardevice();
	draw_month(plant_mode,num,month_data);
	if(num%7==0)
	{
		pagenum=num/7;
		num_left=7;//num_left是最后一页的天数 
	}
	else
	{
		pagenum=num/7+1;
		num_left=num%7; 
	}
	while(1)
	{
		func(2,&meaningless_plant,&meaningless_menu);
		newmouse(&MouseX,&MouseY,&press);
		if(inbutton(560,430,630,460)==1)
		{
			MouseS=1;
			if(mouse_press(560,430,630,460)==1)
			{
				return 4;
			}
		}
		else if(inbutton(45,12,135,52)==1) 
		{
			MouseS=1;
			if(mouse_press(45,12,135,52)==1)
			{
				return 1;
			}
		}
		else if(inbutton(491,12,609,52)==1)
		{
			MouseS=1;
			if(mouse_press(491,12,609,52)==1)
			{
				return 3;
			}
		}
		else if(inbutton(579,235,597,255)==1)
		{
			if(page<pagenum)
			{
				MouseS=1;
				if(mouse_press(579,235,597,255)==1)
				{
					page++;
					clrmous(MouseX,MouseY);
					setfillstyle(1,CYAN);
					bar(100,70,540,420);
					if(page==pagenum)
					{
						for(i=0;i<num_left;i++)
						{
							input_date(plant_mode,month_data[(pagenum-1)*7+i],i);
						}
					    clr_button2();
					}
					else
					{
						for(i=0;i<7;i++)
						{
							input_date(plant_mode,month_data[(page-1)*7+i],i);
						}
					}
					setcolor(LIGHTCYAN);
					rectangle(100,70,540,420);
					draw_button1();
					delay(200);
					if(page==pagenum)
					{
						MouseS=0;
					}
				}
			}
		}
		else if(inbutton(43,235,61,255)==1)
		{
			if(page>1)
			{
				MouseS=1;
				if(mouse_press(43,235,61,255)==1)
				{
					page--;
					clrmous(MouseX,MouseY);
					setfillstyle(1,CYAN);
				    bar(100,70,540,420);
					for(i=0;i<7;i++)
					{
						input_date(plant_mode,month_data[(page-1)*7+i],i);
					}
					setcolor(LIGHTCYAN);
					rectangle(100,70,540,420);
					if(page==1)
					{
						clr_button1();
					}
					draw_button2();
					delay(200);
					if(page==1)
					{
						MouseS=0;
					}
				}
			}
		}
		else if(inbutton(100,70,540,420)==1&&(page<pagenum||MouseY<(70+50*num_left)))
		{
			MouseS=1;
			i=find_date(num-(page-1)*7);
			if(i<7)
			{
				clrmous(MouseX,MouseY);
				cleardevice();
				past_data(plant_mode,&month_data[(page-1)*7+i]);
				draw_month(plant_mode,num,month_data);
				page=1;
				delay(200);
			}
		}
		else
		{
			MouseS=0;
		}
	}
} 

int history_search(int plant_mode,struct DAYDATA *pinitial,struct DAYDATA *pyesterday)
{
	int medium;
	int meaningless_plant=1,meaningless_menu=1;
	struct DAYDATA searchdate;
	int year_j=0,month_j=0,day_j=0;
	int monthnum=0,yearnum,daynum=0,daypage=1;
	yearnum=pyesterday->year-pinitial->year+1;//年份数 
	clrmous(MouseX,MouseY);
	cleardevice();
	draw_search(pinitial,pyesterday);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		func(2,&meaningless_plant,&meaningless_menu);
		if(inbutton(560,430,630,460)==1)
		{
			MouseS=1;
			if(mouse_press(560,430,630,460)==1)
			{
				return 4;
			}
		}
		else if(inbutton(45,12,135,52)==1)
		{
			MouseS=1;
			if(mouse_press(45,12,135,52)==1)
			{
				return 1;
			}
		}
		else if(inbutton(275,12,365,52)==1)
		{
			MouseS=1;
			if(mouse_press(275,12,365,52)==1)
			{
				return 2;
			}
		}
		else if(inbutton(130,100,230,100+20*yearnum)==1)
		{
				MouseS=1;
				medium=find_year(yearnum);
				if(medium>0)
				{
					daypage=1;
					clrmous(MouseX,MouseY);
					clr_year(pinitial,pyesterday);
					clr_month(monthnum);
					clr_day();
					year_j=medium;
					input_year(pinitial,pyesterday); 
					line_year(year_j);
					monthnum=search_month(year_j,pyesterday);
					daynum=day_j=month_j=0;
					input_month(monthnum);
				}
		}
		else if(inbutton(270,100,370,100+20*monthnum)==1)
		{
		    MouseS=1;
		    medium=find_month(monthnum);
			if(medium>0)
			{
				daypage=1;
				clrmous(MouseX,MouseY);
				clr_month(monthnum);
				clr_day();
				month_j=medium;
			    input_month(monthnum);
			    line_month(month_j);
				daynum=search_day(year_j,month_j,pyesterday);
				input_day(daynum);
				day_j=0; 
			}
		    
		}
		else if(inbutton(410,100,510,420)==1&&daypage==1&&daynum>16)
		{
			MouseS=1;
			medium=find_day(16);
			if(medium>0)
			{
				day_j=medium;
				searchdate.year=year_j;
				searchdate.month=month_j;
				searchdate.day=day_j;
				search_data(&searchdate);
				clrmous(MouseX,MouseY);
				cleardevice();
				past_data(plant_mode,&searchdate);
				draw_search(pinitial,pyesterday); 
			    line_year(year_j);
				input_month(monthnum);
				line_month(month_j);
				input_day(daynum);
				delay(200);
			}
		}
		else if(inbutton(410,100,510,100+20*daynum)==1&&daypage==1&&daynum<=16)
		{
			MouseS=1;
			medium=find_day(daynum);
			if(medium>0)
			{
				day_j=medium;
				searchdate.year=year_j;
				searchdate.month=month_j;
				searchdate.day=day_j;
				search_data(&searchdate);
				clrmous(MouseX,MouseY);
				cleardevice();
				past_data(plant_mode,&searchdate);
				draw_search(pinitial,pyesterday); 
			    line_year(year_j);
				input_month(monthnum);
				line_month(month_j);
				input_day(daynum);
				delay(200);
			}
		}
		else if(daypage==2&&inbutton(410,100,510,100+20*(daynum-16))==1)
		{
			MouseS=1;
			medium=find_day(daynum-16);
			if(medium>0)
			{
				day_j=medium+16;
				searchdate.year=year_j;
				searchdate.month=month_j;
				searchdate.day=day_j;
				search_data(&searchdate);
				clrmous(MouseX,MouseY);
				cleardevice();
				past_data(plant_mode,&searchdate);
				draw_search(pinitial,pyesterday); 
			    line_year(year_j);
				input_month(monthnum);
				line_month(month_j);
				input_daypage2(daynum);
				delay(200);
			}
		}
		else if(inbutton(515,85,525,95)==1&&daypage==1&&daynum>16)
		{
			MouseS=1;
			if(mouse_press(515,85,525,95)==1)
			{
				daypage=2;
				clrmous(MouseX,MouseY);
				clr_day();
				input_daypage2(daynum);
				MouseS=0;
			}
		}
		else if(inbutton(395,85,405,95)==1&&daypage==2)
		{
			MouseS=1;
			if(mouse_press(395,85,405,95)==1)
			{
				daypage=1;
				clrmous(MouseX,MouseY);
				clr_day();
				input_day(daynum);
				MouseS=0;
			}
		}
		else
		{
			MouseS=0;
		}
	}
} 
