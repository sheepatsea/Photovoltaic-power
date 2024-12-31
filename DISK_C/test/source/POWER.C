#include"public.h"
#include"main.h"
#include"power.h"

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;

void init_transform()//能量转换初始界面
{
	float i;
	int v[]={188,130,230,130,242,220,176,220};//光伏板 
	int w[]={302,238,302,310,344,310,356,292,356,220,314,220};//逆变器 
	int m[]={302,136,350,136,356,154,359,184,293,184,296,154};//控制器 
	int n[]={218,292,230,292,230,310,242,322,206,322,218,310};//风扇柄 
	setfillstyle(1,LIGHTBLUE);
	setcolor(LIGHTCYAN);
	bar(158,40,483,328);
	rectangle(158,40,483,328);
	setcolor(DARKGRAY);
	setlinestyle(0,0,1);
	setfillstyle(1,LIGHTGRAY);
	fillpoly(4,v);
	line(185.6,148,232.4,148);
	line(183.2,166,234.8,166);
	line(180.8,184,237.2,184);
	line(178.4,202,239.6,202);
	line(201.8,130,197.6,220);
	line(216.2,130,220.4,220);
	setcolor(WHITE);
	setfillstyle(1,RED);
	fillpoly(6,m);
	line(350,136,353,178); 
	line(353,178,359,184);
	line(353,178,299,178);
	line(299,178,293,184);
	line(299,178,302,136);
	setfillstyle(1,LIGHTBLUE);
	bar(317,145,335,160);
	setfillstyle(1,DARKGRAY);
	for(i=308;i<350;i+=7.2)
	{
		fillellipse(i,172,2.4,2.4);
	}
	setfillstyle(1,LIGHTMAGENTA);
	fillpoly(6,w);
	line(302,238,344,238);
	line(344,238,356,220);
	line(344,238,344,310);
	setcolor(LIGHTGRAY);
	setfillstyle(1,DARKGRAY);
	bar(314,250,332,274); 
	setfillstyle(1,LIGHTBLUE);
	bar(315.8,253,329.6,262);
	setfillstyle(1,LIGHTGRAY);
	fillellipse(317.6,270.4,1.8,1.8);
	fillellipse(328.4,270.4,1.8,1.8);
	setlinestyle(0,0,3);
	setcolor(WHITE);
	circle(224,268,24);
	setfillstyle(1,GREEN);
	setcolor(WHITE);
	for(i=60;i<310;i+=120)
	{
		pieslice(224,268,i,i+60,21);
	}
	setfillstyle(1,WHITE);
	fillellipse(224,268,6,6);
	setfillstyle(1,GREEN);
	fillpoly(6,n);
	setfillstyle(1,MAGENTA);
	bar(390.8,70,450.8,112); 
	setfillstyle(1,RED);
	bar(400.4,88,410,112);
	setfillstyle(1,BLUE);
	bar(431.6,88,441.2,112);
	setcolor(WHITE);
	setlinestyle(0,0,1);
	setfillstyle(1,WHITE);
	fillellipse(405.2,88,6,6);
	fillellipse(436.4,88,6,6);
	setcolor(LIGHTGRAY);
	setfillstyle(1,LIGHTGRAY);
	fillellipse(405.2,88,3,3);
	fillellipse(436.4,88,3,3);
	setfillstyle(1,WHITE);
	fillellipse(399.2,76,3,3);
	fillellipse(442.4,76,3,3);
	setcolor(DARKGRAY);
	settextstyle(2,0,4);
	outtextxy(397.4,70,"+");
	outtextxy(440.6,70,"-");
	setfillstyle(1,DARKGRAY);
	bar(392,240,465,288);
	setfillstyle(1,LIGHTGRAY);
	bar(425,289,431,294);
	bar(410,294,446,297);
	setfillstyle(1,LIGHTGREEN);
	bar(232,60,378,112);
	setlinestyle(0,0,3);
	setcolor(YELLOW);
	line(238,74,286,74);
	line(262,74,259,71);
	line(262,74,259,77);
	setcolor(LIGHTGRAY);
	line(238,98,286,98);
	line(262,98,259,95);
	line(262,98,259,101);
	line(237,175,293,175);//电池板发电线 
	line(326,185,326,219.4);//逆变器供电线 
	line(232,301,301,301);//交流负载供电线 
	line(359,175,427,175);
	line(427,175,427,239);//直流负载供电线 
	line(357,155,420,155);
	line(420,155,420,113.5);//蓄电池充电线 
	setcolor(LIGHTCYAN);
	settextstyle(2,0,4);
	outtextxy(302,310,"inverter");
	outtextxy(407,300,"dc load");
	outtextxy(174,300,"ac load");
	outtextxy(179,220,"solar panel");
	outtextxy(300,122,"controller"); 
	outtextxy(396,55,"batteries");
	setcolor(LIGHTBLUE);
	outtextxy(295,67,"light energy");
	outtextxy(289,91,"electric energy");
}

void output(int x)//蓄电池放电箭头绘制 
{
	int i=x%95,j=x%95-38;
	setcolor(LIGHTGRAY);
	setlinestyle(0,0,3);
	if(i<38)
	{
		line(420,118+i,417,115+i);
		line(420,118+i,423,115+i);
	}
	else
	{
		line(415-j,155,418-j,152);
		line(415-j,155,418-j,158);
	}
}

