#ifndef DEVICE_H_
#define DEVICE_H_

void init_device(void);   //����弰������ʼ�� 
void new_device(struct DATA,int mode,int menu_mode);  //�����ͼ����� 
void clear_device(struct DATA system,int mode,int menu_mode);  //ɾ���ɹ����ͼ��
void end_device(void);
void get_device(struct DATA *,int mode);
#endif
