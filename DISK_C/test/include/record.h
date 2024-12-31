#ifndef _record_h_
#define _record_h_  

void record_data();//判断到月初时记录上月总结数据  

void add_data(struct DAYDATA *pyesterday);//记录月数据总结函数 

void handle_data(int record_num,int *pyear_num,int *pmonth_left);//根据记录的月份数计算有几年的月发电量以及最后一年记录到了几月份 

void read_data(int plant_mode,float (*month_energy)[12],float (*coord)[12],int record_num,int year_num,int month_left);//根据记录的月份数将已知的月发电量传进数组中 

void draw_chart(float *month_energy,float *coord,int plant_mode,int year_num,int month_left);//画月数据总结图表初始页面 

void draw_kick1();//画出左按键 

void clr_kick1();//清除左按键

void draw_kick2();//画出右按键 

void clr_kick2();//清除右按键

void draw_back();//（从日发电量界面返回后）画月发电量界面的返回键 

void record_chart(int plant_mode);//数据总结图表界面功能图 

void draw_graph(int plant_mode);//月发电页面画坐标 

void draw_bar(int month_num,int year_j,float *month_energy,float *coord);//月发电页面画柱状图 

#endif
