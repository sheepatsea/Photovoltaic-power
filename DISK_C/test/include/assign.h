#ifndef _assign_h_
#define _assign_h_

void weekago_search(struct DAYDATA *pyesterday,struct DAYDATA *pweekago);//找出一周前的日期，仅赋日期 

void threedayago_search(struct DAYDATA *pyesterday,struct DAYDATA *pdaysago);//找出三天前的日期并赋数据 
 
void monthago_search(struct DAYDATA *pyesterday,struct DAYDATA *pmonthago);//找出一月前的日期,仅赋日期 

int orderjudge(struct DAYDATA *pdate_data,struct DAYDATA *pyesterday);//判断前一个日期是否早于后一个日期，是则返回1

void search_data(struct DAYDATA *pdate_data);//根据结构中已有日期返回剩余数据 

void nextday(struct DAYDATA *plast,struct DAYDATA *pnext);//根据前一天数据返回后一天数据

int judge_record(struct DAYDATA *pyesterday);//判断是否到了记录月数据的时刻

#endif
