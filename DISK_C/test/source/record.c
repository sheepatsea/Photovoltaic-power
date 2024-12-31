#include"public.h"
#include"main.h"
#include"record.h"

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;

void record_data();
void add_data(struct DAYDATA *pyesterday);
void handle_data(int record_num,int *pyear_num,int *pmonth_left);
void read_data(int plant_mode,float (*month_energy)[12],float (*coord)[12],int record_num,int year_num,int month_left);
void draw_chart(float *month_energy,float *coord,int plant_mode,int year_num,int month_left);
void draw_kick1();
void clr_kick1();
void draw_kick2();
void clr_kick2();
void draw_back();
void record_chart(int plant_mode);
void draw_graph(int plant_mode);
void draw_bar(int month_num,int year_j,float *month_energy,float *coord);

void record_data()
{
	FILE *fp;
	struct DAYDATA yesterday;
	int medium;
	fp=fopen("C:\\test\\DATA\\last.txt","rt");
	fscanf(fp,"%d%d%d",&medium,&yesterday.month,&yesterday.day);
	fclose(fp);
	if(medium!=0)
	{
		yesterday.year=medium+2000;
		if(judge_record(&yesterday)==1)
	    {
		    add_data(&yesterday);
	    }
	}
} 

void handle_data(int record_num,int *pyear_num,int *pmonth_left)
{
	if(record_num%12==0)
	{
		*pyear_num=record_num/12;
		if(*pyear_num==0)
		{
			*pmonth_left=0;
		}
		else
		{
			*pmonth_left=12;
		}
	}
	else
	{
		*pyear_num=record_num/12+1;
		*pmonth_left=record_num%12;
	} 
}

void read_data(int plant_mode,float (*month_energy)[12],float coord[11][12],int record_num,int year_num,int month_left)
{
	int i,j,ratio;
	float p[4];//读取文件数据传递给month_energy 
	FILE *fp;
	char s[40],s0[20]="C:\\test\\month\\",s1[5],s2[2]="_",s3[3],s4[5]=".txt";//读取月发电量
	switch(plant_mode)
	{
		case 0:
			ratio=3;
			break;
		case 1:
			ratio=60;
			break;
		case 2:
			ratio=40;
			break;
		case 3:
			ratio=6;
			break;
	}
	for(i=0;year_num>i+1;i++)
	{
		itoa(22+i,s1,10);
		for(j=1;j<=12;j++)
		{
			itoa(j,s3,10);
			strcpy(s,s0);
			strcat(s,s1);
			strcat(s,s2);
			strcat(s,s3);
			strcat(s,s4);
			fp=fopen(s,"rt"); 
			fscanf(fp,"%f%f%f%f",&p[0],&p[1],&p[2],&p[3]);
			fclose(fp);
			month_energy[i][j-1]=p[plant_mode];
			coord[i][j-1]=440-ratio*month_energy[i][j-1];
		}
	}
	itoa(21+year_num,s1,10);
	for(j=1;j<=month_left;j++)
	{
		itoa(j,s3,10);
		strcpy(s,s0);
		strcat(s,s1);
		strcat(s,s2);
		strcat(s,s3);
		strcat(s,s4);
		fp=fopen(s,"rt"); 
		fscanf(fp,"%f%f%f%f",&p[0],&p[1],&p[2],&p[3]);
		fclose(fp);
		month_energy[year_num-1][j-1]=p[plant_mode];
		coord[year_num-1][j-1]=440-ratio*month_energy[year_num-1][j-1];
    }
} 

