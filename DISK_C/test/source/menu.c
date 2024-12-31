#include"public.h"
#include"main.h"
#include"menu.h"

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;

void menu_init(void)
{
   setlinestyle(0,0,NORM_WIDTH);
   setcolor(LIGHTCYAN);
   setfillstyle(7,LIGHTBLUE);
   rectangle(485,190,635,330);  //右二  功能菜单 
   line(485,210,595,210);
   line(595,210,635,190);
   puthz(490,192,"功能菜单",16,32,LIGHTCYAN);
   line(485,210,635,210);
   line(575,210,570,225);
   line(570,225,575,240);
   
   line(485,240,635,240);
   line(575,240,570,255);
   line(570,255,575,270);
   
   line(485,270,635,270);
   line(575,270,570,285);
   line(570,285,575,300);
   
   line(485,300,635,300);
   line(575,300,570,315);
   line(570,315,575,330);
   
  // line(485,310,635,310); 
   puthz(490,218,"总览",16,32,LIGHTCYAN);
   puthz(490,248,"能量调度",16,16,LIGHTCYAN);
   puthz(490,278,"历史记录",16,16,LIGHTCYAN);
   puthz(490,308,"设备运作",16,16,LIGHTCYAN);
	
}
void switch_menu(int *pmenu_mode,struct ERRORS *perr,int *pweather_mode,int *pplant_mode)
{
	if(inbutton(570,210,635,240))  //总览 
		{
			MouseS=1;
			if(mouse_press(570,210,635,239)==1)
			{
				pitch_off_menu(*pmenu_mode);
				*pmenu_mode=0;
				pitch_on_menu(*pmenu_mode);
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
			}
		}
	else if(inbutton(570,241,635,269))  //能量转化 
		{
			MouseS=1;
			if(mouse_press(570,241,635,269)==1)
			{
				pitch_off_menu(*pmenu_mode);
				*pmenu_mode=1;
				pitch_on_menu(*pmenu_mode);
				init_transform();
			}
		}	
	else if(inbutton(570,271,635,299))  //历史记录 
		{
			MouseS=1;
			if(mouse_press(570,271,635,299)==1)
			{
				pitch_off_menu(*pmenu_mode);
				history(func(2,pplant_mode,pmenu_mode));
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
	else if(inbutton(570,301,635,330))  //设备运作 
		{
			MouseS=1;
			if(mouse_press(570,301,635,330)==1)
			{
				pitch_off_menu(*pmenu_mode);
				principle();
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

void pitch_on_menu(int menu_mode)
{
	int cnt;
	int arrow[12]={575,210,570,225,575,240,635,240,635,210,575,210};
	for(cnt=1;cnt<=11;cnt+=2)
	{
		arrow[cnt]+=(30*menu_mode);
	}
	clrmous(MouseX,MouseY); 
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,NORM_WIDTH);
	setfillstyle(1,LIGHTCYAN);
	fillpoly(6,arrow);
}

void pitch_off_menu(int menu_mode)
{
	int cnt;
	int arrow[12]={575,210,570,225,575,240,635,240,635,210,575,210};
	for(cnt=1;cnt<=11;cnt+=2)
	{
		arrow[cnt]+=(30*menu_mode);
	}
	clrmous(MouseX,MouseY); 
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,NORM_WIDTH);
	setfillstyle(7,LIGHTBLUE);
	fillpoly(6,arrow);
}

