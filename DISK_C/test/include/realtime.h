#ifndef realtime_h
#define realtime_h_

void realtime_show(); //初始化动态界面 
void realtime(int daytime,int mode,int menu_mode,int plant_mode,struct DATA *psystem,struct DAYDATA date,struct SUNDATA *psunpower);//动态变化程序主函数 
void angle_change(struct DATA *,int,int mode);//角度变化及太阳圆心和光伏板中心的获取  
void dynamic_change(struct DATA,int ,int,int,struct SUNDATA *psunpower,int plant_mode,int menu_mode);//动态变化
void dynamic_clear(struct DATA,int ,int,int,struct SUNDATA *psunpower,int plant_mode,int menu_mode);
void left_house(void);
void right_house(void);

void system_show();
#endif
