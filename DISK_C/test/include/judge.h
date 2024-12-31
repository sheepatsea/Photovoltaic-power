#ifndef _judge_h_
#define _judge_h_

int find_date(int num);//近一周与近一月页面判断点击的日期

int find_year(int yearnum);//日期定位页面判断选择的年份,系统规定只能运行到2033年之前

int search_month(int year_j,struct DAYDATA *pyesterday);//根据选择的年份判断这一年有哪几月的数据，默认第一年从1月开始 

int search_day(int year_j,int month_j,struct DAYDATA *pyesterday);//根据选择的年份和月份判断有哪些天，默认第一年从1月1号开始

int find_month(int monthnum);//日期定位页面判断选择的月份 

int find_day(int daynum);//日期定位页面判断选择的日期 

#endif
