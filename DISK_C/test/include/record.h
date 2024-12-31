#ifndef _record_h_
#define _record_h_  

void record_data();//�жϵ��³�ʱ��¼�����ܽ�����  

void add_data(struct DAYDATA *pyesterday);//��¼�������ܽắ�� 

void handle_data(int record_num,int *pyear_num,int *pmonth_left);//���ݼ�¼���·��������м�����·������Լ����һ���¼���˼��·� 

void read_data(int plant_mode,float (*month_energy)[12],float (*coord)[12],int record_num,int year_num,int month_left);//���ݼ�¼���·�������֪���·��������������� 

void draw_chart(float *month_energy,float *coord,int plant_mode,int year_num,int month_left);//���������ܽ�ͼ���ʼҳ�� 

void draw_kick1();//�����󰴼� 

void clr_kick1();//����󰴼�

void draw_kick2();//�����Ұ��� 

void clr_kick2();//����Ұ���

void draw_back();//�����շ��������淵�غ󣩻��·���������ķ��ؼ� 

void record_chart(int plant_mode);//�����ܽ�ͼ����湦��ͼ 

void draw_graph(int plant_mode);//�·���ҳ�滭���� 

void draw_bar(int month_num,int year_j,float *month_energy,float *coord);//�·���ҳ�滭��״ͼ 

#endif
