#ifndef _summary_h_
#define _summary_h_

void summary_init();//发电总结题目栏

void summary_chart(int plant_mode);//发电总结显示图 

void summary_graph(int plant_mode);//画发电总结显示图坐标

void summary_bar(struct DAYDATA *pyesterday,int plant_mode);//画发电总结显示图页面柱形图

#endif
