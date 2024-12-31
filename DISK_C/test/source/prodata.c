#include"public.h"
#include"main.h"
#include"prodata.h"

extern struct SUNDATA
{
    int N;  //����
    float Fai;  //γ�� 
    float Delta;  //��γ�� 
	float Omega_S;  //�ճ��� 
	float Gamma;  //̫��ϵ�� 
	float E_0;  //������� 
	float E_sb;   //ʵʱ���� 
	float h;  //�߶Ƚ� 
	float a;  //͸���� 
	float m;  //�������� 
	float Omega;
	float p;
};
void produce_data_show(struct SUNDATA *psunpower,float *dydata,int plant_mode)
{

	char Omega_show[4][10],h_show[4][10],m_show[4][10],E_sb_show[4][15],dydata_show[4][15];
	void *buffer;
	unsigned int s;
	s=imagesize(80,80,150,170);
	buffer=malloc(s);
	getimage(80,80,150,170,buffer);
	free(buffer);
	setcolor(CYAN);
    setlinestyle(0,0,THICK_WIDTH);
	setfillstyle(7,LIGHTBLUE);
	bar(80,70,150,170);
	setcolor(LIGHTCYAN);
	settextstyle(0,0,1);
	sprintf(Omega_show[plant_mode],"%.2f",psunpower[plant_mode].Omega);
	sprintf(h_show[plant_mode],"%.2f",psunpower[plant_mode].h);
	sprintf(m_show[plant_mode],"%.2f",psunpower[plant_mode].m);
	sprintf(E_sb_show[plant_mode],"%.f",psunpower[plant_mode].E_sb);
	strcat(E_sb_show[plant_mode],"W/M2");
	sprintf(dydata_show[plant_mode],"%.2f",dydata[plant_mode]);
	strcat(dydata_show[plant_mode],"KW");
   
    outtextxy(80,71,Omega_show[plant_mode]);
    outtextxy(80,94,h_show[plant_mode]);
    outtextxy(80,117,m_show[plant_mode]);
    outtextxy(80,140,E_sb_show[plant_mode]);
	outtextxy(80,163,dydata_show[plant_mode]);
}
void produce_data_init(void)
{
	setlinestyle(0,0,NORM_WIDTH);
    setcolor(LIGHTCYAN);
    setfillstyle(7,LIGHTBLUE);
    rectangle(5,40,155,180);  //��һ   �������� 
    line(5,60,115,60);
    line(115,60,155,40);
    settextstyle(2,0,4);
    setcolor(LIGHTCYAN); 
    puthz(10,42,"ʵʱ����",16,32,LIGHTCYAN);
    puthz(10,66,"̫����",16,16,LIGHTCYAN);
    puthz(10,89,"�߶Ƚ�",16,16,LIGHTCYAN);
    puthz(10,112,"��������",16,16,LIGHTCYAN);
    puthz(10,135,"̫������",16,16,LIGHTCYAN);
    puthz(10,158,"���繦��",16,16,LIGHTCYAN);
}
