#ifndef TRTIME_H_
#define TRTIME_H_


void draw_time(int *); //画出时间 
void clear_time(void);  //清除时间 
void transform_time(int daytime,int *pa);  //将daytime转化为数组便于储存与显示 
void new_day(struct DAYDATA *,struct SUNDATA *);  //新的一天开始了 
void day_case(struct DAYDATA);  //显示每日状况 
void show_time(struct DAYDATA ,int daytime,int *pa);
#endif
