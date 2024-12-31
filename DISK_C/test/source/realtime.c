#include"main.h"
#include"public.h"
#define pi 3.1415926
#define R 130 //̫��ת���뾶 
#define r 70   //�����ת���뾶 
#define PI 3.1415926
#define length 30
#define width 20


extern struct DATA             //���꼰�Ƕ� 
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
//*************************��ʼ����̬���� (������������ͼ��)
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

//********************�ǶȵĶ�̬�仯��̫��Բ�ĺ͹�������ĵĻ�ȡ 
void angle_change(struct DATA *p,int daytime,int mode) 
{
	
	if(daytime<=1080)  //6-18h����仯 
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
	else if(daytime>1080)  //����帴λ 
	{
			p->angle_fact_0--;
			if(p->angle_fact_0<=30)
            {
        	    p->angle_fact_0=30;
		    }
		    get_device(p,mode);
		
		
	}
        
	    	
}

//*********************̫��������嶯̬�仯 
void dynamic_change(struct DATA system,int weather_mode,int daytime,int mode,struct SUNDATA *psunpower,int plant_mode,int menu_mode)  
{
	 void (*new_sun)(int,int);                       //���庯��ָ�룬��Բ�ͬ�������費̫ͬ���������������� 
//************ÿ��6�㣬��ͬ������Ӧ�����仯 
		switch(weather_mode)       //���������仯������ͬ�����µĺ�����������ָ�� 
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
	switch(mode)                //mode��������������� 
	{
		case 0:
			break;
		case 1:   //ֻ����������Żᷢ���ĸ���仯 
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
			
	        if(weather_mode==1)                       //��Զ���ʱ̫�������ƶ�����ˢ���ƶ� 
            {
		        draw_cloud();
	        }
	        else if(weather_mode==2)            //��������ζ�̬�仯 
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


//**************************//���̫��������壻�������� 
void dynamic_clear(struct DATA system,int weather_mode,int daytime,int mode,struct SUNDATA *psunpower,int plant_mode,int menu_mode)
{
    void (*clear_sun)(int,int);  
	if(fabs(psunpower[plant_mode].Omega-psunpower[plant_mode].Omega_S)<=0.3&&mode==1&&menu_mode==0)
	{
	   weather_show(weather_mode);
    }
    	switch(weather_mode)       //���������仯������ͬ�����µĺ�����������ָ�� 
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

//*******************��̬�仯������������ 
void  realtime(int daytime,int mode,int menu_mode,int plant_mode,struct DATA *psystem,struct DAYDATA date,struct SUNDATA *psunpower)   
{ 

		//*************�Ȳ��󻭣�����ʵ��ͼ��Ķ������棬���ǻ���Ͳ���ͼ����˸ 
			if(daytime==0)
			{
			    angle_change(psystem,daytime,mode);
			}
			 dynamic_clear(*psystem,date.weather_mode[plant_mode],daytime,mode,psunpower,plant_mode,menu_mode);
		       
			   angle_change(psystem,daytime,mode);
		       
				dynamic_change(*psystem,date.weather_mode[plant_mode],daytime,mode,psunpower,plant_mode,menu_mode);
		    
			if(fabs(psunpower[plant_mode].Omega+psunpower[plant_mode].Omega_S)<0.3&&mode==1&&menu_mode==0)  //�չ�18�㣬��� 
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