void input(int x)//蓄电池充电箭头绘制 
{
	int i=x%93,j=x%93-57;
	setcolor(LIGHTGRAY);
	setlinestyle(0,0,3);
	if(i<57)
	{
		line(362+i,155,359+i,152);
		line(362+i,155,359+i,158);
	}
	else
	{
		line(420,150-j,417,153-j);
		line(420,150-j,423,153-j);
	}
}

void absorb(int x)//阳光吸收箭头绘制 
{
	setcolor(YELLOW);
	setlinestyle(0,0,3);
	line(209,60,209,128);
	line(209,65+x%63,206,62+x%63);
	line(209,65+x%63,212,62+x%63);
}

void produce(int x)//电池板发电箭头绘制 
{
	setcolor(LIGHTGRAY);
	setlinestyle(0,0,3);
	line(242+x%50,175,239+x%50,172);
	line(242+x%50,175,239+x%50,178);
}

void work(int x)//供电箭头绘制 
{
	int i=x%121,j=x%121-64;
	setcolor(LIGHTGRAY);
	setlinestyle(0,0,3);
	line(326,190+x%28,323,187+x%28);
	line(326,190+x%28,329,187+x%28);
	line(296-x%63,301,299-x%63,298);
	line(296-x%63,301,299-x%63,304);
	if(i<64)
	{
		line(364+i,175,361+i,172);
	    line(364+i,175,361+i,178);
	}
	else
	{
		line(427,180+j,424,177+j);
		line(427,180+j,430,177+j);
	}
}

void clr_arrow()//清除所有箭头 
{
	setcolor(LIGHTBLUE);
	setlinestyle(0,0,3);
    line(239,172,291,172);
    line(239,178,291,178);//电池板供电线 
    line(323,186,323,217);
    line(329,186,329,217);//逆变器输电线 
    line(234,298,299,298);
    line(234,304,299,304);//交流负载供电线 
    line(361,172,427,172);
    line(361,178,425,178);
	line(424,177,424,237);
	line(430,176,430,237);//直流负载供电线 
	line(359,152,418,152);
	line(359,158,418,158);
	line(423,154,423,114);
	line(417,153,417,114);//蓄电池输电线 
	line(206,60,206,128);
	line(212,60,212,128);
}

void transform(int mode,int menu_mode,int plant_mode,float *a,int daytime)
{
	static int x=0,time[4]={2000,2000,2000,2000},flag[4]={0,0,0,0};
	int i;
	static float b[4],c[4],e[4]={1000,50,75,500};//实时用电功率和蓄电池储电 
	if(x>30000)
	{
		x=0;
	}
	if(daytime>=0&&daytime<420)
	{
		b[0]=c[0]=20;
		b[1]=c[1]=1;
		b[2]=c[2]=1.5;
		b[3]=c[3]=10;
	}
	else if(daytime>=420&&daytime<1200)
	{
		b[0]=40;
		c[0]=50;
		b[1]=2;
		c[1]=2.5;
		b[2]=3;
		c[2]=4;
		b[3]=20;
		c[3]=25;
	}
	else if(daytime>=1200&&daytime<1440)
	{
		b[0]=50;
		c[0]=60;
		b[1]=2.5;
		c[1]=3;
		b[2]=3.5;
		c[2]=4.5;
		b[3]=25;
		c[3]=30;
	}
	for(i=0;i<4;i++)
	{
		e[i]=e[i]+(a[i]-b[i]-c[i])/60;
		if(e[i]<0.1)
		{
			e[i]=0.00001;
			b[i]=c[i]=0.00001;
			if(flag[i]==0)
			{
				flag[i]=1;
				time[i]=daytime;
			}
		} 
	}
	for(i=0;i<4;i++)
	{
		if(e[i]==0.00001&&(daytime>=time[i]+20||daytime<=time[i]-1420)&&time[i]<=1440)
		{
			switch(i)
			{
				case 0:
					e[i]=1000;
					break;
				case 1:
					e[i]=50;
					break;
				case 2:
					e[i]=75;
					break;
				case 3:
					e[i]=500;
					break;
			}
			flag[i]=0;
			time[i]=2000;
		}
		
	}
	if(e[0]>5000)
	{
		e[0]=5000;
	}
	if(e[1]>250)
    {
		e[1]=250;
	}
	if(e[2]>300)
	{
		e[2]=300;
	}
	if(e[3]>2500)
	{
		e[3]=2500;
	}
	if(mode!=1||menu_mode!=1)
	{
		x=0;
	}
	if(mode==1&&menu_mode==1)
	{
		clr_arrow();
		work(x);
		if(a[plant_mode]>0.1)
		{
			absorb(x);
			produce(x);
			if(a[plant_mode]-b[plant_mode]-c[plant_mode]>0)
			{
				input(x);
			}
			else
			{
				output(x);
			}
		}
		else
		{
			setfillstyle(1,LIGHTBLUE);
			setcolor(LIGHTBLUE);
			setlinestyle(0,0,1);
			bar(203,58,215,129);
			output(x);
		}
	}
	if(mode==1)
	{
		battery(plant_mode,b,c,e); 
	}
	x++;
}
