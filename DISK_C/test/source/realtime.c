#include"main.h"
#include"public.h"
#define pi 3.1415926
#define R 130 //太阳转动半径 
#define r 70   //光伏板转动半径 
#define PI 3.1415926
#define length 30
#define width 20


extern struct DATA             //坐标及角度 
{
   int x_sun;
   int y_sun;
   int x_device[3];
   int y_device[3];
   float angle_fact;
   int angle_fact_0;
   int move_edge[12];
   int link[10]; 
   int linkbar[10];
   int linkbar_end[2];
   int spinbar[14];
   int assistant[12];
   int board[10];
   int little_device_x[4][3];
   int little_device_y[4][3];
   int little_board[4][10];
};

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


void left_house()
{
   setcolor(DARKGRAY);
   setfillstyle(1,LIGHTGRAY);
   setlinestyle(0,0,NORM_WIDTH);
   bar(159,171,205,327);
   rectangle(159,171,205,327);
   line(205,171,159,217);
}
void right_house()
{
	int house_right[]={412,217,452,171,481,171,481,327,412,327,412,217};
	setcolor(DARKGRAY);
    setfillstyle(1,LIGHTGRAY);
    setlinestyle(0,0,NORM_WIDTH);
    fillpoly(6,house_right);
    line(412,217,481,217);
}
//*************************初始化动态界面 (按键，环境，图表)
void realtime_show()    
{
   int house[12]={218,217,270,171,398,171,398,327,218,327,218,217};
   
   setcolor(DARKGRAY);
   setfillstyle(1,LIGHTGRAY);
   setlinestyle(0,0,NORM_WIDTH);
   fillpoly(6,house);
   line(344,217,218,217);
   line(344,217,398,171);
   line(344,217,344,327);
   left_house();
   right_house();
}

//********************角度的动态变化及太阳圆心和光伏板中心的获取 
void angle_change(struct DATA *p,int daytime,int mode) 
{
	
	if(daytime<=1080)  //6-18h正向变化 
	{
		p->angle_fact=(daytime-720)*0.25;
		p->angle_fact_0=(daytime-360)/4;
		if(p->angle_fact_0<=30)
        {
        	p->angle_fact_0=30;
		}
		else if(p->angle_fact_0>=150)
		{
			p->angle_fact_0=150;
		}
	    p->x_sun=320-cos((90+1.0 * p->angle_fact)/180*pi)*R;
	    p->y_sun=250-sin((90+1.0 * p->angle_fact)/180*pi)*R;
	    get_device(p,mode);
	}
	else if(daytime>1080)  //光伏板复位 
	{
			p->angle_fact_0--;
			if(p->angle_fact_0<=30)
            {
        	    p->angle_fact_0=30;
		    }
		    get_device(p,mode);
		
		
	}
        
	    	
}

//*********************太阳、光伏板动态变化 
void dynamic_change(struct DATA system,int weather_mode,int daytime,int mode,struct SUNDATA *psunpower,int plant_mode,int menu_mode)  
{
	 void (*new_sun)(int,int);                       //定义函数指针，针对不同天气赋予不同太阳画出和消除函数 
//************每早6点，不同天气相应参数变化 
		switch(weather_mode)       //发生天气变化，将不同天气下的函数赋给函数指针 
		{
			case 0:
				new_sun=sunny_new_sun;
				break;
			case 1:
				new_sun=cloudy_new_sun;
				break;
			default:	
				new_sun=rainy_new_sun;
				break;
		}
	    new_device(system,mode,menu_mode);
	switch(mode)                //mode是所处程序带来的 
	{
		case 0:
			break;
		case 1:   //只有在主界面才会发生的各项变化 
		if(menu_mode==0)
		{
		    if(psunpower[plant_mode].Omega>=psunpower[plant_mode].Omega_S&&psunpower[plant_mode].Omega<=-psunpower[plant_mode].Omega_S)
		{
		   new_sun(system.x_sun,system.y_sun);	
		}
		if(daytime<=540)
		{
			left_house();
		}
		else if(daytime>=900&&daytime<=1080)
		{
			right_house();
		}
			
	        if(weather_mode==1)                       //针对多云时太阳经过云朵的情况刷新云朵 
            {
		        draw_cloud();
	        }
	        else if(weather_mode==2)            //下雨天雨滴动态变化 
	        {
	        	if(daytime<=1080)
	        	{
	//        	   draw_rain();	
				}
	        }
		}
		
            break;
		case 2:
	        break;
		case 3:
		    break;	
	}
	
}


