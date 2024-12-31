#ifndef _daysum_h_
#define _daysum_h_

void daysum(int month_j,int year_j,int plant_mode);//日发电量功能函数 

float daysum_graph(int plant_mode);//日发电量页面坐标图 

void daysum_search(int month_j,int year_j,int plant_mode,float ratio,float *day_energy,float *coord);//得到发电数组和坐标数组 

int get_day(int year_j,int month_j);//根据年份月份判断这一月有多少天 

void daysum_chart(float *coord,int daynum);//日发电页面折线图 

void daysum_input(int year_j,int month_j);//日发电年份月份输入

void daysum_sign(int year_j,int month_j,int day_j,float *day_energy);//标记选择的日期 

void daysum_clrsign();//清除对选择日期的标记 


#endif
