#ifndef _assign_h_
#define _assign_h_

void weekago_search(struct DAYDATA *pyesterday,struct DAYDATA *pweekago);//�ҳ�һ��ǰ�����ڣ��������� 

void threedayago_search(struct DAYDATA *pyesterday,struct DAYDATA *pdaysago);//�ҳ�����ǰ�����ڲ������� 
 
void monthago_search(struct DAYDATA *pyesterday,struct DAYDATA *pmonthago);//�ҳ�һ��ǰ������,�������� 

int orderjudge(struct DAYDATA *pdate_data,struct DAYDATA *pyesterday);//�ж�ǰһ�������Ƿ����ں�һ�����ڣ����򷵻�1

void search_data(struct DAYDATA *pdate_data);//���ݽṹ���������ڷ���ʣ������ 

void nextday(struct DAYDATA *plast,struct DAYDATA *pnext);//����ǰһ�����ݷ��غ�һ������

int judge_record(struct DAYDATA *pyesterday);//�ж��Ƿ��˼�¼�����ݵ�ʱ��

#endif
