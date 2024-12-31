#include"public.h"
#include"main.h"
#include"daysum.h"

float daysum_graph(int plant_mode);
void daysum_search(int month_j,int year_j,int plant_mode,float ratio,float *day_energy,float *coord);
int get_day(int year_j,int month_j);
void daysum(int month_j,int year_j,int plant_mode);
void daysum_chart(float *coord,int daynum);
void daysum_input(int year_j,int month_j);
void daysum_sign(int year_j,int month_j,int day_j,float *day_energy);
void daysum_clrsign();

float daysum_graph(int plant_mode)
{
	float ratio;//坐标缩减比例
	int i;
	char s[10];
	setcolor(WHITE);
	setlinestyle(0,0,1);
	line(60,60,60,440);
	line(60,440,600,440);
	line(60,60,55,65);
	line(60,60,65,65);
	line(600,440,595,435);
	line(600,440,595,445);
	for(i=0;i<10;i++)
	{
		line(60,80+36*i,68,80+36*i);
		line(60,98+36*i,63,98+36*i);
	}
	settextstyle(0,0,1);
	outtextxy(55,445,"0");
	outtextxy(48,50,"kw*h");
	switch(plant_mode)
	{
		case 0:
			ratio=0.09;
			for(i=0;i<10;i++)
	        {
		        itoa((i+1)*400,s,10);
	            outtextxy(60-strlen(s)*9,403-36*i,s);
	        }
			break;
		case 1:
			ratio=1.8;
			for(i=0;i<10;i++)
	        {
		        itoa((i+1)*20,s,10);
		        outtextxy(60-strlen(s)*9,403-36*i,s);
	        }
			break;
		case 2:
			ratio=1.2;
			for(i=0;i<10;i++)
			{
				itoa((i+1)*30,s,10);
				outtextxy(60-strlen(s)*9,403-36*i,s);
			}
			break;
		case 3:
			ratio=0.18;
			for(i=0;i<10;i++)
	        {
		        itoa((i+1)*200,s,10);
		        outtextxy(60-strlen(s)*9,403-36*i,s);
	        }
		    break;
	} 
	puthz(605,432,"日",16,16,WHITE);
	return ratio;
} 

void daysum_search(int month_j,int year_j,int plant_mode,float ratio,float *day_energy,float *coord)
{
	FILE *fp;
	char s[30],s0[10]="day\\",s1[10],s2[2]="_",s3[10],s4[3],s5[10]=".txt";
	int i,j;
	float medium[4];
	itoa(year_j+21,s1,10);
	itoa(month_j,s3,10);
	for(i=1;i<=get_day(year_j,month_j);i++)
	{
		itoa(i,s4,10);
		strcpy(s,s0);
		strcat(s,s1);
		strcat(s,s2);
		strcat(s,s3);
		strcat(s,s2);
		strcat(s,s4);
		strcat(s,s5);
		fp=fopen(s,"rt");
		for(j=0;j<4;j++)
		{
			fscanf(fp,"%f",&medium[j]);
		}
		fclose(fp);
		day_energy[i-1]=medium[plant_mode];
		coord[i-1]=440-ratio*day_energy[i-1];
	}
}

int get_day(int year_j,int month_j)
{
	year_j+=2021;
	switch(month_j)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 2:
			if(year_j%400==0||(year_j%4==0&&year_j%100!=0))
			{
				return 29;
			}
			else
			{
				return 28;
			}
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
	}
}

void daysum_chart(float *coord,int daynum)
{
	int i;
	setcolor(LIGHTGREEN);
	setlinestyle(0,0,1);
	setfillstyle(1,LIGHTGREEN);
	for(i=0;i<daynum;i++)
	{
		bar(72+17*i,coord[i],82+17*i,439);
	}
}

void daysum_input(int year_j,int month_j)
{
	char s1[5],s2[3];
	itoa(year_j+2021,s1,10);
	itoa(month_j,s2,10);
	settextstyle(2,0,8);
	setcolor(WHITE);
	outtextxy(20,3,s1);
	puthz(80,5,"年",24,24,WHITE);
	outtextxy(106,3,s2);
	puthz(106+10*strlen(s2),5,"月",24,24,WHITE);
} 

void daysum_sign(int year_j,int month_j,int day_j,float *day_energy)
{
	int i;
	char s[20],s1[5],s2[3],s3[3],s4[2]=".";
	setcolor(WHITE);
	itoa(year_j+2021,s1,10);
	itoa(month_j,s2,10);
	itoa(day_j,s3,10);
	strcpy(s,s1);
	strcat(s,s4);
	strcat(s,s2);
	strcat(s,s4);
	strcat(s,s3);
	settextstyle(2,0,7);
	puthz(250,10,"日期：",16,16,WHITE);
	outtextxy(298,6,s);
	puthz(250,30,"发电量：",16,16,WHITE);
	sprintf(s,"%.2f",day_energy[day_j-1]);
	outtextxy(314,26,s);
	outtextxy(314+12*strlen(s),26,"kw*h"); 
}

void daysum_clrsign()
{
	int i;
	setcolor(LIGHTBLUE);
	setfillstyle(1,LIGHTBLUE);
	bar(250,10,450,50);
}

void daysum(int month_j,int year_j,int plant_mode)
{
	int i;
	float ratio;
	float day_energy[31],coord[31];
	int daynum;//天数 
	int meaningless_plant=1,meaningless_menu=1;
	int code=0,flag;
	struct DAYDATA A;
	setbkcolor(LIGHTBLUE);
	ratio=daysum_graph(plant_mode);
	daysum_search(month_j,year_j,plant_mode,ratio,day_energy,coord);
	daynum=get_day(year_j,month_j);
	daysum_chart(coord,daynum);
	daysum_input(year_j,month_j);
	draw_back();
	while(1)
	{
		flag=0;
		newmouse(&MouseX,&MouseY,&press);
		func(5,&meaningless_plant,&meaningless_menu);
		for(i=0;i<daynum;i++)
		{
			if(inbutton(72+17*i,coord[i],82+17*i,439)==1&&code==0)
			{
				code=i+1;
				flag=1;
				break;
			}
		}
		if(code>0&&inbutton(72+17*(code-1),coord[code-1],82+17*(code-1),439)==1)
		{
			if(flag==1)
			{
				daysum_sign(year_j,month_j,code,day_energy);
			}
			if(mouse_press(72+17*(code-1),coord[code-1],82+17*(code-1),439)==1)
			{
				A.year=year_j+2021;
				A.month=month_j;
				A.day=code;
				search_data(&A);
				clrmous(MouseX,MouseY);
				cleardevice();
				past_data(plant_mode,&A);
				setbkcolor(LIGHTBLUE);
				daysum_graph(plant_mode);
				daysum_chart(coord,daynum);
	            daysum_input(year_j,month_j);
	            draw_back();
			}
		}
		else if(inbutton(560,10,630,40)==1)
		{
			MouseS=1;
			if(mouse_press(560,10,630,40)==1)
			{
				delay(400);
				newmouse(&MouseX,&MouseY,&press);
				clrmous(MouseX,MouseY);
				cleardevice();
				return;
			}
		}
		else
		{
			MouseS=0;
			if(code>0)
			{
				daysum_clrsign();
				code=0;
			}
		}
	}
}
