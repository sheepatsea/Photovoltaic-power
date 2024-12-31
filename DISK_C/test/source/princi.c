#include"public.h"
#include"main.h"
#include"princi.h"


extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;

extern struct SUNDATA
{
    int N;  //日序
    float Fai;  //纬度 
    float Delta;  //赤纬角 
	float Omega_S;  //日出角 
	float Gamma;  //太阳系数 
	float E_0;  //当天辐射 
	float E_sb;   //实时辐射 
	float h;  //高度角 
	float a;  //透明度 
	float m;  //大气质量
	float Omega;  
	float p;
};

void principle()
{
    static int meaningless_menu=0,meaningless_plant=0;
	principle_show();
	while(1)
	{
		func(3,&meaningless_plant,&meaningless_menu);
		newmouse(&MouseX,&MouseY,&press);
		if(inbutton(560,420,630,450))
		{
			MouseS=1;
			if(mouse_press(560,420,630,450)==1)
			{
				return ;
			}
		}
		else 
		{
			MouseS=0;
		}
	}
}

void chemical_principle(struct SUNDATA *psunpower,int mode,int plant_mode)
{
	static int x[4][2]={{270,290},{270,290},{270,290},{270,290}};
	static int change=0;
		if(mode==3&&psunpower[plant_mode].E_sb>=1)
	{
		chemical_clear(x,plant_mode);
	}
	chemical_change(psunpower,x);
	if(mode==3&&psunpower[plant_mode].E_sb>=1)
	{
		chemical_new(x,plant_mode);
	}



}
void chemical_change(struct SUNDATA *psunpower,int x[4][2])
{
	int cnt;
	int add[4]={0};
	for(cnt=0;cnt<4;cnt++)
	{
		if(psunpower[cnt].E_sb>200)
		{
			add[cnt]=20;
		}
		else if(psunpower[cnt].E_sb>100)
		{
			add[cnt]=10;
		}
		else if(psunpower[cnt].E_sb>10)
		{
			add[cnt]=5;
		}
		else if(psunpower[cnt].E_sb>1)
		{
			add[cnt]=1;
		}

		if(x[cnt][0]>140)
		{
		    x[cnt][0]-=add[cnt];
	    	x[cnt][1]+=add[cnt];	
		}
		if(x[cnt][0]<=140)
		{
			x[cnt][0]=270;
		    x[cnt][1]=290;
		}
	}
}
void chemical_clear(int x[4][2],int plant_mode)
{
	clean_positive(x[plant_mode][0],200);
	clean_negtive(x[plant_mode][1],200);
	setcolor(DARKGRAY);
	line(245-5,300-40,245-5,265-40);
	line(245-5,265-40,355-5,80-40);
	line(305+5,300-40,305+5,265-40);
	line(305+5,265-40,415+5,80-40);
	draw_light(350,67);
	draw_light(396,63);
	draw_light(323,114);
	draw_light(359,117);
	draw_light(299,150);
	draw_light(339,155);
	draw_light(274,189);
	draw_light(322,186);
}

void chemical_new(int x[4][2],int plant_mode)
{
	draw_positive(x[plant_mode][0],200);
	draw_negtive(x[plant_mode][1],200);
}

