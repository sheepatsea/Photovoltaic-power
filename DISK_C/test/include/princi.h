#ifndef princi_h_
#define princi_h_

void principle();  //ԭ������ 
void principle_show();  //ҳ���ʼ�� 
void chemical_principle(struct SUNDATA *psunpower,int mode,int plant_mode);  //��ѧԭ�� 
void chemical_clear(int x[4][2],int plant_mode);  //��̬��� 
void chemical_change(struct SUNDATA *psunpower,int x[4][2]);  //�����仯 
void chemical_new(int x[4][2],int plant_mode);  //��̬���� 
void draw_positive(int x,int y);  //������Ѩ 
void clean_positive(int x,int y);  //�����Ѩ 
void draw_negtive(int x,int y);  //�������� 
void clean_negtive(int x,int y);  //������� 
void draw_positive_arrow(int x,int y);  //������Ѩ�����ͷ 
void draw_negtive_arrow(int x,int y);  //�������ӷ����ͷ 
void draw_light(int x,int y);  //�������� 

#endif