//**************************//清除太阳、光伏板；定义天气 
void dynamic_clear(struct DATA system,int weather_mode,int daytime,int mode,struct SUNDATA *psunpower,int plant_mode,int menu_mode)
{
    void (*clear_sun)(int,int);  
	if(fabs(psunpower[plant_mode].Omega-psunpower[plant_mode].Omega_S)<=0.3&&mode==1&&menu_mode==0)
	{
	   weather_show(weather_mode);
    }
    	switch(weather_mode)       //发生天气变化，将不同天气下的函数赋给函数指针 
		{
			case 0:
				clear_sun=sunny_clear_sun;
				break;
			case 1:
				clear_sun=cloudy_clear_sun;
				break;
			default:	
				clear_sun=rainy_clear_sun;
				break;
		}
		
	clear_device(system,mode,menu_mode);
    switch(mode)
    {
    	case 0:
    		break;
    	case 1:
    		if(menu_mode==0)
    		{
    			if(psunpower[plant_mode].Omega>=psunpower[plant_mode].Omega_S&&psunpower[plant_mode].Omega<=-psunpower[plant_mode].Omega_S)
	     	{
		        clear_sun(system.x_sun,system.y_sun);	
	    	}
	            
            if(weather_mode==2)
	        {
		        if(daytime<=1080)
	        	{
	//        	   draw_rain();	
				}
	        }
			}
    		
	        break;
	    case 2:
	        break;
		case 3:
			
		    break;	
	}
	  
}

//*******************动态变化主函数及操作 
void  realtime(int daytime,int mode,int menu_mode,int plant_mode,struct DATA *psystem,struct DAYDATA date,struct SUNDATA *psunpower)   
{ 

		//*************先擦后画，可以实现图像的短暂留存，而非画完就擦而图像闪烁 
			if(daytime==0)
			{
			    angle_change(psystem,daytime,mode);
			}
			 dynamic_clear(*psystem,date.weather_mode[plant_mode],daytime,mode,psunpower,plant_mode,menu_mode);
		       
			   angle_change(psystem,daytime,mode);
		       
				dynamic_change(*psystem,date.weather_mode[plant_mode],daytime,mode,psunpower,plant_mode,menu_mode);
		    
			if(fabs(psunpower[plant_mode].Omega+psunpower[plant_mode].Omega_S)<0.3&&mode==1&&menu_mode==0)  //刚过18点，天黑 
	        {
	   	        night_show();
	        }
	   

}
void map_show(int plant_mode) 
{
	setcolor(BROWN);
	setlinestyle(0,0,NORM_WIDTH);
	setfillstyle(1,WHITE);
	bar(115,420,180,485);
	rectangle(115,420,180,485);
	setcolor(LIGHTBLUE);
	setfillstyle(1,LIGHTBLUE);
	fillellipse(122,457,3,3);  //1
	fillellipse(144,470,3,3);  //2
	fillellipse(140,428,3,3); //3
	fillellipse(165,445,3,3);  //4
	setcolor(RED);
	setfillstyle(1,RED);
	switch(plant_mode)
	{
		case 0:
		  fillellipse(122,457,3,3);  //1
		  break;
		case 1:
		  fillellipse(144,470,3,3);  //2
		  break;
		case 2:
		  fillellipse(140,428,3,3); //3
		  break;
		case 3:
		  fillellipse(165,445,3,3);  //4
		  break;
	}
	
}
