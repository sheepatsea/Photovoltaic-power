#ifndef error_h_
#define error_h_

void error_monitor(int mode,int *errors,int daytime,struct DAYDATA date);  //���ϼ�⹦�� 
void error_engage(struct ERRORS *perr,int cnt,int daytime,struct DAYDATA date);  //���ϲ������� 
void error_show(struct ERRORS *perr);  //������Ϣ��ʾ 
void error_init();  //���ϱ���ʼ�� 
int error_list_new(struct ERRORS *perr);  //ÿ�տ�ʼɾ���Ѿ��ų��Ĺ��� 
void error_condition_new(struct ERRORS *perr,int error_number);  //������޺�ʼ���� 
void init_error_file(struct ERRORS *perr);  //�ļ���ʼ�� 
void error_file_read(struct ERRORS *perr);  //�ļ���ȡ 
void error_file_print(struct ERRORS *perr);  //�ļ�д�� 
void time_transfer(int year,int month,int day,int daytime,char *p_time);  //ʱ��ת�� 
void error();
void in_error_init();
void in_error_show(struct ERRORS *perr);
#endif
