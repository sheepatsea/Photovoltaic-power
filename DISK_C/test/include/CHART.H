#ifndef _chart_h_
#define _chart_h_

void past_data(int plant_mode,struct DAYDATA *pdate_data);//功率图界面功能函数 

void wri_date(int plant_mode,struct DAYDATA *pdate_data);//在功率图中输入日期 

void chart_graph(int plant_mode);//画功率图坐标

void chart_line(int plant_mode,float *coord,struct DAYDATA *pdate_data);//画功率图曲线 

void chart_energy(int plant_mode,struct DAYDATA *pdate_data);//输出一天的发电量 

void chart_sign(int plant_mode,float *coord,int code,struct DAYDATA *pdate_data);//画出鼠标移到计数点时的标记 

void clr_sign(float *coord,int code);//鼠标移出计数点时清除标记 

void linechart(int plant_mode,float *coord,struct DAYDATA *pdate_data);//画各厂对应功率图 

#endif