void record_chart(int plant_mode)
{
	FILE *fp;
	float month_energy[11][12],coord[11][12]; 
	int record_num,year_j=1,year_num,month_left;
	int meaningless_plant=1,meaningless_menu=1;
	int i,j;
	clrmous(MouseX,MouseY);
	cleardevice();
	fp=fopen("C:\\test\\DATA\\note.txt","rt");
	fscanf(fp,"%d",&record_num);//读取记录了几个月的发电量 
	fclose(fp);
	handle_data(record_num,&year_num,&month_left);
	read_data(plant_mode,month_energy,coord,record_num,year_num,month_left);
	draw_chart(month_energy[0],coord[0],plant_mode,year_num,month_left);
	while(1)
	{
		func(5,&meaningless_plant,&meaningless_menu);
		newmouse(&MouseX,&MouseY,&press);
		if(year_j<year_num)
		{
			for(i=0;i<12;i++)
			{
				if(inbutton(60+45*i,coord[year_j-1][i],85+45*i,439)==1)
				{
					MouseS=1;
					if(mouse_press(60+45*i,coord[year_j-1][i],85+45*i,439)==1)
					{
						delay(400);
						newmouse(&MouseX,&MouseY,&press);
						clrmous(MouseX,MouseY);
						cleardevice();
						daysum(i+1,year_j,plant_mode);
						draw_chart(month_energy[0],coord[0],plant_mode,year_num,month_left);
						year_j=1;
					}
				}
			}
		}
		else
		{
			for(i=0;i<month_left;i++)
			{
				if(inbutton(60+45*i,coord[year_j-1][i],85+45*i,439)==1)
				{
					MouseS=1;
					if(mouse_press(60+45*i,coord[year_j-1][i],85+45*i,439)==1)
					{
						delay(400);
						newmouse(&MouseX,&MouseY,&press);
						clrmous(MouseX,MouseY);
						cleardevice();
						daysum(i+1,year_j,plant_mode);
						draw_chart(month_energy[0],coord[0],plant_mode,year_num,month_left);
						year_j=1;
					}
				}
			}
		}
		if(inbutton(560,10,630,40)==1)
		{
			MouseS=1;
			if(mouse_press(560,10,630,40)==1)
			{
				return;
			}
		}
		else if(year_num>0&&year_num>year_j&&inbutton(615,45,625,55)==1)
		{
			MouseS=1;
			if(mouse_press(615,45,625,55)==1)
			{
				year_j++;
				clrmous(MouseX,MouseY);
				cleardevice();
				setbkcolor(LIGHTBLUE);
				draw_back();
                draw_graph(plant_mode);
                if(year_j==year_num)
                {
                	draw_bar(month_left,year_j,month_energy[year_j-1],coord[year_j-1]);
                	clr_kick2();
				}
				else
				{
					draw_bar(12,year_j,month_energy[year_j-1],coord[year_j-1]);
				}
				draw_kick1();
				delay(200);
			}
		}
		else if(year_num>0&&inbutton(565,45,575,55)==1&&year_j>1)
		{
			MouseS=1;
			if(mouse_press(565,45,575,55)==1)
			{
				year_j--;
				cleardevice();
				clrmous(MouseX,MouseY);
				setbkcolor(LIGHTBLUE);
				draw_back();
                draw_graph(plant_mode);
                draw_bar(12,year_j,month_energy[year_j-1],coord[year_j-1]);
                if(year_j==1)
                {
                	clr_kick1();
				}
				draw_kick2();
				delay(200);
			}
		}
		else
		{
			MouseS=0;
		}
	}
}

void draw_chart(float month_energy[12],float coord[12],int plant_mode,int year_num,int month_left)
{
	setbkcolor(LIGHTBLUE);
	draw_back();
	if(year_num==0)
	{
		puthz(140,221,"无发电总结",48,78,LIGHTCYAN);
	}
	else
	{
		draw_graph(plant_mode);
		if(year_num==1)
		{
			draw_bar(month_left,1,month_energy,coord);
		}
		else
		{
			draw_bar(12,1,month_energy,coord);
			draw_kick2();
		}
	}
} 

void draw_kick1()
{
	int v1[]={575,45,575,55,565,50};
	setfillstyle(1,RED);
	setcolor(RED);
	fillpoly(3,v1);
}

void clr_kick1()
{
	setfillstyle(1,LIGHTBLUE);
    setcolor(LIGHTBLUE);
    bar(565,45,575,55);
} 

void draw_kick2()
{
	int v2[]={615,45,615,55,625,50};
	setfillstyle(1,RED);
	setcolor(RED);
	fillpoly(3,v2);
}

void clr_kick2()
{
	setfillstyle(1,LIGHTBLUE);
    setcolor(LIGHTBLUE);
    bar(615,45,625,55);
} 

