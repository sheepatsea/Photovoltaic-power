#include"public.h"
#include"trtime.h"

extern struct DAYDATA{
	int year;
	int month;
	int day;
	float plant[4][49];
	char file_name[4][50];
	int weekday;
	int weather_mode[4]; 
    float energy[4]; 
};

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

void new_day(struct DAYDATA *pdate,struct SUNDATA *psunpower)
{
	FILE *fpdata,*fpstart;
	enum MONTH { Jan =1, Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec }month_0;
	char s_year[30],s_month[4],s_day[4];
	int i,cnt;
	pdate->year+=2000;
	pdate->day++;
	for(i=0;i<4;i++)
	{
		pdate->weather_mode[i]=weather_change();
	}

	switch(pdate->month)
	{
		case Jan:
		case Mar:
		case May:
		case Jul:
		case Aug:
		case Oct:
		case Dec: 
			if(pdate->day>31)
			{
				pdate->day=1;
				pdate->month++;
				if(pdate->month>Dec)
				{
					pdate->year++;
					pdate->month=Jan;
				}
			}
			break;
		case Feb:
		    if(((pdate->year%4==0)&&pdate->year%100!=0)||pdate->year%400==0)
			{
				if(pdate->day>29)
				{
					pdate->day=1;
				    pdate->month++;
				}
			 } 
			else
			{
				if(pdate->day>28)
				{
					pdate->day=1;
				    pdate->month++;
				}
			}
			 break;
		default:
			if(pdate->day>30)
			{
				pdate->day=1;
				pdate->month++;
			}
			break;
	 } 
	 pdate->year-=2000;
	pdate->weekday++;
	if(pdate->weekday>7)
	{
		pdate->weekday=1;
	}
	
	 	                                          //�õ��ļ��� 
	itoa(pdate->year,s_year,10);
	itoa(pdate->month,s_month,10);
	itoa(pdate->day,s_day,10);
	strcat(s_year,"_");
	strcat(s_year,s_month);
	strcat(s_year,"_");
	strcat(s_year,s_day);
	strcat(s_year,".txt");
	for(i=0;i<4;i++)
	{
		switch(i)
		{
		    case 0:
				strcpy(pdate->file_name[i],"plant1\\");
				break;
			case 1:
				strcpy(pdate->file_name[i],"plant2\\");
				break;
			case 2:
				strcpy(pdate->file_name[i],"plant3\\");
				break;
			default:
				strcpy(pdate->file_name[i],"plant4\\");
				break;
		}
	    strcat(pdate->file_name[i],s_year);
	}
	//****************
    get_data(pdate,psunpower);            //�õ����� ;
    putin_start(*pdate);
	                                            //������Ϣ��start��ʹ��һ�δ򿪳���ӽ��������ڿ�ʼ 
	
	
 } 
 
 void show_time(struct DAYDATA date ,int daytime,int *pa)
 {
 	clear_time();
	transform_time(daytime,pa);
	draw_time(pa);  //��ʾʱ�� 
	day_case(date);  //��ʾ���������� 
	  
 }
void transform_time( int daytime,int *pa)  //daytimeת��Ϊ����洢 
{
	int minute,hour;
	minute=daytime%60;
	pa[3]=minute%10;
	pa[2]=minute/10;
	hour=daytime/60;
	pa[1]=hour%10;
	pa[0]=hour/10;
}

void draw_time(int *a)  //ʱ����ʾ 
{
	int i; 
	char str[4][3];
	for(i=0;i<4;i++)
	  {
		 itoa(a[i],str[i],10);
	  }
	  strcat(str[0],str[1]);
	  strcat(str[0],":");
	  strcat(str[0],str[2]);
	  strcat(str[0],str[3]);
	  setcolor(LIGHTCYAN);
	  settextstyle(2,HORIZ_DIR,7);
	  outtextxy(10,5,str[0]);
	  
	
}

void clear_time()   //���ʱ�� 
{
	void *buffer;
	unsigned int s;
	s=imagesize(0,0,70,40);
	buffer=malloc(s);
	getimage(0,0,70,40,buffer);
	free(buffer);
	setcolor(CYAN);
    setlinestyle(0,0,THICK_WIDTH);
	setfillstyle(7,LIGHTBLUE);
	bar(0,0,70,30);
	rectangle(0,0,70,30);
}

void day_case(struct DAYDATA date)
{
    char str_year[20];
    char str_month[5];
    char str_day[5];
    date.year+=2000;
	itoa(date.year,str_year,10);
	date.year-=2000;
	itoa(date.month,str_month,10);
	itoa(date.day,str_day,10);
    strcat(str_year,".");
	strcat(str_year,str_month);
    strcat(str_year,".");
	strcat(str_year,str_day);
	setcolor(LIGHTCYAN);
	settextstyle(2,0,7);
	outtextxy(450,5,str_year);
	switch(date.weekday)
	{
	   case 1:
	        puthz(565,10,"����һ",16,16,LIGHTCYAN);	
	        break;
	   case 2:
	        puthz(565,10,"���ڶ�",16,16,LIGHTCYAN);	
	        break;
	   case 3:
	        puthz(565,10,"������",16,16,LIGHTCYAN);	
	        break;
	   case 4:
	        puthz(565,10,"������",16,16,LIGHTCYAN);	
	        break;
	   case 5:
	        puthz(565,10,"������",16,16,LIGHTCYAN);	
	        break;
	   case 6:
	        puthz(565,10,"������",16,16,LIGHTCYAN);	
	        break;
	   case 7:
	        puthz(565,10,"������",16,16,LIGHTCYAN);	
	        break;
	}		
}
