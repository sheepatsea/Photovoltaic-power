#ifndef _daysum_h_
#define _daysum_h_

void daysum(int month_j,int year_j,int plant_mode);//�շ��������ܺ��� 

float daysum_graph(int plant_mode);//�շ�����ҳ������ͼ 

void daysum_search(int month_j,int year_j,int plant_mode,float ratio,float *day_energy,float *coord);//�õ������������������ 

int get_day(int year_j,int month_j);//��������·��ж���һ���ж����� 

void daysum_chart(float *coord,int daynum);//�շ���ҳ������ͼ 

void daysum_input(int year_j,int month_j);//�շ�������·�����

void daysum_sign(int year_j,int month_j,int day_j,float *day_energy);//���ѡ������� 

void daysum_clrsign();//�����ѡ�����ڵı�� 


#endif
