#include"public.h"
#include"main.h"
#include"plant.h"

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;

struct PLANTINFORM{
	char longitude[10];  //经度 
	char latitude[10];  //纬度
	char position[100];
	char item[100];
	char content[20];
	char product[20]; 
};
void plant(int *pplant_mode)
{
	int meaningless_menu=5;
	plant_show();
	information(*pplant_mode); 
	while(1)
	{
		func(4,pplant_mode,&meaningless_menu);
		newmouse(&MouseX,&MouseY,&press);
		if(inbutton(10,20,80,50))
		{
			MouseS=1;
			if(mouse_press(10,20,80,50)==1)
			{
				*pplant_mode = 0;
				clrmous(MouseX,MouseY);
				clear_last();
				information(*pplant_mode); 
			}
		}
		else if(inbutton(90,20,160,50))
		{
			MouseS=1;
			if(mouse_press(90,20,160,50)==1)
			{
				*pplant_mode = 1; 
				clrmous(MouseX,MouseY);
				clear_last();
				information(*pplant_mode); 
			}
		}
		else if(inbutton(170,20,240,50))
		{
			MouseS=1;
			if(mouse_press(170,20,240,50)==1)
			{
				*pplant_mode = 2;
				clrmous(MouseX,MouseY);
				clear_last();
				information(*pplant_mode); 
			}
		}
		else if(inbutton(250,20,320,50))
		{
			MouseS=1;
			if(mouse_press(250,20,320,50)==1)
			{
				*pplant_mode = 3;
				clrmous(MouseX,MouseY);
				clear_last();
				information(*pplant_mode); 
			}
		}
		else if(inbutton(560,420,630,450))
		{
			MouseS=1;
			if(mouse_press(560,420,630,450)==1)
			{
				return  ; 
			}
		 } 
		else
		{
			MouseS=0;
		}
	 } 
}

void plant_show() 
{
//	struct PLANTINFORM pp={"140.165","35.6663","日本源清田商事千叶中央工厂","工商业分布式","0.3MW","HI-MO5m"};
//	struct PLANTINFORM *plant1=&pp,*plant2;  //工厂信息需先用中文写入到文件中在读取才是正常汉字 
    clrmous(MouseX,MouseY);
	cleardevice();	
	setbkcolor(BLUE);
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,NORM_WIDTH);
	setfillstyle(7,LIGHTBLUE);
	bar(0,0,640,480);
	setfillstyle(1,CYAN);
	bar(10,20,80,50);   
	rectangle(10,20,80,50);   
	puthz(14,28,"一号站点",16,16,LIGHTCYAN);
	bar(90,20,160,50);
	rectangle(90,20,160,50);   
	puthz(94,28,"二号站点",16,16,LIGHTCYAN);
	bar(170,20,240,50);
	rectangle(170,20,240,50);  
	puthz(174,28,"三号站点",16,16,LIGHTCYAN);
	bar(250,20,320,50);
	rectangle(250,20,320,50);  
	puthz(254,28,"四号站点",16,16,LIGHTCYAN);
	
	bar(10,50,630,400);
	rectangle(10,50,630,400);
	puthz(30,100,"项目经纬",16,16,LIGHTCYAN);
	puthz(30,130,"经度",16,16,LIGHTCYAN);
	puthz(30,160,"纬度",16,16,LIGHTCYAN);
	puthz(300,100,"项目地点",16,16,LIGHTCYAN);
	puthz(30,200,"项目类型",16,16,LIGHTCYAN);
	puthz(300,200,"项目容量",16,16,LIGHTCYAN);
	puthz(30,300,"产品类型",16,16,LIGHTCYAN); 
	bar(560,420,630,450);
	rectangle(560,420,630,450);
	puthz(572,428,"查看",16,32,LIGHTCYAN);

    //**********************这部分我尝试过用数据块读写，但如果结构体中含中文字符会出现问题，因此最终采取逐项读写 
/*	fp=fopen("C:\\TEST\\DATA\\plant4.txt","wt+");
    fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t",plant1->longitude,plant1->latitude,plant1->position,plant1->item,plant1->content,plant1->product);
    fclose(fp);
*/  
	
}


void information(int plant_mode)
{
	FILE *fp;
	struct PLANTINFORM plant_show;
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,NORM_WIDTH);
	//*************按钮重画 
	setfillstyle(1,LIGHTBLUE);
	bar(10,20,80,50);   
	rectangle(10,20,80,50);   
	puthz(14,28,"一号站点",16,16,LIGHTCYAN);
	bar(90,20,160,50);
	rectangle(90,20,160,50);   
	puthz(94,28,"二号站点",16,16,LIGHTCYAN);
	bar(170,20,240,50);
	rectangle(170,20,240,50);  
	puthz(174,28,"三号站点",16,16,LIGHTCYAN);
	bar(250,20,320,50);
	rectangle(250,20,320,50);  
	puthz(254,28,"四号站点",16,16,LIGHTCYAN);
	
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,NORM_WIDTH);
	setfillstyle(1,CYAN);
	switch(plant_mode)
	{
		case 0:
			bar(10,20,80,50); 
			rectangle(10,20,80,50);  
			setcolor(CYAN);
			line(10,50,80,50);
	        puthz(14,28,"一号站点",16,16,LIGHTCYAN);
		    fp=fopen("DATA\\plant1.txt","rt");
		    break;
		case 1:
			bar(90,20,160,50);
			rectangle(90,20,160,50);
			setcolor(CYAN);
			line(90,50,160,50);
	        puthz(94,28,"二号站点",16,16,LIGHTCYAN);
		    fp=fopen("DATA\\plant2.txt","rt");
		    break;
		case 2:
			bar(170,20,240,50);
			rectangle(170,20,240,50);
			setcolor(CYAN);
			line(170,50,240,50);
	        puthz(174,28,"三号站点",16,16,LIGHTCYAN);
		    fp=fopen("DATA\\plant3.txt","rt");
		    break;
		case 3:
			bar(250,20,320,50);
			rectangle(250,20,320,50);
			setcolor(CYAN);
			line(250,50,320,50);
	        puthz(254,28,"四号站点",16,16,LIGHTCYAN);
		    fp=fopen("DATA\\plant4.txt","rt");
		    break;
	}
    fscanf(fp,"%s%s%s%s%s%s",plant_show.longitude,plant_show.latitude,plant_show.position,plant_show.item,plant_show.content,plant_show.product);
    fclose(fp);
	settextstyle(2,0,7);
	setcolor(LIGHTCYAN);
	outtextxy(80,125,plant_show.longitude);
	outtextxy(80,155,plant_show.latitude);
	puthz(300,150,plant_show.position,16,16,LIGHTCYAN);
    puthz(30,250,plant_show.item,16,16,LIGHTCYAN);
    outtextxy(300,250,plant_show.content);
    outtextxy(30,350,plant_show.product);
    
}