void principle_show()
{
	int i;
	int elec_line[2][10]={{0,125,105,125,98,135,0,135,0,125},{640,125,562,125,556,135,640,135,640,125}};
	int chemi[14]={45,300-40,45,265-40,155,80-40,595,80-40,595,115-40,505,300-40,45,300-40};
	clrmous(MouseX,MouseY);
	cleardevice();
	setbkcolor(BLUE);
	setcolor(BLUE);
	setlinestyle(0,0,NORM_WIDTH);
	setfillstyle(7,LIGHTBLUE);
	bar(0,0,640,480);
	setcolor(DARKGRAY);
	setlinestyle(0,0,THICK_WIDTH);
	setfillstyle(1,LIGHTGRAY);
	fillpoly(7,chemi);
	line(505,265-40,505,300-40);
	line(505,265-40,45,265-40);
	line(505,265-40,595,80-40);
	line(245-5,300-40,245-5,265-40);
	line(245-5,265-40,355-5,80-40);
	line(305+5,300-40,305+5,265-40);
	line(305+5,265-40,415+5,80-40);
	
	for(i=0;i<5;i++)
	{
		draw_positive(90+15*i,200-30*i);
		draw_negtive(490+15*i,200-30*i);
	}
    
    draw_positive(317,137);
    draw_positive(337,93);
    draw_positive(269,70);
    draw_positive_arrow(269,70);
    draw_positive(228,111);
    draw_positive_arrow(228,111);
    draw_positive(250,160);
    draw_positive_arrow(250,160);
    draw_positive(295,175);
    
	draw_negtive(442,70);
	draw_negtive_arrow(442,70);
	draw_negtive(410,109);
	draw_negtive_arrow(410,109);
	draw_negtive(391,160);
	draw_negtive_arrow(391,160);
	draw_negtive(347,127);	
	draw_negtive(366,78);
	draw_negtive(325,170);	
	
	draw_light(350,67);
	draw_light(396,63);
	draw_light(323,114);
	draw_light(359,117);
	draw_light(299,150);
	draw_light(339,155);
	draw_light(274,189);
	draw_light(322,186);
	
	setcolor(WHITE);
	settextstyle(2,0,7);
	outtextxy(90,270,"P");
	puthz(102,275,"型半导体",16,16,WHITE);
    outtextxy(250,270,"PN");
    puthz(275,275,"结",16,16,WHITE);
    outtextxy(360,270,"N");
    puthz(372,275,"型半导体",16,16,WHITE); 
    
    draw_positive(20,60);
    outtextxy(35,50,":");
    puthz(40,55,"空穴",16,16,WHITE); 
    draw_negtive(20,90);
    outtextxy(35,80,":");
    puthz(40,85,"电子",16,16,WHITE); 
    
    setcolor(DARKGRAY);
    setfillstyle(1,DARKGRAY);
    fillpoly(5,elec_line[0]);
    fillpoly(5,elec_line[1]);
    
    setcolor(WHITE);
    setlinestyle(0,0,THICK_WIDTH);
    line(555,180,623,180);
    line(555,180,570,170);
    line(555,180,570,190);
    puthz(575,160,"电流",16,16,WHITE);
    

    setcolor(LIGHTCYAN);
	setlinestyle(0,0,NORM_WIDTH);
	setfillstyle(1,CYAN);
	bar(560,420,630,450);
	rectangle(560,420,630,450);
	puthz(572,428,"返回",16,32,LIGHTCYAN);
}

void draw_positive(int x,int y)
{
	setcolor(DARKGRAY);
	setlinestyle(0,0,THICK_WIDTH);
	setfillstyle(1,DARKGRAY);
	fillellipse(x,y,10,10);
	setcolor(WHITE);
	line(x-5,y,x+5,y);
	line(x,y-5,x,y+5);
 } 
 
 void clean_positive(int x,int y)
{
	setcolor(LIGHTGRAY);
	setlinestyle(0,0,THICK_WIDTH);
	setfillstyle(1,LIGHTGRAY);
	fillellipse(x,y,10,10);
 } 
void draw_negtive(int x,int y)
{
	setcolor(DARKGRAY);
	setlinestyle(0,0,THICK_WIDTH);
	setfillstyle(1,DARKGRAY);
	fillellipse(x,y,10,10);
	setcolor(WHITE);
	line(x-5,y,x+5,y);
 } 
 
 void clean_negtive(int x,int y)
{
	setcolor(LIGHTGRAY);
	setlinestyle(0,0,THICK_WIDTH);
	setfillstyle(1,LIGHTGRAY);
	fillellipse(x,y,10,10);
 } 
void draw_positive_arrow(int x,int y)
{
	setcolor(DARKGRAY);
	setlinestyle(0,0,THICK_WIDTH);
	setfillstyle(1,DARKGRAY);
	line(x-30,y,x-80,y);
	line(x-80,y,x-70,y-5);
    line(x-80,y,x-70,y+5);
} 
 
void draw_negtive_arrow(int x,int y)
{
	setcolor(DARKGRAY);
	setlinestyle(0,0,THICK_WIDTH);
	setfillstyle(1,DARKGRAY);
	line(x+30,y,x+80,y);
	line(x+80,y,x+70,y-5);
	line(x+80,y,x+70,y+5);
 }  
void draw_light(int x,int y)
{
   setcolor(YELLOW);
   setlinestyle(0,0,THICK_WIDTH);
   line(x,y,x-40,y-100);
   line(x,y,x-10,y-5);
   line(x,y,x+5,y-10); 
	
} 
       
