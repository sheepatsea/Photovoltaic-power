#ifndef _judge_h_
#define _judge_h_

int find_date(int num);//��һ�����һ��ҳ���жϵ��������

int find_year(int yearnum);//���ڶ�λҳ���ж�ѡ������,ϵͳ�涨ֻ�����е�2033��֮ǰ

int search_month(int year_j,struct DAYDATA *pyesterday);//����ѡ�������ж���һ�����ļ��µ����ݣ�Ĭ�ϵ�һ���1�¿�ʼ 

int search_day(int year_j,int month_j,struct DAYDATA *pyesterday);//����ѡ�����ݺ��·��ж�����Щ�죬Ĭ�ϵ�һ���1��1�ſ�ʼ

int find_month(int monthnum);//���ڶ�λҳ���ж�ѡ����·� 

int find_day(int daynum);//���ڶ�λҳ���ж�ѡ������� 

#endif