void draw_back()
{
	setfillstyle(1,CYAN);
	setlinestyle(0,0,1);
	setcolor(LIGHTCYAN);
	bar(560,10,630,40);
    rectangle(560,10,630,40);
    puthz(572,17,"返回",16,30,LIGHTCYAN);
}

void draw_graph(int plant_mode)
{
	int i;
	char s[10];
	setcolor(WHITE);
	setlinestyle(0,0,1);
	line(40,60,40,440);
	line(40,440,600,440);
	line(40,60,35,65);
	line(40,60,45,65);
	line(600,440,595,445);
	line(600,440,595,435);
	for(i=1;i<=12;i++)
	{
		line(40,440-30*i,48,440-30*i);
		line(40,455-30*i,43,455-30*i);
	}
	settextstyle(0,0,1);
	for(i=1;i<10;i++)
	{
		itoa(i,s,10);
		outtextxy(26+45*i,445,s);
	}
	for(i=10;i<=12;i++)
	{
		itoa(i,s,10);
		outtextxy(24+45*i,445,s);
	}
	puthz(605,432,"月",16,16,WHITE);
	outtextxy(35,445,"0");
	outtextxy(28,50,"mw*h");
	if(plant_mode==0)
	{
		for(i=1;i<=12;i++)
		{
			itoa(i*10,s,10);
			outtextxy(15,438-30*i,s);
		}
	}
	else if(plant_mode==1||plant_mode==2)
	{
		for(i=1;i<=12;i++)
		{
			sprintf(s,"%.1f",i*0.5);
			outtextxy(15,438-30*i,s);
		}
	}
	else
	{
		for(i=1;i<=12;i++)
		{
			itoa(i*5,s,10);
			outtextxy(20,438-30*i,s);
		}
	}
} 

void draw_bar(int month_num,int year_j,float month_energy[12],float coord[12])
{
	float E=0;//一年的总发电量 
	int i;
	char s[10];
	setfillstyle(1,LIGHTGREEN);
	setcolor(LIGHTGREEN);
	settextstyle(0,0,1);
	for(i=0;i<month_num;i++)
	{
		bar(60+45*i,439,85+45*i,coord[i]);
		sprintf(s,"%.2f",month_energy[i]);
		outtextxy(55+45*i,coord[i]-10,s);
	}
	itoa(year_j+2021,s,10);
	settextstyle(2,0,8);
	setcolor(WHITE);
	outtextxy(20,3,s);
	puthz(80,5,"年",24,24,WHITE);
	if(month_num==12)
	{
		puthz(150,5,"年发电量：",24,24,WHITE);
		for(i=0;i<12;i++)
		{
			E+=month_energy[i];
		}
		sprintf(s,"%.2f",E);
		settextstyle(2,0,7);
		outtextxy(270,5,s);
		outtextxy(270+15*strlen(s),5,"mw*h");
	}
}

void add_data(struct DAYDATA *pyesterday)
{
	FILE *fp;
	int i,j;
	float a[4]={0,0,0,0},b[4]={0,0,0,0};//a读取，b存储 
	char s[40],s0[20]="C:\\test\\day\\",s00[20]="C:\\test\\month\\",s1[5],s3[3],s2[2]="_",s4[3],s5[5]=".txt";
	itoa(pyesterday->year-2000,s1,10);
	itoa(pyesterday->month,s3,10);
	for(i=1;i<=pyesterday->day;i++)
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
		fscanf(fp,"%f%f%f%f",&a[0],&a[1],&a[2],&a[3]);
		fclose(fp);
   		for(j=0;j<4;j++)
   		{
   			b[j]+=a[j]/1000;
	    }
	}
	strcpy(s,s00);
	strcat(s,s1);
	strcat(s,s2);
	strcat(s,s3);
	strcat(s,s5);
	fp=fopen(s,"wt+");
	fprintf(fp,"%.4f  %.4f  %.4f  %.4f",b[0],b[1],b[2],b[3]);
	fclose(fp);
	fp=fopen("C:\\test\\DATA\\note.txt","rt+");
	fscanf(fp,"%d",&i);
	fclose(fp);
	fp=fopen("C:\\test\\DATA\\note.txt","rt+");
	fprintf(fp,"%d",i+1);
	fclose(fp);
} 
