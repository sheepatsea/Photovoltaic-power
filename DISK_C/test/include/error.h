#ifndef error_h_
#define error_h_

void error_monitor(int mode,int *errors,int daytime,struct DAYDATA date);  //故障检测功能 
void error_engage(struct ERRORS *perr,int cnt,int daytime,struct DAYDATA date);  //故障参数产生 
void error_show(struct ERRORS *perr);  //故障信息显示 
void error_init();  //故障表格初始化 
int error_list_new(struct ERRORS *perr);  //每日开始删除已经排除的故障 
void error_condition_new(struct ERRORS *perr,int error_number);  //点击待修后开始处理 
void init_error_file(struct ERRORS *perr);  //文件初始化 
void error_file_read(struct ERRORS *perr);  //文件读取 
void error_file_print(struct ERRORS *perr);  //文件写入 
void time_transfer(int year,int month,int day,int daytime,char *p_time);  //时间转换 
void error();
void in_error_init();
void in_error_show(struct ERRORS *perr);
#endif
