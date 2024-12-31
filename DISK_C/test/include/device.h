#ifndef DEVICE_H_
#define DEVICE_H_

void init_device(void);   //光伏板及环境初始化 
void new_device(struct DATA,int mode,int menu_mode);  //光伏板图像更新 
void clear_device(struct DATA system,int mode,int menu_mode);  //删除旧光伏板图像
void end_device(void);
void get_device(struct DATA *,int mode);
#endif
