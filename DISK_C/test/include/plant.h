#ifndef plant_H_
#define plant_H_

void plant(int * plant_mode);  //站点设置主功能 
void plant_show(void);   //绘图 
void information(int );  //根据站点编号显示相应数据 
void clear_last();
void plant_init();
void pitch_on(int plant_mode);
void pitch_off(int plant_mode);
void switch_plant(int *plant_mode,struct ERRORS *perr,int *pweather_mode,int *pmenu_mode);
#endif
