#ifndef TRTIME_H_
#define TRTIME_H_


void draw_time(int *); //����ʱ�� 
void clear_time(void);  //���ʱ�� 
void transform_time(int daytime,int *pa);  //��daytimeת��Ϊ������ڴ�������ʾ 
void new_day(struct DAYDATA *,struct SUNDATA *);  //�µ�һ�쿪ʼ�� 
void day_case(struct DAYDATA);  //��ʾÿ��״�� 
void show_time(struct DAYDATA ,int daytime,int *pa);
#endif
