#ifndef realtime_h
#define realtime_h_

void realtime_show(); //��ʼ����̬���� 
void realtime(int daytime,int mode,int menu_mode,int plant_mode,struct DATA *psystem,struct DAYDATA date,struct SUNDATA *psunpower);//��̬�仯���������� 
void angle_change(struct DATA *,int,int mode);//�Ƕȱ仯��̫��Բ�ĺ͹�������ĵĻ�ȡ  
void dynamic_change(struct DATA,int ,int,int,struct SUNDATA *psunpower,int plant_mode,int menu_mode);//��̬�仯
void dynamic_clear(struct DATA,int ,int,int,struct SUNDATA *psunpower,int plant_mode,int menu_mode);
void left_house(void);
void right_house(void);

void system_show();
#endif
