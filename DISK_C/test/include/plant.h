#ifndef plant_H_
#define plant_H_

void plant(int * plant_mode);  //վ������������ 
void plant_show(void);   //��ͼ 
void information(int );  //����վ������ʾ��Ӧ���� 
void clear_last();
void plant_init();
void pitch_on(int plant_mode);
void pitch_off(int plant_mode);
void switch_plant(int *plant_mode,struct ERRORS *perr,int *pweather_mode,int *pmenu_mode);
#endif