void clear_last()
{
	setcolor(CYAN);
	setlinestyle(0,0,NORM_WIDTH);
	setfillstyle(1,CYAN);
	bar(70,125,620,180);
	bar(30,250,510,275);
	bar(20,350,118,377);
}

void plant_init()
{
   setlinestyle(0,0,NORM_WIDTH);
   setcolor(LIGHTCYAN);
   setfillstyle(7,LIGHTBLUE);
   rectangle(5,190,155,330);  //左二   发电站点 
   line(5,210,115,210);
   line(115,210,155,190);
   puthz(10,192,"站点状况",16,25,LIGHTCYAN);
   line(5,210,155,210);
   line(95,210,90,223);
   line(90,223,95,235);
   
   line(5,235,155,235);
   line(95,235,90,248);
   line(90,248,95,260);
   
   line(5,260,155,260);
   line(95,260,90,273);
   line(90,273,95,285);
   
   line(5,285,155,285);
   line(95,285,90,298);
   line(90,298,95,310);
   
   line(5,310,155,310); 
   puthz(10,212,"一号",16,16,LIGHTCYAN);
   puthz(10,237,"二号",16,16,LIGHTCYAN);
   puthz(10,262,"三号",16,16,LIGHTCYAN);
   puthz(10,287,"四号",16,16,LIGHTCYAN);
   puthz(10,312,"查看详情",16,32,LIGHTCYAN);
	
}


void pitch_on(int plant_mode)
{
	int cnt;
	int arrow[12]={95,210,90,223,95,235,155,235,155,210,95,210};
	for(cnt=1;cnt<=11;cnt+=2)
	{
		arrow[cnt]+=(25*plant_mode);
	}
	clrmous(MouseX,MouseY); 
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,NORM_WIDTH);
	setfillstyle(1,LIGHTCYAN);
	fillpoly(6,arrow);
}

void pitch_off(int plant_mode)
{
	int cnt;
	int arrow[12]={95,210,90,223,95,235,155,235,155,210,95,210};
	for(cnt=1;cnt<=11;cnt+=2)
	{
		arrow[cnt]+=(25*plant_mode);
	}
	clrmous(MouseX,MouseY); 
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,NORM_WIDTH);
	setfillstyle(7,LIGHTBLUE);
	fillpoly(6,arrow);
}

void switch_plant(int *pplant_mode,struct ERRORS *perr,int *pweather_mode,int *pmenu_mode)
{
		if(inbutton(90,210,155,235))
		{
			MouseS=1;
			if(mouse_press(5,210,155,235)==1)
			{
				pitch_off(*pplant_mode);
				*pplant_mode=0;
				pitch_on(*pplant_mode);
				summary_chart(*pplant_mode);
			}
			
		}
		else if(inbutton(90,235,155,260))
		{
			MouseS=1;
			if(mouse_press(5,235,155,260)==1)
			{
				pitch_off(*pplant_mode);
				*pplant_mode=1;
				pitch_on(*pplant_mode);
				summary_chart(*pplant_mode);
			}
		}
		else if(inbutton(90,260,155,285))
		{
			MouseS=1;
			if(mouse_press(5,260,155,285)==1)
			{
				pitch_off(*pplant_mode);
				*pplant_mode=2;
				pitch_on(*pplant_mode);
				summary_chart(*pplant_mode);
			}
		}
		else if(inbutton(90,285,155,310))
		{
			MouseS=1;
			if(mouse_press(5,285,155,310)==1)
			{
				pitch_off(*pplant_mode);
				*pplant_mode=3;
				pitch_on(*pplant_mode);
				summary_chart(*pplant_mode);
			}
		}
		else if(inbutton(5,310,155,330))
		{
			MouseS=1;
			if(mouse_press(5,310,155,330)==1)
			{
				plant(pplant_mode);
				clrmous(MouseX,MouseY);
             	cleardevice();
	            system_show();
	            *pweather_mode=func(1,pplant_mode,pmenu_mode);
	            if(*pmenu_mode==0)
				{
					if(*pweather_mode==5)
              	{
             	   night_show();
            	}
	            else
             	{
	               weather_show(*pweather_mode);
	            }
				}
	            else if(*pmenu_mode==1)
	            {
	            	init_transform(); 
				}
	            pitch_on_menu(*pmenu_mode);
	            pitch_on(*pplant_mode);
	            error_file_read(perr);
	            error_init();
	         	error_show(perr);
	         	summary_chart(*pplant_mode);
			}
		 }
		else 
		{
			MouseS=0;
		}
}
