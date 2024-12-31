#include"public.h"
#include"main.h"
#include"func.h"
#include"trtime.h"
#define meaningless 5

struct DATA             //���꼰�Ƕ� 
{
   int x_sun;
   int y_sun;   //̫������ 
   int x_device[3];
   int y_device[3];  //������˶������������� 
   float angle_fact;  //�������͵ĽǶȣ�����̫������Ļ�ȡ 
   int angle_fact_0;  //�����͵ĽǶȣ����ڹ�����豸�������ȡ��fillpolyֻ����int�����飩 
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


//***********************��̨�ܿؼ�ʱ��仯 
int func(int mode,int *pplant,int *pmenu)  
{
	FILE *fpstart,*fpdata,*fpyesterday;  //�ֱ���������Ӧ���ļ� 
	static int daytime=0; //��ʱ�䣨min�� 
	static long int change_point=0;  //�����ı�� 
	static struct DATA system;
    static struct DAYDATA date;
    static struct SUNDATA sunpower[4];
    static int plant_mode=0,menu_mode=0;
    static int errors[4]={0,0,0,0};   //������Ŀ 
	int a[4];  //������ʾ��ʱ��Ĵ洢 
	float dydata[4];
	static int flag=0; //�����ж��Ƿ�Ϊ��һ�ν������ 
	int i,cnt;  //������ 
 
//*********************�ж��Ƿ�Ϊ��һ�ν������ 
	if(flag==0)  //��һ�ν������ 
	{       
	//**********************��ȡstart������� �ļ��� ���� ���� 
	   flag++;  //flagֵ�ı䣬�����ٴν���if 
	   
	   fpstart=fopen("DATA\\start.txt","rt");
	   fscanf(fpstart,"%d%d%d%s%s%s%s%d",&date.year,&date.month,&date.day,date.file_name[0],date.file_name[1],date.file_name[2],date.file_name[3],&date.weekday);
	   for(i=0;i<4;i++)
	   {
	   	fscanf(fpstart,"%d",&date.weather_mode[i]);
	   }
	   fclose(fpstart);
	    get_data(&date,sunpower);  //�õ��������� 
			
	}  
	
	 if(mode==1)  //����ϵͳ������ 
	 {
	 	plant_mode=*pplant; 
	 	menu_mode=*pmenu;
	 }

	 
//******************��̬�仯���� 
	if(change_point>9999)  //ÿ��change_point+1���������99999�������һ�ζ�̬�仯����������Ӱ���������붯�����ֵ�ͬʱ���� 
	{
		change_point=0;
		daytime++;
	   if(daytime>1440) //һ����� 
	   {
		daytime=0;
		//**************�ѽ�������ݴ����̨������ 
		putin_data(date);
	    //***************last������ڸ�Ϊ���죬���º��������ݾ��ǡ����족
		putin_last(date);   
		
		putin_day(date);
		
	    record_data();//�洢���ܽ����� 
	    if(mode==1)
	    {
	    	summary_chart(plant_mode);
		}
		new_day(&date,sunpower);  //�µ�һ�쿪ʼ�� 
		
		//*******************���ǵ����ڴ�ͼ�� 
		if(mode==1||mode==3||mode==6)
		{
			setfillstyle(7,LIGHTBLUE);
		    bar(441,0,627,36);
		}
		
	   }
	    dynamic_data(daytime,&date,dydata,sunpower,errors);
	    
	    error_monitor(mode,errors,daytime,date);
	   
	  	new_chart(mode,dydata,plant_mode);  //ʵʱ��������ݱ仯���Ƿ񻭳������mode�ж� 
	   
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
	  
		   	
//**************��������ҳ���ж��Ƿ���ʾʱ�� ��ҳ�������ת��������ʾ ����������״����ֻ���realtime��ʵ�����ã� 
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
		case 5:  //�ܽ� 
			return plant_mode;
		case 6:  //����
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

