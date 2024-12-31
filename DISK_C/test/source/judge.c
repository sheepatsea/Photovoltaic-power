#include"public.h"
#include"main.h"
#include"judge.h"

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;

int find_date(int num)
{
	int meaningless_plant=1,meaningless_menu=1;
	int i;
	while(1)
	{
		func(2,&meaningless_plant,&meaningless_menu);
		newmouse(&MouseX,&MouseY,&press);
		if(inbutton(100,70,540,420)==0||(num<7&&MouseY>70+50*num))
		{
			return 7;
		}
		else
		{
			for(i=0;i<7;i++)
			{
				if(mouse_press(100,70+50*i,540,120+50*i)==1)
				{
					return i;
				}
			}
		}
	}
}

int find_year(int yearnum)
{
	int meaningless_plant=1,meaningless_menu=1;
	int i;
	while(1)
	{
		func(2,&meaningless_plant,&meaningless_menu);
		newmouse(&MouseX,&MouseY,&press);
		if(inbutton(130,100,230,100+20*yearnum)==0)
		{
			return (0);
		}
		else
		{
			for(i=0;i<=10;i++)
			{
				if(mouse_press(130,100+20*i,230,120+20*i)==1)
		        {
			        return (2022+i);
		        }
			}
		}
	}
}

int search_month(int year_j,struct DAYDATA *pyesterday)
{
	if(year_j<pyesterday->year)
	{
		return 12;
	}
	else 
	{
		return pyesterday->month;
	}
}

int search_day(int year_j,int month_j,struct DAYDATA *pyesterday)
{
 	if(month_j!=pyesterday->month||year_j!=pyesterday->year)
 	{
 		switch(month_j)
 		{
 			case 1:
 			case 3:
 			case 5:
 			case 7:
 			case 8:
 			case 10:
 			case 12:
 				return 31;
 			case 2:
 				if(year_j%400==0||(year_j%4==0&&year_j%100!=0))
 				{
 					return 29;
				}
				else
				{
					return 28;
				}
			case 4:
			case 6:
			case 9:
			case 11:
				return 30;
		}
	}
		return pyesterday->day;
}

int find_month(int monthnum)
{
	int meaningless_plant=1,meaningless_menu=1;
	int i; 
	while(1)
	{
		func(2,&meaningless_plant,&meaningless_menu);
		newmouse(&MouseX,&MouseY,&press);
		if(inbutton(270,100,370,100+20*monthnum)==0)
		{
			return 0;
		}
		else
		{
			for(i=0;i<12;i++)
			{
				if(mouse_press(270,100+20*i,370,120+20*i)==1)
		        {
			        return (1+i);
		        }
			}
		}
	}
} 

int find_day(int daynum)
{
	int i;
	int meaningless_plant=1,meaningless_menu=1;
	while(1)
	{
		func(2,&meaningless_plant,&meaningless_menu);
		newmouse(&MouseX,&MouseY,&press);
		if(inbutton(410,100,510,100+20*daynum)==0)
		{
			return 0;
		}
		else
		{
			for(i=0;i<16;i++)
			{
				if(mouse_press(410,100+20*i,510,120+20*i)==1)
			    {
				    return (i+1);
			    }
			}
		}
	}
}
