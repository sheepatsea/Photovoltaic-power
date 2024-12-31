#ifndef _calendar_h_
#define _calendar_h_

void draw_nonweek();//无历史数据时近一周画面 

void draw_nonmonth();//无历史数据时近一月画面 

void draw_week(int plant_mode,int weekday_num,struct DAYDATA *week_data);//有历史数据时近一周画面 

void draw_button1();//画出调月页面的左按键 

void clr_button1();//清除调月页面的左按键 

void draw_button2();//画出调月页面的右按键 

void clr_button2();//清除调月页面的右按键 

void draw_month(int plant_mode,int num,struct DAYDATA *month_data);//有历史数据时近一月画面 

void draw_search(struct DAYDATA *,struct DAYDATA *);//日期定位初始画面 

void input_date(int plant_mode,struct DAYDATA date_data,int i);//在日历页面输入日期信息及画线 

void input_year(struct DAYDATA *pinitial,struct DAYDATA *pyesterday);//在搜索界面列出年份 

void line_year(int year_j);//标出选定的年份 

void clr_year(struct DAYDATA *pinitial,struct DAYDATA *pyesterday);//清除年份列表 

void input_month(int monthnum);//在搜索界面列出月份 

void line_month(int month_j);//标出选中的月份 

void clr_month(int monthnum);//清除月份列表

void input_day(int);// 在搜索界面列出第一面日期 

void input_daypage2(int);//在搜索界面列出第2面日期 

void clr_day();//清除日期列表 

#endif
