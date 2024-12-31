#ifndef _data_h_
#define _data_h_

void get_data(struct DAYDATA *pdate,struct SUNDATA *psunpower ); //获取一天的数据 
void dynamic_data(int ,struct DAYDATA *pdate,float *,struct SUNDATA *,int perrors[4]);  //动态数据生成 
void putin_data(struct DAYDATA date);  //存入功率 
void putin_last(struct DAYDATA date);  //更新last 
void putin_start(struct DAYDATA date);  //更新start 
void calculate_N(struct DAYDATA date,struct SUNDATA *psunpower);  //计算N值 
void putin_day(struct DAYDATA date);  //存入一天发电量 
#endif
