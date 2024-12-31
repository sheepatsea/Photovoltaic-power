#include"public.h"
#include"main.h"
#include"func.h"
#include"trtime.h"
#define meaningless 5

struct DATA             //坐标及角度 
{
   int x_sun;
   int y_sun;   //太阳坐标 
   int x_device[3];
   int y_device[3];  //光伏板运动主杆中心坐标 
   float angle_fact;  //浮点数型的角度，用于太阳坐标的获取 
   int angle_fact_0;  //整数型的角度，用于光伏板设备的坐标获取（fillpoly只能用int型数组） 
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
struct SUNDATA
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


//***********************后台总控及时间变化 
int func(int mode,int *pplant,int *pmenu)  
{
	FILE *fpstart,*fpdata,*fpyesterday;  //分别用来打开相应的文件 
	static int daytime=0; //主时间（min） 
	static long int change_point=0;  //动画改变点 
	static struct DATA system;
    static struct DAYDATA date;
    static struct SUNDATA sunpower[4];
    static int plant_mode=0,menu_mode=0;
    static int errors[4]={0,0,0,0};   //厂和数目 
	int a[4];  //用于显示的时间的存储 
	float dydata[4];
	static int flag=0; //用于判断是否为第一次进入程序 
	int i,cnt;  //计数用 
 
//*********************判断是否为第一次进入程序 
	if(flag==0)  //第一次进入程序 
	{       
	//**********************读取start里的日期 文件名 星期 天气 
	   flag++;  //flag值改变，不会再次进入if 
	   
	   fpstart=fopen("DATA\\start.txt","rt");
	   fscanf(fpstart,"%d%d%d%s%s%s%s%d",&date.year,&date.month,&date.day,date.file_name[0],date.file_name[1],date.file_name[2],date.file_name[3],&date.weekday);
	   for(i=0;i<4;i++)
	   {
	   	fscanf(fpstart,"%d",&date.weather_mode[i]);
	   }
	   fclose(fpstart);
	    get_data(&date,sunpower);  //得到当天天气 
			
	}  
	
	 if(mode==1)  //在主系统界面中 
	 {
	 	plant_mode=*pplant; 
	 	menu_mode=*pmenu;
	 }

	 
//******************动态变化过程 
	if(change_point>9999)  //每次change_point+1，如果到达99999，则进行一次动态变化，这样不会影响鼠标操作与动画表现的同时进行 
	{
		change_point=0;
		daytime++;
	   if(daytime>1440) //一天结束 
	   {
		daytime=0;
		//**************把今天的数据存入后台数据中 
		putin_data(date);
	    //***************last里的日期改为今天，更新后其中数据就是“昨天”
		putin_last(date);   
		
		putin_day(date);
		
	    record_data();//存储月总结数据 
	    if(mode==1)
	    {
	    	summary_chart(plant_mode);
		}
		new_day(&date,sunpower);  //新的一天开始啦 
		
		//*******************覆盖掉日期处图层 
		if(mode==1||mode==3||mode==6)
		{
			setfillstyle(7,LIGHTBLUE);
		    bar(441,0,627,36);
		}
		
	   }
	    dynamic_data(daytime,&date,dydata,sunpower,errors);
	    
	    error_monitor(mode,errors,daytime,date);
	   
	  	new_chart(mode,dydata,plant_mode);  //实时检测表的数据变化，是否画出需根据mode判断 
	   
	    transform(mode,menu_mode,plant_mode,dydata,daytime);
	   
	   realtime(daytime,mode,menu_mode,plant_mode,&system,date,sunpower);
	   if(mode==1||mode==3||mode==6)
	   {
	   	show_time(date,daytime,a);
        if(mode==1)
	    {
	   	    produce_data_show(sunpower,dydata,plant_mode);
	    }	
	   }
	   chemical_principle(sunpower,mode,plant_mode);
	  
		   	
//**************根据所处页面判断是否显示时间 主页面和能量转换均会显示 ；返回天气状况（只针对realtime有实际作用） 
		switch(mode)
	  {
		case 0:     //main 
			return date.weather_mode[plant_mode];
		case 1:    //realtime 
			
	        if(sunpower[plant_mode].Omega<=sunpower[plant_mode].Omega_S||sunpower[plant_mode].Omega>=-sunpower[plant_mode].Omega_S)
	         {
	   	       return 5;
		     }
			return date.weather_mode[plant_mode];
		case 2:    //record 
			return plant_mode;
		case 3:     //principle
			return plant_mode;
		case 4:  //plant
			return date.weather_mode[plant_mode];
		case 5:  //总结 
			return plant_mode;
		case 6:  //报错
		    return plant_mode;
	  }
	}
	else 
	{
	    change_point++;
		if(mode==2||mode==5)
		{
			return plant_mode;
		} 
	    if(sunpower[plant_mode].Omega<=sunpower[plant_mode].Omega_S||sunpower[plant_mode].Omega>=-sunpower[plant_mode].Omega_S)
	    {
	   	    return 5;
		}
		return date.weather_mode[plant_mode];	
	}
	
}

