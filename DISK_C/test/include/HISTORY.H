#ifndef _history_h_
#define _history_h_

struct DAYDATA{
	int year;
	int month;
	int day;
	float plant[4][49];
	char file_name[4][50];
	int weekday;
	int weather_mode[4]; 
	float energy[4]; 
};

void history(int plant_mode);//历史数据全部功能，判断日期范围,判断选择的哪个厂历史数据 

void nondata();//没有历史数据时的功能函数 

int nonweek();//无历史数据时近一周界面功能函数 

int nonmonth();//无历史数据时近一月界面功能函数  

void history_data(int num,int plant_mode,struct DAYDATA *month_data,struct DAYDATA *week_data,struct DAYDATA *,struct DAYDATA *);//有历史数据时的功能函数 

int history_week(int num,int plant_mode,struct DAYDATA *week_dat);//有历史数据时近一周界面功能函数  

int history_month(int num,int plant_mode,struct DAYDATA *month_data);//有历史数据时近一月界面功能函数  

int history_search(int plant_mode,struct DAYDATA *pinitial,struct DAYDATA *pyesterday);//有历史数据时日期定位界面功能函数

#endif
