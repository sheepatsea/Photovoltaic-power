#include"main.h"
#include"public.h"
extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;

extern struct ERRORS{
	int plant_0;
	char plant[5];
	char mount[5];
	int mount_0;
	int condition;
	char engage_time[30];
	char solve_time[30];
};


void main_system(void)   
{ 
    static struct ERRORS err[10];  //故障站点与故障数 
    static int menu_mode=0,plant_mode=0,weather_mode=0;  //功能菜单 站点  天气 
    int change=0; 
	clrmous(MouseX,MouseY);
	cleardevice();
	system_show();
	pitch_on(plant_mode);
	pitch_on_menu(menu_mode);
	weather_mode=func(1,&plant_mode,&menu_mode);  
	error_file_read(err);
	error_show(err);
	summary_chart(plant_mode);
	if(menu_mode==0)
	{
	    if(weather_mode==5)
        {
            night_show();
        }
	    else
        {
	        weather_show(weather_mode);
	    }
	}
	else if(menu_mode==1)
	{
	    init_transform(); 
	}
	while(1)
	{
		if(change<9999)
		{
			change++;
		}
		else
		{
			change=0;
			error_file_read(err);
		}
		newmouse(&MouseX,&MouseY,&press);
		weather_mode=func(1,&plant_mode,&menu_mode);  
		if(inbutton(5,210,155,330))  //站点模块 
		{
			switch_plant(&plant_mode,err,&weather_mode,&menu_mode);
		}

        else if(inbutton(485,210,635,330))  //功能模块 
        {
        	switch_menu(&menu_mode,err,&weather_mode,&plant_mode);
		}
		
		else if(inbutton(230,0,410,40))
		{
			MouseS=1;
			if(mouse_press(230,0,410,40)==1)
			{
				return ;
			}
		}
		else if(inbutton(5,140,115,360))
		{	
		    MouseS=1;
			if(mouse_press(5,140,115,360)==1)
			{
				pitch_off_menu(menu_mode);
				error();
				clrmous(MouseX,MouseY);
             	cleardevice();
	            system_show();
	            weather_mode=func(1,&plant_mode,&menu_mode);
	            if(menu_mode==0)
				{
					if(weather_mode==5)
              	{
             	   night_show();
            	}
	            else
             	{
	               weather_show(weather_mode);
	            }
				}
	            else if(menu_mode==1)
	            {
	            	init_transform(); 
				}
	            pitch_on_menu(menu_mode);
	            pitch_on(plant_mode);
	            error_file_read(err);
	            error_init();
	            error_show(err);
	         	summary_chart(plant_mode);
			 } 
		        
		}
     	else if(inbutton(485,340,635,360)==1)
		{
			MouseS=1;
			if(mouse_press(485,340,635,360)==1)
			{
				pitch_off_menu(menu_mode);
				record_chart(func(5,&plant_mode,&menu_mode));
				func(1,&plant_mode,&menu_mode);
				clrmous(MouseX,MouseY);
             	cleardevice();
	            system_show();
	            weather_mode=func(1,&plant_mode,&menu_mode);
	            if(menu_mode==0)
				{
					if(weather_mode==5)
              	{
             	   night_show();
            	}
	            else
             	{
	               weather_show(weather_mode);
	            }
				}
	            else if(menu_mode==1)
	            {
	            	init_transform(); 
				}
	            pitch_on_menu(menu_mode);
	            pitch_on(plant_mode);
	            error_file_read(err);
	            error_init();
	            error_show(err);
	         	summary_chart(plant_mode);
			} 
		}
		
		else
		{
			MouseS=0;
		}
		
	 } 
}

void struct_init()
{
   setbkcolor(BLUE);
   setlinestyle(0,0,THICK_WIDTH);
   setcolor(CYAN);
   setfillstyle(7,LIGHTBLUE);
   bar(0,0,640,480);
   moveto(230,0);
   lineto(245,35);
   lineto(258,35);
   lineto(260,30);
   lineto(380,30);
   lineto(382,35);
   lineto(395,35);
   lineto(410,0);
   puthz(248,10,"光伏电站可视化仿真",16,16,LIGHTCYAN);
}
void system_show()
{
   struct_init();  //总 
   produce_data_init();   //发电数据 
   
   plant_init();    //发电厂功能 
   
   error_init();  //故障检测功能 
   	
   rectangle(158,40,483,328);  //中一（动态及能量） 
   rectangle(158,328,483,480);  //中二  功率图 
   battery_init();
   menu_init();
   summary_init();

}


